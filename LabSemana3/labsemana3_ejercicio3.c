#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Team 5

struct jugador
{
	char name[50];
	int id; //Es una variable extra que funciona como identificador único de cada jugador, con propositos más bien de funcionalidad, estética y comprensión para el usuario
	int team; //Representa a que equipo pertenece, representado por un 1 o un 2
	//int level; Borré la variable de nivel, ya que por cómo estoy creando el programa, perdió relevancia dentro del mismo
	int damage; //Representa el daño base de los jugadores. Va de 0 a 20 y se le suma al daño final de los ataques de un jugador
	int speed; //Define el orden en que pelearan los jugadores. Quien tenga una velocidad más alta jugará antes. Esta caracteristica se le suma al número aleatorio de ordenes que define los turnos (funcion AsignarTurnos), y estará dada por lo que le falte al daño para llegar a 20 (por ejemplo, si el daño es 15, la velocidad será 5)
	int health; //Funciona de 0 a 100 para todos, al llegar a 0 el personaje muere
	int stamina; //Recurso que permite realizar hechizos o golpes. Max 500. Cada ataque consume una cierta cantidad de estamina. No se pueden realizar ataques si no se tiene la stamina necesaria
	int score; //Se acumula según el daño, sanación o estamina generada o regenerada, todas suman puntos 1:1 (si sano 100 de vida gano 100 puntos, si hago 30 de daño gano 30 puntos, si recupero 50 estamina, gano 50 puntos)
	bool cargando; //Representa el estado de estar cargando un hechizo, lo cual sirve para ciertas comprobaciones al realizar movimientos
	int movimientos[3]; //Representa los movimientos que puede realizar un jugador. De un total de X movimientos distintos, se eligen 3 diferentes. Entre estos movimientos hay regeneración de vida, de estamina, hechizos y golpes.
};

void Movimientos()
{
	printf("\n\t***Lista de Movimientos***\n");
	printf("\n (1) Pu\xA4o del dragon: Realiza un golpe basico de pelea, haciendo 10 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRecupera 50 puntos de estamina al ser ejecutado\n");
	printf("\n (2) Latigo Fantasma: Un ataque magico a distancia que roba vida al jugador atacado. \nHace 15 puntos de da\xA4o (mas los puntos de da\xA4o base), \nde los cuales 15 son recuperados en vida propia.\nRequiere 100 puntos de estamina para ser ejecutado\n");
	printf("\n (3) Rafaga Mortal: Lanza un combo de golpes al enemigo seleccionado \nhaciendo 40 puntos de da\xA4o (mas los puntos de da\xA4o base). \nRequiere de 200 puntos de estamina para ser ejecutado\n");
	printf("\n (4) Trueno Llameante: Carga y lanza en el mismo turno un hechizo de trueno, \nque se dispara en forma de llamas mortales, haciendo 50 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRequiere de 300 puntos de estamina para ser ejecutado\n");
	printf("\n (5) Golpe Certero: Un solo ataque fisico en un punto critico del contrincante \nhaciendo 80 puntos de da\xA4o (mas los puntos de da\xA4o base) \nal jugador seleccionado. Requiere 500 de estamina para su uso, \nademas de 20 puntos de vida de quien lo ejecuta\n");
	printf("\n (6) Esfera Mortal: Carga durante un turno un poderoso hechizo \nque requiere 500 de estamina para ser realizado. \nAl siguiente turno, lanza esta esfera al jugador seleccionado \nhaciendo 70 puntos de da\xA4o (mas los puntos de da\xA4o base)\n");
	printf("\n (7) Sanacion: Recupera 25 puntos de vida al jugador seleccionado. \nRequiere de 200 puntos de estamina para ser ejecutado.\nEste movimiento es capaz de revivir jugadores \n");
	printf("\n (8) Energizante: Recupera 200 puntos de estamina al jugador seleccionado \nRequiere de 50 puntos de estamina para ser ejecutado.\n");
}

