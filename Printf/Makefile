# -*-🦕-*- Make Printf Baby -*-🦕-*- 

NAME	= libftprintf.a

# -*- Definitions of variables -*-

SRCS		= ${shell find . -type f \( -name "ft_*.c" -not -name "*bonus.c" -not -wholename "./libft/ft_*.c" \)}
SRCS_BONUS	= ${shell find . -type f \( -name "ft_*.c" -not -wholename "./libft/ft_*.c" \)}

OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

HEADER		= ${shell find . -type f \( -name "ft_*.h" \)}

LIBFT_DIR		= ./libft
LIBFT_PATH	= ./libft/libft.a
LIB			= -L. -lftprintf ${LIBFT_PATH}

CC			= gcc
RM			= rm -f
MAKE		= make
CFLAGS 		= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#	Active rules

all:		$(NAME) test

$(NAME):	$(OBJS) $(HEADER)
			${MAKE} bonus -C ${LIBFT_DIR}
			ar rc $(NAME) $(OBJS) && ranlib $(NAME)
			#--------------------------------

test: 	
			${CC} ${CFLAGS} -fsanitize=address main.c ${LIB} -o result
			#🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄
			./result\

bonus:		fclean $(OBJS_BONUS) $(HEADER)
			ar rc $(NAME) $(OBJS_BONUS)
			ranlib $(NAME)

#	Cleaning rules

clean:
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
