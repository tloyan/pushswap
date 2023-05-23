/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc_stdlib.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:45:58 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 13:15:05 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBC_STDLIB_H
# define FT_LIBC_STDLIB_H

int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);

#endif