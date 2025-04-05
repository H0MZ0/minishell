CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = minishell.c tools_1.c
OSRC = $(SRC:.c=.o)

NAME = minishell

all : $(OSRC)
	@$(CC) $(CFLAGS) $(OSRC) -o $(NAME) -lreadline -lhistory

clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(OSRC)
re : fclean all

.PHONY : all clean fclean re