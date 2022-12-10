#include "../foge-foge.h"

void	mover_fantasma(t_mapa *mapa)
{
	char	direcao;

	direcao = CIMA;
	if (verificar_local(mapa, &mapa->fantasmas, direcao, 'F') == TRUE)
		mover(mapa, &mapa->fantasmas, direcao, 'F');
}
