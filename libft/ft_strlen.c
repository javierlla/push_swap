/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:37:14 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/08 16:37:15 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char	*s1;
	char	*s2;

	s1 = "re";
	s2 = "Test string";
	printf("string: %s length: %ld\n", s1, ft_strlen(s1));
	printf("string: %s length: %ld\n", s2, ft_strlen(s2));
	printf("string: %s length: %ld\n", s1, strlen(s1));
	printf("string: %s length: %ld\n", s2, strlen(s2));
}
*/
