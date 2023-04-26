#include <iostream>
#include <string>

using namespace std;

int Fibonacci(int pos, int m, int n)
{
	if (pos == 0)
	{
		return n;
	}
	
	int aux = m + n;
	m = n;
	n = aux;
	pos--;
	cout << n << " ";
	n = Fibonacci(pos, m, n);
}

int main()
{
	int pos;
	cout << "Que numero de la secuencia Fibonacci desea obtener" << endl << "(Ingrese el numero de esa posicion, ej: si quiere el numero que esta en la quinta posicion, ingrese el 5): ";
	cin >> pos;
	
	cout << endl << "El numero en la posicion " << pos << " de la secuencia Fibonacci es: " << Fibonacci(pos, 0, 1);
	
	return 0;
}
