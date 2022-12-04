#include "../foge-foge.h"

static int	filtrar_input(char direcao);
static int	verificar_local(t_mapa *mapa, char direcao);
static void	mover(t_mapa *mapa, char direcao);

void	mover_jogador(t_mapa *mapa, char direcao)
{
	if (filtrar_input(direcao) == TRUE)
	{
		if (verificar_local(mapa, direcao) == TRUE)
			mover(mapa, direcao);
	}
}

static int	filtrar_input(char direcao)
{
	if (direcao == CIMA || direcao == ESQUERDA ||
		direcao == BAIXO || direcao == DIREITA)
		return (TRUE);
	return (FALSE);
}

static int	verificar_local(t_mapa *mapa, char direcao)
{
	t_posicao	proxima;

	proxima.x = mapa->jogador.x;
	proxima.y = mapa->jogador.y;
	if (direcao == CIMA)
		proxima.y--;
	else if (direcao == ESQUERDA)
		proxima.x--;
	else if (direcao == BAIXO)
		proxima.y++;
	else if (direcao == DIREITA)
		proxima.x++;
	if (mapa->mapa[proxima.y][proxima.x] != '0')
		return (FALSE);
	mapa->mapa[mapa->jogador.y][mapa->jogador.x] = '0';
	return (TRUE);
}

static void	mover(t_mapa *mapa, char direcao)
{
	if (direcao == CIMA)
	{
		mapa->mapa[mapa->jogador.y - 1][mapa->jogador.x] = 'P';
		mapa->jogador.y--;
	}
	else if (direcao == ESQUERDA)
	{
		mapa->mapa[mapa->jogador.y][mapa->jogador.x - 1] = 'P';
		mapa->jogador.x--;
	}
	else if (direcao == BAIXO)
	{
		mapa->mapa[mapa->jogador.y + 1][mapa->jogador.x] = 'P';
		mapa->jogador.y++;
	}
	else if (direcao == DIREITA)
	{
		mapa->mapa[mapa->jogador.y][mapa->jogador.x + 1] = 'P';
		mapa->jogador.x++;
	}
}
