/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:11:45 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 19:37:40 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

enum e_state
{
	BUSY,
	READY,
};
void	kill_wraper(pid_t pid, int sig);
void	signal_wrapper(int signum, void *signal_handler, int use_siginfo);
#endif
