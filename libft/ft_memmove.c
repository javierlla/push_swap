/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:36:08 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/08 16:36:11 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_p;
	char	*src_p;
	size_t	i;

	i = 0;
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (src == dst || !n)
		return (dst);
	if (src_p < dst_p)
	{
		while (++i <= n)
		{
			dst_p[n - i] = src_p[n - i];
		}
	}
	else
		while (n-- > 0)
			*dst_p++ = *src_p++;
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*p;
	char src[] = "hallaaaaaaaao";
	char dest[] = "test";
	p = ft_memmove(dest, src, 4);
	printf("%s", (unsigned char *)(p));
}*/
