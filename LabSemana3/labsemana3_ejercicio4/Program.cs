using System.Collections.Generic;
using LabSemana3.labsemana3_ejercicio4.models;

Random r = new Random();
Config c = new Config();

List<Jugador> Team1 = new List<Jugador>();
List<Jugador> Team2 = new List<Jugador>();

int teamsize = 0;
int cantRondas = 0;
int expParaGanar = 0;

int op = 0;
int i;

//Introduccion al Programa
System.Console.WriteLine("\n\t*****Bienvenido a Castillos Y Ciclopes*****\n");
System.Console.WriteLine("Este es un juego de peleas por turnos que actualmente se encuentra en una fase de desarrollo.\nA continuacion encontraras un generador de personajes basico, el cual te pedira distintos datos. \nEntre ellos un nombre para tu jugador y un daño (un numero entre 0 y 20), \nel resto de caracteristicas seran generadas de forma basica \nexcepto la velocidad, que se define como la cantidad que le falta al daño para llegar a 20\nPor ejemplo, si tu daño es 13, tu velocidad sera 7. \nEl primer dato representa el daño base de los jugadores y se le suma al daño final de los ataques de un jugador. \nMientras que la segunda caracteristica se le suma al numero aleatorio de ordenes, \ny quien tenga una velocidad mas alta jugara antes que el resto.\nTambien cuentas con 100 puntos de vida, 500 puntos de mana (que es el recurso necesario para realizar movimientos),\ny un puntaje, el cual definira que equipo gana al final de la partida.\nFinalmente, el creador te pedira que elijas 3 de los 8 movimientos que hay disponibles.\nAparecera una lista mas adelante con la descripcion de cada movimiento, solo intenta elegir sabiamente...\n");
System.Console.WriteLine("Una vez hayas armado los equipos, comenzara el combate en si. \nSe asignaran aleatoriamente los turnos mediante un dado de 20 caras, sumandole los puntos propios de velocidad.\nY despues, cuando sea el turno de cada jugador, podra elegir que hacer,\nel objetivo siendo vencer a todos tus oponentes (que sus puntos de vida lleguen a 0)\no quien tenga mas puntos de experiencia al acabarse el maximo de turnos\n");

System.Console.WriteLine("\t***Antes de empezar, un par de configuraciones previas***\n");

//Tamaños equipos
bool done = false;
while (!done)
{
    System.Console.WriteLine("Cuantos jugadores tendran los equipos? (ingrese un numero entre 1 y 5): ");
    try
    {
        teamsize = Convert.ToInt32(Console.ReadLine());

        if(teamsize > 0 && teamsize < 5)
        {
            done = true;
        }
        else
        {
            System.Console.WriteLine("Ese valor no es valido, por favor ingrese otro (un numero entre 1 y 5)");
        }
    }
    catch (System.Exception)
    {
        System.Console.WriteLine("Ese valor no es valido, por favor ingrese otro (un numero entero entre 1 y 5)");
    }
}

int[] turnos = new int[teamsize * 2];

//Cantidad de Rondas
done = false;
while (!done)
{
    System.Console.WriteLine("Durante cuantas Rondas desea jugar?: ");
    try
    {
        cantRondas = Convert.ToInt32(Console.ReadLine());

        if(cantRondas > 0)
        {
            done = true;
        }
        else
        {
            System.Console.WriteLine("Ese valor no es valido, por favor ingrese otro (un numero mayor que 0)");
        }
    }
    catch (System.Exception)
    {
        System.Console.WriteLine("Ese valor no es valido, por favor ingrese otro (un numero entero mayor que 0)");
    }
}

//Experiencia necesaria para ganar
done = false;
while (!done)
{
    System.Console.WriteLine("Cuanta experiencia necesita un equipo para ganar? (un valor de a lo menos 500 puntos): ");
    try
    {
        expParaGanar = Convert.ToInt32(Console.ReadLine());

        if(expParaGanar >= 500)
        {
            done = true;
        }
        else
        {
            System.Console.WriteLine("Ese valor no es valido, por favor ingrese otro (de 500 hacia arriba)");
        }
    }
    catch (System.Exception)
    {
        System.Console.WriteLine("Ese valor no es valido, por favor ingrese otro (un numero entero de 500 hacia arriba)");
    }
}

//Creando Team1
System.Console.WriteLine("\n\t***Ahora vamos a crear a los jugadores del equipo 1***\n");

