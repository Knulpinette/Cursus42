# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:35:43 by osurcouf          #+#    #+#              #
#    Updated: 2021/06/28 18:04:53 by osurcouf         ###   ########.fr        #
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
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address

# Will allow to compile the right library according to if the OS is WSL/Linux or Mac
UNAME = ${shell uname}

# If Mac
ifeq ($(UNAME), Darwin)
INCLUDES	= -Imlx -Ilibft -Iinclude

MLX_LIB		= -Lmlx -lmlx 
MLX_FLAGS	= -framework OpenGL -framework AppKit

#If Linux
else
INCLUDES	= -Iinclude -I/usr/include -Imlx_linux -Ilibft

MLX_LIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib
MLX_FLAGS	= -Imlx_linux -lXext -lX11 -lm -lz
endif

# Colors

GRAY		= \e[1;30m
END			= \e[0m

# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c 
			@mkdir -p objs
			@mkdir -p objs/parsing
			@mkdir -p objs/utils
			@mkdir -p objs/intersect_obj
			@mkdir -p objs/raytracing
			@${CC} ${CFLAGS} ${INCLUDES} -O3 -c $< -o $@

#	Active rules

all:		${NAME} test

# Make libft + compile miniRT
${NAME}:	${OBJS}
			@${MAKE} bonus -C ${LIBFT_DIR}
			@printf "\n	\e[1;37m[\e[1;32m"
			@printf "Compiling miniRT${END}]\n\n"
			@printf "\e[1;30m"
			$(CC) ${CFLAGS} ${OBJS} ${MLX_LIB} ${LIBFT_LIB} ${MLX_FLAGS} -o $(NAME)
			@printf "\n	🎉 [\e[0;32m SUCCESS${END}] 🎉\n"
			@printf "	${GRAY}________________${END}\n"

test:		${NAME}
			@printf "\n	📚 [\e[1;35mINSTRUCTIONS${END}] 📚\n"
			@printf "\n🦕🍭	\e[1;33mTo start miniRT on MacOS or Linux${END}\n"
			@printf "	[${GRAY}./miniRT ./scenes/scene-example.rt${END}]\n"
			@printf "\n🍭🦄	\e[1;36mTo start miniRT on WSL${END}\n" 
			@printf "	[\e[1;30mLaunch vcxsrv.exe${END}]\n"
			@printf "🦄🍭	\e[1;36mCopy the following command line${END}\n" 
			@printf "	[${GRAY}DISPLAY=\$$(cat /etc/resolv.conf | grep nameserver | awk '{print \$$2}'):0 ./miniRT ./scenes/scene-debug.rt${END}]\n"
			@printf "\n🦕🍭\e[0;37mBy Ophélie Surcouf @ 42Lisboa${END} 🍭🦕\n"

#	Cleaning rules

clean:
			@printf "\n\e[1;37m"
			@${MAKE} clean -C ${LIBFT_DIR}
			@printf "\n	\e[1;37m[\e[1;34m"
			@printf "Cleaning miniRT objects${END}]\n\n"
			@printf "\e[1;30m"
			${RM} ${OBJS} ${OBJS_BONUS}
			@rm -rf objs
			@printf "${END}"

fclean:		clean
			@printf "\n\e[1;37m"
			@${MAKE} fclean_no_clean -C ${LIBFT_DIR}
			@printf "\n	\e[1;37m[\e[1;34m"
			@printf "Cleaning miniRT output files${END}]\n\n"
			@printf "\e[1;30m"
			${RM} ${NAME}
			@printf "\n${END}"

re:			fclean all

.PHONY:		libft all clean fclean re
