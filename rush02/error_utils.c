/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:13:54 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/21 21:19:28 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	handle_error(t_err_code err_code)
{
	if (err_code == ARG_ERROR)
		write(1, "Error\n", 6);
	else if (err_code == DICT_ERROR)
		write(1, "Dict Error\n", 11);
	return (1);
}
