#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(string s)
{
	if (s.length() <= 1)
	{
		return true;
	}
	
	int a = 0;
	int b = s.length() - 1;
	
	while (s[a] == ' ')
	{
		a++;
	}
	
	while (s[b] == ' ')
	{
		b--;
	}
	
	if (s[a] != s[b])
	{
		return false;
	}
	
	return IsPalindrome(s.substr(a + 1, b - a - 1));	
}

int main()
{
	string s;
	
	cout << "Ingrese la palabra o frase que quiere comprobar si es palindromo o no: ";
	getline(cin, s);
	
	if (IsPalindrome(s))
	{
		cout << s << " es palindromo" << endl;
	}
	else
	{
		cout << s << " no es palindromo" << endl;
	}
	
	return 0;
}
