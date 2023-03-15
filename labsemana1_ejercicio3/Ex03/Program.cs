using System;
using System.Threading;

int barra = 0;
int time = 0;
int i = 0;
Random r = new Random();

while (i < 20)
{
    Console.Clear();

    barra = r.Next(0, 4);
    time = r.Next(2000);

    i += barra;

    for (var j = 0; j < i; j++)
    {
        System.Console.Write("/");
    }
    
    Thread.Sleep(1000);
}
