/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:56:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/29 14:11:39 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_data
{
	int		bytes;
	int		bits;
	int		msg_started;
	int		msg_len;
	char	*message;
}	t_data;

#endif
