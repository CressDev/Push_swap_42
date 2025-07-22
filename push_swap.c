/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:59:21 by cress             #+#    #+#             */
/*   Updated: 2025/07/21 11:32:37 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_multiple(char **argv)
{
	char	*result;
	char	*aux;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (argv[i])
	{
		cmp_str_empty(argv[i]);
		aux = result;
		result = ft_strjoin(aux, argv[i]);
		free(aux);
		aux = result;
		result = ft_strjoin(aux, " ");
		free(aux);
		i++;
	}
	return (result);
}

void	cmp_argv_empty(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		cmp_str_empty(argv[i]);
		i++;
	}
}

int	cmp_str_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] == ' ')
		i++;
	if (argv[i] == '\0')
		error_exit();
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) || argv[i] == ' '
			|| argv[i] == '+' || argv[i] == '-')
			i++;
		else
			error_exit();
	}
	return (1);
}

t_list	*argv_define(char **argv, int n)
{
	t_list	*st_a;
	char	**split_a;
	char	*join_args;

	st_a = NULL;
	if (n == 1)
	{
		cmp_argv_empty(argv);
		join_args = ft_strjoin_multiple(argv);
		cmp_str_empty(join_args);
		split_a = ft_split(join_args, ' ');
		free(join_args);
		if (error_handler(split_a) == 1)
			st_a = stack_init_radix(split_a);
		free_mem(split_a);
	}
	else
	{
		cmp_str_empty(argv[0]);
		split_a = ft_split(argv[0], ' ');
		if (error_handler(split_a) == 1)
			st_a = stack_init_radix(split_a);
		free_mem(split_a);
	}
	return (st_a);
}

int	main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;

	if (argc > 1)
	{
		st_b = NULL;
		if (argc == 2)
			st_a = argv_define(argv + 1, 2);
		else
			st_a = argv_define(argv + 1, 1);
		radix_sort(&st_a, &st_b);
		free_list(st_a);
	}
	return (0);
}
