
# -*-🦕-*- Make Libft -*-🦕-*-

NAME		= libft.a

# -*- Definitions of variables -*-

SRCS		= ${shell find . -type f \( -name "ft_*.c" ! -name "ft_lst*.c" ! -name "*bonus.c" \)}
SRCSBONUS	= ${shell find . -type f \( -name "ft_*.c" \)}

OBJS		= ${SRCS:.c=.o}
OBJSBONUS	= ${SRCSBONUS:.c=.o}

HEADER		= libft.h
HEADERS_OWN = libft.h libft_bonus.h

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

.c.o:
		${CC} ${CFLAGS} -I libft -c $< -o ${<:.c=.o}

#	Active rules

all: $(NAME)

$(NAME): ${OBJS} 
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

bonus: ${OBJS} ${OBJSBONUS} 
	ar rc ${NAME} ${OBJS} ${OBJSBONUS}
	ranlib ${NAME}

#	Cleaning rules

clean:
	${RM} ${OBJS} $(OBJSBONUS)

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
