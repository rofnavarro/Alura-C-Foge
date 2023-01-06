#ifndef FOGE_FOGE_H
# define FOGE_FOGE_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "./ft_printf/ft_printf.h"

# define	TRUE		0
# define	FALSE		1

# define	CIMA		'w'
# define	ESQUERDA	'a'
# define	BAIXO		's'
# define	DIREITA		'd'
# define	BOMBA		'b'
# define	ESC			27

# define	VAZIO		'0'
# define	JOGADOR		'P'
# define	FANTASMA	'F'
# define	PODER		'B'
# define	PAREDE		'1'

typedef struct s_posicao
{
	int	x;
	int	y;
}	t_posicao;

typedef struct s_mapa
{
	char		**mapa;
	int			y;
	int			x;
	int			bomba;
	t_posicao	jogador;
	t_posicao	fantasmas;
}	t_mapa;

//	alvo.c
int		encontrar_no_mapa(t_mapa *mapa, t_posicao *alvo, char char_no_mapa);
int		verificar_local(t_mapa *mapa, t_posicao *alvo, char direcao, char alvo_id);
void	mover(t_mapa *mapa, t_posicao *alvo, char direcao, char alvo_id);

//	fantasma.c
void	fantasma(t_mapa *mapa);
void	mover_fantasma(t_mapa *mapa);

//	jogador.c
void	mover_jogador(t_mapa *mapa, char direcao);
void	explodir(t_mapa *mapa);

//	mapa.c
void	ler_mapa(t_mapa *mapa);
void	alocar_mapa(t_mapa *mapa);
void	imprimir_mapa(t_mapa *mapa);
void	liberar_mapa(t_mapa *mapa);
void	copiar_mapa(t_mapa *destino, t_mapa *origem);

//	ui.c
void	definir_desenho(char letra, int parte);
void	imprimir_parte(char desenho[4][7], int parte);

#endif