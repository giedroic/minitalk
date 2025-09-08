/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:11:45 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/08 16:00:59 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	signal_wrapper(int sig, void *signal_handler, int use_siginfo);
#endif
