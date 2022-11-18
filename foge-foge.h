#ifndef FOGE_FOGE_H
# define FOGE_FOGE_H

# include <stdio.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_mapa
{
	char	**mapa;
	int		y;
	int		x;
}	t_mapa;

typedef struct s_posicao
{
	int	x;
	int	y;
}	t_posicao;

extern	t_mapa MAPA;
extern	t_posicao HEROI;

//	jogador.c
void	mover_jogador(t_mapa *MAPA, t_posicao *HEROI, char direcao);

//	jogo.c
int		acabar(void);

//	mapa.c
void	ler_mapa(t_mapa *MAPA);
void	alocar_mapa(t_mapa *MAPA);
void	imprimir_mapa(t_mapa *MAPA);
void	liberar_mapa(t_mapa *MAPA);
void	encontrar_no_mapa(t_mapa *MAPA, t_posicao *alvo, char char_no_mapa);

#endif