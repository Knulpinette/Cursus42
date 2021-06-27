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
	@printf "\n	\e[1;37m[\e[1;32m"
	@printf "Compiling Libft\e[0m]\n\n"
	@printf "\e[1;30m"
	ar rcs ${NAME} ${OBJS}
	@printf "\n\e[0m"

bonus: ${OBJS} ${OBJS_BONUS} 
	@printf "\n	\e[1;37m[\e[1;32m"
	@printf "Compiling Libft -bonus\e[0m]\n\n"
	@printf "\e[1;30m"
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
	@printf "\n\e[0m"

#	Cleaning rules

clean:
	@echo "\n	\e[1;37m[\e[1;34m\
	Cleaning libft objects\e[0m]\
	\e[1;30m\n"
	${RM} ${OBJS_BONUS}
	@rm -rf objs
	@printf "\n\e[0m"

fclean: clean
	@echo "\n	\e[1;37m[\e[1;34m\
	Cleaning libft output files\e[0m]\
	\e[1;30m\n"
	${RM} ${NAME}
	@printf "\n\e[0m"

fclean_no_clean:
	@echo "\n	\e[1;37m[\e[1;34m\
	Cleaning libft output files\e[0m]\
	\e[1;30m\n"
	${RM} ${NAME}
	@printf "\n\e[0m"

re: fclean all

.PHONY: all clean fclean fclean_no_clean re
