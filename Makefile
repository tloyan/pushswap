# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:38:39 by thloyan           #+#    #+#              #
#    Updated: 2022/12/19 17:23:28 by thloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                                   VARIABLES                                  #
#                                                                              #
################################################################################

LIBFT = libft
INLCUDES_LIBFT = libft/includes

NAME_PUSHSWAP = push_swap
NAME_CHECKER = checker
NAME = $(NAME_PUSHSWAP)

UTILS = utils

INLCUDES = includes

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
OBJDIR = objs

OBJDIR_UTILS = $(OBJDIR)/utils
PATH_UTILS = srcs/utils
SRCS_UTILS = process_args.c process_exit.c display_lst.c
OBJS_UTILS = $(addprefix $(OBJDIR_UTILS)/, $(SRCS_UTILS:.c=.o))

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

$(NAME): $(LIBFT) $(UTILS) $(OBJDIR) $(OBJDIR_PUSHSWAP) $(OBJS_PUSHSWAP)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PUSHSWAP) $(OBJS_UTILS) -Llibft -lft

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR_PUSHSWAP):
	mkdir $(OBJDIR_PUSHSWAP)

$(OBJDIR_PUSHSWAP)/%.o: $(PATH_PUSHSWAP)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES} -I$(INLCUDES_LIBFT)

clean:
	rm -f $(OBJS_PUSHSWAP)
	rm -rf $(OBJDIR_PUSHSWAP)

fclean: clean
	rm -f $(NAME)

re: fclean all

################################################################################
#                                  CHECKER                                     #
################################################################################

$(NAME_CHECKER): $(LIBFT) $(UTILS) $(OBJDIR) $(OBJDIR_CHECKER) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJS_CHECKER) $(OBJS_UTILS) -Llibft -lft

$(OBJDIR_CHECKER):
	mkdir $(OBJDIR_CHECKER)

$(OBJDIR_CHECKER)/%.o: $(PATH_CHECKER)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES} -I$(INLCUDES_LIBFT)

clean_checker:
	rm -f $(OBJS_CHECKER)
	rm -rf $(OBJDIR_CHECKER)

fclean_checker: clean_checker
	rm -f $(NAME_CHECKER)

re_checker: fclean_checker $(NAME_CHECKER)

################################################################################
#                                    UTILS                                     #
################################################################################

utils: $(LIBFT) $(OBJDIR) $(OBJDIR_UTILS) $(OBJS_UTILS)

$(OBJDIR_UTILS):
	mkdir $(OBJDIR_UTILS)

$(OBJDIR_UTILS)/%.o: $(PATH_UTILS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES} -I$(INLCUDES_LIBFT)

clean_utils:
	rm -f $(OBJS_UTILS)
	rm -rf $(OBJDIR_UTILS)

fclean_utils: clean_utils
	rm -f $(NAME_UTILS)

re_utils: fclean_utils $(NAME_UTILS)

################################################################################
#                                   LIBFT                                      #
################################################################################

$(LIBFT):
	make -C $(LIBFT) all

clean_libft:
	make -C $(LIBFT) clean

fclean_libft:
	make -C $(LIBFT) fclean

re_libft:
	make -C $(LIBFT) re

.PHONY: all clean fclean re \
		clean_checker fclean_checker re_checker \
		clean_libft fclean_libft re_libft \
		$(LIBFT) $(UTILS)

################################################################################
#                                                                              #
#                                   END                                        #
#                                                                              #
################################################################################