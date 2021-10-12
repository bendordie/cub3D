/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:42:41 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 02:22:46 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_str_to_lowercase(char **str)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] >= 'A' && str[0][i] <= 'Z')
			str[0][i] = str[0][i] + 32;
		i++;
	}
}

void	ft_check_extension(char *filename, char *extension)
{
	char	*result;

	if (!filename)
		ft_error("Error: Filename not found");
	ft_str_to_lowercase(&filename);
	result = ft_strnstr(filename, extension, ft_strlen(filename));
	if (!result || ft_strncmp(result, extension, 4))
		ft_error("Error: Invalid file extension");
}
