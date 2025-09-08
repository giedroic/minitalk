/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:21:20 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 16:59:09 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	server;
	char	*string;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_PID> <string>\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
