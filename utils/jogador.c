#include "../foge-foge.h"

static int	filtrar_input(char direcao);

void	mover_jogador(t_mapa *mapa, char direcao)
{
	if (filtrar_input(direcao) == TRUE)
	{
		if (verificar_local(mapa, &mapa->jogador, direcao, 'P') == TRUE)
			mover(mapa, &mapa->jogador, direcao, 'P');
	}
}

static int	filtrar_input(char direcao)
{
	if (direcao == CIMA || direcao == ESQUERDA ||
		direcao == BAIXO || direcao == DIREITA)
		return (TRUE);
	return (FALSE);
}
