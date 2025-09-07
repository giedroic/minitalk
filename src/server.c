/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:16:04 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/07 23:29:07 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	signal_handler(int signum);

int	main(void)
{
	struct sigaction action;

	
	ft_printf("Server PID: %d\n", getpid());
	
	while (1)
		pause();
	return (0);
}

static void	signal_handler(int signum)
{
	ft_printf("SIGTERM: %d\n", signum);
	exit(0);
}
