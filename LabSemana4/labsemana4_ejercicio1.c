#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Max 5

typedef struct 
{
	char name[50];
	int age;
	int room;
	float temperature;
} Patient;

void AddPatient(Patient patients[], int i)
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
}

void PrintPatients(Patient p)
{
	printf("\n**********************************\n");
	printf("\nNombre de el o la paciente: %s", p.name);
	printf("\nEdad de el o la paciente: %d", p.age);
	printf("\nHabitacion de el o la paciente: %d", p.room);
	printf("\nTemperatura de el o la paciente: %.1f\n", p.temperature);
}

int main()
{
	Patient patients[Max];
	
	int i = 0;
	int op;
	
	while (i < Max)
	{
		AddPatient(patients, i);
		
		//Esto... 
		printf("\n(En caso de que haya ingresado un dato erroneo) \nDesea reingresar al paciente %d? \nIngrese <1> si es asi, de lo contrario cualquier otro numero: ", i + 1);
		scanf("%d", &op);
		
		if (op != 1)
		{
			i++;
		}
		//...podria no existir
	}
	
	for (i = 0; i < Max; i++)
	{
		PrintPatients(patients[i]);
	}
	
	return 0;
}

