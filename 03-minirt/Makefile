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
SRCS_FIND	= ${shell find . -type f \( -wholename "./srcs/*.c" -not -wholename "./ft_*bonus.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}
SRCS_BONUS	= ${addprefix ${SRCS_DIR}/,${SRCS_BFIND}}
SRCS_BFIND	= ${shell find . -type f \( -wholename "./srcs/*.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}

OBJS_DIR	= objs
OBJS		= ${addprefix ${OBJS_DIR}/,${SRCS_FIND:.c=.o}}
OBJS_BONUS	= ${addprefix ${OBJS_DIR}/,${SRCS_BFIND:.c=.o}}

HEADER		= include

LIBFT_DIR	= libft
LIBFT_LIB	= -Llibft -lft

CC			= gcc
RM			= rm -f
MAKE		= make
CFLAGS 		= -Wall -Wextra -Werror

# Will allow to compile the right library according to if the OS is WSL/Linux or Mac
UNAME = ${shell uname}

ifeq ($(UNAME), Darwin)
INCLUDES	= -Imlx -Ilibft -Iinclude

MLX_LIB		= -Lmlx -lmlx 
MLX_FLAGS	= -framework OpenGL -framework AppKit

else
INCLUDES	= -Iinclude -I/usr/include -Imlx_linux -Ilibft

MLX_LIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib
MLX_FLAGS	= -Imlx_linux -lXext -lX11 -lm -lz

endif


# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c 
			@mkdir -p objs
			@mkdir -p objs/win_action
			@mkdir -p objs/geometry
			@mkdir -p objs/light
			@mkdir -p objs/parsing
			@mkdir -p objs/utils
			${CC} ${CFLAGS} ${INCLUDES} -O3 -c $< -o $@

#	Active rules

all:		${NAME} test

# Make libft + compile miniRT
${NAME}:	${OBJS}
			@${MAKE} bonus -C ${LIBFT_DIR}
			$(CC) ${CFLAGS} ${OBJS} ${MLX_LIB} ${LIBFT_LIB} ${MLX_FLAGS} -o $(NAME)
			#--------------------------------

test:		${NAME}
			@echo "🦕🍭 To just debug, type in command line :"
			@echo "🦕🍭🦕 ./miniRT ./scenes/scene-example.rt"
			@echo "🍭🦄 IF WSL -> Launch vcxsrv.exe" 
			@echo "🦄🍭 Type in command line :" 
			@echo "🍭🦄🍭 DISPLAY=\$$(cat /etc/resolv.conf | grep nameserver | awk '{print \$$2}'):0 ./miniRT ./scenes/scene-example.rt"

bonus:		${OBJS_BONUS}
			${MAKE} bonus -C ${LIBFT_DIR}
			$(CC) ${CFLAGS} ${OBJS_BONUS} ${MLX_LIB} ${MLX_FLAGS} -o $(NAME)


#	Cleaning rules

clean:
			@${MAKE} clean -C ${LIBFT_DIR}
			@${RM} ${OBJS} ${OBJS_BONUS}
			@rm -rf objs

fclean:		clean
			@${MAKE} fclean -C ${LIBFT_DIR}
			@${RM} ${NAME}

re:			fclean all

.PHONY:		libft all clean fclean re
