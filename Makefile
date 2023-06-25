CC = gcc
KOMUT = -Imlx -framework OpenGL -framework Appkit
NAME = so_long.a
OUT = so_long
LIBFTMAKER = libftmaker
MLXMAKER = mlxmaker
HDR = ./src/so_long.h
SRC = ./src/so_long.c ./src/gnl.c ./src/maprender.c ./src/moves.c ./src/animation.c ./src/utils.c ./src/ft_putnbr.c ./src/checkmap.c ./src/checkmap2.c
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(LIBFTMAKER) $(MLXMAKER)  $(OUT)

$(OUT): $(NAME)
	$(CC) $(CFLAGS) $(KOMUT) libft/libft.a mlx/libmlx.a $(NAME) -o so_long

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(LIBFTMAKER):
		@cd libft && $(MAKE)

$(MLXMAKER):
		@cd mlx && $(MAKE)

clean:
	$(RM) so_long
	$(RM) $(OBJ)
	cd libft && $(MAKE) clean
	cd mlx && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) libft/libft.a
	$(RM) mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re
