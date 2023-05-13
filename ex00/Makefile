# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 19:34:14 by jgo               #+#    #+#              #
#    Updated: 2023/05/13 18:54:26 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_config/Rules.mk
include ../make_config/Color_rules.mk

SRCS :=	main.cpp \
		ClapTrap.cpp

NAME := Aaaaaaand...OPEN!

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../make_config/Recipes.mk