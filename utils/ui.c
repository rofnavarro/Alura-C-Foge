#include "../foge-foge.h"

char	desenho_parede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char	desenho_vazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

char	desenho_jogador[4][7] = {
    {" .--. "  },
    {"'-.O '"  },
    {".-'  /" },
    {" '--' "  }
};

char	desenho_fantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char	desenho_pilula[4][7] = {
    {"      "},
    {" .--. "},
    {" '--' "},
    {"      "}
};

void	definir_desenho(char letra, int parte)
{
	switch (letra)
	{
		case PAREDE:
			imprimir_parte(desenho_parede, parte);
			break ;
		case VAZIO:
			imprimir_parte(desenho_vazio, parte);
			break ;
		case JOGADOR:
			imprimir_parte(desenho_jogador, parte);
			break ;
		case FANTASMA:
			imprimir_parte(desenho_fantasma, parte);
			break ;
		case PODER:
			imprimir_parte(desenho_pilula, parte);
			break ;
	}
}

void	imprimir_parte(char desenho[4][7], int parte)
{
	ft_printf("%s", desenho[parte]);
}
