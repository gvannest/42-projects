# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    uninit.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:12:19 by pprikazs          #+#    #+#              #
#    Updated: 2018/06/15 11:40:55 by srossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/zsh

root=`pwd`

echo "Desinisialisation des liens..."

rm -f $root/asm/libs/libft.a
rm -f $root/vm/libs/libft.a
rm -rf $root/asm/libs
rm -rf $root/vm/libs
rm -rf $root/libs

echo "Désinitialisation effectuee..."
