/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:53 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/29 15:06:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	ft_reset_data(t_data *data)
{
	data->msg_started = 0;
	data->msg_len = 0;
	data->bits = 0;
	data->bytes = 0;
	free(data->message);
	data->message = NULL;
}

void	ft_assign_message(t_data *data, int signum)
{
	static int	char_pos;

	if (data->bits == 0)
		data->bytes = 0;
	if (signum == SIGUSR1)
		data->bytes |= 1 << (7 - data->bits);
	else if (signum == SIGUSR2)
		data->bytes &= ~(1 << (7 - data->bits));
	data->bits++;
	if (data->bits == 8)
	{
		if (char_pos < data->msg_len)
			data->message[char_pos] = data->bytes;
		char_pos++;
		data->bits = 0;
		if (data->bytes == '\0')
		{
			ft_printf("%s\n", data->message);
			ft_reset_data(data);
			char_pos = 0;
		}
	}
}

void	ft_sig_handler(int signum)
{
	static t_data		data;
	static long int		sig_count;

	if (data.msg_started == 0)
	{
		if (signum == SIGUSR1)
			data.msg_len |= 1 << (31 - sig_count);
		else if (signum == SIGUSR2)
			data.msg_len &= ~(1 << (31 - sig_count));
		if (sig_count == 31)
		{
			data.msg_started = 1;
			data.message = malloc(sizeof(char) * (data.msg_len + 1));
		}
		sig_count++;
	}
	else
	{
		ft_assign_message(&data, signum);
		sig_count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_act;

	pid = getpid();
	sig_act.sa_handler = ft_sig_handler;
	sig_act.sa_flags = 0;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	ft_printf("server PID %d\n", pid);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (42)
		pause();
	return (0);
}
