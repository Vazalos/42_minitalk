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
#include <stdlib.h>

void	ft_assign_message(char *message, int signum, int sig_count) // Everytime I have 8 chars I assign a new char to message str
{
	static int	bit_count;
	static char	c;
	static int	test_i;

	ft_printf("%i", test_i++);
	if (signum == SIGUSR1)
		c |= 1 << (31 - sig_count);
	else if (signum == SIGUSR2)
		c &= ~(1 << (31 - sig_count));
	bit_count++;
	(void)message;
	if (bit_count == 8)
	{/*
		bit_count = 0;
		message[sig_count - 31] = c;
		if (c == '\0')
		{
			ft_printf("%s", message);
			exit(0);
		}
		c = 0;*/
		ft_printf("%c", c);
	}
}

void	sig_handler(int signum)
{
	static char	msg_start;
	static int	sig_count;
	static char *message;
	static int	msg_len;
	
	if (msg_start == 0)
	{
		if (signum == SIGUSR1)
			msg_len |= 1 << (31 - sig_count);
		else if (signum == SIGUSR2)
			msg_len &= ~(1 << (31 - sig_count));
		if (sig_count == 31)
		{
			message = malloc(sizeof(char) * (msg_len + 1));
			msg_start = 1;
		}
	}
	else
		ft_assign_message(message, signum, sig_count);
	sig_count++;
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sig_act;

	pid = getpid();
	sig_act.sa_handler = sig_handler;
	sig_act.sa_flags = 0;
	sigemptyset(&sig_act.sa_mask); 
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	ft_printf("server PID %d\n", pid);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while(42)
		pause();
	return (0);
}

	/*static int i;
	if(signum == SIGUSR1)
		ft_printf("1");
	if(signum == SIGUSR2)
		ft_printf("0");
	i++;
	if(i % 8 == 0)
	{
		ft_printf(" ");
	}*/

