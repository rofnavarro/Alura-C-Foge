#include "../foge-foge.h"

static int	checar_proximo_local(t_mapa *mapa, char proximo, char alvo_id);

int	encontrar_no_mapa(t_mapa *mapa, t_posicao *alvo, char char_no_mapa)
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
				return (TRUE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}

int	verificar_local(t_mapa *mapa, t_posicao *alvo, char direcao, char alvo_id)
{
	t_posicao	proxima;
	int			ret;

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
	ret = checar_proximo_local(mapa, mapa->mapa[proxima.y][proxima.x], alvo_id);
	if (ret == TRUE)
		mapa->mapa[alvo->y][alvo->x] = '0';
	return (ret);
}

void	mover(t_mapa *mapa, t_posicao *alvo, char direcao, char alvo_id)
{
	if (direcao == CIMA)
	{
		mapa->mapa[alvo->y - 1][alvo->x] = alvo_id;
		alvo->y--;
	}
	else if (direcao == ESQUERDA)
	{
		mapa->mapa[alvo->y][alvo->x - 1] = alvo_id;
		alvo->x--;
	}
	else if (direcao == BAIXO)
	{
		mapa->mapa[alvo->y + 1][alvo->x] = alvo_id;
		alvo->y++;
	}
	else if (direcao == DIREITA)
	{
		mapa->mapa[alvo->y][alvo->x + 1] = alvo_id;
		alvo->x++;
	}
}

static int	checar_proximo_local(t_mapa *mapa, char proximo, char alvo_id)
{
	if (alvo_id == 'P')
	{
		if (proximo == '0' || proximo == 'B')
		{
			if (proximo == 'B')
				mapa->bomba = 1;
			return (TRUE);
		}
		else
			return (FALSE);
	}
	else if (alvo_id == 'F')
	{
		if (proximo == 'P' || proximo == 'C' || proximo == '0')
			return (TRUE);
		else
			return (FALSE);
	}
}
