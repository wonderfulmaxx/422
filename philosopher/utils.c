/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:25:34 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 06:25:49 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    smart_sleep(int time)
{
    sleep (time);
}

long long timestamp(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}