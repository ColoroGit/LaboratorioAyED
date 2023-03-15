#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int piezas[7] = {1, 2, 3, 4, 5, 6, 7};
	int used = 0; 
	srand(time(NULL));
	int op = (rand() % 7) + 1;
	char seguir = 'S';
	
	printf("En VRVTetrix las piezas estan representadas por numeros. \nY durante los proximos turnos, a usted le saldran piezas aleatorias. \nAl final de su turno debera decidir si seguir jugando (ingresando por teclado el caracter <S>) \nO no (ingresando el caracter <N>)");
	printf("\n\nAhora, comencemos el juego!!!");
	
	printf("\n\nLe ha salido la pieza numero %d", op);
	
	used = piezas[op - 1];
	
	printf("\n\nDesea seguir jugando? \n SI <S> o NO <N>: ");
	scanf(" %c", &seguir);
	
	while (seguir != 'N')
	{
		do
		{
			op = (rand() % 7) + 1;
		}
		while (op == used);
		
		printf("\n\nAhora le ha salido la pieza numero %d", op);
		
		used = piezas[op - 1];
		
		printf("\n\nDesea seguir jugando? \n SI <S> o NO <N>: ");
		scanf(" %c", &seguir);
	}
	
	return 0;
}
