#include <iostream>
#include <string>

using namespace std;

void PrintStringnInt(int n, string s)
{
    cout << "N\xA3mero ingresado: " << n << endl;
    cout << "Palabra ingresada: " << s << endl;
}

int main()
{
    int num;
    string word;

    cout << "Ingrese un n\xA3mero entero: ";
    cin >> num;
    cout << "Ahora ingrese una palabra: ";
    cin >> word;

    PrintStringnInt(num, word);

    return 0;
}
