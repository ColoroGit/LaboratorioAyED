#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct guardian
{
	char name[50]; //Nombre del guardian
	char type[20]; //tipo del guardian
	int id; //identificador único del guardian, sirve para que algunas funciones sean más simples de realizar
	int hp; //puntos de vida del guardian
	int dmg; //puntos de daño del guardian
	int defense; //puntos de defensa del guardian
	struct guardian *next; //la direccion de memoria del guardian que le sigue en la cola
} Guardian;

//estructura que registra los combates realizados
typedef struct combat
{
	char tournament[20]; //torneo en el que peleo este combate
	int numBattle; //que combate del torneo era
	int turns; //la cantidad de rondas que le tomó esta pelea
	Guardian *opponent; //el oponente de esa pelea
	Guardian *player; //cómo terminó el jugador esa pelea (dependiendo de si murió o no dirá que se perdió o se mostraran las estadisticas cuando venció al oponente)
	struct combat *next; //la direccion de memoria del combate que le sigue
} Combat;

Guardian* CreateGuardian(char name[], char type[], int id, int hp, int dmg, int defense) //función básica para crear a un guardian en base a los parametros entregados
{
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	strcpy(newGuardian->name, name);
	strcpy(newGuardian->type, type);
	newGuardian->id = id;
	newGuardian->hp = hp;
	newGuardian->dmg = dmg;
	newGuardian->defense = defense;
	newGuardian->next = NULL;
	
	return newGuardian;
}

void Enqueue(Guardian **head, Guardian *newGuardian) //Clásica función para agregar a una estructura al final de una cola
{
	if (*head == NULL)
	{
		*head = newGuardian;
	}
	else
	{
		Guardian *current = *head;
		
		while (current->next != NULL)
		{
			current = current->next;
		}
		
		current->next = newGuardian;
	}
}

Guardian* Dequeue(Guardian **head) //Conocida función para sacar y retornar al primer objeto de la cola
{
	Guardian *aux = *head;
	*head = aux->next;
	aux->next = NULL; //Por conveniencia
	return aux;
}

Guardian* ReturnElement(Guardian **head, Guardian *g)
{
	if (g == *head)
	{
		return Dequeue(head);
	}
	else
	{
		Guardian *current = *head;
		
		while (current->next != g)
		{
			current = current->next;
		}	
		
		Guardian *aux = current->next;
		current->next = aux->next;
		aux->next = NULL;
		return aux;
	}
}

void Push (Combat **top, Combat *newCombat)
{
	if (*top == NULL)
	{
		*top = newCombat;
	}
	else
	{
		newCombat->next = *top;
		*top = newCombat;
	}
}

void PrintGuardians(Guardian *head, int i) //Función para imprimir a toda o parte de la cola de guardianes
{
	Guardian *current = head;
	
	while (i > 0 && current != NULL)
	{
		printf("\n   Guardi\xA0n %d:\n Nombre: %s\n Tipo: %s\n Vida: %d\n Da\xA4o: %d\n Defensa: %d\n", current->id, current->name, current->type, current->hp, current->dmg, current->defense);
		current = current->next;
		i--;
	}
}

void PrintGuardian(Guardian *g) //Función para imprimir a un solo guardian
{
	printf("\n\t***Estadisticas del Guardi\xA0n***\n");
	printf("\n Nombre: %s\n Tipo: %s\n Vida: %d\n Da\xA4o: %d\n Defensa: %d\n", g->name, g->type, g->hp, g->dmg, g->defense);
}

void Randomize(Guardian **head, int i) //Función para desordenar a los guardianes ubicados en una cola
{
	srand(time(NULL)); //Lo que hace esta funcion es tomar a un guardian cualquiera dentro de la cola y mandarlo al final de esta, luego de nuevo, pero sin contar a los que ya han sido movidos.
	
	while (i > 0)
	{
		Guardian *current = *head;
		int j = rand() % i;
		
		while (j > 0)
		{
			current = current->next;
			j--;
		}
		
		Guardian *aux = current->next;
		current->next = aux->next;
		aux->next = NULL;
		Enqueue(head, aux);
		i--;
	}
}

