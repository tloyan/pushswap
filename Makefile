# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:38:39 by thloyan           #+#    #+#              #
#    Updated: 2023/01/16 16:24:10 by thloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                                   VARIABLES                                  #
#                                                                              #
################################################################################

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
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
SRCS_UTILS = 	process_args.c process_args_val.c process_exit.c stack.c ft_swap.c \
				ft_push.c ft_rotate.c ft_rrotate.c exec_instruction.c
OBJS_UTILS = $(addprefix $(OBJDIR_UTILS)/, $(SRCS_UTILS:.c=.o))

OBJDIR_PUSHSWAP = $(OBJDIR)/push_swap
PATH_PUSHSWAP = srcs/push_swap
SRCS_PUSHSWAP = main.c algo_low.c algo_utils.c instructions.c
OBJS_PUSHSWAP = $(addprefix $(OBJDIR_PUSHSWAP)/, $(SRCS_PUSHSWAP:.c=.o))

OBJDIR_CHECKER = $(OBJDIR)/checker
PATH_CHECKER = srcs/checker
SRCS_CHECKER = main.c check_result.c instructions.c
OBJS_CHECKER = $(addprefix $(OBJDIR_CHECKER)/, $(SRCS_CHECKER:.c=.o))


################################################################################
#                                                                              #
#                                   RULES                                      #
#                                                                              #
################################################################################

all: $(NAME)

bonus: $(NAME_CHECKER)

################################################################################
#                                 PUSH_SWAP                                    #
################################################################################

$(NAME): $(LIBFT) $(OBJDIR) $(OBJDIR_UTILS) $(OBJS_UTILS) $(OBJDIR_PUSHSWAP) $(OBJS_PUSHSWAP)
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

$(NAME_CHECKER): $(LIBFT) $(OBJDIR) $(OBJDIR_UTILS) $(OBJS_UTILS) $(OBJDIR_CHECKER) $(OBJS_CHECKER)
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

$(UTILS): $(LIBFT) $(OBJDIR) $(OBJDIR_UTILS) $(OBJS_UTILS)

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