#include "../foge-foge.h"

void	ler_mapa(t_mapa *mapa)
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
	fscanf(f, "%d %d", &(mapa->y), &(mapa->x));
	ft_printf("x: %d / y: %d\n", mapa->x, mapa->y);
	alocar_mapa(mapa);
	while (i < mapa->y)
	{
		fscanf(f, "%s", mapa->mapa[i]);
		i++;
	}
	fclose(f);
}

void	alocar_mapa(t_mapa *mapa)
{
	int	i;

	i = 0;
	mapa->mapa = (char **)malloc(sizeof(char *) * mapa->y);
	while (i < mapa->y)
	{
		mapa->mapa[i] = (char *)malloc(sizeof(char) * (mapa->x + 1));
		i++;
	}
}

void	imprimir_mapa(t_mapa *mapa)
{
	int	i;

	i = 0;
	while (i < mapa->y)
	{
		ft_printf("%s\n", mapa->mapa[i]);
		i++;
	}
}

void	liberar_mapa(t_mapa *mapa)
{
	int	i;

	i = 0;
	while (i < mapa->y)
	{
		free(mapa->mapa[i]);
		i++;
	}
	free(mapa->mapa);
}
