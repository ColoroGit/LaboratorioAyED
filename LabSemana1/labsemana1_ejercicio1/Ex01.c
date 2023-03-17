#include <stdio.h>

int main()
{
	int entero1 = 0;
	int entero2 = 0;
	int res = 0;
	char caracter = ' ';
	char string[100];
	int i = 0;
	float num1 = 0;
	float num2 = 0;
	float decimal = 0;
	
	//Enteros (int)
	printf("Ingrese un numero entero por teclado: ");
	scanf("%d", &entero1);
	
	printf("Ingrese otro numero entero para sumarselo al anterior: ");
	scanf("%d", &entero2);
	
	res = entero1 + entero2;
	
	printf("El resultado de la suma de los numeros entregados es %d", res);
	
	//Caracteres (char)
	printf("\n\nIngrese una sola letra por teclado: ");
	scanf(" %c", &caracter);
	
	printf("Ahora ingrese una palabra que comience con la letra que ingreso, pero escriba la palabra sin incluir dicha letra\nEjemplo: ingreso la letra <H> anteriormente y quiere escribir la palabra <Hola>, \npor lo tanto deberia escribir <ola>: ");
	scanf("%s", string);
	
	for(i = 98; i >= 0; i--)
	{
		string[i + 1] = string[i];
	}
	
	string[0] = caracter;
	
	printf("Su palabra es %s", string);
	
	//Flotantes o Decimales (float)
	printf("\n\nIngrese un numero para ser dividido: ");
	scanf("%f", &num1);
	
	printf("Ingrese por cuanto quiere dividir este numero: ");
	scanf("%f", &num2);
	
	decimal = num1/num2;
	
	printf("El resultado de la division es %f", decimal);
	
	return 0;
}
