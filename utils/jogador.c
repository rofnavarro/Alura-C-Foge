#include "../foge-foge.h"

void	mover_jogador(t_mapa *MAPA, t_posicao *HEROI, char direcao)
{
	MAPA->mapa[HEROI->y][HEROI->x] = '0';
	if (direcao == 'a')
	{
		MAPA->mapa[HEROI->y][HEROI->x - 1] = 'P';
		HEROI->x--;
		return ;
	}
	else if (direcao == 'd')
	{
		MAPA->mapa[HEROI->y][HEROI->x + 1] = 'P';
		HEROI->x++;
		return ;
	}
	else if (direcao == 'w')
	{
		MAPA->mapa[HEROI->y - 1][HEROI->x] = 'P';
		HEROI->y--;
		return ;
	}
	else if (direcao == 's')
	{
		MAPA->mapa[HEROI->y + 1][HEROI->x] = 'P';
		HEROI->y++;
		return ;
	}
}
