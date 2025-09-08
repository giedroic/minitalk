# ======================================
#        Makefile for minitalk
# ======================================

CFLAGS = -Wall -Wextra -Werror -I include -I libft/include

LDFLAGS = -L libft

LDLIBS = -l ft

SOURCES = server.c client.c utils.c

OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS := $(addprefix obj/,$(OBJECTS))

NAME = server client
NAME := $(addprefix bin/,$(NAME))

.PHONY : all libft clean fclean re

all : libft $(NAME)

bin/server: $(SERVER_OBJ)	
	$(CC) $(SERVER_OBJ) $(LDFLAGS) -o $@ $(LDLIBS)

bin/client: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LDFLAGS) -o $@ $(LDLIBS)

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
