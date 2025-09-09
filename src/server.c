/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:16:04 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/09 22:26:11 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal_wrapper(SIGUSR1, handler, 1);
	signal_wrapper(SIGUSR2, handler, 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static char	byte;
	static int	bit_pos;

	(void) ucontext;
	if (signum == SIGUSR1)
		byte = byte | (128 >> bit_pos);
	++bit_pos;
	if (bit_pos == CHAR_BIT)
	{
		bit_pos = 0;
		if (byte == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			kill_wraper(info->si_pid, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &byte, 1);
		byte = 0;
	}
	kill_wraper(info->si_pid, SIGUSR1);
}
