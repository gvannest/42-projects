# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    salamahenagalabadoun.s                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjestin <gjestin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/21 22:08:42 by gjestin           #+#    #+#              #
#    Updated: 2018/08/02 19:25:01 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "salamahenagalabadoun"
.comment "sussKBO hin hin"

ld		32, r3
ld		4, r4
ld		190, r5
st		r1, 6
loop:
live	%666
sti		r5, r5, r3
add		r3, r4, r5
ld		%0, r16
zjmp	%:loop
