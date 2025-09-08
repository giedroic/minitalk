/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:16:04 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 16:35:03 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
}
