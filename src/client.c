/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:53:35 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/29 15:12:31 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_char(pid_t pid, char c)
{
	int	bit_pos;

	bit_pos = CHAR_BIT - 1;
	while (bit_pos >= 0)
	{
		if ((c >> bit_pos) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_pos--;
		usleep(100);
	}
}

void	ft_send_message(pid_t pid, char *message)
{
	int	char_pos;

	char_pos = 0;
	while (message[char_pos])
		ft_send_char(pid, message[char_pos++]);
}

void	ft_send_len(pid_t pid, int message_len)
{
	int	bit_pos;

	bit_pos = (sizeof(int) * CHAR_BIT) - 1;
	while (bit_pos >= 0)
	{
		if ((message_len >> bit_pos) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_pos--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		write(2, "FORMAT => ./client <server PID> \"message\"\n", 42);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_send_len(server_pid, ft_strlen(message));
	ft_send_message(server_pid, message);
	ft_send_char(server_pid, '\0');
}
