/**************************************************
* Project: Sette e mezzo
* Version: 0.1.0
* Author: Pasquale Fetto & Mariano Iscaro
* Last modified: 07/02/2021
***************************************************/

/*dichiarazione librerie*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include <string.h>


/*dichiarazione variabili esterne*/
float budget=5; //budget del primo utente
float budget1=5; //budget del secondo utente
float punt1=0; //punteggio del primo utente
float punt2=0; //punteggio del secondo utente
float p=0; //puntata del giocatore 1
int f=0; //contatore nel quale salvo le volte che è uscito il jolly	
char nome[20]; //nome del giocatore
char nome1[20]; //nome del giocatore

/*record*/
struct data
{
	int giorno;
	int mese;
	int anno;
};
		
struct uomo 
{
	char nome[20];
	char cognome[20];
	struct data nascita;
};


/*dichiarazione funzioni*/
void versione (void);
void identita (struct uomo *);
void presentazione_1 (void);
void presentazione_2 (void);
void giochiamo (void);
void ng (void); //ascii art per non giocare
void ci_vediamo (void); //ascii art per non giocare numero 2
void decisione (struct uomo *); //si decide chi da carte 
void puntata (void); 	 //chiediamo all'utente di inserire una puntata
void dammi_la_carta (void);
void scelta (float*);
void s_m (void);
float jolly (void);	
void punteggio1 (void); //punteggio dell'utente 1
void tac (void); //ricordiamo all'utente il nostro punteggio
void dammi_la_carta1 (void);  
void scelta1 (float*); 
void tac1 (void);
void punteggio (void);
void winner (void); //vediamo chi ha vinto
void haivinto (void); //ascii art hai vinto 


