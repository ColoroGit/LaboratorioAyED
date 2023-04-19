#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct patient
{
	char name[50];
	int id;
	int age;
	int room;
	int numTemp;
	float temperature[7];
	struct patient *next;
} Patient;

void AddPatient(Patient **head, int i, int cantPatients, int *pointer)
{
	if (i != *pointer)
	{
		Patient *newPatient = (Patient*)malloc(sizeof(Patient));
		newPatient->id = cantPatients + 1;
		newPatient->numTemp = 0;
		
		printf("\n\n\t***Ingresando Paciente %d***\n", newPatient->id);
		
		printf("\nIngrese el nombre de el o la paciente: ");
		scanf("%s", newPatient->name);
		
		printf("Ingrese la edad de el o la paciente: ");
		scanf("%d", &newPatient->age);
		
		printf("Ingrese la habitacion donde se ospedara el o la paciente: ");
		scanf("%d", &newPatient->room);
		
		printf("Ingrese la temperatura actual de el o la paciente\nDebe ingresar un punto <.> en vez de una coma <,>: ");
		scanf("%f", &newPatient->temperature[newPatient->numTemp]);
		
		newPatient->numTemp++;
		
		newPatient->next = NULL;
		
		printf("\n\t***Paciente Ingresado***\n");
		
		//Poniendo al paciente nuevo al final de la lista
		if (*head == NULL)
		{
			*head = newPatient;
		}
		else
		{
			Patient *current = *head;
			
			while (current->next != NULL)
			{
				current = current->next;
			}
			
			current->next = newPatient;
		}
	}
	else
	{
		printf("\nYa no es posible agregar mas pacientes, se ha llegado al maximo ingresado (%d)\n", *pointer);
	}
	
}

void PrintPatients(Patient *head)
{
	int i;
	
	Patient *current = head;
	
	while (current != NULL)
	{
		printf("\n***Paciente %d***\n", current->id);
		printf("\nNombre de el o la paciente: %s", current->name);
		printf("\nEdad de el o la paciente: %d", current->age);
		printf("\nHabitacion de el o la paciente: %d", current->room);
		printf("\nTemperaturas de el o la paciente: \n");
		
		for (i = 0; i < current->numTemp; i++)
		{
			printf("   Temperatura %d: %.1f\n", i + 1, current->temperature[i]);
		}
		
		current = current->next;
	}
}

void RecordTemperature(Patient **head, int cantPatients)
{
	Patient *p = *head;
	int op;
	float temp;
	bool done = false;
	bool exit = false;
	
	while (!done)
	{
		//dar a elegir al paciente al cual se le va a ingresar la temp
		printf("\nIngrese el numero del paciente al cual le desea ingresar la temperatura: ");
		scanf("%d", &op);
		
		if (op > 0 && op < cantPatients + 1)
		{
			while (p->id != op && !exit)
			{
				if (p->next != NULL)
				{
					p = p->next;
				}
				else
				{
					exit = true;
				}
			}
			
			done = true;
		}
		else
		{
			printf("No existe un paciente con ese identificador, por favor ingrese otro numero");
		}
	}
	
	if (!exit)
	{
		//Revisar si se pueden agregar mas temperaturas (tamaño arreglo temperatura)
		if (p->numTemp < 7)
		{
			//ingresar la temperatura
			printf("Ingrese la temperatura de %s: ", p->name);
			scanf("%f", &temp);
			
			p->temperature[p->numTemp] = temp;
			p->numTemp++;
		}
		else
		{
			printf("\nEl registro de temperaturas de este paciente esta lleno \nDesea reescribir el registro realizado? \n(esto implica borrar las temperaturas previas y empezar de 0) \nIngrese <1> si es asi, de lo contrario cualquier otro numero: ");
			scanf("%d", &op);
			
			if (op == 1)
			{
				//ingresar la temperatura
				p->numTemp = 0; //esto es para que empiece el registro todo de nuevo desde el primer espaio, el más antiguo
				
				printf("Ingrese la temperatura de %s: ", p->name);
				scanf("%f", &temp);
				
				p->temperature[p->numTemp] = temp;
				p->numTemp++;
			}
		}
	}
	else
	{
		printf("Ese paciente ya no se encuentra en el registro\n");
	}
}

void DischargePatient(Patient **head, int cantPatients)
{
	Patient *p = *head;
	int op;
	bool done = false;
	bool exit = false;
	
	while (!done)
	{
		printf("\nIngrese el numero del paciente al cual le desea dar de alta: ");
		scanf("%d", &op);
		
		if (op > 0 && op < cantPatients + 1)
		{
			while (p->id != op && !exit)
			{
				if (p->next != NULL)
				{
					p = p->next;
				}
				else
				{
					exit = true;
				}
			}
			
			done = true;
		}
		else
		{
			printf("No existe un paciente con ese identificador, por favor ingrese otro numero");
		}
	}
	
	if (!exit)
	{
		//Que pasa si el que quiero eliminar es el prmero?
		if (*head == p)
		{
			*head = p->next;
			free(p);
		}
		else
		{
			Patient *current = *head;
			
			while (current->next != p)
			{
				current = current->next;
			}
			
			current->next = p->next;
			free(p);
		}
	}
	else
	{
		printf("Ese paciente ya no se encuentra en el registro\n");
	}
}

void FreePatients(Patient *head) 
{
	Patient *current = head;
	
	while (current != NULL) 
	{
		Patient *next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	Patient *head = NULL;
	
	int numPatients;
	int *pointNumPatients;
	int i = 0; //esta variable es un contador de los pacientes presentes en la lista
	int cantPatients = 0; //Mientras que esta es la que ayuda a asignar los id's y otros detalles
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
		printf("\n   (1) Ingresar Paciente \n   (2) Imprimir lista de pacientes \n   (3) Ingresar temperatura de un paciente \n   (4) Dar de alta a un paciente \n   (5) Salir del programa \n");
		printf("\nQue desea hacer? \n(Ingrese el numero correspondiente entre parentesis): ");
		scanf("%d", &op);
		
		switch (op)
		{
			case 1:
			AddPatient(&head, i, cantPatients, pointNumPatients);
			i++;
			cantPatients++;
			break;
			
			case 2:
			printf("\n\t*****Lista de pacientes*****\n");
			PrintPatients(head); 
			printf("\n**********************************\n");
			break;
			
			case 3:
			if (i > 0)
			{
				printf("\n\t*****Lista de pacientes*****\n");
				PrintPatients(head); 
				RecordTemperature(&head, cantPatients);
			}
			else
			{
				printf("\nNo hay paciente en el registro, por lo que no se pueden registrar temperaturas. \nPrimero ingrese pacientes\n");
			}
			break;
			
			case 4:
			if (i > 0)
			{
				printf("\n\t*****Lista de pacientes*****\n");
				PrintPatients(head);
				DischargePatient(&head, i);
				i--;
			}
			else
			{
				printf("\nNo hay paciente en el registro, no se le puede dar de alta a nada. \nPrimero ingrese pacientes\n");
			}
			break;
			
			case 5:
			exit = true;
			break;
			
			default:
			printf("Esa opcion es invalida, por favor ingrese otra");
			break;
		}
	}
	
	FreePatients(head);
	
	return 0;
}
