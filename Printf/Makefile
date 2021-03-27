# -*-🦕-*- Make Printf Baby -*-🦕-*- 

NAME	= libftprintf.a

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
LIB			= -L. -lftprintf

CC			= gcc
RM			= rm -f
MAKE		= make
CFLAGS 		= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${HEADER}/ft_printf.h
			 @mkdir -p objs
			 @mkdir -p objs/conversions
			 @mkdir -p objs/print
			 @mkdir -p objs/parse
			 ${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<

#	Active rules

all:		${NAME}

# Compile libft and copy it to the root
libft:
			${MAKE} bonus -C ${LIBFT_DIR}
			cp ${LIBFT_PATH} ./${NAME}

# Create the printf library out of libft.a + libftprintf.a
${NAME}:	libft ${OBJS}
			@ar rcs ${NAME} ${OBJS}
			#--------------------------------

test: 		${NAME}	
			@${CC} ${CFLAGS} main.c ${LIB} -o result
			#🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄
			#@./result\

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
