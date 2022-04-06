/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:22:58 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/30 15:43:56 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_percent(va_list ptr, const char *str, int i, int *count)
{
	if (str[i + 1] == 'c' || str[i + 1] == 's')
		ft_ischar(ptr, str, i, count);
	else if (str[i + 1] == 'p')
	{
		write(1, "0x", 2);
		ft_bin_hex(va_arg(ptr, unsigned long int), count);
		*count += 2;
	}
	else if (str[i + 1] == 'd')
		ft_putnbr_pr_fd(va_arg(ptr, int), 1, count);
	else if (str[i + 1] == 'i')
		ft_putnbr_pr_fd(va_arg(ptr, int), 1, count);
	else if (str[i + 1] == 'u')
		ft_putuns_fd(va_arg(ptr, int), 1, count);
	else if (str[i + 1] == 'x')
		ft_putnbr_base2_fd(va_arg(ptr, int), 1, count);
	else if (str[i + 1] == 'X')
		ft_putnbr_base_fd(va_arg(ptr, int), 1, count);
	else if (str [i + 1] == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
}

void	ft_ischar(va_list ptr, const char *str, int i, int *count)
{
	char	*strr;

	if (str[i + 1] == 'c')
	{
		ft_putchar_fd(va_arg(ptr, int), 1);
		*count += 1;
	}
	else if (str[i + 1] == 's')
	{
		strr = va_arg(ptr, char *);
		if (strr == NULL)
		{
			ft_putstr_fd("(null)", 1);
			*count += 6;
			return ;
		}
		*count += ft_strlen(strr);
		ft_putstr_fd(strr, 1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			write(1, &str[i++], 1);
			count++;
		}
		if (str[i])
		{
			ft_percent(ptr, str, i, &count);
			i += 2;
		}
	}
	va_end(ptr);
	return (count);
}
