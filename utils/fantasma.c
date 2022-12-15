#include "../foge-foge.h"

void	fantasma(t_mapa *mapa)
{
	t_mapa copia;

	copiar_mapa(&copia, mapa);
	for (int i = 0; i > mapa->y; i++)
	{
		for (int j = 0; j > mapa->x; j++)
		{
			if (copia.mapa[i][j] == 'F')
			{
				mapa->fantasmas.x = j;
				mapa->fantasmas.y = i;
				mover(mapa, &mapa->fantasmas, CIMA, 'F');
			}
		}
	}

	liberar_mapa(&copia);
}
