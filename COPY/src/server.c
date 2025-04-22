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

void	*sig_handler(int signal)
{
	ft_printf("received signal %d", signal);
}

int	main(void)
{
	int pid;

	pid = getpid();
	ft_printf("%process ID", pid);

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	while(1)
	{
		pause();
	}

	return (0);
}
