# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 14:59:54 by srossi            #+#    #+#              #
#    Updated: 2018/06/15 16:07:16 by srossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

new_dir()
{
	if [ ! -d $1 ];
	then
		mkdir $1 &>/dev/null
	fi
}

new_link()
{
	if [ ! -f $2 ];
	then
		ln -sf $1 $2
	fi
}

new_link_dir()
{
	if [ ! -f $2 ];
	then
		ln -s $1 $2
	fi
}

root=`pwd`
echo "Initialisation des liens..."

new_link $root/libs/libft/libft.h $root/asm/includes/libft.h
new_link $root/libs/libft/libft.h $root/vm/includes/libft.h
new_link $root/includes/op.h $root/asm/includes/op.h
new_link $root/includes/op.h $root/vm/includes/op.h
new_dir $root/libs
new_dir $root/asm/libs
new_dir $root/vm/libs
new_link_dir $root/../libft/ $root/libs/libft
new_link $root/libs/libft/libft.a $root/asm/libs/libft.a
new_link $root/libs/libft/libft.a $root/vm/libs/libft.a

echo "Initialisation effectuee"
