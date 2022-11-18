#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "foge-foge.h"

t_mapa MAPA;
t_posicao HEROI;

int	main(void)
{
	char	comando;

	ler_mapa(&MAPA);
	encontrar_no_mapa(&MAPA, &HEROI, 'P');
	do
	{
		imprimir_mapa(&MAPA);
		scanf(" %c", &comando);
		mover_jogador(&MAPA, &HEROI, comando);
	} while (!acabar());
	liberar_mapa(&MAPA);
}
