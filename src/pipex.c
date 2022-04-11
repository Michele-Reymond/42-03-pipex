/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:23 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/11 16:01:08 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc, char **argv)
{
	(void) argv;
	if (argc != 5)
	{
		printf("(Error) Too few or too much arguments\n");
		exit(0);
	}
	return (0);
}

void	check_files(char **argv)
{
	if (access( argv[1], F_OK ) != 0) 
	{
		printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(0);
	}
	if (access( argv[1], R_OK ) != 0)
	{
		printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(0);
	}	
	if (access( argv[4], F_OK ) != 0) 
		open ("outfile", O_CREAT, 0644);
	if (access( argv[4], W_OK) != 0)
	{
		printf("(Error) %s : %s \n", strerror(errno), argv[4]);
		exit(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	(void) envp;
	(void) pid1;
	(void) pid2;
	check_args(argc, argv);
	check_files(argv);
	if (pipe(fd) == -1)
		return (1);
	return (0);
}
