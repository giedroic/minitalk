/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:05:05 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 15:53:05 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	Signal(int sig, void *handler, int use_siginfo)
{
	struct sigaction	act;

	if (use_siginfo)
	{
		act.sa_flags = SA_SIGINFO;
		act.sa_sigaction = signal_handler;
	}
	else
		act.sa_handler = signal_handler;
}
