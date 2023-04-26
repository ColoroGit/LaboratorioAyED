#include <iostream>
#include <string>

using namespace std;

int GetFactorial(int n, int res)
{
	if (n == 0)
	{
		return res;
	}
	
	res *= n;
	n--;
	res = GetFactorial(n, res);
}

int main()
{
	int num;
	cout << "Ingrese el numero al que desea calcularle su factoria: ";
	cin >> num;
	
	cout << "El factorial de " << num << " es " << GetFactorial(num, 1);
	
	return 0;
}
