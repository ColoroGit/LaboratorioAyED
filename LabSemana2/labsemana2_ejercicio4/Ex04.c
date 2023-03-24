#include <stdio.h>
#include <stdbool.h>
#define Max 10

void Inicializar(int matriz[Max][Max], int num)
{
	int i;
	int j;
	
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			matriz[i][j] = num;
		}
	}
}

void Ingreso(int hospital[Max][Max]) 
{
	int habitacion;
	int edad;
	
	printf("\nIngrese la habitacion en la que se va a hospedar el/la paciente (un numero del 1 al 100) o <-1> para salir: ");
	scanf("%d", &habitacion);
	
	if (habitacion != -1)
	{
		if(habitacion > 0 && habitacion <= 100)
		{				//Conversion de número de habitación a coordenadas de la matriz
			if (hospital[(int)(habitacion - 1) / 10][(habitacion - 1) % 10] == -1)
			{
				printf("Ingrese la edad de el o la paciente o <-1> para salir: ");
				scanf("%d", &edad);
				
				if (edad != -1)
				{
					hospital[(int)(habitacion - 1) / 10][(habitacion - 1) % 10] = edad;
					printf("\nPaciente ingresado exitosamente");
				}
			}
			else
			{
				printf("\nEsa habitacion ya esta ocupada");
			}
		}
		else
		{
			printf("\nEsa habitacion no existe");
		}
	}
}

void Temperatura(int racha[Max][Max], float promedio[Max][Max], int diasDeEstadia[Max][Max], int i, int j) 
{
	int grados;
	float temp;
	bool ingresado = false;
	
	printf("\n\n\tPaciente de la habitacion %d.", (i * 10) + j + 1);
	
	while(!ingresado)
	{
		printf("\n\nVa a ingresar la temperatura en Celcius o Farenheit? \nIngrese <1> para Celcius y <2> para Farenheit: ");
		scanf("%d", &grados);
		
		switch (grados)
		{
			case 1:
				printf("\nIngrese la temperatura con solo un numero despues de la coma, \npero en vez de una coma use un punto: ");
				scanf("%f", &temp);
				
				if (temp >= 37.5)
				{
					printf("\nEl o la paciente tiene fiebre");
					racha[i][j]++;
				}
				else
				{
					printf("\nEl o la paciente no tiene fiebre");
					racha[i][j] = 0;
				}
				
				promedio[i][j] += temp;
				diasDeEstadia[i][j]++;
				ingresado = true;
				break;
				
			case 2:
				printf("\nIngrese la temperatura con solo un numero despues de la coma, \npero en vez de una coma use un punto: ");
				scanf("%f", &temp);
				
				temp = (temp - 32) * 5 / 9;
				
				if (temp >= 37.5)
				{
					printf("\nEl o la paciente tiene fiebre");
					racha[i][j]++;
				}
				else
				{
					printf("\nEl o la paciente no tiene fiebre");
					racha[i][j] = 0;
				}
				
				promedio[i][j] += temp;
				diasDeEstadia[i][j]++;
				ingresado = true;
				break;
				
			default:
				printf("Esa opcion no existe");
				break;
		}
	}
}

bool Racha(int racha[Max][Max]) 
{
	int i;
	int j;
	bool siHay = false;
	
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			if (racha[i][j] >= 3)
			{
				printf("\nEl o la paciente de la habitacion %d ha tenido fiebre por %d dias consecutivos", (i * 10) + j + 1, racha[i][j]);
				siHay = true;
			}
		}
	}
	
	return siHay;
}

void Promedio(float promedio[Max][Max], int diasDeEstadia[Max][Max])
{
	int i;
	int j;
	
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			if (promedio[i][j] != 0)
			{
				printf("\nEl o la paciente de la habitacion %d ha tenido un promedio de %f C durante la ultima semana", (i * 10) + j + 1, promedio[i][j]/diasDeEstadia[i][j]);
				promedio[i][j] = 0;
				diasDeEstadia[i][j] = 0;
			}
		}
	}
}

int main ()
{
	int hospital[Max][Max];
	int racha[Max][Max] = {0};
	float promedio[Max][Max] = {0};
	int diasDeEstadia[Max][Max] = {0};
	int dias = 1;
	int op = 0;
	int i;
	int j;
	bool termino = false;
	bool listo = false;
	
	printf("\n\t\t*****Bienvenido al programa de Seguimiento Hospitalario*****\n");
	printf("\nEste programa le pedira ciertos datos y es bastante intuitivo de usar, \npero su proposito es hacer un seguimiento de las temperaturas registradas por los pacientes.");
	printf("\nEste programa va por dias, y cada dia podra ingresar nuevos pacientes e ingresar sus temperaturas. \nAl final de cada dia podra saber que pacientes han tenido fiebre por 3 dias consecutivos \nY al final de cada semana recibira un reporte sobre el promedio semanal de temperatura de cada paciente");
	printf("\n\n\t\t*****Ahora comencemos*****");
	
	Inicializar(hospital, -1);
	
	while (!termino)
	{
		printf("\n\n\t\t*****Dia %d*****\n", dias);
		printf("\nDesea ingresar nuevos pacientes? \nIngrese <1> si es asi, de lo contrario <0>: ");
		scanf("%d", &op);
		
		while (op != 0)
		{
			Ingreso(hospital);
			
			printf("\n\nDesea ingresar otro paciente? \nIngrese <1> si es asi, de lo contrario <0>: ");
			scanf("%d", &op);
		}
		
		printf("\nAhora vamos a ingresar las temperaturas de los pacientes");
		
		for (i = 0; i < Max; i++)
		{
			for (j = 0; j < Max; j++)
			{
				if (hospital[i][j] != -1)
				{
					Temperatura(racha, promedio, diasDeEstadia, i, j);
				}
			}
		}
		
		printf("\n\nA continuacion se mostraran los pacientes que \nhan tenido fibre por 3 o mas dias consecutivos: \n");
		
		if(!Racha(racha))
		{
			printf("\nNo hay pacientes con mas de 3 dias consecutivos de fiebre");
		}
		
		if (dias % 7 == 0)
		{
			printf("\n\n\t\t*****Reporte semanal*****\n");
			printf("\nEn pantalla se mostraran los promedios de temperatura \nregistrados por los pacientes durante la ultima semana\n///Recuerde que las temperaturas estan representadas en grados Celcius///\n");
			
			Promedio(promedio, diasDeEstadia);
		}
		
		dias++;
	}
	
	
	
	return 0;
}
