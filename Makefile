CLIENT		=	client
CLIENT_SRC	=	./client.c

SERVER		=	server
SERVER_SRC	=	./server.c

LIBFT		=	libft.a
LIBFT_SRC	=	./libft/

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra

all:		$(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
			@make -C libft

$(SERVER):	$(SERVER_SRC)
			@$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_SRC)$(LIBFT) -o $(SERVER)
			@printf "\nServer compiled ✅\n"

$(CLIENT):	$(CLIENT_SRC)
			@$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT)
			@printf "\nClient compiled ✅\n"

clean:		
			@$(RM) $(OBJS) $(OBJSB)
			@$(RM) $(CLIENT) $(SERVER)
			@printf "\nRemoved minitalk 🗑️\n"

fclean:		clean
			@make -C libft clean

re:			fclean all

.PHONY:		all clean fclean re