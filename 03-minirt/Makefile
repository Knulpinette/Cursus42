# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:35:43 by osurcouf          #+#    #+#              #
#    Updated: 2021/04/01 16:35:44 by osurcouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-🦕-*- Make MiniRT Sparkle -*-🦕-*- 

NAME	= miniRT

# -*- Definitions of variables -*-

SRCS_DIR	= srcs
SRCS		= ${addprefix ${SRCS_DIR}/,${SRCS_FIND}}
SRCS_FIND	= ${shell find . -type f \( -name "ft_*.c" -not -wholename "./ft_*bonus.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}
SRCS_BONUS	= ${addprefix ${SRCS_DIR}/,${SRCS_BFIND}}
SRCS_BFIND	= ${shell find . -type f \( -name "ft_*.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}

OBJS_DIR	= objs
OBJS		= ${addprefix ${OBJS_DIR}/,${SRCS_FIND:.c=.o}}
OBJS_BONUS	= ${addprefix ${OBJS_DIR}/,${SRCS_BFIND:.c=.o}}

HEADER		= include

LIBFT_DIR	= libft
LIBFT_PATH	= libft/libft.a

MLX_PATH	= mlx_linux/libmlx_Linux.a

CC			= gcc
RM			= rm -f
MAKE		= make bonus
CFLAGS 		= -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c 
			 @mkdir -p objs
			 @mkdir -p objs/mlx_cmd
			 ${CC} ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

#	Active rules

all:		${NAME}

# 

${NAME}:	${OBJS}
			${MAKE} -C ${LIBFT_DIR}
			$(CC) -c ${SRCS}
			$(CC) ${CFLAGS} ${OBJS} ${MLX_FLAGS} -o $(NAME)
			gcc $(CFLAGS) $(SRCS) -L. $(MLX_PATH) $(LFLAGS) -o $(NAME)
			#--------------------------------

bonus:		libft ${OBJS} ${OBJS_BONUS}
			@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}


#	Cleaning rules

clean:
			${MAKE} clean -C ${LIBFT_DIR}
			${RM} ${OBJS} ${OBJS_BONUS}
			@rm -rf objs

fclean:		clean
			${MAKE} fclean -C ${LIBFT_DIR}
			${RM} ${NAME}

re:			fclean all

.PHONY:		libft all clean fclean re
