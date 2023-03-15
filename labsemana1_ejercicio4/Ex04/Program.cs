char[ , ] gato = {{'X', 'O', 'X'}, {'O', 'X', 'X'}, {'X', 'O', 'O'}};

//Intento detectar jugadas
/*char[ , ] gato = new char [2, 2];
int turns = 1;

while (turns < 10)
{
    System.Console.WriteLine("Ingrese la fila en la que quiere poner una cruz: ");
}
*/
System.Console.WriteLine(" " + gato[0, 0] + " | " + gato[0, 1] + " | " + gato[0, 2] + " ");
System.Console.WriteLine(" " + gato[1, 0] + " | " + gato[1, 1] + " | " + gato[1, 2] + " ");
System.Console.WriteLine(" " + gato[2, 0] + " | " + gato[2, 1] + " | " + gato[2, 2] + " ");