# ======================================
#        Makefile for minitalk
# ======================================

CFLAGS = -Wall -Wextra -Werror -I include -I libft/include

LDFLAGS = -L libft

LDLIBS = -l ft

SOURCES = server.c utils.c

OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS := $(addprefix obj/,$(OBJECTS))

NAME = server
NAME := $(addprefix bin/,$(NAME))

.PHONY : all libft clean fclean re

all : libft $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ $(LDLIBS)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

libft :
	$(MAKE) -C libft

clean :
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS)

fclean :
	$(MAKE) -C libft fclean
	$(RM) $(OBJECTS) $(NAME)

re : fclean all
