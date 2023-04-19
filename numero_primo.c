// Escriba un programa que determine si un número es primo o no.
// Se incluyen las librerías necesarias para el programa. stdio.h para las funciones printf y scanf; math.h para las funciones sqrt y fmod.
#include <stdio.h>
#include <math.h>

// Se crea el prototipo de la función para evitar errores de compilación.
int checkPrimeNumber(float n);

int main(int argc, char *argv[])
{
    // Se define la variable n, que va a tener el número ingresado por el usuario.
    int n;
    printf("Ingrese un numero entero positivo:  ");
    scanf("%i", &n);

    // Se revisa si el número es primo o no.
    if (checkPrimeNumber((float)n))
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
    // La forma más rápida de saber si un número es primo es viendo si es divisible entre cualquier número entero positivo hasta la raíz cuadrada del número.
    // Sacamos la raíz cuadrada del número.
    float square = sqrt(n);

    // Revisamos si el número ingresado por el usuario es divisible entre 2, para reducir la cantidad de operaciones a realizar a la mitad.
    // Aquí se usa la función fmod ya que se está trabajando con un flotante.
    if (fmod(n, 2) == 0)
    {
        return 0;
    }

    // Se itera desde el 3 hasta la raíz cuadrada del número, saltando un número de por medio. Esto se hace ya que el número 1 no se cuenta para el cálculo de números primos (porque todos los números son divisibles entre 1), y ya comprobamos si el número es divisible entre 2. Si el número es divisible entre 2, también lo será entre todos sus múltiplos, por lo que se omiten los números pares por cuestiones de optimización.
    for (float i = 3; i < square; i += 2)
    {
        // En cada iteración se verifica si el número es divisible entre el número actual de iteración. Si lo es, se retorna falso (0).
        if (fmod(n, i) == 0)
        {
            return 0;
        }
    }

    // Si la función llega hasta este punto, no fue divisible entre ningún número, así que se retorna verdadero (1).
    return 1;
}