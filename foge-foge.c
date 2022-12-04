#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "foge-foge.h"


int	main(void)
{
	t_mapa		mapa;
	char		comando;

	ler_mapa(&mapa);
	encontrar_no_mapa(&mapa, &mapa.jogador, 'P');
	//encontrar_no_mapa(&mapa, &mapa.fantasmas, 'F');
	do
	{
		imprimir_mapa(&mapa);
		scanf(" %c", &comando);
		mover_jogador(&mapa, comando);
	} while (!acabar());
	liberar_mapa(&mapa);
}
