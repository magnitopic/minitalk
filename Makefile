# Server
SERVER				=	server
SERVER_SRC			=	./server.c

SERVER_BONUS		=	server_bonus
SERVER_BONUS_SRC	=	./server_bonus.c

# Client
CLIENT				=	client
CLIENT_SRC			=	./client.c

CLIENT_BONUS		=	client_bonus
CLIENT_BONUS_SRC	=	./client_bonus.c

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Colours
BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:		$(LIBFT) $(SERVER) $(CLIENT)
			@printf "$(BLUE)==> $(CYAN)Minitalk compiled ✅\n$(RESET)"

bonus:		$(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)
			@printf "$(BLUE)==> $(CYAN)Minitalk bonus compiled ✅✨\n$(RESET)"

$(LIBFT):
			@make -C libft  bonus

$(SERVER):			$(SERVER_SRC)
					$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_SRC)$(LIBFT) -o $(SERVER)
					@printf "$(GREEN)Server compiled ✅\n\n$(RESET)"

$(SERVER_BONUS):	$(SERVER_BONUS_SRC)
					$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(LIBFT_SRC)$(LIBFT) -o $(SERVER_BONUS)
					@printf "$(GREEN)Server bonus compiled ✅✨\n\n$(RESET)"

$(CLIENT):			$(CLIENT_SRC)
					$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT)
					@printf "$(GREEN)Client compiled ✅\n\n$(RESET)"

$(CLIENT_BONUS):	$(CLIENT_BONUS_SRC)
					$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT_BONUS)
					@printf "$(GREEN)Client bonus compiled ✅✨\n\n$(RESET)"

$(CLIENT_BONUS):	

clean:
			@$(RM) $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)
			@printf "\n$(BLUE)==> $(RED)Removed minitalk 🗑️\n$(RESET)"

fclean:		clean
			@make -C libft fclean

re:			fclean all
			@printf "$(BLUE)==> $(CYAN)Minitalk recompiled 🔄\n$(RESET)"

.PHONY:		all clean fclean re bonus