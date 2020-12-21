# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 19:53:39 by najimehdi         #+#    #+#              #
#    Updated: 2019/12/10 15:15:49 by mnaji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
.SILENT:
endif

NAME		=	libasm.a

SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
BONUS_SRCS	=	ft_list_size_bonus.s ft_list_push_front_bonus.s
BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NA_FLAGS	=	nasm -f macho64
FLAGS 		=	-Wall -Werror -Wextra

%.o: %.s
	$(NA_FLAGS) $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "\033[32mlibasm.a generated !\033[0m"

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)
	@echo "\033[31mObjects deleted !\033[0m"

fclean:	clean
	rm -rf $(NAME) $(BONUS) $(TEST) $(TEST_BONUS)
	@echo "\033[31mlibasm.a deleted !\033[0m"

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "\033[32mlibasm.a with bonus generated !\033[0m"

.PHONY: clean fclean re bonus