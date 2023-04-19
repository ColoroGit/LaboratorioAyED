#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Team 5

struct jugador
{
	char name[50];
	int id; //Es una variable extra que funciona como identificador único de cada jugador, con propositos más bien de funcionalidad, estética y comprensión para el usuario
	//int level; Borré la variable de nivel, ya que por cómo estoy creando el programa, perdió relevancia dentro del mismo
	int damage; //Representa el daño base de los jugadores. Va de 0 a 20 y se le suma al daño final de los ataques de un jugador
	int speed; //Define el orden en que pelearan los jugadores. Quien tenga una velocidad más alta jugará antes. Esta caracteristica se le suma al número aleatorio de ordenes que aparecerá en el siguiente ejercicio, y estará dada por lo que le falte al daño para llegar a 20 (por ejemplo, si el daño es 15, la velocidad será 5)
	int health; //Funciona de 0 a 100 para todos, al llegar a 0 el personaje muere
	int stamina; //Recurso que permite realizar hechizos o golpes. Max 500. Cada ataque consume una cierta cantidad de estamina. No se pueden realizar ataques si no se tiene la stamina necesaria
	int score; //Se acumula según el daño, sanación o estamina generada o regenerada, todas suman puntos 1:1 (si sano 100 de vida gano 100 puntos, si hago 30 de daño gano 30 puntos, si recupero 50 estamina, gano 50 puntos)
	int movimientos[3]; //Representa los movimientos que puede realizar un jugador. De un total de X movimientos distintos, se eligen 3 diferentes. Entre estos movimientos hay regeneración de vida, de estamina, hechizos y golpes.
};

void Movimientos()
{
	printf("\n\t***Lista de Movimientos***\n");
	printf("\n (1) Puño del dragon: Realiza un golpe basico de pelea, haciendo 10 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRecupera 50 puntos de estamina al ser ejecutado\n");
	printf("\n (2) Latigo Fantasma: Un ataque magico a distancia que roba vida al jugador atacado. \nHace 15 puntos de da\xA4o (mas los puntos de da\xA4o base), \nde los cuales 15 son recuperados en vida propia\n");
	printf("\n (3) Rafaga Mortal: Lanza un combo de golpes al enemigo seleccionado \nhaciendo 40 puntos de da\xA4o (mas los puntos de da\xA4o base). \nRequiere de 200 puntos de estamina para ser ejecutado\n");
	printf("\n (4) Trueno Llameante: Carga y lanza en el mismo turno un hechizo de trueno, \nque se dispara en forma de llamas mortales, haciendo 50 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRequiere de 300 puntos de estamina para ser ejecutado\n");
	printf("\n (5) Golpe Certero: Un solo ataque fisico en un punto critico del contrincante \nhaciendo 80 puntos de da\xA4o (mas los puntos de da\xA4o base) \nal jugador seleccionado. Requiere 500 de estamina para su uso, \nademas de 20 puntos de vida de quien lo ejecuta\n");
	printf("\n (6) Esfera Mortal: Carga durante un turno un poderoso hechizo \nque requiere 500 de estamina para ser realizado. \nAl siguiente turno, lanza esta esfera al jugador seleccionado \nhaciendo 70 puntos de da\xA4o (mas los puntos de da\xA4o base)\n");
	printf("\n (7) Sanacion: Recupera 25 puntos de vida al jugador seleccionado \n");
	printf("\n (8) Energizante: Recupera 150 puntos de estamina al jugador seleccionado \n");
}

void CrearJugador(struct jugador array[Team], int i)
{
	int movDisp[3] = {0};
	int j = 0;
	int k;
	int op;
	bool picked = false;
	
	array[i].id = i + 1;
	
	printf("\n\n\t*****Creando al jugador %d*****\n", array[i].id);
	
	printf("\nIngrese el nombre de su jugador: ");
	scanf("%s", array[i].name);
	
	printf("Ingrese el da\xA4o de %s (un numero entre 0 y 20) \n***Recuerde que su velocidad sera calculada en base a su da\xA4o \nsiendo la velocidad lo que le falta al da\xA4o para llegar a 20 \n(ejemplo, si su da\xA4o es 11, su velocidad sera 9)***: ", array[i].name);
	scanf("%d", &array[i].damage);
	
	while (array[i].damage < 0 || array[i].damage > 20)
	{
		printf("Ese valor es invalido, porfavor ingrese otro (un número entre 0 y 20): ");
		scanf("%d", &array[i].damage);
	}
	
	array[i].speed = 20 - array[i].damage;
	array[i].health = 100;
	array[i].stamina = 500;
	array[i].score = 0;
	
	Movimientos();
	
	printf("\nElijalos ingresando el numero que aparece entre parentesis ()\n");
	
	while (j < 3)
	{
		switch (j)
		{
			case 0: 
			printf("\nIngrese su primer movimiento: ");
			break;
			
			case 1:
			printf("\nIngrese su segundo movimiento: ");
			break;
			
			case 2:
			printf("\nIngrese su ultimo movimiento: ");
			break;
		}
		
		scanf("%d", &op);
		picked = false;
		
		if (op > 0 && op < 9)
		{
			for (k = 0; k < 3; k++)
			{
				if (op == movDisp[k])
				{
					picked = true;
					break;
				}
			}
			
			if (!picked)
			{
				array[i].movimientos[j] = op;
				movDisp[j] = op;
				j++;
			}
			else
			{
				printf("Ya ha elegido ese movimiento, por favor seleccione otro");
			}
		}
		else
		{
			printf("Ese movimiento no existe");
		}
	}
}

