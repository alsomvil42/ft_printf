#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	int	retour;
	int	retour2;

	setlocale(LC_ALL, "");
	retour = ft_printf("%u", -1001234);
	retour2 = printf("%u", -1001234);
	printf("VRAI = %d\n", retour2);
	printf("FAUX = %d\n", retour);
	return (0);
}
