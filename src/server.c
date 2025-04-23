/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:53 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/22 10:56:36 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"
#include <signal.h>

void	sig_handler(int signum)
{
	ft_printf("sig %d\n", signum);
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sig_act;

	pid = getpid();
	sig_act.sa_handler = sig_handler;
	sig_act.sa_flags = 0;
	sigemptyset(&sig_act.sa_mask); 
	//sigaddset(&sig_act.sa_mask, SIGUSR1);
	//sigaddset(&sig_act.sa_mask, SIGUSR2);
	ft_printf("server PID %d\n", pid);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while(1)
	{
		pause();
	}

	return (0);
}
