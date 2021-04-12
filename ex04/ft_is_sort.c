/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:15:56 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 15:47:05 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int way;
	int ret;
	int sign;

	i = 0;
	ret = 0;
	way = 0;
	while (way == 0 && i < length)
		way = f(tab[i++], tab[i + 1]);
	while (i < length)
	{
		ret = f(tab[i], tab[i + 1]);
		if (way * ret < 0)
			return (0);
		i++;
	}
	return (1);
}