for (i = 1; i <= teamsize; i++)
{
    done = false;
    while (!done)
    {
        System.Console.WriteLine("Desea crear al jugador " + i + " a mano o que se genere automaticamente? \nIngrese <1> si desea hacerlo a mano, de lo contrario ingrese <0>: ");
        try
        {
            op = Convert.ToInt32(Console.ReadLine());

            if (op == 1)
            {
                int[] movs = {0, 0, 0};
                int[] movUsed = {0, 0, 0};
                string name = string.Empty;
                int daño;
                int j = 0;
                bool picked = false;

                System.Console.WriteLine("\n\t***Creando al jugador " + i + "***\n");
                System.Console.WriteLine("Ingrese el nombre de su jugador: ");
                name = Console.ReadLine() ?? "";
                
                System.Console.WriteLine("Ingrese el daño de " + name + " (un numero entre 0 y 20) \n***Recuerde que su velocidad sera calculada en base a su daño \nsiendo la velocidad lo que le falta al daño para llegar a 20 \n(ejemplo, si su daño es 11, su velocidad sera 9)***: ");
                daño = Convert.ToInt32(Console.ReadLine());
                
                while (daño < 0 || daño > 20)
                {
                    System.Console.WriteLine("Ese valor es invalido, porfavor ingrese otro (un número entre 0 y 20): ");
                    daño = Convert.ToInt32(Console.ReadLine());
                }

                c.Movimientos();

                System.Console.WriteLine("A continuacion debera elegir 3 de estos 8 movimientos, \nelijalos ingresando el numero que aparece entre parentesis");

                while (j < 3)
                {
                    switch (j)
                    {
                        case 0: 
                        System.Console.WriteLine("Ingrese su primer movimiento: ");
                        break;
                        
                        case 1:
                        System.Console.WriteLine("Ingrese su segundo movimiento: ");
                        break;
                        
                        case 2:
                        System.Console.WriteLine("Ingrese su ultimo movimiento: ");
                        break;
                    }
                    
                    op = Convert.ToInt32(Console.ReadLine());
                    picked = false;
                    
                    if (op > 0 && op < 9)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (op == movUsed[k])
                            {
                                picked = true;
                                break;
                            }
                        }
                        
                        if (!picked)
                        {
                            movs[j] = op;
                            movUsed[j] = op;
                            j++;
                        }
                        else
                        {
                            System.Console.WriteLine("Ya ha elegido ese movimiento, por favor seleccione otro");
                        }
                    }
                    else
                    {
                        System.Console.WriteLine("Ese movimiento no existe");
                    }
                }

                Team1.Add(new Jugador(name, i, 1, daño, movs[0], movs[1], movs[2]));
                c.MostrarDatos(Team1.ElementAt(i - 1));
                c.Movimientos();
                done = true;
            }
            else if (op == 0)
            {
                System.Console.WriteLine("\n\t***Creando al jugador " + i + "***\n");
                System.Console.WriteLine("Ingrese el nombre del jugador. \nEl resto de estadisticas se asignaran aleatoriamente: ");
                string name = Console.ReadLine() ?? "";
                Team1.Add(new Jugador(name, i, 1));
                c.MostrarDatos(Team1.ElementAt(i - 1));
                c.Movimientos();
                done = true;
            }
            else
            {
                System.Console.WriteLine("Ese valor es invalido, por favor ingrese otro");
            }
        }
        catch (System.Exception)
        {
            System.Console.WriteLine("Ese valor es invalido. \nDebera realizar el proceso de creacion nuevamente, \ntenga cuidado al ingresar datos y lea bien las instrucciones\n");
        }
    }

    done = false;
    while (!done)
    {
        System.Console.WriteLine("\nDesea rehacer al jugador " + i + "? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ");
        try
        {
            op = Convert.ToInt32(Console.ReadLine());
            
            if(op == 1)
            {
                Team1.RemoveAt(i - 1);
                i--;
                done = true;
            }
            else if (op == 0)
            {
                done = true;
            }
            else
            {
                System.Console.WriteLine("Ese valor es invalido, por favor ingrese otro");
            }
        }
        catch (System.Exception)
        {
            System.Console.WriteLine("Ese valor es invalido");
        }
    }
}

foreach (var item in Team1)
{
    c.MostrarDatos(item);
}
c.Movimientos();

//Creando Team2
System.Console.WriteLine("\n\t***Ahora vamos a crear a los jugadores del equipo 2***\n");

