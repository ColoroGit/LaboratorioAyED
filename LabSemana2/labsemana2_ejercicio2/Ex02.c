#include <stdio.h>
#include <stdbool.h>
#define Max 50
#define Tope 10

bool Validar(int inventarioGeneral[], int ident, int cantidad)
{
	if (inventarioGeneral[ident - 1] + cantidad > Tope)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int IngresarObjetos(int inventarioGeneral[], int inventario[], int ident, int cantidad, int cantObjetosInvent)
{
	if(Validar(inventarioGeneral, ident, cantidad))
	{
		if (cantidad + cantObjetosInvent <= Max)
		{
			if (cantidad + inventario[ident - 1] <= Tope)
			{
				inventario[ident - 1] += cantidad;
				inventarioGeneral[ident - 1] += cantidad;
				cantObjetosInvent += cantidad;	
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
	else
	{
		printf("\nEsa cantidad no es posible, ya que en el juego no existen tantos objetos de ese tipo (cantidad maxima de objetos: %d)", Tope);
	}
	
	return cantObjetosInvent;
}

int main()
{
	int inventario[Tope] = {0};
	int inventario2[Tope] = {0};
	int inventarioGeneral[Tope] = {0};
	int cantObjetosInvent = 0;
	int cantObjetosInvent2 = 0;
	int ident = 0;
	int cantidad = 0;
	int op = -1;
	int i = 0;
	bool listo = false;
	
	printf("\nVamos a ingresar el inventario del jugador 1");
	
	while (!listo)
	{
		printf("\n\nIngrese el tipo de objeto que quiere guardar en su inventario (numeros del 1 al 10): ");
		scanf("%d", &ident);
		
		if (ident <= 0 || ident > 10)
		{
			printf("\nEse tipo de objeto no existe");
		}
		else
		{
			printf("Cuantos de este objeto quieres guardar?: ");
			scanf("%d", &cantidad);
			
			cantObjetosInvent = IngresarObjetos(inventarioGeneral, inventario, ident, cantidad, cantObjetosInvent);
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
	
	printf("\n\nAhora vamos a ingresar el inventario del segundo jugador");
	
	listo = false;
	
	while (!listo)
	{
		printf("\n\nIngrese el tipo de objeto que quiere guardar en su inventario (numeros del 1 al 10): ");
		scanf("%d", &ident);
		
		if (ident <= 0 || ident > 10)
		{
			printf("\nEse tipo de objeto no existe");
		}
		else
		{
			printf("Cuantos de este objeto quieres guardar?: ");
			scanf("%d", &cantidad);
			
			cantObjetosInvent2 = IngresarObjetos(inventarioGeneral, inventario2, ident, cantidad, cantObjetosInvent2);
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
		printf("\n%d. %d", i + 1, inventario2[i]);
	}

	printf("\n\nInventario General: ");
	
	for (i = 0; i < Tope; i++)
	{
		printf("\n%d. %d", i + 1, inventarioGeneral[i]);
	}
	
	return 0;
}
