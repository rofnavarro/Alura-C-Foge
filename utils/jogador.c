#include "../foge-foge.h"

static int	filtrar_input(t_mapa *mapa, char direcao);

void	mover_jogador(t_mapa *mapa, char direcao)
{
	if (filtrar_input(mapa, direcao) == TRUE)
	{
		if (verificar_local(mapa, &mapa->jogador, direcao, 'P') == TRUE)
			mover(mapa, &mapa->jogador, direcao, 'P');
	}
}

static int	filtrar_input(t_mapa *mapa, char direcao)
{
	if (direcao == CIMA || direcao == ESQUERDA ||
		direcao == BAIXO || direcao == DIREITA)
		return (TRUE);
	else if (direcao == ESC)
	{
		liberar_mapa(mapa);
		exit(EXIT_SUCCESS);
	}
	return (FALSE);
}

void	explodir_bomba(t_mapa *mapa)
{
	mapa->bomba = 0;
	ft_printf("BUM!!\n");
}
