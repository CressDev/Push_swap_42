/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:59:21 by cress             #+#    #+#             */
/*   Updated: 2025/07/11 19:38:00 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

int	cmp_str_empty(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
	{
		write (2, "ERRORes\n", 8);
		exit(1);
	}
	while (argv[i])
	{
		if (argv[i] == ' ' && argv[i + 1] == ' ')
		{
			write (2, "ERRORess\n", 9);
			exit(1);
		}
		if (ft_isdigit(argv[i]) || argv[i] == ' '
			|| argv[i] == '+' || argv[i] == '-')
			i++;
		else
		{
			write (2, "ERRORess\n", 9);
			exit(1);
		}
	}
	return (1);
}
ls -p -t -m
t_list	*argv_define(char **argv, int n)
{
	t_list	*st_a;
	char	**split_a;

	st_a = NULL;
	if (n == 1)
	{
		write (1, "inicio\n", 7);
		if (error_handler(argv, 0) == 1)
			st_a = stack_init(argv);
		write (1, "stack iniciada\n", 15);
	}
	else
	{
		cmp_str_empty(argv[0]);
		split_a = ft_split(argv[0], ' ');
		write (1, "inicio\n", 7);
		if (error_handler(split_a, 1) == 1)
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

	if (argc > 1)
	{
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
		free_list(st_a);
	}
	return (0);
}9o9