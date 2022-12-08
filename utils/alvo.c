#include "../foge-foge.h"

void	encontrar_no_mapa(t_mapa *mapa, t_posicao *alvo, char char_no_mapa)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mapa->y)
	{
		while (j < mapa->x - 1)
		{
			if (mapa->mapa[i][j] == char_no_mapa)
			{
				alvo->y = i;
				alvo->x = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	verificar_local(t_mapa *mapa, t_posicao *alvo, char direcao)
{
	t_posicao	proxima;

	proxima.x = alvo->x;
	proxima.y = alvo->y;
	if (direcao == CIMA)
		proxima.y--;
	else if (direcao == ESQUERDA)
		proxima.x--;
	else if (direcao == BAIXO)
		proxima.y++;
	else if (direcao == DIREITA)
		proxima.x++;
	if (mapa->mapa[proxima.y][proxima.x] != '0')
		return (FALSE);
	mapa->mapa[alvo->y][alvo->x] = '0';
	return (TRUE);
}

void	mover(t_mapa *mapa, t_posicao *alvo, char direcao)
{
	if (direcao == CIMA)
	{
		mapa->mapa[alvo->y - 1][alvo->x] = 'P';
		alvo->y--;
	}
	else if (direcao == ESQUERDA)
	{
		mapa->mapa[alvo->y][alvo->x - 1] = 'P';
		alvo->x--;
	}
	else if (direcao == BAIXO)
	{
		mapa->mapa[alvo->y + 1][alvo->x] = 'P';
		alvo->y++;
	}
	else if (direcao == DIREITA)
	{
		mapa->mapa[alvo->y][alvo->x + 1] = 'P';
		alvo->x++;
	}
}
