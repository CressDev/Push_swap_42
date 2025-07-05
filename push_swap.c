/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:59:21 by cress             #+#    #+#             */
/*   Updated: 2025/07/05 21:10:36 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*argv_define(char **argv, int n)
{
	t_list	*st_a;
	char	**split_a;

	if (n == 1)
	{
		write (1, "inicio\n", 7);
		if (error_handler(argv) == 1)
			st_a = stack_init(argv);
		write (1, "stack iniciada\n", 15);
	}
	else
	{
		split_a = ft_split(argv[0], ' ');
		write (1, "inicio\n", 7);
		if (error_handler(split_a) == 1)
			st_a = stack_init(split_a);
		write (1, "stack iniciada\n", 15);
		free_mem(split_a);
	}
	return (st_a);
}

int	main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*aux;

	if (argc == 2)
		st_a = argv_define(argv + 1, 2);
	else
		st_a = argv_define(argv + 1, 1);
	aux = st_a;
	while (aux != NULL)
	{
		ft_printf("%d\n", (int)(long)aux->content);
		aux = aux->next;
	}

	return (0);
}