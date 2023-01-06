#include "../foge-foge.h"

static int	filtrar_input(t_mapa *mapa, char direcao);
static void	explodir_bomba(t_mapa *mapa, t_posicao *jogador, int somay, int somax, int quantidade);
static int	pode_explodir(t_mapa *mapa, int y, int x);

void	mover_jogador(t_mapa *mapa, char direcao)
{
	if (filtrar_input(mapa, direcao) == TRUE)
	{
		if (verificar_local(mapa, &mapa->jogador, direcao, JOGADOR) == TRUE)
			mover(mapa, &mapa->jogador, direcao, JOGADOR);
	}
}

static int	filtrar_input(t_mapa *mapa, char direcao)
{
	if (direcao == CIMA || direcao == ESQUERDA || direcao == BAIXO || direcao == DIREITA)
		return (TRUE);
	else if (direcao == ESC)
	{
		liberar_mapa(mapa);
		exit(EXIT_SUCCESS);
	}
	return (FALSE);
}

void	explodir(t_mapa *mapa)
{
	if (mapa->bomba > 0)
	{
		explodir_bomba(mapa, &mapa->jogador, 0, 1, 3);
		explodir_bomba(mapa, &mapa->jogador, 0, -1, 3);
		explodir_bomba(mapa, &mapa->jogador, 1, 0, 3);
		explodir_bomba(mapa, &mapa->jogador, -1, 0, 3);
		mapa->bomba--;
	}
	return ;
}

static void	explodir_bomba(t_mapa *mapa, t_posicao *jogador, int somay, int somax, int quantidade)
{
	t_posicao alvo;

	alvo.y = jogador->y + somay;
	alvo.x = jogador->x + somax;
	if (quantidade == 0)
		return ;
	if (!pode_explodir(mapa, alvo.y, alvo.x) == TRUE)
		return ;
	mapa->mapa[alvo.y][alvo.x] = VAZIO;
	explodir_bomba(mapa, &alvo, somay, somax, quantidade - 1);
}

static int	pode_explodir(t_mapa *mapa, int y, int x)
{
	if (mapa->mapa[y][x] == VAZIO || mapa->mapa[y][x] == FANTASMA || mapa->mapa[y][x] == PODER)
		return TRUE;
	return FALSE;
}
