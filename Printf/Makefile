# -*-🦕-*- Make Printf Baby -*-🦕-*- 

NAME	= libftprintf.a

# -*- Definitions of variables -*-

SRCSDIR		= srcs
SRCS		= ${addprefix ${SRCSDIR}/,${SOURCES}}
SRCS_BONUS	= ${addprefix ${SRCSDIR}/,${S_BONUS}}
SOURCES		= ${shell find . -type f \( -name "ft_*.c" -not -wholename "./srcs/*bonus.c" -not -wholename "./srcs/libft/ft_*.c" \) | cut -d'/' -f3-}
S_BONUS		= ${shell find . -type f \( -name "ft_*.c" -not -wholename "./srcs/libft/ft_*.c" \) | cut -d'/' -f3-}

OBJSDIR		= objs
OBJS		= ${addprefix ${OBJSDIR}/,${SOURCES:.c=.o}}
OBJS_BONUS	= ${addprefix ${OBJSDIR}/,${S_BONUS:.c=.o}}

HEADER		= include

LIBFT_DIR	= ./srcs/libft
LIBFT_PATH	= ./srcs/libft/libft.a
LIB			= -L. -lftprintf

CC			= gcc
RM			= rm -f
MAKE		= make
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address

# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJSDIR}/%.o: ${SRCSDIR}/%.c ${HEADER}/ft_printf.h
	 @mkdir -p objs
	 @mkdir -p objs/conversions
	 @mkdir -p objs/print
	 @mkdir -p objs/parse
	 @${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<

#	Active rules

all:		${NAME} test

# Compile libft and copy it to the root
libft:
			@${MAKE} bonus -C ${LIBFT_DIR}
			@cp ${LIBFT_PATH} ./${NAME}

# Create the printf library out of libft.a + libftprintf.a
${NAME}:	libft ${OBJS}
			@ar rcs ${NAME} ${OBJS}
			#--------------------------------

test: 	
			${CC} ${CFLAGS} main.c ${LIB} -o result
			#🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄
			./result\

bonus:		libft ${OBJS} ${OBJS_BONUS}
			@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}


#	Cleaning rules

clean:
	@${MAKE} clean -C ${LIBFT_DIR}
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	@${MAKE} fclean -C ${LIBFT_DIR}
	@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
