NAME = libftprintf.a
SRCS = ft_asprintf.c\
	  ft_citoa_base.c\
	  ft_cprintf.c\
	  ft_cprintf2.c\
	  ft_printf.c \
	  fmt_c.c\
	  fmt_i.c\
	  fmt_o.c\
	  fmt_p.c\
	  fmt_percent.c\
	  fmt_s.c\
	  fmt_u.c\
	  fmt_x.c\
	  va_arg.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra #-g

all: $(NAME)
%.o: %.c ft_printf.h Makefile
	gcc $(CFLAGS) -c $< -o $@
$(NAME):	$(OBJS)
	ar -rcs   $(NAME) $(OBJS)
bonus: all
clean:
	rm -rf $(OBJS)
fclean:	clean
	rm -rf $(NAME)
re: fclean all
