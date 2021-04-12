/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:09:45 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 15:15:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int cnt;
	int ret;

	cnt = 0;
	while (*tab)
	{
		ret = f(*tab);
		if (ret != 0)
			cnt++;
		tab++;
	}
	return (cnt);
}
