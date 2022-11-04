C = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
NAME = libftprintf.a
FILE = ft_printf ft_printf_utils ft_putnbr_base
PRINTF_H = ft_printf.h

SRCS = $(addsuffix .c, $(FILE))
OBJS = $(addsuffix .o, $(FILE))


%.o : %.c $(PRINTF_H)
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(NAME): $(OBJS) 
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re
	