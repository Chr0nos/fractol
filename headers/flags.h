/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:05:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 22:42:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define FLAG_NONE 0
# define FLAG_AIM 1u
# define FLAG_HALFMOUSE 1u << 1
# define FLAG_LOCKMOUSE 1u << 2
# define FLAG_AUTOITER 1u << 3
# define FLAG_NOSTATS 1u << 4
# define FLAG_NOHSCROLL 1u << 5

#endif
