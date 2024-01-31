NAME_S	=	server
NAME_C	=	client
FILES_S	=	server.c
FILES_C	=	client.c
OBJ_S	=	$(FILES_S:.c=.o)
OBJ_C	=	$(FILES_C:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:		$(NAME_S) $(NAME_C)


$(NAME_S):	$(OBJ_S)
			$(CC) $(CFLAGS) -o $(NAME_S) $(OBJ_S)

$(NAME_C):	$(OBJ_C)
			$(CC) $(CFLAGS) -o $(NAME_C) $(OBJ_C)

clean:
			$(RM) $(OBJ_S) $(OBJ_C)

fclean:		clean
			$(RM) $(NAME_S) $(NAME_C)

re:			fclean all

.PHONY:		all clean fclean re