for (i = 1; i <= teamsize; i++)
{
    done = false;
    while (!done)
    {
        System.Console.WriteLine("Desea crear al jugador " + (i + teamsize) + " a mano o que se genere automaticamente? \nIngrese <1> si desea hacerlo a mano, de lo contrario ingrese <0>: ");
        try
        {
            op = Convert.ToInt32(Console.ReadLine());

            if (op == 1)
            {
                int[] movs = {0, 0, 0};
                int[] movUsed = {0, 0, 0};
                string name = string.Empty;
                int daño;
                int j = 0;
                bool picked = false;

                System.Console.WriteLine("\n\t***Creando al jugador " + (i + teamsize) + "***\n");
                System.Console.WriteLine("Ingrese el nombre de su jugador: ");
                name = Console.ReadLine() ?? "";
                
                System.Console.WriteLine("Ingrese el daño de " + name + " (un numero entre 0 y 20) \n***Recuerde que su velocidad sera calculada en base a su daño \nsiendo la velocidad lo que le falta al daño para llegar a 20 \n(ejemplo, si su daño es 11, su velocidad sera 9)***: ");
                daño = Convert.ToInt32(Console.ReadLine());
                
                while (daño < 0 || daño > 20)
                {
                    System.Console.WriteLine("Ese valor es invalido, porfavor ingrese otro (un número entre 0 y 20): ");
                    daño = Convert.ToInt32(Console.ReadLine());
                }

                c.Movimientos();

                System.Console.WriteLine("A continuacion debera elegir 3 de estos 8 movimientos, \nelijalos ingresando el numero que aparece entre parentesis");

                while (j < 3)
                {
                    switch (j)
                    {
                        case 0: 
                        System.Console.WriteLine("Ingrese su primer movimiento: ");
                        break;
                        
                        case 1:
                        System.Console.WriteLine("Ingrese su segundo movimiento: ");
                        break;
                        
                        case 2:
                        System.Console.WriteLine("Ingrese su ultimo movimiento: ");
                        break;
                    }
                    
                    op = Convert.ToInt32(Console.ReadLine());
                    picked = false;
                    
                    if (op > 0 && op < 9)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (op == movUsed[k])
                            {
                                picked = true;
                                break;
                            }
                        }
                        
                        if (!picked)
                        {
                            movs[j] = op;
                            movUsed[j] = op;
                            j++;
                        }
                        else
                        {
                            System.Console.WriteLine("Ya ha elegido ese movimiento, por favor seleccione otro");
                        }
                    }
                    else
                    {
                        System.Console.WriteLine("Ese movimiento no existe");
                    }
                }

                Team2.Add(new Jugador(name, i + teamsize, 2, daño, movs[0], movs[1], movs[2]));
                c.MostrarDatos(Team2.ElementAt(i - 1));
                c.Movimientos();
                done = true;
            }
            else if (op == 0)
            {
                System.Console.WriteLine("\n\t***Creando al jugador " + (i + teamsize) + "***\n");
                System.Console.WriteLine("Ingrese el nombre del jugador. \nEl resto de estadisticas se asignaran aleatoriamente: ");
                string name = Console.ReadLine() ?? "";
                Team2.Add(new Jugador(name, i + teamsize, 2));
                c.MostrarDatos(Team2.ElementAt(i - 1));
                c.Movimientos();
                done = true;
            }
            else
            {
                System.Console.WriteLine("Ese valor es invalido, por favor ingrese otro");
            }
        }
        catch (System.Exception)
        {
            System.Console.WriteLine("Ese valor es invalido. \nDebera realizar el proceso de creacion nuevamente, \ntenga cuidado al ingresar datos y lea bien las instrucciones\n");
        }
    }

    done = false;
    while (!done)
    {
        System.Console.WriteLine("\nDesea rehacer al jugador " + (i + teamsize) + "? \nIngrese <1> si es asi, de lo contrario ingrese <0>: ");
        try
        {
            op = Convert.ToInt32(Console.ReadLine());
            
            if(op == 1)
            {
                Team2.RemoveAt(i - 1);
                i--;
                done = true;
            }
            else if (op == 0)
            {
                done = true;
            }
            else
            {
                System.Console.WriteLine("Ese valor es invalido, por favor ingrese otro");
            }
        }
        catch (System.Exception)
        {
            System.Console.WriteLine("Ese valor es invalido");
        }
    }
}

foreach (var item in Team2)
{
    c.MostrarDatos(item);
}
c.Movimientos();

//Asignar turnos
System.Console.WriteLine("\n\n\t***Asignacion de turnos***\n\n");
	
c.AsignarTurnos(Team1, Team2, turnos, teamsize);
	
System.Console.WriteLine("\n\t*****Ahora que esta todo listo, empecemos el combate!!!*****");

//Comienza pelea (bucle dado por rondas)
i = 0;

List<Jugador> Jugadores = new List<Jugador>();

foreach (var item in Team1)
{
    Jugadores.Add(item);
}

foreach (var item in Team2)
{
    Jugadores.Add(item);
}

while (cantRondas > 0 || c.MetaExperienciaAlcanzada(Team1, Team2, teamsize) != 0)
{
    Jugador j = Jugadores.ElementAt(turnos[i] - 1);

    if (j.health > 0)
    {
        c.CambiarEstadistica(Jugadores, j, i, teamsize, c.RealizarMovimiento(Jugadores, j));	
    }
    else
    {
        System.Console.WriteLine("\t***" + j.name + " no puede jugar ya que está muerto***\n");
    }
    
    if (i == (teamsize * 2) - 1)
    {
        cantRondas--;
        i = 0;
    }
    else
    {
        i++;	
    }
}

if (c.MetaExperienciaAlcanzada(Team1, Team2, teamsize) == 1)
{
    Console.WriteLine("\n\t*****Felicidades, ha ganado el Equipo 1*****\n");
}
else
{
    Console.WriteLine("\n\t*****Felicidades, ha ganado el Equipo 2*****\n");
}

System.Console.WriteLine("\t*****Gracias por jugar a Castillos Y Ciclopes*****\n");