void RandomizarJugador(struct jugador array[Team], int i)
{
	srand(time(NULL));
	int movDisp[3] = {0};
	int j;
	int k;
	int op;
	bool picked = false;
	
	array[i].id = i + 1;
	
	printf("\n\n\t*****Creando al jugador %d*****\n", array[i].id);
	
	printf("\nIngrese el nombre del jugador \nEL resto de estadisticas se asignaran aleatoriamente: ");
	scanf("%s", array[i].name);
	array[i].damage = (rand() % 20) + 1;
	array[i].speed = 20 - array[i].damage;
	array[i].health = 100;
	array[i].stamina = 500;
	array[i].score = 0;
	
	while (j < 3)
	{
		op = (rand() % 8) + 1;
		picked = false;
		
		for (k = 0; k < 3; k++)
		{
			if (op == movDisp[k])
			{
				picked = true;
				break;
			}
		}
			
		if (!picked)
		{
			array[i].movimientos[j] = op;
			movDisp[j] = op;
			j++;
		}
	}
}

void MostrarJugador(struct jugador j)
{
	int k;
	
	printf("\n\t*****Jugador %d*****\n", j.id);
	
	printf("\nNombre: %s \nda\xA4o: %d \nVelocidad: %d \nVida: %d \nEstamina: %d \nPuntaje: %d\n", j.name, j.damage, j.speed, j.health, j.stamina, j.score);
	
	for (k = 0; k < 3; k++)
	{
		printf("Movimiento %d: %d\n", k + 1, j.movimientos[k]);
	}
}

int main()
{
	struct jugador Team1[Team];
	struct jugador Team2[Team];

	int i;
	int j;
	int auxi;
	int auxj;
	int op;
	
	//Dar Bienvenida y explicar juego
	printf("\n\t*****Bienvenido a Castillos Y Ciclopes*****\n");
	printf("\nEste es un juego de peleas por turnos que actualmente se encuentra en una fase de desarrollo.\nA continuacion encontraras un generador de personajes basico, el cual te pedira distintos datos. \nEntre ellos un nombre para tu jugador y un da\xA4o (un numero entre 1 y 20), \nel resto de caracteristicas seran generadas de forma basica \nexcepto la velocidad, que se define como la cantidad que le falta al da\xA4o para llegar a 20\nPor ejemplo, si tu da\xA4o es 13, tu velocidad sera 7. \nEl primer dato representa el da\xA4o base de los jugadores y se le suma al da\xA4o final de los ataques de un jugador. \nMientras que la segunda caracteristica se le suma al numero aleatorio de ordenes, \ny quien tenga una velocidad mas alta jugara antes que el resto.\nTambien cuentas con 100 puntos de vida, 500 puntos de mana (que es el recurso necesario para realizar movimientos),\ny un puntaje, el cual definira que equipo gana al final de la partida.\nFinalmente, el creador te pedira que elijas 3 de los 8 movimientos que hay disponibles.\nAparecera una lista mas adelante con la descripcion de cada movimiento, solo intenta elegir sabiamente...\n\n");
	
	system("pause");
	printf("\n\n\t***Partamos por crear a los jugadores del equipo 1***\n");
	
	for (i = 0; i < Team; i++)
	{
		printf("\nDesea crear al jugador %d a mano o que se genere automaticamente? \nIngrese <1> si desea hacerlo a mano, de lo contrario ingrese <0>: ", i + 1);
		scanf("%d", &op);
		
		if (op == 1)
		{
			CrearJugador(Team1, i);
		}
		else
		{
			RandomizarJugador(Team1, i);
		}
		
		MostrarJugador(Team1[i]);
		Movimientos();
		
		printf("\nDesea rehacer al jugador %d? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ", i + 1);
		scanf("%d", &op);
		
		if(op == 1)
		{
			i--;
		}
		else
		{
			printf("\nDesea agregar mas jugadores? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ");
			scanf("%d", &op);
			
			if (op == 0)
			{
				auxi = i + 1;
				i += 5;
			}
		}
	}
	
	for (i = 0; i < auxi; i++)
	{
		MostrarJugador(Team1[i]);
	}
	
	Movimientos();
	
	system("pause");
	
	printf("\n\t***Ahora creemos a los jugadores del equipo 2***\n");
	
	for (j = 0; j < Team; j++)
	{
		printf("\nDesea crear al jugador %d a mano o que se genere automaticamente? \nIngrese <1> si desea hacerlo a mano, de lo contrario ingrese <0>: ", j + auxi + 1);
		scanf("%d", &op);
		
		if (op == 1)
		{
			CrearJugador(Team2, j + auxi);
		}
		else
		{
			RandomizarJugador(Team2, j + auxi);
		}
		
		MostrarJugador(Team2[j + auxi]);
		Movimientos();
		
		printf("\nDesea rehacer al jugador %d? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ", j + auxi + 1);
		scanf("%d", &op);
		
		if(op == 1)
		{
			j--;
		}
		else
		{
			printf("\nDesea agregar mas jugadores? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ");
			scanf("%d", &op);
			
			if (op == 0)
			{
				auxj = j + 1;
				j += 5;
			}
		}
	}
	
	for (j = 0; j < auxj; j++)
	{
		MostrarJugador(Team2[j + auxi]);
	}
	
	Movimientos();
	
	system("pause");
	
	return 0;
}
