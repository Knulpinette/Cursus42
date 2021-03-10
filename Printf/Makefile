# -*-🦕-*- Make Printf Baby -*-🦕-*- 

NAME	= libftprintf.a

# -*- Definitions of variables -*-

SRCS	= ${shell find . -type f \( -name "ft_*.c" ! -wholename "ft_*/ft_*.c" \)}
SRCS_BONUS = ${shell find . -type f \( -name "ft_*bonus.c" ! -wholename "ft_*/ft_*bonus.c" \)}

OBJS	= ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

HEADER	= ${shell find . -type f \( -name "ft_*.h" ! -wholename "ft_*/*.h" \)}

CC		= gcc
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#	Active rules

all:		$(NAME) test

$(NAME):	$(OBJS) $(HEADER)
			ar rc $(NAME) $(OBJS) && ranlib $(NAME)
			#--------------------------------

test: 	
			${CC} ${CFLAGS} main.c -L. -lftprintf -o result
			#🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄🍭🦄
			./result\

bonus:		fclean $(OBJS_BONUS) $(HEADER)
			ar rc $(NAME) $(OBJS_BONUS)
			ranlib $(NAME)

#	Cleaning rules

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
