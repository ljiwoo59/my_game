CC = gcc
CFLAG = -Lminilibx -lmlx -framework OpenGL -framework AppKit

TARGET = cub3d
SRC = main.c game.c keycode.c keycode2.c error.c get_next_line.c get_next_line_utils.c ft_utils.c ft_utils2.c ft_utils3.c map_set.c init.c draw.c

$(NAME) : all

all : $(TARGET)

$(TARGET) :
	      $(CC) $(CFLAG) $(SRC) -o $(TARGET)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re
