using System.Collections.Generic;
using labsemana1_ejercicio7.Ex07.models;

List<Vehiculo> vehiculos = new List<Vehiculo>();
bool selected = false;

vehiculos.Add(new Vehiculo("Ford", "Xion52", 2019, 79, 92));
vehiculos.Add(new Vehiculo("Toyota", "Zakareas300", 2022, 88, 80));
vehiculos.Add(new Vehiculo("Lotus", "ArrowHead7", 2020, 95, 78));

while (!selected)
{
    System.Console.WriteLine("\nElija uno de los vehiculos (ingresando su correspondiente numero) para ver sus especificicaciones: ");

    var i = 1;

    foreach (var item in vehiculos)
    {
        System.Console.Write("Vehiculo " + i + ": " + item.fabricante + "     ");
        i++;
    }

    int op = Convert.ToInt32(Console.ReadLine());
    op--;

    System.Console.WriteLine(vehiculos.ElementAt(op).MostrarDatos());

    System.Console.WriteLine("\nDesea elegir este vehiculo? \n(Ingrese <1> si es asi, si no ingrese <0>): ");
    op = Convert.ToInt32(Console.ReadLine());

    if (op == 1)
    {
        selected = true;
    }
}

System.Console.WriteLine("\nEs hora de correr!\n");
