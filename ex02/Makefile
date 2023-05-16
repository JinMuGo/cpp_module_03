# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 19:34:14 by jgo               #+#    #+#              #
#    Updated: 2023/05/16 15:34:01 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_config/Rules.mk
include ../make_config/Color_Rules.mk

SRCS :=	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

NAME := Serena_my_love!

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../make_config/Recipes.mk