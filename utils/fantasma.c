#include "../foge-foge.h"

void	fantasma(t_mapa *mapa)
{
	t_mapa	copia;
	char	direcao;

	copiar_mapa(&copia, mapa);
	for (int i = 0; i < mapa->y; i++)
	{
		for (int j = 0; j < mapa->x; j++)
		{
			if (copia.mapa[i][j] == 'F')
			{
				mapa->fantasmas.x = j;
				mapa->fantasmas.y = i;
				direcao = ai_fantasma(mapa, &mapa->fantasmas);
				mover(mapa, &mapa->fantasmas, direcao, 'F');
			}
		}
	}
	liberar_mapa(&copia);
}

char	ai_fantasma(t_mapa *mapa, t_posicao *fantasma)
{
	int		i;
	int		direcao;
	char	ret;

	srand(time(0));
	i = 0;
	while (i < 10)
	{
		direcao = rand() % 4;
		if (direcao == 0)
			ret = CIMA;
		else if (direcao == 1)
			ret = BAIXO;
		else if (direcao == 2)
			ret = DIREITA;
		else if (direcao == 3)
			ret = ESQUERDA;
		if (!verificar_local(mapa, fantasma, direcao, 'F') == TRUE)
			i++;
		else
			return (ret);
	}
}
