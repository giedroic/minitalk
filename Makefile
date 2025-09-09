# ======================================
#        Makefile for minitalk
# ======================================

CFLAGS = -Wall -Wextra -Werror -g -I include -I libft/include

LDFLAGS = -L libft

LDLIBS = -l ft

MKDIR = mkdir -p
RMDIR = rm -rf

NAME = server client
NAME := $(addprefix bin/,$(NAME))

BIN_DIR = bin/
OBJ_DIR = obj/

SERVER_SRC = server.c
CLIENT_SRC = client.c
UTILS_SRC = utils.c

UTILS_OBJ = $(addprefix obj/, $(UTILS_SRC:%.c=%.o))
SERVER_OBJ = $(addprefix obj/, $(SERVER_SRC:%.c=%.o)) $(UTILS_OBJ)
CLIENT_OBJ = $(addprefix obj/, $(CLIENT_SRC:%.c=%.o)) $(UTILS_OBJ)

.PHONY : all libft clean fclean re

all : libft $(OBJ_DIR) $(BIN_DIR) $(NAME)

bin/server: $(SERVER_OBJ)	
	$(CC) $(SERVER_OBJ) $(LDFLAGS) -o $@ $(LDLIBS)

bin/client: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LDFLAGS) -o $@ $(LDLIBS)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

libft :
	$(MAKE) -C libft

$(OBJ_DIR) :
	$(MKDIR) $@	

$(BIN_DIR) :
	$(MKDIR) $@

clean :
	$(MAKE) -C libft clean
	$(RM) $(UTILS_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(RMDIR) $(OBJ_DIR) $(BIN_DIR)

fclean :
	$(MAKE) -C libft fclean
	$(RM) $(UTILS_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ) $(NAME)
	$(RMDIR) $(OBJ_DIR) $(BIN_DIR)

re : fclean all
