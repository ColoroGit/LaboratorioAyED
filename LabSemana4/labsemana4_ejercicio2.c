#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Max 50

typedef struct 
{
	char name[50];
	int age;
	int room;
	float temperature;
} Patient;

void AddPatient(Patient patients[], int i, int *pointer)
{
	if (i != *pointer)
	{
		printf("\n\n\t***Ingresando Paciente %d***\n", i + 1);
		
		printf("\nIngrese el nombre de el o la paciente: ");
		scanf("%s", patients[i].name);
		
		printf("Ingrese la edad de el o la paciente: ");
		scanf("%d", &patients[i].age);
		
		printf("Ingrese la habitacion donde se ospedara el o la paciente: ");
		scanf("%d", &patients[i].room);
		
		printf("Ingrese la temperatura actual de el o la paciente\nDebe ingresar un punto <.> en vez de una coma <,>: ");
		scanf("%f", &patients[i].temperature);
		
		printf("\n\t***Paciente Ingresado***\n");
	}
	else
	{
		printf("\nYa no es posible agregar mas pacientes, se ha llegado al maximo ingresado (%d)\n", *pointer);
	}
	
}

void PrintPatients(Patient patients[], int i)
{
	int j;
	
	for (j = 0; j < i; j++)
	{
		printf("\n**********************************\n");
		printf("\nNombre de el o la paciente: %s", patients[j].name);
		printf("\nEdad de el o la paciente: %d", patients[j].age);
		printf("\nHabitacion de el o la paciente: %d", patients[j].room);
		printf("\nTemperatura de el o la paciente: %.1f\n", patients[j].temperature);
	}
}

int main()
{
	Patient patients[Max];
	
	int numPatients;
	int *pointNumPatients;
	int i = 0;
	int op;
	bool done = false;
	bool exit = false;
	
	while (!done)
	{
		printf("\nCuantos pacientes va a agregar? \n(Considere que no se pueden ingresar mas de 50 pacientes): ");
		scanf("%d", &numPatients);
		
		if (numPatients <= 50 && numPatients >= 0)
		{
			pointNumPatients = &numPatients;
			done = true;
		}
		else
		{
			printf("Ese valor es invalido, por favor ingrese otro");
		}
	}
	
	//Menu de seleccion
	
	while (!exit)
	{
		printf("\n   (1) Ingresar Paciente \n   (2) Imprimir lista de pacientes \n   (3) Salir del programa\n");
		printf("\nQue desea hacer? \n(Ingrese el numero correspondiente entre parentesis): ");
		scanf("%d", &op);
		
		switch (op)
		{
			case 1:
			AddPatient(patients, i, pointNumPatients);
			i++;
			break;
			
			case 2:
			printf("\n\t***Lista de pacientes***\n");
			PrintPatients(patients, i);
			printf("\n**********************************\n");
			break;
			
			case 3:
			exit = true;
			break;
			
			default:
			printf("Esa opcion es invalida, por favor ingrese otra");
			break;
		}
	}
	
	return 0;
}
