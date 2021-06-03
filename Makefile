CC = gcc
CFLAG = -Lminilibx -lmlx -framework OpenGL -framework AppKit

TARGET = cub3d
SRC = game.c

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
