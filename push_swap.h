/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:54:24 by cress             #+#    #+#             */
/*   Updated: 2025/07/05 20:08:50 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

void	free_mem(char **s);
int		error_handler(char **s_a);
int		error_dup(char	**s_a);
int		error_no_digit(char **s_a);
t_list	*stack_init(char **split_a);








#endif
