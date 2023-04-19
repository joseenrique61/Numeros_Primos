#include <stdio.h>
#include <math.h>

int checkPrimeNumber(float n);

int main(int argc, char *argv[])
{
	int n;
	printf("Ingrese un numero entero positivo:  ");
	scanf("%i", &n);
	if(checkPrimeNumber((float)n))
	{
		printf("%i es un numero primo.", n);
	}
	else
	{
		printf("%i no es un numero primo.", n);
	}
}

int checkPrimeNumber(float n)
{
	float square = sqrt(n);
	
	if (fmod(n, 2) == 0)
	{
		return 0;
	}
	
	for (float i = 3; i < square; i += 2)
	{
		if (fmod(n, i) == 0)
		{
			return 0;
		}
	}
	return 1;
}