#include <iostream>
#include <string>

using namespace std;

int Length(string s/*, int count*/)
{
	/*if (c == NULL || c == "\n")
	{
		return count;
	}*/
	
	return s.length();
}

int main()
{
	string word;
	
	cout << "Ingrese una palabra para contar la cantidad de caracteres que tiene: ";
	cin >> word;
	cout << "La longitud de su palabra es: " << Length(word);
	
	return 0;
}
