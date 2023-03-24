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

void AgregarObjeto(int inventarioGeneral[], int inventario[], int ident, int cantObjetosInvent)
{
	if (inventarioGeneral[ident - 1]++ < Tope)
	{
		if (cantObjetosInvent++ <= Max)
		{
			inventarioGeneral[ident - 1]++;
			inventario[ident - 1]++;
			cantObjetosInvent++;
		}
		else
		{
			printf("\nNo tienes suficiente espacio en tu inventario para guarda tanto objeto (espacio maximo: %d)", Max);
		}
	}
	else
	{
		printf("\nNo puedes agregar el objeto ya que no existen mas de este tipo");
	}
}

void EliminarObjeto(int inventarioGeneral[], int inventario[], int ident, int cantObjetosInvent)
{
	if (inventarioGeneral[ident - 1] == 0)
	{
		printf("\nNo puedes eliminar un objeto que no tienes");
		
	}
	else
	{
		inventarioGeneral[ident - 1]--;
		inventario[ident - 1]--;
		cantObjetosInvent--;
	}
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
	
	printf("\n\nAhora puede agregar o eliminar un objeto, o simplemente terminar el programa");
	
	listo = false;
	
	while (!listo)
	{
		printf("\n\nIngrese: \n<1> si quiere agregar un objeto \n<2> si quiere eliminar un objeto \n<3> si quiere terminar el programa: ");
		scanf("%d", &op);
		
		switch (op)
		{
			case 1: 
			
			printf("\nEn el inventario de que jugador quiere agregar un objeto (ingrese el numero de ese jugador): ");
			scanf("%d", &op);
			
			if (op == 1)
			{
				printf("Que objeto desea agregar: ");
				scanf("%d", &ident);
				
				if (ident <= 0 || ident > 10)
				{
					printf("\nEse tipo de objeto no existe, tu inventario queda igual");
				}
				else
				{
					AgregarObjeto(inventarioGeneral, inventario, ident, cantObjetosInvent);
					
					printf("\n\nTu inventario: ");
					
					for (i = 0; i < Tope; i++)
					{
						printf("\n%d. %d", i + 1, inventario[i]);
					}
				}
			}
			else if (op == 2)
			{
				printf("Que objeto desea agregar: ");
				scanf("%d", &ident);
				
				if (ident <= 0 || ident > 10)
				{
					printf("\nEse tipo de objeto no existe, tu inventario queda igual");
				}
				else
				{
					AgregarObjeto(inventarioGeneral, inventario2, ident, cantObjetosInvent2);
					
					printf("\n\nTu inventario: ");
					
					for (i = 0; i < Tope; i++)
					{
						printf("\n%d. %d", i + 1, inventario2[i]);
					}
				}
			}
			else
			{
				printf("\nEse inventario no existe");
			}
			
			break;
			
			case 2: 
			
			printf("\nEn el inventario de que jugador quiere eliminar un objeto (ingrese el numero de ese jugador): ");
			scanf("%d", &op);
			
			if (op == 1)
			{
				printf("Que objeto desea eliminar: ");
				scanf("%d", &ident);
				
				if (ident <= 0 || ident > 10)
				{
					printf("\nEse tipo de objeto no existe, tu inventario queda igual");
				}
				else
				{
					EliminarObjeto(inventarioGeneral, inventario, ident, cantObjetosInvent);
					
					printf("\n\nTu inventario: ");
					
					for (i = 0; i < Tope; i++)
					{
						printf("\n%d. %d", i + 1, inventario[i]);
					}
				}
			}
			else if (op == 2)
			{
				printf("Que objeto desea eliminar: ");
				scanf("%d", &ident);
				
				if (ident <= 0 || ident > 10)
				{
					printf("\nEse tipo de objeto no existe, tu inventario queda igual");
				}
				else
				{
					EliminarObjeto(inventarioGeneral, inventario2, ident, cantObjetosInvent2);
					
					printf("\n\nTu inventario: ");
					
					for (i = 0; i < Tope; i++)
					{
						printf("\n%d. %d", i + 1, inventario2[i]);
					}
				}
			}
			else
			{
				printf("\nEse inventario no existe");
			}
			
			break;
			
			case 3:
				
			listo = true;
			break;
		}
	}
	
	printf("\n\nGracias por usar el programa :)");
	
	return 0;
}
