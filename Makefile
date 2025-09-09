# ======================================
#        Makefile for minitalk
# ======================================

CFLAGS = -Wall -Wextra -Werror -g -I include -I libft/include

LDFLAGS = -L libft

LDLIBS = -l ft

NAME = server client
NAME := $(addprefix bin/,$(NAME))

SERVER_SRC = server.c
CLIENT_SRC = client.c
UTILS_SRC = utils.c

UTILS_OBJ = $(addprefix obj/, $(UTILS_SRC:%.c=%.o))
SERVER_OBJ = $(addprefix obj/, $(SERVER_SRC:%.c=%.o)) $(UTILS_OBJ)
CLIENT_OBJ = $(addprefix obj/, $(CLIENT_SRC:%.c=%.o)) $(UTILS_OBJ)

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
	$(RM) $(UTILS_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean :
	$(MAKE) -C libft fclean
	$(RM) $(UTILS_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ) $(NAME)

re : fclean all
