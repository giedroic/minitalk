/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:21:20 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 17:27:54 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(char byte, pid_t server);

int	main(int argc, char *argv[])
{
	pid_t	server;
	char	*string;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: ./client <server_PID> <string>\n", 38);
		return (EXIT_FAILURE);
	}
	server = ft_atoi(argv[1]);
	string = argv[2];
	return (EXIT_SUCCESS);
}

void	send_byte(char byte, pid_t server);
{
	
}
