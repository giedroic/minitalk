/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:05:05 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 16:15:22 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	signal_wrapper(int signum, void *handler, int use_siginfo)
{
	struct sigaction	act;

	act = {0};
	if (use_siginfo)
	{
		act.sa_flags = SA_SIGINFO;
		act.sa_sigaction = signal_handler;
	}
	else
		act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
}
