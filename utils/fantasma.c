#include "../foge-foge.h"

void	mover_fantasma(t_mapa *copia, t_mapa *mapa)
{
	char	direcao;

	direcao = DIREITA;
	
}

void	fantasma(t_mapa *mapa)
{
	t_mapa copia;

	copiar_mapa(&copia, &mapa);
	mover_fantasma(&copia, &mapa);
}
