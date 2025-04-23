/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:53:35 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/22 10:55:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <signal.h>
#include <stdio.h>

void	ft_send_char(pid_t pid, char c)
{
	int	bit_pos;

	bit_pos = CHAR_BIT - 1;
	while(bit_pos >= 0)
	{
		if ((c >> bit_pos) & 1) //SIGUSR1 => bit 1
		{
			kill(pid, SIGUSR1);
			ft_printf("%i", (c >> bit_pos) & 1);
		}
		else //SIGUSR2 => bit 0
		{
			kill(pid, SIGUSR2);
			ft_printf("0");
		}
		bit_pos--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		char_pos;

	if (argc != 3)
	{
		write(2, "FORMAT => ./client <server PID> \"message\"\n", 42);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	char_pos = 0;

	while (message[char_pos])
		ft_send_char(server_pid, message[char_pos++]);
	ft_printf("\n");
	ft_send_char(server_pid, '\0');
}
