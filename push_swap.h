/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:54:24 by cress             #+#    #+#             */
/*   Updated: 2025/07/08 21:26:27 by cress            ###   ########.fr       */
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
void	free_list(t_list *lst);
int		error_handler(char **s_a, int out_free);
int		error_str(char **s_a);
int		error_max(char **s_a, int out_free);
int		error_dup(char	**s_a, int out_free);
int		error_no_digit(char **s_a, int out_free);
t_list	*stack_init(char **split_a);








#endif
