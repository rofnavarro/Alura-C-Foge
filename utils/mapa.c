#include "../foge-foge.h"

void	ler_mapa(t_mapa *MAPA)
{
	int		i;
	FILE	*f;

	i = 0;
	f = fopen("./mapas/mapa.txt", "r");
	if (f == 0)
	{
		ft_printf("Erro de leitura de mapa!\n");
		exit(EXIT_FAILURE);
	}
	fscanf(f, "%d %d", &(MAPA->y), &(MAPA->x));
	alocar_mapa(MAPA);
	while (i < MAPA->y)
	{
		fscanf(f, "%s", MAPA->mapa[i]);
		i++;
	}
	fclose(f);
}

void	alocar_mapa(t_mapa *MAPA)
{
	int i;

	i = 0;
	MAPA->mapa = (char **)malloc(sizeof(char *) * MAPA->y);
	while (i < MAPA->y)
	{
		MAPA->mapa[i] = (char *)malloc(sizeof(char) * (MAPA->x + 1));
		i++;
	}
}

void	imprimir_mapa(t_mapa *MAPA)
{
	int	i;

	i = 0;
	while (i < MAPA->y)
	{
		ft_printf("%s\n", MAPA->mapa[i]);
		i++;
	}
}

void	liberar_mapa(t_mapa *MAPA)
{
	int	i;

	i = 0;
	while (i < MAPA->y)
	{
		free(MAPA->mapa[i]);
		i++;
	}
	free(MAPA->mapa);
}
