/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:07:25 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/21 22:07:27 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	int a = 1472;

	   printf("1234 - %d - 5678\n", a);
	ft_printf("1234 - %d - 5678\n", a);
	return 0;
}
