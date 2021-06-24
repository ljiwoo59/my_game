CC = gcc
CFLAG = -Wall -Wextra -Werror
LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit

NAME = cub3d

SRC = srcs/main.c \
	  srcs/game.c \
	  srcs/keycode.c \
	  srcs/keycode2.c \
	  srcs/error.c \
	  srcs/get_next_line/get_next_line.c \
	  srcs/get_next_line/get_next_line_utils.c \
	  srcs/utils/ft_utils.c \
	  srcs/utils/ft_utils2.c \
	  srcs/utils/ft_utils3.c \
	  srcs/map_set.c \
	  srcs/init.c \
	  srcs/draw.c \

INCDIR = ./includes/

OBJ = $(SRC:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCDIR) 

all : $(NAME)

$(NAME) : $(OBJ)
	      $(CC) $(LIB) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
