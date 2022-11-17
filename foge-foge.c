#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "foge-foge.h"

int	main(int arc, char **argv)
{
	char	comando;

	ler_mapa(&MAPA);
		imprimir_mapa(&MAPA);
	do
	{
		scanf(" %c", &comando);
		mover_jogador(comando);
	} while (!acabar());
	liberar_mapa(&MAPA);
}
