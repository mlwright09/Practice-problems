/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 09:03:36 by exam              #+#    #+#             */
/*   Updated: 2017/02/08 18:57:15 by mwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
int		ft_strlen(char *s)
{
	int i = 0;
	
	while (s[i] != 0)
		i++;
	return (i);
}

int		wordcount(char *s)
{
	int i = 0;
	int count = 1;

	while(s[i] != 0)
	{
		if ((s[i] == ' ' || s[i] == '\t') && ft_strlen(s) > 1)
			count++;
		i++;
	}
	if (count == 1 && ft_strlen(s) >= 1)
		count = 1;
	else if (count == 1)
		count = 0;
	return (count);
}

int		main(int argc, char **argv)
{
	int i = 0;
	int words = 0;
	char *s;
	int newcount = 0;
	int start = 0;
	int a = 0;
	
	if (argc == 2)
	{
		words = wordcount(argv[1]);
		i = ft_strlen(argv[1]) -1;
		s = (char *)malloc(sizeof(char) * ft_strlen(argv[1]));
		while (words > 0)
		{
				while(i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
				{
					i--;
					newcount++;
				}
				words--;
				start = i + 1;
				i--;
				while (newcount > 0)
				{
					s[a] = argv[1][start];
					start++;
					a++;
					newcount--;
				}
					s[a] = ' ';
					a++;
		}
		s[a -1] = '\0';
		a = 0;
		while(s[a] != '\0')
		{
			write(1, &s[a], 1);
			a++;	
		}
	}
	write(1, "\n", 1);
	return (0);
}
