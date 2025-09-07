/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:16:04 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/07 22:25:23 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "libft.h"

static void	signal_handler(int signum);

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGTERM, signal_handler);
	while (1)
		pause();
	return (0);
}

static void	signal_handler(int signum)
{
	ft_printf("SIGTERM: %d\n", signum);
	exit(0);
}
