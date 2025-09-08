/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:16:04 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 14:42:17 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
