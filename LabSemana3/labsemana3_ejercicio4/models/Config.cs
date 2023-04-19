namespace LabSemana3.labsemana3_ejercicio4.models
{
    public class Config
    {
        public void Movimientos()
        {
            Console.WriteLine("\n\t***Lista de Movimientos***\n");
            Console.WriteLine("\n (1) Pu\xA4o del dragon: Realiza un golpe basico de pelea, haciendo 10 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRecupera 50 puntos de estamina al ser ejecutado\n");
            Console.WriteLine("\n (2) Latigo Fantasma: Un ataque magico a distancia que roba vida al jugador atacado. \nHace 15 puntos de da\xA4o (mas los puntos de da\xA4o base), \nde los cuales 15 son recuperados en vida propia.\nRequiere 100 puntos de estamina para ser ejecutado\n");
            Console.WriteLine("\n (3) Rafaga Mortal: Lanza un combo de golpes al enemigo seleccionado \nhaciendo 40 puntos de da\xA4o (mas los puntos de da\xA4o base). \nRequiere de 200 puntos de estamina para ser ejecutado\n");
            Console.WriteLine("\n (4) Trueno Llameante: Carga y lanza en el mismo turno un hechizo de trueno, \nque se dispara en forma de llamas mortales, haciendo 50 puntos de da\xA4o \n(mas los puntos de da\xA4o base) al jugador seleccionado \nRequiere de 300 puntos de estamina para ser ejecutado\n");
            Console.WriteLine("\n (5) Golpe Certero: Un solo ataque fisico en un punto critico del contrincante \nhaciendo 80 puntos de da\xA4o (mas los puntos de da\xA4o base) \nal jugador seleccionado. Requiere 500 de estamina para su uso, \nademas de 20 puntos de vida de quien lo ejecuta\n");
            Console.WriteLine("\n (6) Esfera Mortal: Carga durante un turno un poderoso hechizo \nque requiere 500 de estamina para ser realizado. \nAl siguiente turno, lanza esta esfera al jugador seleccionado \nhaciendo 70 puntos de da\xA4o (mas los puntos de da\xA4o base)\n");
            Console.WriteLine("\n (7) Sanacion: Recupera 25 puntos de vida al jugador seleccionado. \nRequiere de 200 puntos de estamina para ser ejecutado.\nEste movimiento es capaz de revivir jugadores \n");
            Console.WriteLine("\n (8) Energizante: Recupera 200 puntos de estamina al jugador seleccionado \nRequiere de 50 puntos de estamina para ser ejecutado.\n");
        }
        public void MostrarDatos(Jugador j)
        {
            System.Console.WriteLine("\n\t*****Jugador " + j.id + "*****\n");
            System.Console.WriteLine("Nombre: " + j.name + "\ndaño: " + j.damage + "\nVelocidad: " + j.speed + "\nVida: " + j.health + "\nEstamina: " + j.stamina + "\nPuntaje: " + j.score);
            System.Console.WriteLine("Movimiento 1: " + j.movimientos[0] + "\nMovimiento 2: " + j.movimientos[1] + "\nMovimiento 3: " + j.movimientos[2]);
        }
        public void AsignarTurnos(List<Jugador> Team1, List<Jugador> Team2, int[] turnos, int teamsize)
        {
            Random r = new Random();
            int[] speedValues = new int[teamsize * 2];
            int i;
            int j;
            int aux1;
            int aux2;

            for (i = 0; i < teamsize * 2; i++)
            {
                if (i < teamsize)
                {
                    speedValues[i] = r.Next(21) + Team1.ElementAt(i).speed;
                    turnos[i] = Team1.ElementAt(i).id;
                }
                else
                {
                    speedValues[i] = r.Next(21) + Team2.ElementAt(i - teamsize).speed;
                    turnos[i] = Team2.ElementAt(i - teamsize).id;
                }
            }

            for (i = 0; i < teamsize * 2; i++)
            {
                for (j = i + 1; j < teamsize * 2; j++)
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

            System.Console.WriteLine("\t***Orden de los turnos***\n");

            for (i = 0; i < teamsize * 2; i++)
            {
                System.Console.WriteLine("Turno " + (i + 1) + ": Jugador " + turnos[i] + " con " + speedValues[i] + " puntos de velocidad");
            }
        }
        public int RealizarMovimiento(List<Jugador> jugadores, Jugador j)
        {
            int op;
            bool done = false;
            
            System.Console.WriteLine("\n\t***Tu turno, " + j.name + "***\n");
            
            if (!j.cargando)
            {
                if (j.movimientos[0] == 1 || j.movimientos[1] == 1 || j.movimientos[2] == 1)
                {
                    Console.WriteLine(" (1) Puño del dragon: Realiza un golpe basico de pelea, haciendo 10 puntos de daño \n(mas los puntos de daño base) al jugador seleccionado \nRecupera 50 puntos de estamina al ser ejecutado\n");
                }
                
                if (j.movimientos[0] == 2 || j.movimientos[1] == 2 || j.movimientos[2] == 2)
                {
                    Console.WriteLine(" (2) Latigo Fantasma: Un ataque magico a distancia que roba vida al jugador atacado. \nHace 15 puntos de daño (mas los puntos de daño base), \nde los cuales 15 son recuperados en vida propia.\nRequiere 100 puntos de estamina para ser ejecutado\n");
                }
                
                if (j.movimientos[0] == 3 || j.movimientos[1] == 3 || j.movimientos[2] == 3)
                {
                    Console.WriteLine(" (3) Rafaga Mortal: Lanza un combo de golpes al enemigo seleccionado \nhaciendo 40 puntos de daño (mas los puntos de daño base). \nRequiere de 200 puntos de estamina para ser ejecutado\n");
                }
                
                if (j.movimientos[0] == 4 || j.movimientos[1] == 4 || j.movimientos[2] == 4)
                {
                    Console.WriteLine(" (4) Trueno Llameante: Carga y lanza en el mismo turno un hechizo de trueno, \nque se dispara en forma de llamas mortales, haciendo 50 puntos de daño \n(mas los puntos de daño base) al jugador seleccionado \nRequiere de 300 puntos de estamina para ser ejecutado\n");
                }
                
                if (j.movimientos[0] == 5 || j.movimientos[1] == 5 || j.movimientos[2] == 5)
                {
                    Console.WriteLine(" (5) Golpe Certero: Un solo ataque fisico en un punto critico del contrincante \nhaciendo 80 puntos de daño (mas los puntos de daño base) \nal jugador seleccionado. Requiere 500 de estamina para su uso, \nademas de 20 puntos de vida de quien lo ejecuta\n");
                }
                
                if (j.movimientos[0] == 6 || j.movimientos[1] == 6 || j.movimientos[2] == 6)
                {
                    Console.WriteLine(" (6) Esfera Mortal: Carga durante un turno un poderoso hechizo \nque requiere 500 de estamina para ser realizado. \nAl siguiente turno, lanza esta esfera al jugador seleccionado \nhaciendo 70 puntos de daño (mas los puntos de daño base)\n");
                }
                
                if (j.movimientos[0] == 7 || j.movimientos[1] == 7 || j.movimientos[2] == 7)
                {
                    Console.WriteLine(" (7) Sanacion: Recupera 25 puntos de vida al jugador seleccionado. \nRequiere de 200 puntos de estamina para ser ejecutado.\nEste movimiento es capaz de revivir jugadores \n");
                }
                
                if (j.movimientos[0] == 8 || j.movimientos[1] == 8 || j.movimientos[2] == 8)
                {
                    Console.WriteLine(" (8) Energizante: Recupera 200 puntos de estamina al jugador seleccionado \nRequiere de 50 puntos de estamina para ser ejecutado.\n");
                }
                
                while (!done)
                {
                    try
                    {
                        Console.WriteLine("\nQue movimiento desea realizar?\n(Elijalo ingresando el numero entre parentesis): ");
                        op = Convert.ToInt32(Console.ReadLine());
                        
                        if(op > 0 && op < 9)
                        {
                            if (op == j.movimientos[0] || op == j.movimientos[1] || op == j.movimientos[2])
                            {
                                switch (op)
                                {	
                                    case 1:
                                    return op;
                                    
                                    case 2:
                                    if (j.stamina - 100 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 100;
                                        return op;
                                    }
                                    break;
                                    
                                    case 3:
                                    if (j.stamina - 200 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 200;
                                        return op;
                                    }
                                    break;
                                    
                                    case 4:
                                    if (j.stamina - 300 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 300;
                                        return op;
                                    }
                                    break;
                                    
                                    case 5:
                                    if (j.stamina - 500 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 500;
                                        return op;
                                    }
                                    break;
                                    
                                    case 6:
                                    if (j.stamina - 500 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 500;
                                        return op;
                                    }
                                    break;
                                    
                                    case 7:
                                    if (j.stamina - 200 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 200;
                                        return op;
                                    }
                                    break;
                                    
                                    case 8:
                                    if (j.stamina - 50 >= 0)
                                    {
                                        jugadores.ElementAt(j.id - 1).stamina -= 50;
                                        return op;
                                    }
                                    break;
                                }
                                
                                Console.WriteLine("No tienes la estamina suficiente para realizar ese movimiento \n(estamina actual: " + j.stamina + ")");
                                Console.WriteLine("Deseas elegir otro movimiento o saltar tu turno?\nIngresa <1> si quieres elegir otro movimiento, \n<0> si quieres saltar tu turno: ");
                                op = Convert.ToInt32(Console.ReadLine());
                                
                                if (op != 1)
                                {
                                    return 0;
                                }
                            }
                            else
                            {
                                Console.WriteLine("Usted no posee ese movimiento, elija uno de los que aparecio en pantalla");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Ese movimiento no existe, por favor ingrese otro");
                        }
                    }
                    catch (System.Exception)
                    {
                        System.Console.WriteLine("Ese valor es invalido, debera realizar este proceso nuevamente");
                    }
                }
            }
            else
            {
                return 6;
            }

            return 0;
        }
        public void CambiarEstadistica(List<Jugador> Jugadores, Jugador j, int tyipe, int teamsize, int mov)
        {
            int k;
            int op;
            bool done = false;
            bool teammate = false;
            
            if (mov == 7 || mov == 8)
            {
                if (j.team == 1)
                {
                    for (k = 0; k < teamsize; k++)
                    {
                        MostrarDatos(Jugadores[k]);
                    }
                }
                else
                {
                    for (k = teamsize; k < teamsize * 2; k++)
                    {
                        MostrarDatos(Jugadores[k]);
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
                    for (k = 0; k < teamsize; k++)
                    {
                        MostrarDatos(Jugadores[k]);
                    }	
                }
                else
                {
                    for (k = teamsize; k < teamsize * 2; k++)
                    {
                        MostrarDatos(Jugadores[k]);
                    }
                }
            }
            else
            {
                Console.WriteLine("\t\tTurno Omitido\n");
                done = true;
            }
            
            while (!done)
            {
                try
                {
                    Console.WriteLine("\nCon que jugador desea aplicar este movimiento? \n(Ingrese el numero de ese jugador): ");
                    op = Convert.ToInt32(Console.ReadLine());
                    
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
                                        Jugadores[op - 1].health += 25;	
                                        Jugadores[j.id - 1].score += 25;
                                        
                                        if (Jugadores[op - 1].health > 100)
                                        {
                                            Jugadores[op - 1].health = 100;
                                        }
                                    }
                                    else
                                    {
                                        Jugadores[op - 1].stamina += 200;
                                        Jugadores[j.id - 1].score += 200;
                                        
                                        if (Jugadores[op - 1].stamina > 500)
                                        {
                                            Jugadores[op - 1].stamina = 500;
                                        }
                                    }
                                    
                                    Console.WriteLine("\n\t\tEstadisticas actualizadas: \n");
                                    MostrarDatos(Jugadores[op - 1]);
                                    done = true;
                                }
                                else
                                {
                                    Console.WriteLine("Opcion invalida, ese no es tu compañero");
                                }
                            }
                            else
                            {
                                if (op > 5)
                                {
                                    if(mov == 7)
                                    {
                                        Jugadores[op - 1].health += 25;
                                        Jugadores[j.id - 1].score += 25;
                                        
                                        if (Jugadores[op - 1].health > 100)
                                        {
                                            Jugadores[op - 1].health = 100;
                                        }
                                    }
                                    else
                                    {
                                        Jugadores[op - 1].stamina += 200;
                                        Jugadores[j.id - 1].score += 200;
                                        
                                        if (Jugadores[op - 1].stamina > 500)
                                        {
                                            Jugadores[op - 1].stamina = 500;
                                        }
                                    }
                                    
                                    Console.WriteLine("\n\t\tEstadisticas actualizadas: \n");
                                    MostrarDatos(Jugadores[op - 1]);
                                    done = true;
                                }
                                else
                                {
                                    Console.WriteLine("Opcion invalida, ese no es tu compañero");
                                }
                            }
                        }
                        else
                        {
                            if (j.team == 1)
                            {
                                if (op > 5)
                                {
                                    if (Jugadores[op - 1].health > 0)
                                    {
                                        switch (mov)
                                        {
                                            case 1:
                                            Jugadores[op - 1].health -= (10 + j.damage);
                                            Jugadores[j.id - 1].score += (10 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].stamina += 50;
                                            Jugadores[j.id - 1].score += 50;
                                            
                                            if (j.stamina > 500)
                                            {
                                                Jugadores[j.id - 1].stamina = 500;
                                            }
                                            
                                            MostrarDatos(Jugadores[j.id - 1]);
                                            break;	
                                            
                                            case 2:
                                            Jugadores[op - 1].health -= (15 + j.damage);
                                            Jugadores[j.id - 1].score += (15 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].health += 15;
                                            Jugadores[j.id - 1].score += 15;
                                            
                                            if (j.health > 100)
                                            {
                                                Jugadores[j.id - 1].health = 100;
                                            }
                                            
                                            MostrarDatos(Jugadores[j.id - 1]);
                                            break;
                                            
                                            case 3:
                                            Jugadores[op - 1].health -= (40 + j.damage);
                                            Jugadores[j.id - 1].score += (40 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            break;
                                            
                                            case 4:
                                            Jugadores[op - 1].health -= (50 + j.damage);
                                            Jugadores[j.id - 1].score += (50 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            break;
                                            
                                            case 5:
                                            Jugadores[op - 1].health -= (80 + j.damage);
                                            Jugadores[j.id - 1].score += (80 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].health -= 20;
                                            
                                            if (j.health < 0)
                                            {
                                                Jugadores[j.id - 1].health = 0;
                                                Console.WriteLine("\n\t***Has muerto***\n");
                                            }
                                            
                                            break;
                                            
                                            case 6:
                                            Jugadores[op - 1].health -= (80 + j.damage);
                                            Jugadores[j.id - 1].score += (80 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].cargando = false;
                                            
                                            break;
                                        }
                                        
                                        Console.WriteLine("\n\t\tEstadisticas actualizadas: \n");
                                        MostrarDatos(Jugadores[op - 1]);
                                        done = true;
                                    }
                                    else
                                    {
                                        Console.WriteLine("Ese jugador ya esta muerto");
                                    }
                                }
                                else
                                {
                                    Console.WriteLine("Opcion invalida, ese no es tu enemigo");
                                }
                            }
                            else
                            {
                                if (op < 6)
                                {
                                    if (Jugadores[op - 1].health > 0)
                                    {
                                        switch (mov)
                                        {
                                            case 1:
                                            Jugadores[op - 1].health -= (10 + j.damage);
                                            Jugadores[j.id - 1].score += (10 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].stamina += 50;
                                            Jugadores[j.id - 1].score += 50;
                                            
                                            if (j.stamina > 500)
                                            {
                                                Jugadores[j.id - 1].stamina = 500;
                                            }
                                            
                                            MostrarDatos(Jugadores[j.id - 1]);
                                            break;	
                                            
                                            case 2:
                                            Jugadores[op - 1].health -= (15 + j.damage);
                                            Jugadores[j.id - 1].score += (15 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].health += 15;
                                            Jugadores[j.id - 1].score += 15;
                                            
                                            if (j.health > 100)
                                            {
                                                Jugadores[j.id - 1].health = 100;
                                            }
                                            
                                            MostrarDatos(Jugadores[j.id - 1]);
                                            break;
                                            
                                            case 3:
                                            Jugadores[op - 1].health -= (40 + j.damage);
                                            Jugadores[j.id - 1].score += (40 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            break;
                                            
                                            case 4:
                                            Jugadores[op - 1].health -= (50 + j.damage);
                                            Jugadores[j.id - 1].score += (50 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            break;
                                            
                                            case 5:
                                            Jugadores[op - 1].health -= (80 + j.damage);
                                            Jugadores[j.id - 1].score += (80 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].health -= 20;
                                            
                                            if (j.health < 0)
                                            {
                                                Jugadores[j.id - 1].health = 0;
                                                Console.WriteLine("\n\t***Has muerto***\n");
                                            }
                                            
                                            break;
                                            
                                            case 6:
                                            Jugadores[op - 1].health -= (80 + j.damage);
                                            Jugadores[j.id - 1].score += (80 + j.damage);
                                            
                                            if (Jugadores[op - 1].health < 0)
                                            {
                                                Jugadores[op - 1].health = 0;
                                                Console.WriteLine("\n\t***Enemigo abatido***\n");
                                            }
                                            
                                            Jugadores[j.id - 1].cargando = false;
                                            
                                            break;
                                        }
                                        
                                        Console.WriteLine("\n\t\tEstadisticas actualizadas: \n");
                                        MostrarDatos(Jugadores[op - 1]);
                                        done = true;
                                    }
                                    else
                                    {
                                        Console.WriteLine("Ese jugador ya esta muerto");
                                    }
                                }
                                else
                                {
                                    Console.WriteLine("Opcion invalida, ese no es tu enemigo");
                                }
                            }
                        }
                    }
                    else
                    {
                        Console.WriteLine("Ese jugador no existe");
                    }
                }
                catch (System.Exception)
                {
                    System.Console.WriteLine("Ese valor es invalido, deberá realizar este proceso nuevamente");
                }
            }
            
            if (!j.cargando && mov == 6)
            {
                Jugadores[j.id - 1].cargando = true;
                Console.WriteLine("\n\t***Cargando Hechizo***\n");
            }
        }
        public int MetaExperienciaAlcanzada(List<Jugador> Team1, List<Jugador> Team2, int teamsize)
        {
            int i;
            int suma = 0;
            
            for (i = 0; i < teamsize; i++)
            {
                suma += Team1[i].score;
            }
            
            if (suma >= 500)
            {
                return 1;
            }
            
            suma = 0;
            
            for (i = 0; i < teamsize; i++)
            {
                suma += Team2[i].score;
            }
            
            if (suma >= 500)
            {
                return 2;
            }

            return 0;
        }
    }
}