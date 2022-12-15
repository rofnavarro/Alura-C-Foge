#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "foge-foge.h"

int	main(void)
{
	t_mapa		mapa;
	char		comando;

	ler_mapa(&mapa);
	encontrar_no_mapa(&mapa, &mapa.jogador, 'P');
	do
	{
		imprimir_mapa(&mapa);
		scanf(" %c", &comando);
		mover_jogador(&mapa, comando);
		fantasma(&mapa);
	} while (!acabar());
	liberar_mapa(&mapa);
}
