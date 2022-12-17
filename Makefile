# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:38:39 by thloyan           #+#    #+#              #
#    Updated: 2022/12/17 16:35:44 by thloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                                   VARIABLES                                  #
#                                                                              #
################################################################################

LIBFT_PATH = libft
INLCUDES_LIBFT = libft/includes

NAME_PUSHSWAP = push_swap
NAME_CHECKER = checker
NAME = $(NAME_PUSHSWAP)


INLCUDES_PUSHSWAP = includes/push_swap
INLCUDES_CHECKER = includes/checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = objs

OBJDIR_PUSHSWAP = $(OBJDIR)/push_swap
PATH_PUSHSWAP = srcs/push_swap
SRCS_PUSHSWAP = main.c push_swap.c
OBJS_PUSHSWAP = $(addprefix $(OBJDIR_PUSHSWAP)/, $(SRCS_PUSHSWAP:.c=.o))


OBJDIR_CHECKER = $(OBJDIR)/checker
PATH_CHECKER = srcs/checker
SRCS_CHECKER = main.c checker.c
OBJS_CHECKER = $(addprefix $(OBJDIR_CHECKER)/, $(SRCS_CHECKER:.c=.o))


################################################################################
#                                                                              #
#                                   RULES                                      #
#                                                                              #
################################################################################

################################################################################
#                                 PUSH_SWAP                                    #
################################################################################

all: $(NAME)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJDIR) $(OBJDIR_PUSHSWAP) $(OBJS_PUSHSWAP)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PUSHSWAP) -Llibft -lft

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR_PUSHSWAP):
	mkdir $(OBJDIR_PUSHSWAP)

$(OBJDIR_PUSHSWAP)/%.o: $(PATH_PUSHSWAP)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES_PUSHSWAP} -I$(INLCUDES_LIBFT)

clean:
	rm -f $(OBJS_PUSHSWAP)
	rm -rf $(OBJDIR_PUSHSWAP)

fclean: clean
	rm -f $(NAME)

re: fclean all

################################################################################
#                                  CHECKER                                     #
################################################################################

$(NAME_CHECKER): $(LIBFT_PATH)/libft.a $(OBJDIR) $(OBJDIR_CHECKER) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJS_CHECKER) -Llibft -lft

$(OBJDIR_CHECKER):
	mkdir $(OBJDIR_CHECKER)

$(OBJDIR_CHECKER)/%.o: $(PATH_CHECKER)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES_CHECKER} -I$(INLCUDES_LIBFT)

clean_checker:
	rm -f $(OBJS_CHECKER)
	rm -rf $(OBJDIR_CHECKER)

fclean_checker: clean_checker
	rm -f $(NAME_CHECKER)

re_checker: fclean_checker $(NAME_CHECKER)

################################################################################
#                                   LIBFT                                      #
################################################################################

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) all

clean_libft:
	make -C $(LIBFT_PATH) clean

fclean_libft:
	make -C $(LIBFT_PATH) fclean

re_libft:
	make -C $(LIBFT_PATH) re

.PHONY: all clean fclean re \
		clean_checker fclean_checker re_checker \
		clean_libft fclean_libft re_libft

################################################################################
#                                                                              #
#                                   END                                        #
#                                                                              #
################################################################################