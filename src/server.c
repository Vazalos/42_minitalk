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

int	main(void)
{
	int pid;

	pid = getpid();
	ft_printf("%process ID", pid);

	while(1)
	{

	}

	return EXIT_SUCCESS;
}
