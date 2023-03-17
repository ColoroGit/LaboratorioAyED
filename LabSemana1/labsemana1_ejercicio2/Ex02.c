#include <stdio.h>

int main()
{
	int num = 0;
	int sum = 12; //Puede modificar estos números si lo desea
	int mult = 5;
	int rest = 9;
	int mod = 2;
	
	printf("Ingrese un numero entero para que pase por la maquina aritmetica: ");
	scanf("%d", &num);
	
	num += sum;
	
	printf("\nPrimero, a su numero se le sumo %d, y por lo tanto ahora es un %d", sum, num);
	
	num *= mult;
	
	printf("\n\nSegundo, su numero fue multiplicado por %d y ahora es un %d", mult, num);
	
	num -= rest; 
	
	printf("\n\nAhora a su numero se le resto %d, y ahora es un %d", rest, num);
	
	num = num%mod;
	
	printf("\n\nY por ultimo, le sacamos el resto a su numero, \nresultante entre la division de este con %d, dando como resultado un %d", mod, num);
	
	
	return 0;
}
