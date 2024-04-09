/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:37:25 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/08 16:37:26 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	char	str1[50]="za";
	char	str2[50]="";
	printf("ft_cmp:%d\n", ft_strncmp(str1, str2, 5));
	printf("cmp:%d\n", strncmp(str1, str2, 5));
}
*/