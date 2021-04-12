/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:29:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 18:51:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERROR_QUIT "Stop : division by zero\n"
#define ERROR_RMID "Stop : modulo by zero\n"
#include <unistd.h>

long long	convert_int(char *c)
{
	long long	sum;
	int			sign;

	sign = 1;
	sum = 0;
	while ((*c >= 9 && *c <= 13) || *c == ' ')
		c++;
	while (*c == '-' || *c == '+')
	{
		if (*c == '-')
			sign *= -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		sum *= 10;
		sum += *c - '0';
		c++;
	}
	return (sign * sum);
}

long long	do_oper(char *a, char *oper, char *b, long long (*f)(char*))
{
	long long	num_1;
	long long	num_2;
	long long	ret;

	num_1 = f(a);
	num_2 = f(b);
	ret = 0;
	if (*oper == '+')
		ret = num_1 + num_2;
	if (*oper == '-')
		ret = num_1 - num_2;
	if (*oper == '/')
		ret = num_1 / num_2;
	if (*oper == '*')
		ret = num_1 * num_2;
	if (*oper == '%')
		ret = num_1 % num_2;
	return (ret);
}

void		rec_write(long long nbr)
{
	char	c;

	c = nbr % 10 + '0';
	if (nbr / 10)
		rec_write(nbr / 10);
	write(1, &c, 1);
}

void		print_ret(long long nbr)
{
	char		c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		if (-(nbr / 10))
			rec_write(-(nbr / 10));
		c = -(nbr % 10) + '0';
	}
	else
	{
		if (nbr / 10)
			rec_write(nbr / 10);
		c = nbr % 10 + '0';
	}
	write(1, &c, 1);
	write(1, "\n", 1);
}

int			main(int n, char *str[])
{
	if (n - 1 != 3)
		return (0);
	if (*str[2] != '+' && *str[2] != '-'
			&& *str[2] != '/' && *str[2] != '*' && *str[2] != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (*str[3] == '0')
	{
		if (*str[2] == '/')
		{
			write(1, ERROR_QUIT, 24);
			return (0);
		}
		if (*str[2] == '%')
		{
			write(1, ERROR_RMID, 22);
			return (0);
		}
	}
	print_ret(do_oper(str[1], str[2], str[3], &convert_int));
	return (0);
}
