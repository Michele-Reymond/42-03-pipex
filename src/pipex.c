/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:23 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/04 17:08:19 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("(Error) Too few or too much arguments\n");
		exit(1);
	}
	// if(access("ACCESS.C",F_OK)==0) {
	// 	printf("Le fichier «ACCESS.C» existe !\n");
	// } else {
	// 	printf("Le fichier «ACCESS.C» n'existe pas !\n");
	// } 
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	check_args(argc, argv);
	if (pipe(fd) == -1)
		return (1);
	return (0);
}
