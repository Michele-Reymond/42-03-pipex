/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:33:04 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/18 15:17:37 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_paths(char **envp)
{
	int		i;
	char	*path;
	char	**all_path;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH", 20) == NULL))
		i++;
	if (envp[i] == NULL)
	{
		ft_printf("(Error) PATH not found\n");
		exit(EXIT_FAILURE);
	}
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	all_path = ft_split(path, ':');
	free(path);
	return (all_path);
}

void	exec_cmd(char **paths, char *first_cmd, char **envp, char **flags)
{
	int		i;
	char	*cmd;

	i = 0;
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], first_cmd);
		free(first_cmd);
		execve(cmd, flags, envp);
		free(cmd);
		i++;
	}
}

void	first_child_process(char **argv, char **paths, int fd[], char **envp)
{
	int		infile;
	char	**flags;
	char	*first_cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close(fd[1]);
		close(fd[0]);
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}
	flags = ft_split(argv[2], ' ');
	first_cmd = ft_strjoin("/", flags[0]);
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	exec_cmd(paths, first_cmd, envp, flags);
}

void	scd_child_process(char **argv, char **paths, int fd[], char **envp)
{
	int		outfile;
	char	**flags;
	char	*first_cmd;

	outfile = open(argv[4], O_WRONLY);
	if (outfile < 0)
	{
		close(fd[1]);
		close(fd[0]);
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}
	flags = ft_split(argv[3], ' ');
	first_cmd = ft_strjoin("/", flags[0]);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	exec_cmd(paths, first_cmd, envp, flags);
}

void	pipex(char **argv, char **paths, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		return ;
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork: "));
	if (pid1 == 0)
		first_child_process(argv, paths, fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork: "));
	if (pid2 == 0)
		scd_child_process(argv, paths, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
