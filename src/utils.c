/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:05:05 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 16:47:19 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_wrapper(int signum, void *handler, int use_siginfo)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	if (use_siginfo)
	{
		act.sa_flags = SA_SIGINFO;
		act.sa_sigaction = handler;
	}
	else
		act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	if (sigaction(signum, &act, NULL) < 0)
		exit(EXIT_FAILURE);
}
