#include <stdio.h>;
#define Max 10

int main()
{
	int op;
	int i;
	int j;
	int hospital[Max][Max] = {0};
	
	/*while (op != -1)
	{
	
		scanf("%d", &op);
	
		printf("%d, %d", (int)(op - 1) / 10, (op - 1) % 10);
	}*/
	
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			printf("%d", hospital[i][j]);
		}
		
		printf("\n");
	}
	
	
	return 0;
}
