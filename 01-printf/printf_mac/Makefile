# -*-🦕-*- Make Printf Baby -*-🦕-*- 

NAME	= libftprintf.a

# -*- Definitions of variables -*-

C = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = include

SOURCES = ft_printf.c \
			conversions/ft_get_arg.c \
			conversions/ft_printf_c.c \
			conversions/ft_printf_i.c \
			conversions/ft_printf_p.c \
			conversions/ft_printf_s.c \
			conversions/ft_printf_u.c \
			conversions/ft_printf_x.c \
			parse/ft_align.c \
			parse/ft_get_flags.c \
			print/ft_print_arg.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@mkdir -p obj/conversions
	@mkdir -p obj/parse
	@mkdir -p obj/print
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean

