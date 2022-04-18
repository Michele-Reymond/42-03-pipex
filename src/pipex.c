/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:23 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/18 17:38:42 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = find_paths(envp);
	check_args(argc);
	check_files(argv);
	pipex(argv, paths, envp);
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (0);
}
