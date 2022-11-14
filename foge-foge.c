#include <stdio.h>
#include "./ft_printf/ft_printf.h"

int	main()
{
	char	mapa[5][11];
	FILE	*f;
	int		i;

	i = 0;
	f = fopen("./mapas/mapa.txt", "r");
	if (f == 0)
	{
		ft_printf("Erro de leitura do mapa!\n");
		exit(EXIT_FAILURE);
	}
	while (i < 5)
	{
		fscanf(f, "%s", mapa[i]);
		ft_printf("%s\n", mapa[i]);
		i++;
	}
	fclose(f);
}

void	open_map()
{
	
}
