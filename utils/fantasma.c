#include "../foge-foge.h"

void	fantasma(t_mapa *mapa)
{
	t_mapa	copia;

	copiar_mapa(&copia, mapa);
	for (int i = 0; i < mapa->y; i++)
	{
		for (int j = 0; j < mapa->x; j++)
		{
			if (copia.mapa[i][j] == 'F')
			{
				mapa->fantasmas.x = j;
				mapa->fantasmas.y = i;
				mover_fantasma(mapa, &copia);
			}
		}
	}
	liberar_mapa(&copia);
}

void	mover_fantasma(t_mapa *mapa, t_mapa *copia)
{
	char	direcao[4] = {CIMA, BAIXO, DIREITA, ESQUERDA};
	int		i;
	int		trys;

	srand(time(0));
	i = 0;
	trys = 0;
	while (trys < 10)
	{
		i = rand() % 4;
		if (verificar_local(mapa, &mapa->fantasmas, direcao[i], 'F') == TRUE)
		{
			mover(mapa, &mapa->fantasmas, direcao[i], 'F');
			return ;
		}
		trys++;
	}
	return ;
}
