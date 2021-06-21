CC = gcc
CFLAG = -Wall -Wextra -Werror
LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit

TARGET = cub3d
SRC = main.c game.c keycode.c keycode2.c error.c get_next_line.c get_next_line_utils.c ft_utils.c ft_utils2.c ft_utils3.c map_set.c init.c draw.c
OBJ = $(SRC:.c=.o)

$(NAME) : all

all : $(TARGET)

$(TARGET) : $(OBJ)
	      $(CC) $(CFLAG) $(LIB) -o $(TARGET) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAG) -c $(SRC)	   

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re
