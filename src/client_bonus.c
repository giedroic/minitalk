/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:21:20 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/09 22:25:52 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server;
void	ack_handler(int signum);
void	end_handler(int signum);
void	send_byte(char byte, pid_t pid);

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: ./client <server_PID> <message>\n", 38);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	signal_wrapper(SIGUSR1, ack_handler, 0);
	signal_wrapper(SIGUSR2, end_handler, 0);
	while (*message != '\0')
		send_byte(*message++, server_pid);
	send_byte('\0', server_pid);
	return (EXIT_SUCCESS);
}

void	ack_handler(int signum)
{
	(void) signum;
	g_server = READY;
}

void	end_handler(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "Message received!\n", 17);
	exit (EXIT_SUCCESS);
}

void	send_byte(char byte, pid_t pid)
{
	int	bit_pos;

	bit_pos = 0;
	while (bit_pos < CHAR_BIT)
	{
		if (byte & 128 >> bit_pos)
			kill_wraper(pid, SIGUSR1);
		else
			kill_wraper(pid, SIGUSR2);
		++bit_pos;
		while (g_server == BUSY)
			usleep(100);
		g_server = BUSY;
	}
}
