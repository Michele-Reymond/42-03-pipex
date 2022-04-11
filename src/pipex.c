/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:23 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/11 19:29:50 by mreymond         ###   ########.fr       */
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
	if (access( argv[1], F_OK ) != 0) 
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (access( argv[1], R_OK ) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}	
	if (access( argv[4], F_OK ) != 0) 
		open ("outfile", O_CREAT, 0644);
	if (access( argv[4], W_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[4]);
		exit(EXIT_FAILURE);
	}
}

void 	pipex(char **argv, char **envp)
{
	pid_t	pid1;
	// pid_t	pid2;
	int		fd[2];

	(void)envp;
	(void)argv;
	if (pipe(fd) == -1)
		return ;
	pid1 = fork();
	if (pid1 == -1)
		return ;
	if (pid1 == 0)
	{
		printf("hello from child\n");
		printf("pid = %d\n", pid1);
	}
	else
	{
		printf("hello from parent\n");
		printf("pid = %d\n", pid1);
	}
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	check_args(argc, argv);
	check_files(argv);
	pipex(argv, envp);

	return (0);
}
