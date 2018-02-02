#include <stdio.h>

int		puissance(int nbr, int p)
{
	int i = nbr;

	if (p == 0)
		return (1);
	if (p == 1)
		return (nbr);
	while (p > 1)
	{
		nbr = nbr * i;
		p--;
	}
	return(nbr);
}


int		decimal2octal(int n)
{
	int n_oct = 0, k;

	k = 0;
	while (n > 0)
	{
		n_oct = n_oct + (n % 8) * puissance(10, k);
		n = n / 8;
		k++;
	}
	return (n_oct);
}


int main (){
	int n = 585;
	int i;

	i = decimal2octal(n);
	printf("%d\n", i);
	return (0);
}
