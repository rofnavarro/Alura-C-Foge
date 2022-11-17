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

extern t_mapa MAPA;

//	jogo.c
int		acabar();

//	mapa.c
void	ler_mapa(t_mapa *MAPA);
void	alocar_mapa(t_mapa *MAPA);
void	imprimir_mapa(t_mapa *MAPA);
void	liberar_mapa(t_mapa *MAPA);

#endif