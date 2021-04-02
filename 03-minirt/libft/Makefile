
# -*-🦕-*- Make Libft -*-🦕-*-

NAME		= libft.a

# -*- Definitions of variables -*-

SRCS		= ${shell find . -type f \( -name "ft_*.c" ! -name "ft_lst*.c" ! -name "*bonus.c" \) | cut -d'/' -f2-}
SRCS_BONUS	= ${shell find . -type f \( -name "ft_*.c" \) | cut -d'/' -f2-}

OBJS_DIR	= objs
OBJS		= ${addprefix ${OBJS_DIR}/,${SRCS:.c=.o}}
OBJS_BONUS	= ${addprefix ${OBJS_DIR}/,${SRCS_BONUS:.c=.o}}

HEADER		= libft.h
HEADERS_OWN = libft.h libft_bonus.h

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

${OBJS_DIR}/%.o: %.c ${HEADER}
	@mkdir -p objs
	@${CC} ${FLAGS} -o $@ -c $<

#	Active rules

all: $(NAME)

$(NAME): ${OBJS} 
	@ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_BONUS} 
	@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

#	Cleaning rules

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@rm -rf objs

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