Guardian* CrearGuardian(char name[], int op)
{
	srand(time(NULL));
	Guardian *newGuardian = (Guardian*)malloc(sizeof(Guardian));
	
	newGuardian->id = 0;
	strcpy(newGuardian->name, name);
	
	switch (op)
	{
		case 1:
		strcpy(newGuardian->type, "mage");
		break;
		
		case 2:
		strcpy(newGuardian->type, "nigromante");
		break;
		
		case 3:
		strcpy(newGuardian->type, "beast");
		break;
		
		case 4:
		strcpy(newGuardian->type, "viking");
		break;
	}
	
	newGuardian->hp = (((rand() % 21) + 40) * 10);
	newGuardian->dmg = (((rand() % 21) + 20) * 5);
	newGuardian->defense = (((rand() % 15) + 6) * 5);
	newGuardian->next = NULL;
	
	return newGuardian;
}

Guardian* SelectGuardian(Guardian **head, int i)
{
	Guardian *current = *head;
	int op;
	int aux = i;
	
	while (op != -1)
	{
		printf("\nElija a su Guardi\xA0n ingresando su n\xA3mero correspondiente\no <-1> para volver al men\xA3: ");
		scanf("%d", &op);
		
		i = aux;
			
		while (i > 0)
		{
			if (current->id == op)
			{
				return ReturnElement(head, current);
			}
			current =current->next;
			i--;
		}
		
		printf("Ese Guardi\xA0n no existe, por favor ingrese otro n\xA3mero");
	}
	
	return NULL;
}

