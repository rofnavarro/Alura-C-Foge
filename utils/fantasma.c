#include "../foge-foge.h"

void	mover_fantasma(t_mapa *mapa, char direcao)
{
	if (verificar_local(mapa, &mapa->fantasmas, direcao) == TRUE)
		mover(mapa, &mapa->fantasmas, direcao);
}
