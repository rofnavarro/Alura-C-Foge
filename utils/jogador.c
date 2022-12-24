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
	explodir_direcao(mapa, CIMA, 3);
	explodir_direcao(mapa, ESQUERDA, 3);
	explodir_direcao(mapa, BAIXO, 3);
	explodir_direcao(mapa, DIREITA, 3);
	ft_printf("\nBUM!!\n");
}

void	explodir_direcao(t_mapa *mapa, char direcao, int quantidade)
{
	if (quantidade == 0)
		return ;
	
}
