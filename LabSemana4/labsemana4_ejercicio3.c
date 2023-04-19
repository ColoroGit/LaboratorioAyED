#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Max 50

typedef struct
{
	char name[50];
	int id;
	int age;
	int room;
	float temperature[7];
	int numTemp;
} Patient;

void AddPatient(Patient patients[], int i, int *pointer)
{
	if (i != *pointer)
	{
		patients[i].id = i + 1;
		patients[i].numTemp = 0;
		
		printf("\n\n\t***Ingresando Paciente %d***\n", patients[i].id);
		
		printf("\nIngrese el nombre de el o la paciente: ");
		scanf("%s", patients[i].name);
		
		printf("Ingrese la edad de el o la paciente: ");
		scanf("%d", &patients[i].age);
		
		printf("Ingrese la habitacion donde se ospedara el o la paciente: ");
		scanf("%d", &patients[i].room);
		
		printf("Ingrese la temperatura actual de el o la paciente\nDebe ingresar un punto <.> en vez de una coma <,>: ");
		scanf("%f", &patients[i].temperature[patients[i].numTemp]);
		
		patients[i].numTemp++;
		
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
	int k;
	
	for (j = 0; j < i; j++)
	{
		printf("\n***Paciente %d***\n", patients[j].id);
		printf("\nNombre de el o la paciente: %s", patients[j].name);
		printf("\nEdad de el o la paciente: %d", patients[j].age);
		printf("\nHabitacion de el o la paciente: %d", patients[j].room);
		printf("\nTemperaturas de el o la paciente: \n");
		
		for (k = 0; k < patients[j].numTemp; k++)
		{
			printf("   Temperatura %d: %.1f\n", k + 1, patients[j].temperature[k]);
		}
	}
}

void RecordTemperature(Patient patients[], int i)
{
	int op;
	int p;
	float temp;
	bool done = false;
	
	//mostrar a los pacientes actuales
	printf("\n\t*****Lista de pacientes*****\n");
	PrintPatients(patients, i);
	
	while (!done)
	{
		//dar a elegir al paciente al cual se le va a ingresar la temp
		printf("\nIngrese el numero del paciente al cual le desea ingresar la temperatura: ");
		scanf("%d", &op);
		
		if (op > 0 && op < i + 1)
		{
			p = op - 1;
			done = true;
		}
		else
		{
			printf("No existe un paciente con ese identificador, por favor ingrese otro numero");
		}
	}
	
	//Revisar si se pueden agregar mas temperaturas (tamaño arreglo temperatura)
	if (patients[p].numTemp < 7)
	{
		//ingresar la temperatura
		printf("Ingrese la temperatura de %s: ", patients[p].name);
		scanf("%f", &temp);
		
		patients[p].temperature[patients[p].numTemp] = temp;
		patients[p].numTemp++;
	}
	else
	{
		printf("\nEl registro de temperaturas de este paciente esta lleno \nDesea reescribir el registro realizado? \n(esto implica borrar las temperaturas previas y empezar de 0) \nIngrese <1> si es asi, de lo contrario cualquier otro numero: ");
		scanf("%d", &op);
		
		if (op == 1)
		{
			//ingresar la temperatura
			patients[p].numTemp = 0; //esto es para que empiece el registro todo de nuevo desde el primer espaio, el más antiguo
			
			printf("Ingrese la temperatura de %s: ", patients[p].name);
			scanf("%f", &temp);
			
			patients[p].temperature[patients[p].numTemp] = temp;
			patients[p].numTemp++;
		}
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
	
	while (!exit)
	{
		printf("\n   (1) Ingresar Paciente \n   (2) Imprimir lista de pacientes \n   (3) Ingresar temperatura de un paciente \n   (4) Salir del programa \n");
		printf("\nQue desea hacer? \n(Ingrese el numero correspondiente entre parentesis): ");
		scanf("%d", &op);
		
		switch (op)
		{
			case 1:
			AddPatient(patients, i, pointNumPatients);
			i++;
			break;
			
			case 2:
			printf("\n\t*****Lista de pacientes*****\n");
			PrintPatients(patients, i);
			printf("\n**********************************\n");
			break;
			
			case 3:
			if (i > 0)
			{
				RecordTemperature(patients, i);	
			}
			else
			{
				printf("\nNo hay paciente en el registro, por lo que no se pueden registrar temperaturas. \nPrimero ingrese pacientes\n");
			}
			break;
			
			case 4:
			exit = true;
			break;
			
			default:
			printf("Esa opcion es invalida, por favor ingrese otra");
			break;
		}
	}
	
	return 0;
}
