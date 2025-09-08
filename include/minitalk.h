/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:11:45 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 17:52:03 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define BYTE 8
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	kill_wraper(pid_t pid, int sig)
void	signal_wrapper(int signum, void *signal_handler, int use_siginfo);
#endif