bool Combate(Guardian *jugador, Guardian *opponent, int numBattle, Combat *newCombat)
{
	srand(time(NULL));
	Guardian *current = (Guardian*)malloc(sizeof(Guardian)); 
	int turn = 1;
	int valor;
	int op;
	int dado;
	bool extra = false; //variable que representa si se está en el turno extra o no
	
	while (jugador->hp > 0 && opponent->hp > 0)
	{
		if (turn == 1) //Asignación de quién parte
		{
			if (rand() % 2 == 0)
			{
				current = jugador;
			}
			else
			{
				current = opponent;
			}	
		}
		
		printf("\n\t\t*****Turno %d*****\n", turn);
		printf("\nT\xA3: ");
		PrintGuardian(jugador);
		printf("\nTu oponente: ");
		PrintGuardian(opponent);
		system("pause");
		
		if (current == jugador) //Turno del jugador
		{
			printf("\n\t***Te toca %s***\n", jugador->name);
			printf("Qu\x82 deseas hacer?\n   (1) Atacar\n   (2) Sanarte\nIngresa el n\xA3mero entre per\x82ntesis de tu selecci\xA2n: ");
			scanf("%d", &op);
			
			while (op != 1 && op != 2)
			{
				printf("Esa opci\xA2n no existe, por favor selecciona otra: ");
				scanf("%d", &op);
			}
			
			if (op == 1) //ATACAR
			{
				printf("\nPresiona enter para lanzar el dado");
				fflush(stdin);
				getchar(); //esto está pensado únicamente para hacer una pausa y que haya interacción por parte del usuario
				dado = (rand() % 6) + 1;
				printf("Has obtenido un %d!", dado);
				
				switch (dado)
				{
					case 1:
					valor = (int)(jugador->dmg * 0.8);
					opponent->hp -= valor;
					printf("\n\tAtaque exitoso!!!\nLe has quitado %d puntos de vida a tu oponente\n", valor);
					
					if (opponent->hp < 0)
					{
						opponent->hp = 0;
						printf("\n\tOponente Abatido!!!\n");
					}
					break;
					
					case 3:
					valor = jugador->dmg;
					opponent->hp -= valor;
					printf("\n\tAtaque exitoso!!!\nLe has quitado %d puntos de vida a tu oponente\n", valor);
					
					if (opponent->hp < 0)
					{
						opponent->hp = 0;
						printf("\n\tOponente Abatido!!!\n");
					}
					break;
					
					case 5:
					valor = (int)(jugador->dmg * 1.3);
					opponent->hp -= valor;
					printf("\n\tAtaque exitoso!!!\nLe has quitado %d puntos de vida a tu oponente\n", valor);
					
					if (opponent->hp < 0)
					{
						opponent->hp = 0;
						printf("\n\tOponente Abatido!!!\n");
					}
					break;
					
					default:
					printf("\nTu ataque ha fallado, pero no te rindas todavia!!!\n");
					break;
				}
			}
			else //SANARSE
			{
				printf("\nPresiona enter para lanzar el dado");
				fflush(stdin);
				getchar(); //esto está pensado únicamente para hacer una pausa y que haya interacción por parte del usuario
				dado = (rand() % 6) + 1;
				printf("Has obtenido un %d", dado);
				
				switch (dado)
				{
					case 2:
					valor = (int)(jugador->defense * 0.5);
					jugador->hp += valor; 
					printf("\n\tSanaci\xA2 exitosa!!!\nHas recuperado %d puntos de vida\n", valor);
					break;
					
					case 4:
					valor = jugador->defense;
					jugador->hp += valor; 
					printf("\n\tSanaci\xA2 exitosa!!!\nHas recuperado %d puntos de vida\n", valor);
					break;
					
					case 6:
					valor = (int)(jugador->defense * 1.2);
					jugador->hp += valor; 
					printf("\n\tSanaci\xA2 exitosa!!!\nHas recuperado %d puntos de vida\n", valor);
					break;
					
					default:
					printf("\nTu sanaci\xA2n ha fallado\n");
					if (jugador->defense > 30)
					{
						valor = (int)(jugador->defense * 0.05);
						jugador->defense -= valor;
						printf("has recibido un desgaste en tu defensa de %d puntos!\n", valor);
						
						if (jugador->defense < 30)
						{
							jugador->defense = 30;
							printf("\nTu defensa ha llegado al minimo (no recibir\xA0s m\xA0s desgaste)\n");
						}
					}
					break;
				}
			}
			
			if (dado == 6 && !extra)
			{
				extra = true;
				printf("\nComo obtuviste un 6 en el dado, tienes un turno extra!!!\n");
			}
			else
			{
				extra = false;
				current = opponent;
			}
			
			system("pause");
		}
		else //Juega la máquina
		{
			printf("\n\t***Le toca a tu oponente %s***\n", opponent->name);
			
			op = (rand() % 2) + 1;
			
			if (op == 1) //ATACAR
			{
				dado = (rand() % 6) + 1;
				printf("El enemigo a decidido Atacar y obtuvo un %d en el dado\n", dado);
				
				switch (dado)
				{
					case 1:
					valor = (int)(opponent->dmg * 0.8);
					jugador->hp -= valor;
					printf("\n\tAtaque exitoso!!!\nTu oponente te ha quitado %d puntos de vida\n", valor);
					
					if (jugador->hp < 0)
					{
						jugador->hp = 0;
						printf("\n\tHas sido derrotado\n");
					}
					break;
					
					case 3:
					valor = opponent->dmg;
					jugador->hp -= valor;
					printf("\n\tAtaque exitoso!!!\nTu oponente te ha quitado %d puntos de vida\n", valor);
					
					if (jugador->hp < 0)
					{
						jugador->hp = 0;
						printf("\n\tHas sido derrotado\n");
					}
					break;
					
					case 5:
					valor = (int)(opponent->dmg * 1.3);
					jugador->hp -= valor;
					printf("\n\tAtaque exitoso!!!\nTu oponente te ha quitado %d puntos de vida\n", valor);
					
					if (jugador->hp < 0)
					{
						jugador->hp = 0;
						printf("\n\tHas sido derrotado\n");
					}
					break;
					
					default:
					printf("\nEl ataque de %s ha fallado!!!\n", opponent->name);
					break;
				}
			}
			else //SANARSE
			{
				dado = (rand() % 6) + 1;
				printf("El enemigo a decidido Sanarse y obtuvo un %d en el dado\n", dado);
				
				switch (dado)
				{
					case 2:
					valor = (int)(opponent->defense * 0.5);
					opponent->hp += valor; 
					printf("\n\tSanaci\xA2 exitosa!\nTu oponente ha recuperado %d puntos de vida\n", valor);
					break;
					
					case 4:
					valor = opponent->defense;
					opponent->hp += valor; 
					printf("\n\tSanaci\xA2 exitosa!\nTu oponente ha recuperado %d puntos de vida\n", valor);
					break;
					
					case 6:
					valor = (int)(opponent->defense * 1.2);
					opponent->hp += valor; 
					printf("\n\tSanaci\xA2 exitosa!\nTu oponente ha recuperado %d puntos de vida\n", valor);
					break;
					
					default:
					printf("\nLa sanaci\xA2n de %s ha fallado!!!", opponent->name);
					if (opponent->defense > 30)
					{
						valor = (int)(opponent->defense * 0.05);
						opponent->defense -= valor;
						printf("\nY ha recibido un desgaste de %d puntos en su defensa!!!\n", valor);
						
						if (opponent->defense < 30)
						{
							opponent->defense = 30;
							printf("\nLa defensa de %s ha llegado al minimo (no recibir\xA0 m\xA0s desgaste)\n", opponent->name);
						}
					}
					break;
				}
			}
			
			if (dado == 6 && !extra) 
			{
				extra = true;
				printf("\nComo %s obtuvo un 6 en el dado, tiene un turno extra!\n", opponent->name);
			}
			else
			{
				extra = false;
				current = jugador; 
			}
			
			system("pause");
		}
		
		turn++;
	}
		
	//Registro final del combate
	newCombat->turns = turn;
	newCombat->player = jugador;
	
	if (jugador->hp <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool IniciarTorneo(Guardian **head, int torneo, Guardian *jugador, Combat **top)
{
	Combat *newCombat = (Combat*)malloc(sizeof(Combat));
	Guardian *opponent = Dequeue(head);
	char tournament[20];
	int combats = torneo*2 + 1;
	int i = 1;
	bool victoria = true;
	
	if (torneo == 1)
	{
		strcpy(tournament, "Principiante");
	}
	else if (torneo == 2)
	{
		strcpy(tournament,  "Intermedio");
	}
	else if (torneo == 3)
	{
		strcpy(tournament, "Experto");
	}
	
	while (i <= combats && victoria) //inician las batallas del torneo
	{
		//Registro inicial del combate
		newCombat->opponent = opponent;
		newCombat->numBattle = i;
		strcpy(newCombat->tournament, tournament);
		
		//Inicio del combate
		printf("\n\t***Que comience el combate n\xA3mero %d***\n", i);
		system("pause");
		victoria = Combate(jugador, opponent, i, newCombat);
		
		Push(top, newCombat);
		
		if (victoria)
		{
			opponent = Dequeue(head);
			i++;
		}
	}
	
	return victoria;
}

int main(int argc, char *argv[]) 
{
	//inicialización de variables
	Guardian *guardians = NULL; //cola de guardianes
	Combat *history = NULL; //pila de registro de combate
	char name[50];
	char type[20];
	int i = 1;
	
	//El código que viene a continuación es para cargar en el programa el archivo Guardians.txt, donde viene la información de los guardianes
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
		
		token = strtok(line, ",");
		strcpy(name, token);
		
		token = strtok(NULL, ",");
		strcpy(type, token);
		
		int hp = atoi(strtok(NULL, ","));
		int dmg = atoi(strtok(NULL, ","));
		int defense = atoi(strtok(NULL, ","));
		
		Enqueue(&guardians, CreateGuardian(name, type, i, hp, dmg, defense));
		i++;
	}
	
	i--;
	
	Randomize(&guardians, i);
	Enqueue(&guardians, Dequeue(&guardians)); //esto es para mover al primero de la cola al final, ya que es el único que no se mueve durante la randomización
	Randomize(&guardians, i);
	
	//Aquí deberia ir la carga de el historial (OPCIONAL), que debería agarrar un archivo que se escribe dentro del programa, que es la forma de cargar la partida
	
	//Bienvenida del programa (sacada del documento del Proyecto de Unidad, elaborado por Manuel Moscoso)
	printf("\n\t*****Bienvenido a The Guardians Tournament*****\n");
	printf("\nEn un mundo devastado por la guerra y la lucha constante, donde la magia es real, existen los Guardianes.\nLos Guardianes son h\x82roes con habilidades y destrezas \xA3nicas que protegen a las aldeas a lo largo de toda la tierra,\nsiendo estas los \xA3ltimos asentamientos de la humanidad. \nTodos los a\xA4os se realiza el torneo de los guardianes, donde se busca encontrar al campe\xA2n,\nquien gozar\xA0 del reconocimiento y la gloria eterna.\n");
	system("pause");
	
	//Inicialización de variables
	Guardian *jugador = (Guardian*)malloc(sizeof(Guardian));
	jugador = NULL;
	bool torneosSuperados[3] = {false, false, false};
	int op;
	bool exit = false;
	
	//Menú de selección
	while (!exit)
	{
		printf("\n\t***Men\xA3 Principal***\n");
		
		printf("\nQu\x82 desea realizar?\n\n   (1) Crear un Guardi\xA0n\n   (2) Seleccionar un Guardi\xA0n preexistente\n   (3) Seleccionar Torneo\n   (4) Ver Resultados Previos\n   (5) Tutorial\n   (6) Salir del Juego\n");
		printf("\nIngrese el n\xA3mero entre parentesis de la acci\xA2n: ");
		scanf("%d", &op);
		
		if (op > 0 && op < 7)
		{
			switch (op)
			{
				case 1: //Crear Guardian
				if (jugador != NULL)
				{
					printf("\n\tYa tienes a un Guardi\xA0n seleccionado, est\xA0s seguro de que quieres reemplazarlo por uno nuevo?");
					printf("\nIngresa <1> si es asi, de lo contrario cualquier otro n\xA3mero: ");
					scanf("%d", &op);
				}
				
				if (op == 1)
				{
					printf("\n\t***Creando a un Guardi\xA0n***\n\nA continuaci\xA2n deber\xA0s ingresar el nombre y el tipo de tu Guardi\xa0n.\nEl resto de estadisticas ser\xA0n asignadas aleatoriamente.");
					printf("\nIngrese el nombre de su Guardi\xA0n: ");
					scanf("%s", name);
					printf("Seleccione el tipo de su Guardi\xA0n:   (1) Mago   (2) Nigromante   (3) Bestia   (4) Vikingo");
					printf("\nIngrese el n\xA3mero entre parentesis del que eligi\xA2: ");
					scanf("%d", &op);
					
					while (op < 1 || op > 4)
					{
						printf("Ese tipo no existe, por favor ingrese otro: ");
						scanf("%d", &op);
					}
					
					jugador = CrearGuardian(name, op);
					
					//Tu Guardian
					PrintGuardian(jugador);
				}
				break;
				
				case 2: //Seleccionar Guardian
				if (jugador == NULL)
				{
					printf("\n\t***Seleccione a su Guardi\xA0n***\n");
					PrintGuardians(guardians, 5);
					jugador = SelectGuardian(&guardians, 5);
					
					printf("\n\t***Guardi\xA0n Seleccionado***\n");
					PrintGuardian(jugador);
				}
				else
				{
					printf("\n\t***Ya has seleccionado a tu Guardi\xA0n, no puedes elegir a otro preexistente***\n");
				}
				break;
				
				case 3: //Seleccionar Torneo
				if (jugador != NULL)
				{
					printf("\nSeleccione la dificultad del torneo:\n\n   (1)   Principiante\nObjetivo: derrotar a 3 Guardianes\n   (2)   Intermedio\nObjetivo: derrotar a 5 Guardianes\n   (3)   Experto\nObjetivo: derrotar a 7 Guardianes\n");
					printf("\nPara elegir la dificultad, ingrese el n\xA3mero entre parentesis de su selecci\xA2n\no <-1> para volver al men\xA3: ");
					scanf("%d", &op);
					
					if (op != -1)
					{
						while (op < 1 || op > 3)
						{
							printf("Esa opci\xA2n es inv\xA0lida, por favor ingrese otra: ");
							scanf("%d", &op);
							
							if (op == -1)
							{
								break;
							}
						}
					}
					
					if (op != -1)
					{
						Guardian *aux = jugador; //malloc? para crear una copia con un espacio de memoria aparte?? probar si funciona perdiendo un torneo e intentando jugar otro
						PrintGuardian(aux); ///////////////////////////////
							
						if (!torneosSuperados[op - 1])
						{
							bool res = IniciarTorneo(&guardians, op, jugador, &history);
							torneosSuperados[op - 1] = res;
							
							PrintGuardian(aux); ///////////////////////////////
							
							if (!res)
							{
								jugador = aux;
								PrintGuardian(jugador); //////////////////////7
							}
						}
						else
						{
							printf("\nYa has completado y ganado este torneo, prueba las dem\xA0s dificultades, \no reinicia el juego (sin cargar partida) para empezar desde 0.\n");
						}
					}
				}
				else
				{
					printf("\n\t***No puedes iniciar un torneo si no has seleccionado o creado a un Guardi\xA0n***\n");
				}
				break;
				
				case 4:
				//Ver resultados
				break;
				
				case 5:
				printf("\nThe Guardians Tournament es un juego de peleas por turnos, donde usando a tu guardi\xA0n, \nte enfrentar\xA0s al resto de guardianes en distintos torneos, clasificados seg\xA3n su dificultad.\n\nDurante el combate, tendr\xA0s la opci\xA2n de Atacar o Sanarte.\n\nSi decides atacar, se lanzar\xA0 un dado de 6 caras, y si obtienes un n\xA3mero impar,\ntu ataque ser\xA0 exitoso, de lo contrario fallar\xA0s.\nSi sacaste un 1 en el dado, tu estadistica de Da\xA4o se multiplicar\xA0 por un factor de 0.8, \ny ese ser\xa0 el da\xA4o que ejerzas a tu enemigo.\nSi es un 3, el factor ser\xA0 un 1, y si es 5, el factor ser\xA0 un 1.3.\n\nSi decides sanarte, se lanzar\xA0 un dado de 6 caras, y si es par, tu sanaci\xA2n ser\xA0 exitosa, \nde lo contrario recibir\xA0s un desgaste en tu capacidad de sanaci\xA2n, que se ver\xA0 reflejado en tus puntos de defensa.\nSi obtuviste un 2, tu estadistica de Defensa se multiplicar\xA0 por un 0.5,\ny esa ser\xA0 la sanaci\xA2n que recibas\nSi es un 4, el factor ser\xA0 un 1, y si es un 6, el factor ser\xA0 un 1.2.\n");
				printf("\nSi sacas un 6, independiente de tu acci\xA2n, tendr\xA0s un turno extra, para atacar o sanarte nuevamente, \npero s\xA2lo obtienes un turno extra por jugada, si vuelves a sacar un segundo 6 consecutivo, no tendr\xA0s jugada extra.\n");
				printf("\nUna vez terminado el torneo, podr\xA0s revisar tus resultados en el men\xA3 principal, y, si lo deseas,\ncompetir en otro torneo de mayor o menor dificultad.\n");
				system("pause");
				break;
				
				case 6:
				exit = true;
				break;
			}
		}
		else
		{
			printf("\n\t***Esa opci\xA2n no existe, ingrese otra por favor***\n");
		}
	}
	
	printf("\n\t*****Gracias por Jugar*****\n\n");
	
	return 0;
}

