NAME			=		foge-foge

CC				=		gcc
CCFLAGS			=		-Wall -Werror -Wextra

PATH_PRINTF		=		./ft_printf
PRINTF			=		$(PATH_PRINTF)/libftprintf.a

RM				=		rm -rf

SRC				=		foge-foge.c \
						$(addprefix utils/, alvo.c \
											fantasma.c \
											jogador.c \
											mapa.c)

OBJ				=		$(SRC:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				$(MAKE) -C $(PATH_PRINTF)
				$(CC) $(CCFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

clean:
				$(MAKE) -C $(PATH_PRINTF) clean
				$(RM) $(OBJ)

fclean:			clean
				$(MAKE) -C $(PATH_PRINTF) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all fclean clean re