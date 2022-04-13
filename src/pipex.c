/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:23 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/13 16:12:43 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc, char **argv)
{
	(void) argv;
	if (argc > 5)
	{
		ft_printf("(Error) Too much arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (argc < 5)
	{
		ft_printf("(Error) Too few arguments\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	check_files(char **argv)
{
	if (access(argv[1], F_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}	
	if (access(argv[4], F_OK) != 0)
		open ("outfile", O_CREAT, 0644);
	if (access(argv[4], W_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[4]);
		exit(EXIT_FAILURE);
	}
}

void	child_process(int infile, char *cmd1, char **paths, int fd[])
{
	(void)paths;
	(void)cmd1;
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	// execve();
}

void	pipex(char **argv, char **paths)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;

	(void)pid2;
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY);
	if (pipe(fd) == -1)
		return ;
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork: "));
	if (pid1 == 0)
		child_process(infile, argv[2], paths, fd);
	else
	{
		printf("hello from parent\n");
		printf("pid = %d\n", pid1);
	}
	wait(NULL);
}

char	**find_paths(char **envp)
{
	int		i;
	char	*path;
	char	**all_path;

	i = 0;
	while ((ft_strnstr(envp[i], "PATH", 20) == NULL) && envp[i])
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	all_path = ft_split(path, ':');
	return (all_path);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	paths = find_paths(envp);
	check_args(argc, argv);
	check_files(argv);
	pipex(argv, paths);
	return (0);
}

// pid1 = 0 child
// pid1 != 0 parent

// malloc path et all_path dans find_path