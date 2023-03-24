#include <stdio.h>
#include <stdbool.h>
#define Max 50
#define Tope 10

int main()
{
	int inventario[Tope] = {0};
	int cantObjetosTotal = 0;
	int ident = 0;
	int cantidad = 0;
	int op = -1;
	int i = 0;
	bool listo = false;
	
	while (!listo)
	{
		printf("\nIngrese el tipo de objeto que quiere guardar en su inventario (numeros del 1 al 10): ");
		scanf("%d", &ident);
		
		if (ident <= 0 || ident > 10)
		{
			printf("\nEse tipo de objeto no existe");
		}
		else
		{
			printf("Cuantos de este objeto quieres guardar?: ");
			scanf("%d", &cantidad);
			
			if (cantidad + cantObjetosTotal <= Max)
			{
				if (cantidad + inventario[ident - 1] <= Tope)
				{
					inventario[ident - 1] += cantidad;
					cantObjetosTotal += cantidad;
				}
				else
				{
					printf("\nNo tienes espacio suficiente en este bolsillo para guardar este tipo de objeto (espacio maximo: %d)", Tope);
				}
			}
			else
			{
				printf("\nNo tienes suficiente espacio en tu inventario para guarda tanto objeto (espacio maximo: %d)", Max);
			}
		}
		
		printf("\n\nDeseas seguir guardando objetos? \nIngrese <1> si es asi, de lo contrario <0>: ");
		scanf("%d", &op);
			
		if(op == 0)
		{
			listo = true;
		}
	}
	
	printf("\n\nTu inventario: ");
	
	for (i = 0; i < Tope; i++)
	{
		printf("\n%d. %d", i + 1, inventario[i]);
	}
	
	return 0;
}