void CrearJugador(struct jugador array[], int i, int team)
{
	int movDisp[3] = {0};
	int j = 0;
	int k;
	int op;
	bool picked = false;
	
	array[i].id = i + 1;
	array[i].team = team;
	
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
	array[i].cargando = false;
	
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

void RandomizarJugador(struct jugador array[], int i, int team)
{
	srand(time(NULL));
	int movDisp[3] = {0};
	int j;
	int k;
	int op;
	bool picked = false;
	
	array[i].id = i + 1;
	array[i].team = team;
	
	printf("\n\n\t*****Creando al jugador %d*****\n", array[i].id);
	
	printf("\nIngrese el nombre del jugador \nEL resto de estadisticas se asignaran aleatoriamente: ");
	scanf("%s", array[i].name);
	array[i].damage = (rand() % 21);
	array[i].speed = 20 - array[i].damage;
	array[i].health = 100;
	array[i].stamina = 500;
	array[i].score = 0;
	array[i].cargando = false;
	
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
	
	printf("\nNombre: %s \nEquipo: %d \nda\xA4o: %d \nVelocidad: %d \nVida: %d \nEstamina: %d \nPuntaje: %d\n", j.name, j.team, j.damage, j.speed, j.health, j.stamina, j.score);
	
	for (k = 0; k < 3; k++)
	{
		printf("Movimiento %d: %d\n", k + 1, j.movimientos[k]);
	}
}

void AsignarTurnos(struct jugador array[], int turnos[])
{
	srand(time(NULL));
	int speedValues[Team * 2] = {0};
	int i;
	int j;
	int aux1;
	int aux2;
	
	for (i = 0; i < Team * 2; i++)
	{
		speedValues[i] = (rand() % 21) + array[i].speed;
		turnos[i] = array[i].id;
	}
	
	for (i = 0; i < Team * 2; i++)
	{
		for (j = i + 1; j < Team * 2; j++)
		{
			if (speedValues[i] < speedValues[j])
			{
				aux1 = speedValues[i];
				aux2 = speedValues[j];
				
				speedValues[i] = aux2;
				speedValues[j] = aux1;
				
				aux1 = turnos[i];
				aux2 = turnos[j];
				
				turnos[i] = aux2;
				turnos[j] = aux1;
			}
		}
	}
	
	printf("\t***Orden de los turnos***\n\n");
	
	for (i = 0; i < Team * 2; i++)
	{
		printf("Turno %d: Jugador %d con %d puntos de velocidad\n", i + 1, turnos[i], speedValues[i]);
	}
}

int RealizarMovimiento(struct jugador array[], struct jugador j)
{
	int op;
	bool done = false;
	
	printf("\n\t***Tu turno, %s***\n", j.name);
	
	if (!j.cargando)
	{
		if (j.movimientos[0] == 1 || j.movimientos[1] == 1 || j.movimientos[2] == 1)
		{
			printf("\n (1) Pu\xA4o del dragon: Realiza un golpe basico de pelea, haciendo 10 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRecupera 50 puntos de estamina al ser ejecutado\n");
		}
		
		if (j.movimientos[0] == 2 || j.movimientos[1] == 2 || j.movimientos[2] == 2)
		{
			printf("\n (2) Latigo Fantasma: Un ataque magico a distancia que roba vida al jugador atacado. \nHace 15 puntos de da\xA4o (mas los puntos de da\xA4o base), \nde los cuales 15 son recuperados en vida propia.\nRequiere 100 puntos de estamina para ser ejecutado\n");
		}
		
		if (j.movimientos[0] == 3 || j.movimientos[1] == 3 || j.movimientos[2] == 3)
		{
			printf("\n (3) Rafaga Mortal: Lanza un combo de golpes al enemigo seleccionado \nhaciendo 40 puntos de da\xA4o (mas los puntos de da\xA4o base). \nRequiere de 200 puntos de estamina para ser ejecutado\n");
		}
		
		if (j.movimientos[0] == 4 || j.movimientos[1] == 4 || j.movimientos[2] == 4)
		{
			printf("\n (4) Trueno Llameante: Carga y lanza en el mismo turno un hechizo de trueno, \nque se dispara en forma de llamas mortales, haciendo 50 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRequiere de 300 puntos de estamina para ser ejecutado\n");
		}
		
		if (j.movimientos[0] == 5 || j.movimientos[1] == 5 || j.movimientos[2] == 5)
		{
			printf("\n (5) Golpe Certero: Un solo ataque fisico en un punto critico del contrincante \nhaciendo 80 puntos de da\xA4o (mas los puntos de da\xA4o base) \nal jugador seleccionado. Requiere 500 de estamina para su uso, \nademas de 20 puntos de vida de quien lo ejecuta\n");
		}
		
		if (j.movimientos[0] == 6 || j.movimientos[1] == 6 || j.movimientos[2] == 6)
		{
			printf("\n (6) Esfera Mortal: Carga durante un turno un poderoso hechizo \nque requiere 500 de estamina para ser realizado. \nAl siguiente turno, lanza esta esfera al jugador seleccionado \nhaciendo 70 puntos de da\xA4o (mas los puntos de da\xA4o base)\n");
		}
		
		if (j.movimientos[0] == 7 || j.movimientos[1] == 7 || j.movimientos[2] == 7)
		{
			printf("\n (7) Sanacion: Recupera 25 puntos de vida al jugador seleccionado. \nRequiere de 200 puntos de estamina para ser ejecutado.\nEste movimiento es capaz de revivir jugadores \n");
		}
		
		if (j.movimientos[0] == 8 || j.movimientos[1] == 8 || j.movimientos[2] == 8)
		{
			printf("\n (8) Energizante: Recupera 200 puntos de estamina al jugador seleccionado \nRequiere de 50 puntos de estamina para ser ejecutado.\n");
		}
		
		while (!done)
		{
			printf("\nQue movimiento desea realizar?\n(Elijalo ingresando el numero entre parentesis): ");
			scanf("%d", &op);
			
			if(op > 0 && op < 9)
			{
				if (op == j.movimientos[0] || op == j.movimientos[1] || op == j.movimientos[2])
				{
					//Chequeo de estamina, Preguntar si quiere pasar: return 0;
					switch (op)
					{	
						case 1:
						return op;
						break;
						
						case 2:
						if (j.stamina - 100 >= 0)
						{
							array[j.id - 1].stamina -= 100;
							return op;
						}
						break;
						
						case 3:
						if (j.stamina - 200 >= 0)
						{
							array[j.id - 1].stamina -= 200;
							return op;
						}
						break;
						
						case 4:
						if (j.stamina - 300 >= 0)
						{
							array[j.id - 1].stamina -= 300;
							return op;
						}
						break;
						
						case 5:
						if (j.stamina - 500 >= 0)
						{
							array[j.id - 1].stamina -= 500;
							return op;
						}
						break;
						
						case 6:
						if (j.stamina - 500 >= 0)
						{
							array[j.id - 1].stamina -= 500;
							return op;
						}
						break;
						
						case 7:
						if (j.stamina - 200 >= 0)
						{
							array[j.id - 1].stamina -= 200;
							return op;
						}
						break;
						
						case 8:
						if (j.stamina - 50 >= 0)
						{
							array[j.id - 1].stamina -= 50;
							return op;
						}
						break;
					}
					
					printf("No tienes la estamina suficiente para realizar ese movimiento \n(estamina actual: %d)", j.stamina);
					printf("\nDeseas elegir otro movimiento o saltar tu turno?\nIngresa <1> si quieres elegir otro movimiento, \n<0> si quieres saltar tu turno: ");
					scanf("%d", &op);
					
					if (op != 1)
					{
						return 0;
					}
				}
				else
				{
					printf("Usted no posee ese movimiento, elija uno de los que aparecio en pantalla");
				}
			}
			else
			{
				printf("Ese movimiento no existe, por favor ingrese otro");
			}
		}
	}
	else
	{
		return 6;
	}
}

void CambiarEstadistica(struct jugador array[], struct jugador j, int i, int mov)
{
	int k;
	int op;
	bool done = false;
	bool teammate = false;
	
	if (mov == 7 || mov == 8)
	{
		if (j.team == 1)
		{
			for (k = 0; k < Team; k++)
			{
				MostrarJugador(array[k]);
			}
		}
		else
		{
			for (k = 5; k < Team * 2; k++)
			{
				MostrarJugador(array[k]);
			}
		}
		
		teammate = true;
	}
	else if (mov == 6 && !j.cargando)
	{
		//Si este es el caos, en este turno no se elije a que jugador atacar, ya que se va a cargar el hechizo (Justo al final, despues del while (!done))
		done = true;
	}
	else if (mov > 0 && mov < 7)
	{
		if (j.team == 2)
		{
			for (k = 0; k < Team; k++)
			{
				MostrarJugador(array[k]);
			}	
		}
		else
		{
			for (k = 5; k < Team * 2; k++)
			{
				MostrarJugador(array[k]);
			}
		}
	}
	else
	{
		printf("\n\t\tTurno Omitido\n");
		done = true;
	}
	
	while (!done)
	{
		printf("\nCon que jugador desea aplicar este movimiento? \n(Ingrese el numero de ese jugador): ");
		scanf("%d", &op);
		
		if (op > 0 && op < 11)
		{
			if (teammate)
			{
				if (j.team == 1)
				{
					if (op < 6)
					{
						if(mov == 7)
						{
							array[op - 1].health += 25;	
							array[j.id - 1].score += 25;
							
							if (array[op - 1].health > 100)
							{
								array[op - 1].health = 100;
							}
						}
						else
						{
							array[op - 1].stamina += 200;
							array[j.id - 1].score += 200;
							
							if (array[op - 1].stamina > 500)
							{
								array[op - 1].stamina = 500;
							}
						}
						
						printf("\n\t\tEstadisticas actualizadas: \n");
						MostrarJugador(array[op - 1]);
						done = true;
					}
					else
					{
						printf("Opcion invalida, ese no es tu compañero");
					}
				}
				else
				{
					if (op > 5)
					{
						if(mov == 7)
						{
							array[op - 1].health += 25;
							array[j.id - 1].score += 25;
							
							if (array[op - 1].health > 100)
							{
								array[op - 1].health = 100;
							}
						}
						else
						{
							array[op - 1].stamina += 200;
							array[j.id - 1].score += 200;
							
							if (array[op - 1].stamina > 500)
							{
								array[op - 1].stamina = 500;
							}
						}
						
						printf("\n\t\tEstadisticas actualizadas: \n");
						MostrarJugador(array[op - 1]);
						done = true;
					}
					else
					{
						printf("Opcion invalida, ese no es tu compañero");
					}
				}
			}
			else
			{
				if (j.team == 1)
				{
					if (op > 5)
					{
						if (array[op - 1].health > 0)
						{
							switch (mov)
							{
								case 1:
								array[op - 1].health -= (10 + j.damage);
								array[j.id - 1].score += (10 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].stamina += 50;
								array[j.id - 1].score += 50;
								
								if (j.stamina > 500)
								{
									array[j.id - 1].stamina = 500;
								}
								
								MostrarJugador(array[j.id - 1]);
								break;	
								
								case 2:
								array[op - 1].health -= (15 + j.damage);
								array[j.id - 1].score += (15 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].health += 15;
								array[j.id - 1].score += 15;
								
								if (j.health > 100)
								{
									array[j.id - 1].health = 100;
								}
								
								MostrarJugador(array[j.id - 1]);
								break;
								
								case 3:
								array[op - 1].health -= (40 + j.damage);
								array[j.id - 1].score += (40 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								break;
								
								case 4:
								array[op - 1].health -= (50 + j.damage);
								array[j.id - 1].score += (50 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								break;
								
								case 5:
								array[op - 1].health -= (80 + j.damage);
								array[j.id - 1].score += (80 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].health -= 20;
								
								if (j.health < 0)
								{
									array[j.id - 1].health = 0;
									printf("\n\t***Has muerto***\n");
								}
								
								break;
								
								case 6:
								array[op - 1].health -= (80 + j.damage);
								array[j.id - 1].score += (80 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].cargando = false;
								
								break;
							}
							
							printf("\n\t\tEstadisticas actualizadas: \n");
							MostrarJugador(array[op - 1]);
							done = true;
						}
						else
						{
							printf("Ese jugador ya esta muerto");
						}
					}
					else
					{
						printf("Opcion invalida, ese no es tu enemigo");
					}
				}
				else
				{
					if (op < 6)
					{
						if (array[op - 1].health > 0)
						{
							switch (mov)
							{
								case 1:
								array[op - 1].health -= (10 + j.damage);
								array[j.id - 1].score += (10 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].stamina += 50;
								array[j.id - 1].score += 50;
								
								if (j.stamina > 500)
								{
									array[j.id - 1].stamina = 500;
								}
								
								MostrarJugador(array[j.id - 1]);
								break;	
								
								case 2:
								array[op - 1].health -= (15 + j.damage);
								array[j.id - 1].score += (15 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].health += 15;
								array[j.id - 1].score += 15;
								
								if (j.health > 100)
								{
									array[j.id - 1].health = 100;
								}
								
								MostrarJugador(array[j.id - 1]);
								break;
								
								case 3:
								array[op - 1].health -= (40 + j.damage);
								array[j.id - 1].score += (40 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								break;
								
								case 4:
								array[op - 1].health -= (50 + j.damage);
								array[j.id - 1].score += (50 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								break;
								
								case 5:
								array[op - 1].health -= (80 + j.damage);
								array[j.id - 1].score += (80 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].health -= 20;
								
								if (j.health < 0)
								{
									array[j.id - 1].health = 0;
									printf("\n\t***Has muerto***\n");
								}
								
								break;
								
								case 6:
								array[op - 1].health -= (80 + j.damage);
								array[j.id - 1].score += (80 + j.damage);
								
								if (array[op - 1].health < 0)
								{
									array[op - 1].health = 0;
									printf("\n\t***Enemigo abatido***\n");
								}
								
								array[j.id - 1].cargando = false;
								
								break;
							}
							
							printf("\n\t\tEstadisticas actualizadas: \n");
							MostrarJugador(array[op - 1]);
							done = true;
						}
						else
						{
							printf("Ese jugador ya esta muerto");
						}
					}
					else
					{
						printf("Opcion invalida, ese no es tu enemigo");
					}
				}
			}
		}
		else
		{
			printf("Ese jugador no existe");
		}
	}
	
	if (!j.cargando && mov == 6)
	{
		array[j.id - 1].cargando = true;
		printf("\n\t***Cargando Hechizo***\n");
	}
}

int MetaExperienciaAlcanzada(struct jugador array[])
{
	int i;
	int suma = 0;
	
	for (i = 0; i < Team; i++)
	{
		suma += array[i].score;
	}
	
	if (suma >= 500)
	{
		return 1;
	}
	
	suma = 0;
	
	for (i = 5; i < Team * 2; i++)
	{
		suma += array[i].score;
	}
	
	if (suma >= 500)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int main()
{
	struct jugador Jugadores[Team * 2];
	int turnos[Team * 2] = {0};
	
	int team;
	int i;
	int j;
	int op;
	bool done = false;
	
	printf("\n\t*****Bienvenido a Castillos Y Ciclopes*****\n");
	printf("\nEste es un juego de peleas por turnos que actualmente se encuentra en una fase de desarrollo.\nA continuacion encontraras un generador de personajes basico, el cual te pedira distintos datos. \nEntre ellos un nombre para tu jugador y un da\xA4o (un numero entre 0 y 20), \nel resto de caracteristicas seran generadas de forma basica \nexcepto la velocidad, que se define como la cantidad que le falta al da\xA4o para llegar a 20\nPor ejemplo, si tu da\xA4o es 13, tu velocidad sera 7. \nEl primer dato representa el da\xA4o base de los jugadores y se le suma al da\xA4o final de los ataques de un jugador. \nMientras que la segunda caracteristica se le suma al numero aleatorio de ordenes, \ny quien tenga una velocidad mas alta jugara antes que el resto.\nTambien cuentas con 100 puntos de vida, 500 puntos de mana (que es el recurso necesario para realizar movimientos),\ny un puntaje, el cual definira que equipo gana al final de la partida.\nFinalmente, el creador te pedira que elijas 3 de los 8 movimientos que hay disponibles.\nAparecera una lista mas adelante con la descripcion de cada movimiento, solo intenta elegir sabiamente...\n");
	printf("\nUna vez hayas armado los equipos, comenzara el combate en si. \nSe asignaran aleatoriamente los turnos mediante un dado de 20 caras, sumandole los puntos propios de velocidad.\nY despues, cuando sea el turno de cada jugador, podra elegir que hacer,\nEl objetivo siendo vencer a todos tus oponentes (que sus puntos de vida lleguen a 0)\n\n");
	
	system("pause");
	printf("\n\n\t***Partamos por crear a los jugadores del equipo 1***\n");
	team = 1;
	
	for (i = 0; i < Team * 2; i++)
	{
		if (i == 5 && !done)
		{
			for (i = 0; i < Team; i++)
			{
				MostrarJugador(Jugadores[i]);
			}
			
			Movimientos();
			
			printf("\n");
			system("pause");
			
			printf("\n\n\t***Ahora creemos a los jugadores del equipo 2***\n");
			team = 2;
			
			done = true;
		}
		
		printf("\nDesea crear al jugador %d a mano o que se genere automaticamente? \nIngrese <1> si desea hacerlo a mano, de lo contrario ingrese <0>: ", i + 1);
		scanf("%d", &op);
		
		if (op == 1)
		{
			CrearJugador(Jugadores, i, team);
		}
		else
		{
			RandomizarJugador(Jugadores, i, team);
		}
		
		MostrarJugador(Jugadores[i]);
		Movimientos();
		
		printf("\nDesea rehacer al jugador %d? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ", i + 1);
		scanf("%d", &op);
		
		if(op == 1)
		{
			i--;
		}
	}
	
	for (i = 5; i < Team * 2; i++)
	{
		MostrarJugador(Jugadores[i]);
	}
	
	Movimientos();
	
	printf("\n");
	system("pause");
	
	printf("\n\n\t***Asignacion de turnos***\n\n");
	
	AsignarTurnos(Jugadores, turnos);
	
	printf("\n\n\t*****Ahora que esta todo listo, empecemos el combate!!!*****\n");
	
	printf("\n");
	system("pause");
	
	printf("\n\n\t***La condicion de victoria en esta fase demo sera llegar a los 500 puntos de experiencia para ganar***\n");
	i = 0;
	
	while (MetaExperienciaAlcanzada(Jugadores) == 0)
	{
		if (Jugadores[turnos[i] - 1].health > 0)
		{
			CambiarEstadistica(Jugadores, Jugadores[turnos[i] - 1], i, RealizarMovimiento(Jugadores, Jugadores[turnos[i] - 1]));	
		}
		else
		{
			printf("\n\t***%s no puede jugar ya que está muerto***\n", Jugadores[turnos[i] - 1].name);
		}
		
		if(i == 9)
		{
			i = 0;
		}
		else
		{
			i++;	
		}
	}
	
	if (MetaExperienciaAlcanzada(Jugadores) == 1)
	{
		printf("\n\n\t*****Felicidades, ha ganado el Equipo 1*****\n");
	}
	else
	{
		printf("\n\n\t*****Felicidades, ha ganado el Equipo 2*****\n");
	}
	
	printf("\n");
	system("pause");
	printf("\n\n\t*****Gracias por jugar a Castillos Y Ciclopes*****\n");
	
	return 0;
}
