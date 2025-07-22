/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:30:24 by cress             #+#    #+#             */
/*   Updated: 2025/07/18 21:13:23 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(char **s)

{
	size_t	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	is_negative(char *str, int *is_po_or_ne)
{
	int	start;

	start = 0;
	*is_po_or_ne = 0;
	if (str[0] == '-')
	{
		*is_po_or_ne = 1;
		start = 1;
	}
	else if (str[0] == '+')
		start = 1;
	return (start);
}

int	cmp_max_min(char *str, int start, int len, int is_po_or_ne)
{
	char	*max_int;
	char	*min_int;

	max_int = "2147483647";
	min_int = "2147483648";
	if (len == 10)
	{
		if (is_po_or_ne == 1)
		{
			if (ft_strncmp(str + start, min_int, 10) > 0)
				return (0);
		}
		else
		{
			if (ft_strncmp(str + start, max_int, 10) > 0)
				return (0);
		}
	}
	return (1);
}

int	is_more_or_less(char *str)
{
	int	len;
	int	is_po_or_ne;
	int	start;

	is_po_or_ne = 0;
	start = is_negative(str, &is_po_or_ne);
	len = ft_strlen(str + start);
	if (len > 10)
		return (0);
	if (cmp_max_min(str, start, len, is_po_or_ne) == 1)
		return (1);
	return (0);
}

int	error_max(char **s_a)
{
	int	i;
	int	result;

	i = 0;
	while (s_a[i])
	{
		result = is_more_or_less(s_a[i]);
		if (result == 0)
		{
			free_mem(s_a);
			error_exit();
		}
		i++;
	}
	return (1);
}

