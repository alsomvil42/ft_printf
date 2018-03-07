#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	int	retour;
	int	retour2;

	setlocale(LC_ALL, "");
	retour = ft_printf("OUI123 = %.4s\n", "Test123Test");
	retour2 = printf("NON123 = %.4s\n", "Test123Test");
	printf("VRAI = %d\n", retour2);
	printf("FAUX = %d\n", retour);
	return (0);
}
