#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	int	retour;
	int	retour2;

	setlocale(LC_ALL, "");
	retour = ft_printf("%20.12ld", 0x11ffaa147);
	retour2 = printf("%20.12ld", 0x11ffaa147);
	printf("VRAI = %d\n", retour2);
	printf("FAUX = %d\n", retour);
	return (0);
}
