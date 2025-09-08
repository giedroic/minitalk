/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:16:04 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 18:24:43 by agiedroi         ###   ########.fr       */
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
	(void) ucontext;
	static char	byte;
	static int	bit_pos;
}
