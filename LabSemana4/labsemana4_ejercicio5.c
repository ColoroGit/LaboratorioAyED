#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct patient
{
	char name[50];
	int age;
	int room;
	float temperature;
	struct patient *next;
} Patient;

Patient* CreatePatient()
{
	Patient *newPatient = (Patient*)malloc(sizeof(Patient)); 
	
	printf("\n\n\t***Ingresando Paciente***\n");
	
	printf("\nIngrese el nombre de el o la paciente: ");
	scanf("%s", newPatient->name);
	
	printf("Ingrese la edad de el o la paciente: ");
	scanf("%d", &newPatient->age);
	
	printf("Ingrese la habitacion donde se ospedara el o la paciente: ");
	scanf("%d", &newPatient->room);
	
	printf("Ingrese la temperatura actual de el o la paciente\nDebe ingresar un punto <.> en vez de una coma <,>: ");
	scanf("%f", &newPatient->temperature);
	
	newPatient->next = NULL;
	
	return newPatient;
}

Patient* ChargePatient(char name[], int age, int room, float temperature)
{
	Patient *newPatient = (Patient*)malloc(sizeof(Patient)); 
	
	strcpy(newPatient->name, name);
	newPatient->age = age;
	newPatient->room = room;
	newPatient->temperature = temperature;
	newPatient->next = NULL;
	
	return newPatient;
}

void Enqueue(Patient **head, Patient *newPatient)
{	
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

void Dequeue(Patient **head)
{
	Patient *p = *head;
	
	if (p != NULL)
	{
		*head = p->next;
		free(p);
	}
	else
	{
		printf("\nNo hay pacientes para dar de alta\n");
	}
}

void PrintPatients(Patient *head)
{	
	Patient *current = head;
	
	while (current != NULL) //Modificar las variables que se van a mostrar (solo son nombre, edad, room y temperatura)
	{
		printf("\nNombre de el o la paciente: %s", current->name);
		printf("\nEdad de el o la paciente: %d", current->age);
		printf("\nHabitacion de el o la paciente: %d", current->room);
		printf("\nTemperatura de el o la paciente: %.1f\n", current->temperature);
		
		current = current->next;
	}
}

void GetNextPatient(Patient *head) //solo imprimir al primer paciente de la cola, para verlo
{	
	if (head != NULL)
	{
		printf("\nNombre de el o la paciente: %s", head->name);
		printf("\nEdad de el o la paciente: %d", head->age);
		printf("\nHabitacion de el o la paciente: %d", head->room);
		printf("\nTemperatura de el o la paciente: %.1f\n", head->temperature);
	}
	else
	{
		printf("\nNo hay pacientes para mostrar\n");
	}
}

int GetQueueSize(Patient *head) //Contar los elementos de la cola 
{
	Patient *current = head;
	
	int i = 0;
	
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	
	return i;
}

int GetLeftPatients(Patient *head) //Contar cuantos pacientes faltan para cierto paciente
{
	//Mostrar pacientes
	Patient *current = head;
	
	int i = 1;
	int op;
	
	while (current != NULL) 
	{
		printf("\n\t***Paciente %d***\n", i);
		printf("\nNombre de el o la paciente: %s", current->name);
		printf("\nEdad de el o la paciente: %d", current->age);
		printf("\nHabitacion de el o la paciente: %d", current->room);
		printf("\nTemperatura de el o la paciente: %.1f\n", current->temperature);
		
		current = current->next;
		i++;
	}
	
	//Elegir a cuál paciente contarle los puestos
	printf("\nA que paciente desea contarle los puestos? \nIngrese el numero de dicho paciente: ");
	scanf("%d", &op); //op es el mismo valor restante para que atiendan a ese paciente, pero bueno
	
	//Hacer algo parecido al GetQueueSize, pero detenerse con la condición de que op llegue a 0
	if (op > 0 && op <= i)
	{
		Patient *chosen = head;
		i = 1;
		
		while (op > 1)
		{
			chosen = chosen->next;
			i++;
			op--;
		}
		
		printf("\nFaltan %d pacientes para atender a %s\n", i, chosen->name);
	}
	else
	{
		printf("\nEse paciente no existe\n");
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

int main(int argc, char *argv[]) 
{
	Patient *head = NULL;
	
	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
		return 1;
	}
	
	char *file_name = argv[1];
	FILE *file = fopen(file_name, "r");
	
	if (file == NULL) 
	{
		fprintf(stderr, "Error: Could not open file \n");
		return 1;
	}
	
	char line[100];
	
	while (fgets(line, 100, file) != NULL) 
	{
		char *token;
		//https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
		token = strtok(line, ",");
		char name[50];
		strcpy(name, token);
		//https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm
		int age = atoi(strtok(NULL, ","));
		int room = atoi(strtok(NULL, ","));
		float temperature = atof(strtok(NULL, ","));
		//printf("%s, age:%d T°:%.1f ROOM:%d\n",name,age,temperature,room);
		
		Enqueue(&head, ChargePatient(name, age, room, temperature));
	}
	
	int op;
	bool done = false;
	bool exit = false;
	
	while (!exit)
	{
		printf("\n   (1) Ingresar Paciente \n   (2) Imprimir lista de pacientes \n   (3) Dar de alta al paciente actual \n   (4) Revisar al paciente actual \n   (5) Cantidad de pacientes en la cola \n   (6) Cantidad de pacientes restantes para atender a paciente X \n   (7) Salir del programa \n");
		printf("\nQue desea hacer? \n(Ingrese el numero correspondiente entre parentesis): ");
		scanf("%d", &op);
		
		switch (op)
		{
			case 1:
			Enqueue(&head, CreatePatient());
			printf("\n\t***Paciente agregado***\n");
			break;
			
			case 2:
			printf("\n\t*****Lista de pacientes*****\n");
			PrintPatients(head); 
			printf("\n**********************************\n");
			break;
			
			case 3:
			Dequeue(&head);
			break;
			
			case 4:
			GetNextPatient(head);
			break;
			
			case 5:
			printf("\nHay %d paciente(s) esperando a ser atendido(s)\n", GetQueueSize(head));
			break;
			
			case 6:
			GetLeftPatients(head);
			break;
			
			case 7:
			exit = true;
			break;
			
			default:
			printf("\nEsa opcion es invalida, por favor ingrese otra\n");
			break;
		}
	}
	
	FreePatients(head);
	
	fclose(file);
	
	return 0;
}
