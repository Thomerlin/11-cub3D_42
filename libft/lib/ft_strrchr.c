/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:06:09 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/04 17:00:42 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	*backup;

	backup = 0;
	while (*string)
	{
		if (*string == (unsigned char)c)
			backup = (char *)string;
		string++;
	}
	if (*string == (unsigned char)c)
		backup = (char *)string;
	return (backup);
}
