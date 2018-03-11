#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	int	retour;
	int	retour2;

	setlocale(LC_ALL, "");
	retour = ft_printf("%.5d", -421);
	retour2 = printf("%.5d", -421);
	printf("VRAI = %d\n", retour2);
	printf("FAUX = %d\n", retour);
	return (0);
}
