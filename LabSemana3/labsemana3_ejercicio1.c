#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jugador
{
	char name[50];
	int level;
	int health;
	int score;
};

void CrearJugador(struct jugador array[3], int i)
{	
	printf("\n\t*****Creando al jugador %d*****\n", i + 1);
	
	printf("\nIngrese el nombre de su jugador: ");
	scanf("%s", array[i].name);
	printf("Ingrese el nivel de %s: ", array[i].name);
	scanf("%d", &array[i].level);
	printf("Ingrese la vida de %s: ", array[i].name);
	scanf("%d", &array[i].health);
	printf("Por ultimo ingrese el puntaje de %s: ", array[i].name);
	scanf("%d", &array[i].score);
}

void MostrarJugador(struct jugador j, int i)
{
	printf("\n\t*****Jugador %d*****\n", i + 1);
	
	printf("\nNombre: %s \nNivel: %d \nVida: %d \nPuntaje: %d\n", j.name, j.level, j.health, j.score);
}

int main()
{
	struct jugador jugadores[3];
	int i;
	
	for (i = 0; i < 3; i++)
	{
		CrearJugador(jugadores, i);
	}
	
	for (i = 0; i < 3; i++)
	{
		MostrarJugador(jugadores[i], i);
	}
	
	system("pause");
	return 0;
}
