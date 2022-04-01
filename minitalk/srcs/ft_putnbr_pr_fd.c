/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:59 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/30 15:42:21 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_pr_fd(int n, int fd, int *count)
{
	char	*str;

	ft_putnbr_fd(n, fd);
	str = ft_itoa(n);
	*count += ft_strlen(str);
	free(str);
}

void	ft_putnbr_pr2_fd(int n, int fd, int *count)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	*count += ft_strlen(str);
	free(str);
}
