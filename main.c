#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ciccio (void);
void maschera (int[4][10],int *,int *);
void scelta();


int main(int argc, char *argv[]) 
{
	printf("Benvenuto\n");
	sleep(2);
	ciccio();
	printf("Hai finito di giocare\n");
	system("PAUSE");
	return 0;
}


void maschera (int q[4][10],int *y,int *x)
{
	q[*y][*x]=60;
}



void ciccio (void)
{
	static int mimmo[4][10]={{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10}};
	int x;
	int y;
	int z;
	int *punt;
	int *punt1;	
	punt=&y;
	punt1=&x;
	srand(time(NULL));
	y=rand()%4;
	x=rand()%10;
	if(mimmo[y][x]==60)
	{
		printf("La carta e' gia' uscita\n");		
	}	
	else
	{
		switch(y)
		{
			case 0:
			printf("Ecco la tua carta:%d di simbolo spade\n",mimmo[y][x]);
			break;
			case 1:
			printf("Ecco la tua carta:%d di simbolo bastoni\n",mimmo[y][x]);
			break;
			case 2:
			printf("Ecco la tua carta:%d di simbolo coppe \n",mimmo[y][x]);
			break;	
			case 3:
			printf("Ecco la tua carta:%d di simbolo denari\n",mimmo[y][x]);			
			break;		
		}
		
			maschera(mimmo,punt,punt1);
			printf("Il valore della tua carta adesso e':%d\n",mimmo[y][x]);
			scelta();
	}
}

void scelta (void)
{
	int s;
	printf("Vuoi un'altra carta?\n");
	scanf("%d",&s);
	if(s==0)
	{
		ciccio();
	}
	else
	{
		printf("Sto bene così.\n");
	}
}