int main(int argc, char *argv[]) 
{
	struct uomo giocatore[2];
	int mariano=0; 
	versione(); //versione del gioco
	printf("\n");
	presentazione_1(); //schermata iniziale
	printf("\n");
	presentazione_2(); //decidi se giocare o meno
	printf ("\n");
	identita(&giocatore); //chiedo all'utente di inserire qualche informazione personale
	printf("\n");
	decisione(&giocatore);
	printf("\n");
	do
	{
		puntata();
		printf("\n");
		printf("Adesso comincia il gioco.\n");
		printf("Il mazziere da le carte.");
		printf("\nE' il turno di %s",nome);
		dammi_la_carta();
		printf("\n");
		if(punt1>7.5)
		{
		  printf("Hai sforato!\n");
		  winner();
		  printf("%s il tuo budget e' %.2f.",nome,budget);
		  printf("\n%s il tuo budget e' %.2f.",nome1,budget1);
		  
		  if(budget<=0)
		{
			printf("Mi dispiace %s ma hai finito i soldi.\n",nome);
			ci_vediamo();
			exit(0);
		}
		else if(budget1<=0)
		{
			printf("Mi dispiace %s ma hai finito i soldi.\n",nome1);
			ci_vediamo();
			exit(0);		
		}
		}
		
	    else
		{
		tac(); //ricordiamo all'utente1 il suo punteggio
		printf("\n");
		printf("Adesso tocca a %s",nome1);
		dammi_la_carta1();
		printf("\n");
		tac1();
		printf("\n");
		winner();
		printf("\n");
		printf("%s il tuo budget e' %.2f.",nome,budget);
		printf("\n%s il tuo budget e' %.2f.",nome1,budget1);
		printf("\n");
		if(budget<=0)
		{
			printf("Mi dispiace %s ma hai finito i soldi.\n",nome);
			ci_vediamo();
			exit(0);
		}
		else if(budget1<=0)
		{
			printf("Mi dispiace %s ma hai finito i soldi.\n",nome1);
			ci_vediamo();
			exit(0);		
		}
	    }
	    
		printf("Vuoi fare un'altra partita?\n");
		printf("Digita <<1>> se vuoi giocare, altrimenti digita qualsiasi altro numero.\n");
		scanf("%d",&mariano);
	}while(mariano==1 && budget>0 || budget1>0);
	printf("\n");
	ci_vediamo();
	return 0;
}
	void versione (void)
	{
		printf("/**************************************************/");
		printf("\n");
		printf("Project: Sette e mezzo\n");
		printf("Version: 0.1.0\n");
		printf("Author: Pasquale Fetto & Mariano Iscaro\n");
		printf("Last modified:10/1/2021\n");
		printf("***************************************************/");
	}
	
	void presentazione_1 (void)
	{
	    printf("\t _______ _______ __    _ __   __ _______ __    _ __   __ _______ _______ __ \n");
		printf("\t|  _    |       |  |  | |  | |  |       |  |  | |  | |  |       |       |  |\n");
		printf("\t| |_|   |    ___|   |_| |  |_|  |    ___|   |_| |  | |  |_     _|   _   |  |\n");
		printf("\t|       |   |___|       |       |   |___|       |  |_|  | |   | |  | |  |  |\n");
		printf("\t|  _   ||    ___|  _    |       |    ___|  _    |       | |   | |  |_|  |__|\n");
		printf("\t| |_|   |   |___| | |   ||     ||   |___| | |   |       | |   | |       |__ \n");
		printf("\t|_______|_______|_|  |__| |___| |_______|_|  |__|_______| |___| |_______|__|\n");
		printf("\n");
		printf("Questo e' il gioco del sette e mezzo --- Avete a disposizione 5 euro di budget.\n");
		printf("\n");
		printf("In questa versione del gioco,una volta terminato il budget per effettuare le puntate ,non e' possibile effettuare una ricarica.\n");
		printf("\n");
		printf("Prossimamente Fisca rilascera' una versione completa e aggiornata del gioco.\n");
		printf("\n");
		printf("Giocate senza esagerare! --- Buon divertimento.\n");
	}
	
	void presentazione_2 (void)
	{
		char risposta[20];
		char affermativo[]="si";
		int risultato=-1;
		do
		{
			printf("Sei pronto per giocare a sette e mezzo?\n");
			printf("Digita <<si>> per iniziare oppure <<no>> per uscire\n");
			gets(risposta);
			strlwr(risposta); //in minuscolo
			risultato=strcmp(affermativo, risposta);
			if(risultato == 0)
			{
				printf("Allora iniziamo a giocare!\n");
				printf("\n");
				giochiamo();
				sleep(5);
				system("cls");
			}
			else
			{	
				printf("\n");
				ng();
				printf("\n");
				printf("Alla prossima!\n");
				ci_vediamo();
				sleep(2);
				exit(0);	
			}
	  	}while(risultato!=0);
	}
		
	void giochiamo (void)
	{
		printf("\t             ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦             \n");
		printf("\t        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦        \n");
		printf("\t      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦      \n");
		printf("\t    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦    \n");
		printf("\t   ¦¦¦¦¦¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   \n");
		printf("\t  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦           ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  \n");
		printf("\t  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                ¦¦¦¦¦¦¦¦¦¦¦¦¦  \n");
		printf("\t  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                ¦¦¦¦¦¦¦¦¦¦¦¦¦  \n");
		printf("\t  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦           ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  \n");
		printf("\t   ¦¦¦¦¦¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   \n");
		printf("\t    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦    \n");
		printf("\t      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦      \n");
		printf("\t        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦        \n");
		printf("\t             ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦             \n");
	}
		
		void ng (void)
	{
		printf("\t _______ __   __    __    _ _______ ______  \n"); 
		printf("\t|       |  | |  |  |  |  | |       |      | \n");
		printf("\t|   _   |  |_|  |  |   |_| |   _   |___   | \n"); 
		printf("\t|  |_|  |       |  |       |  | |  | __|  | \n");
		printf("\t|       |       |  |  _    |  |_|  ||_____| \n");
		printf("\t|   _   |   _   |  | | |   |       |  __    \n");
		printf("\t|__| |__|__| |__|  |_|  |__|_______| |__|   \n");

	}
		
	void ci_vediamo (void)
	{
			printf("\t _______ ______   ______   ___ __   __ _______ ______  _______ ______   _______ ___ __ \n");
			printf("\t|       |    _ | |    _ | |   |  | |  |       |      ||       |    _ | |       |   |  |\n");
			printf("\t|   _   |   | || |   | || |   |  |_|  |    ___|  _    |    ___|   | || |       |   |  |\n");
			printf("\t|  |_|  |   |_||_|   |_||_|   |       |   |___| | |   |   |___|   |_||_|      _|   |  |\n");
			printf("\t|       |    __  |    __  |   |       |    ___| |_|   |    ___|    __  |     | |   |__|\n");
			printf("\t|   _   |   |  | |   |  | |   ||     ||   |___|       |   |___|   |  | |     |_|   |__ \n");
			printf("\t|__| |__|___|  |_|___|  |_|___| |___| |_______|______||_______|___|  |_|_______|___|__|\n");
	}
	
	
		
	
	void identita (struct uomo *giocatore)
	{
		int i=0;
		{
			for(i=0;i<2;i++)
			{
				printf("\nCiao utente numero %d\n",i+1);
				printf("Inserisci il tuo nome:");
				gets(giocatore[i].nome);
				printf("Inserisci il tuo cognome:");
				gets(giocatore[i].cognome);
				printf("Inserisci la tua data di nascita\n");
				printf("Giorno:");
				scanf("%d",&giocatore[i].nascita.giorno);
				printf("Mese:");
				scanf("%s",&giocatore[i].nascita.mese);
				printf("Anno:");
				scanf("%d",&giocatore[i].nascita.anno);
				fflush(stdin);
			}
		}
	}	 
	
	void decisione (struct uomo *giocatore)
	{
		srand(time(NULL));
		int i=0;
		int s;
		int punteggio; //testa o croce
		printf("\n\nAdesso si decide chi da carte.");
		printf("Chi vince inizia, chi perde da le carte.\n");
		printf("%s testa o croce?",giocatore[0].nome);
		do
		{
			printf("\nPremi 0 per scegliere testa --- Premi 1 per scegliere croce.\n");
			scanf("%d",&s);
		}while(s != 0 && s != 1);
		
		if(s==0)
		{
			printf("%s ha scelto testa",giocatore[0].nome);
			printf("\n%s per te  e' croce.",giocatore[1].nome);
		}
		else
		{
			printf("%s ha scelto croce",giocatore[0].nome);
			printf("\n%s per te e' testa",giocatore[1].nome);
		}
		punteggio=rand()%2; //0 testa, 1 croce
		switch(punteggio)
		{
			case 0:
			if(s==0)
			{
				printf("\nE' uscito testa\n");
				printf("\n%s inizi tu",giocatore[0].nome);
				strcpy(nome, giocatore[0].nome);
				strcpy(nome1, giocatore[1].nome);
			}
			else
			{
				printf("\nE'uscito testa\n");
				printf("\n%s inizi tu",giocatore[1].nome);
				strcpy(nome, giocatore[1].nome);
				strcpy(nome1, giocatore[0].nome);
			}
			break;
			case 1:
			if(s==1)
			{
				printf("\nE' uscito croce\n");
				printf("\n%s inizi tu",giocatore[0].nome);
				strcpy(nome, giocatore[0].nome);
				strcpy(nome1, giocatore[1].nome);
			}
			else
			{
				printf("\nE'uscito croce\n");
				printf("\n%s inizi tu",giocatore[1].nome);
				strcpy(nome, giocatore[1].nome);
				strcpy(nome1, giocatore[0].nome);
			}
			break;
		}
	}
		
	void puntata (void)
	{
		do
		{ 
			printf("%s inserisci la tua puntata,tra 0.50 centesimi e 5 euro\n",nome);
			scanf("%f",&p);
			if(p>budget)
			{
				printf("La puntata massima e' di 5 euro\n");
			}
			if(p<0.50)
			{
				printf("La puntata minima e' di 0.50 euro\n");;
			}
		}while(p>budget || p<0.50);
		
	}	
	
		
	void dammi_la_carta (void)
	{
		srand(time(NULL));
		float roger[]={0,1,2,3,4,5,6,7,8,9,10}; //possibili carte
		int x; //indice causale che decide quale carta viene generata
		static float punteggio=0;	
		float *punt;
		punt=&punteggio;	
		x=rand()%11;
		printf("\nEcco la tua carta:%.2f\n",roger[x]); 
		if(roger[x]>7)
		{
			printf("Ricordati che le carte 8,9,10 valgono 0.5\n");
			roger[x]=(float)1/2;
		}
		if(roger[x]==0)
		{
			f++;
			if(f==1)
			{
				printf("E' uscito il jolly.\n");
				roger[x]=jolly();
			}
			else
			{
				dammi_la_carta();
			}
		}
		punteggio=punteggio+roger[x];
		printf("Il punteggio vale: %.2f\n",punteggio);
		punt1=punteggio;
		if(punteggio==7.5)
		{
			punteggio=0;
			printf("Hai fatto sette e mezzo\n");
			s_m();
			sleep(2);
			system("cls");
			return 0;
		}
		if(punteggio<7.5)
		{
			scelta(punt); //scelta di un'altra carta;
		}

		{
			punteggio=0;
		}
	}
	
	void s_m (void)
	{
		 printf("\t _______      _______ __ \n");
		 printf("\t|       |    |       |  |\n");
		 printf("\t|___    |    |   ____|  |\n");
		 printf("\t    |   |    |  |____|  |\n");
		 printf("\t    |   |___ |_____  |__|\n");
		 printf("\t    |   |   | _____| |__ \n");
		 printf("\t    |___|___||_______|__|\n");
	}
	
	float jolly (void)
	{
		float z;
		do
		{
			printf("Hai avuto una gran fortuna\n");
			printf("Adesso scegli che valore assegnare al jolly\n");
			scanf("%f",&z);
		}while(z>7.5);
		return z;
	}
		
	void scelta (float *x)
	{
		int pasquale;
	 	printf("Vuoi un'altra carta?\n");
	 	printf("Premi il tasto <<1>> per ricevere un'altra carta,altrimenti premi qualunque altro tasto\n");
		scanf("%d",&pasquale);
		if(pasquale==1)
		{
		 	dammi_la_carta();
		 	return;
		}
		else
		{
			printf("Sto bene cosi',grazie");
			*x=0;
			sleep(2);
			system("cls"); 
		}
	}
		
	void tac (void)
	{
		versione();
		punteggio1();
		printf("\n");	
		sleep(5);
	}
		
	void punteggio1 (void)
	{
		printf("\n");
		printf("Il punteggio di %s vale:%.2f\n",nome,punt1);
	}
	
	void dammi_la_carta1 (void)
	{
		srand(time(NULL));
		float roger[]={0,1,2,3,4,5,6,7,8,9,10}; //possibili carte
		int x; //indice causale che decide quale carta viene generata
		static float punteggio1=0;	
		float *punt;
		punt=&punteggio1;
		x=rand()%11;
		printf("\nEcco la tua carta:%.2f\n",roger[x]); 
		if(roger[x]>7)
		{
			printf("Ricordati che le carte 8,9,10 valgono 0.5\n");
			roger[x]=(float)1/2;
		}
		if(roger[x]==0)
		{
			f++;
			if(f==1)
			{
				printf("E' uscito il jolly.\n");
				roger[x]=jolly();
			}
			else
			{
				dammi_la_carta1();
			}
		}
		punteggio1=punteggio1+roger[x];
		printf("Il punteggio vale: %.2f\n",punteggio1);
		punt2=punteggio1;
		if(punteggio1==7.5)
		{
			printf("Hai fatto sette e mezzo\n");
			s_m();
			sleep(2);
			punteggio1=0;
		}
		if(punteggio1<7.5)
		{
			scelta1(punt); //scelta di un'altra carta;
		}
		if(punteggio1>7.5)
		{
			punteggio1=0;
		}
	}
	
	void scelta1 (float *x)
	{
		int pasquale;
	 	printf("Vuoi un'altra carta?\n");
	 	printf("Premi il tasto <<1>> per ricevere un'altra carta,altrimenti premi qualunque altro tasto\n");
		scanf("%d",&pasquale);
		if(pasquale==1)
		{
		 	dammi_la_carta1();
		 	return;
		}
		else
		{
			printf("Sto bene cosi',grazie");
			*x=0;
			sleep(2);
			system("cls"); 
		}
	}
		
	void tac1 (void)
	{
		versione();
		printf("\n");
		punteggio2();	
		sleep(5);
	}
	
	void punteggio2 (void)
	{
		printf("Il punteggio di %s vale:%.2f\n",nome1,punt2);
	}
	
	void winner (void)
	{
		if(punt1>7.5)
		{
			printf("Il vincitore e':%s", nome1);
			budget=budget-p;
			budget1=budget1+p;
			void haivinto (void)
			{
				printf("\t  __   __ _______ ___    __   __ ___ __    _ _______ _______ __ \n"); 
				printf("\t |  | |  |       |   |  |  | |  |   |  |  | |       |       |  |\n");
				printf("\t |  |_|  |   _   |   |  |  |_|  |   |   |_| |_     _|   _   |  |\n");
				printf("\t |       |  |_|  |   |  |       |   |       | |   | |  | |  |  |\n");
				printf("\t |       |       |   |  |       |   |  _    | |   | |  |_|  |__|\n");
				printf("\t |   _   |   _   |   |   |     ||   | | |   | |   | |       |__ \n");
				printf("\t |__| |__|__| |__|___|    |___| |___|_|  |__| |___| |_______|__|\n");

			}
		}
		else if(punt2>7.5)
		{
			printf("\nIl vincitore e':%s",nome);
			budget=budget+p;
			budget1=budget1-p;
			void haivinto (void)
			{
				printf("\t  __   __ _______ ___    __   __ ___ __    _ _______ _______ __ \n"); 
				printf("\t |  | |  |       |   |  |  | |  |   |  |  | |       |       |  |\n");
				printf("\t |  |_|  |   _   |   |  |  |_|  |   |   |_| |_     _|   _   |  |\n");
				printf("\t |       |  |_|  |   |  |       |   |       | |   | |  | |  |  |\n");
				printf("\t |       |       |   |  |       |   |  _    | |   | |  |_|  |__|\n");
				printf("\t |   _   |   _   |   |   |     ||   | | |   | |   | |       |__ \n");
				printf("\t |__| |__|__| |__|___|    |___| |___|_|  |__| |___| |_______|__|\n");

			}
		}
		else if(punt1>punt2)
		{
			printf("Il vincitore e':%s", nome);
			budget=budget+p;
			budget1=budget1-p;
			void haivinto (void)
			{
				printf("\t  __   __ _______ ___    __   __ ___ __    _ _______ _______ __ \n"); 
				printf("\t |  | |  |       |   |  |  | |  |   |  |  | |       |       |  |\n");
				printf("\t |  |_|  |   _   |   |  |  |_|  |   |   |_| |_     _|   _   |  |\n");
				printf("\t |       |  |_|  |   |  |       |   |       | |   | |  | |  |  |\n");
				printf("\t |       |       |   |  |       |   |  _    | |   | |  |_|  |__|\n");
				printf("\t |   _   |   _   |   |   |     ||   | | |   | |   | |       |__ \n");
				printf("\t |__| |__|__| |__|___|    |___| |___|_|  |__| |___| |_______|__|\n");

			}
		}
		else if (punt1<punt2)
		{
			printf("\nIl vincitore e':%s",nome1);
			budget=budget-p;
			budget1=budget1+p;
			void haivinto (void)
			{
				printf("\t  __   __ _______ ___    __   __ ___ __    _ _______ _______ __ \n"); 
				printf("\t |  | |  |       |   |  |  | |  |   |  |  | |       |       |  |\n");
				printf("\t |  |_|  |   _   |   |  |  |_|  |   |   |_| |_     _|   _   |  |\n");
				printf("\t |       |  |_|  |   |  |       |   |       | |   | |  | |  |  |\n");
				printf("\t |       |       |   |  |       |   |  _    | |   | |  |_|  |__|\n");
				printf("\t |   _   |   _   |   |   |     ||   | | |   | |   | |       |__ \n");
				printf("\t |__| |__|__| |__|___|    |___| |___|_|  |__| |___| |_______|__|\n");

			}
		}
		else if (punt1==punt2)
		{
			printf("\nE' finita in parita'");
			void haivinto (void)
			{
				printf("\t  __   __ _______ ___    __   __ ___ __    _ _______ _______ __ \n"); 
				printf("\t |  | |  |       |   |  |  | |  |   |  |  | |       |       |  |\n");
				printf("\t |  |_|  |   _   |   |  |  |_|  |   |   |_| |_     _|   _   |  |\n");
				printf("\t |       |  |_|  |   |  |       |   |       | |   | |  | |  |  |\n");
				printf("\t |       |       |   |  |       |   |  _    | |   | |  |_|  |__|\n");
				printf("\t |   _   |   _   |   |   |     ||   | | |   | |   | |       |__ \n");
				printf("\t |__| |__|__| |__|___|    |___| |___|_|  |__| |___| |_______|__|\n");

			}
		}
	}
