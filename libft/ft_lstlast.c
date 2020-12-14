/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:15:33 by atinseau          #+#    #+#             */
/*   Updated: 2020/11/20 13:17:55 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *s;

	s = lst;
	while (s != NULL)
	{
		if (s->next == NULL)
			return (s);
		s = s->next;
	}
	return (s);
}