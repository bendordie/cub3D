/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:57:10 by cshells           #+#    #+#             */
/*   Updated: 2020/12/08 16:56:12 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int    main(int argc, char **argv)
{
    int        res;
    int        fd;
    char    *str;

	str = NULL;
    fd = open("map.cub", O_RDONLY);
    //res = get_next_line(open("test", O_RDONLY), &str);
    while ((res = get_next_line(fd, &str)) > 0)
    {
        printf("[%d]: %s\n", res, str);
        //free(str);
    }
    return (0);
}
