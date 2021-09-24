#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

//----------------------------
// ultimo arquivo que sobrevive do antigo RIT
//-----------------------------------



// mixador pra criar seed, da net
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

//FALANDO EM RANDOM KKKKKKK
//num = (rand() % (upper - lower + 1)) + lower
//CODIGO DA NET, GERA NUMERO ALEATORIO ENTRE LOWER E UPPER





int RANDOM_X=0,RANDOM_H, RANDOM_W, RANDOM_Y =0;
int RANDOM_Q = 0;

int SALA_INICIO[40][2];
int SALA_FIM[40][2];
int SALA_CONTADOR = 0;
int contadola = 0;

void printret(int startrow,int startcol,int height,int width,int maxx)
{
 for(int r=startrow;r<=startrow+height;r++)
 {
  for(int c=startcol;c<=startcol+width;c++)
  {
   move(r,c);
   printw("#");

   if (contadola==0)
   {
    SALA_INICIO[SALA_CONTADOR][0] = startrow;
    SALA_INICIO[SALA_CONTADOR][1] = startcol;
    contadola++;
   }
   SALA_FIM[SALA_CONTADOR][0] = r;
   SALA_FIM[SALA_CONTADOR][1] = c;
   SALA_CONTADOR++;
  }
 }
}



void printretfuro(int startrow,int startcol,int height,int width,int maxx)
{
 for(int r=startrow;r<=startrow+height;r++)
 {
  for(int c=startcol;c<=startcol+width;c++)
  {
   move(r,c);
   printw(" ");
  }
 }
}


void GERARSALAS(int quantas,int maxy,int maxx)
{
    int MAIOR_ALTURA = 0;
    //RANDOM_Y = rand() % 60;
    //int bolean_umavez = 0;
	for (int i = 0; i < quantas; i ++ )
	{
	    RANDOM_W = 0;
	    RANDOM_H = 0;
	    unsigned long cusd = 4654;
	    unsigned long semente = mix(clock(), time(NULL), cusd);

	   // srand (time(NULL));
	    srand (clock());


	    while(RANDOM_H < 4||RANDOM_H> 8)
	    {
	       RANDOM_H = rand() % 8;
	    }

	    srand (semente);


	    while(RANDOM_W < 8||RANDOM_W>10)
	    {
	       RANDOM_W = rand() % 14;
	    }


	    if((RANDOM_X+ RANDOM_W)+10 > maxx)
	    {
	        RANDOM_X = 0;
	        RANDOM_Y = (RANDOM_Y-1) + MAIOR_ALTURA;
	        MAIOR_ALTURA = 0;
	    }
	    else //if(RANDOM_X != 0&& bolean_umavez != 0)
	    {
	      RANDOM_X = RANDOM_X + RANDOM_H;
	    }

	     if((RANDOM_Y+ MAIOR_ALTURA) > maxy)
	    {
            i = quantas+2;
	    }



       // bolean_umavez++;



	    if(RANDOM_H > MAIOR_ALTURA)
	    {
	        MAIOR_ALTURA = RANDOM_H;
	    }

	    printret(RANDOM_Y, RANDOM_X,RANDOM_H,RANDOM_W,maxx);
	    printretfuro(RANDOM_Y+1, RANDOM_X+1,RANDOM_H-2,RANDOM_W-2,maxx);
	}
}

void GERAR_PORTAS(int * MEM_XY)
{
	char l1,l2,l3;

	int CONT = 0;
    for(int x = 0;x<MEM_XY[1];x=x+1)
    {
        int contaP = 0;
        for(int y = 0;y<MEM_XY[0];y++)
       	{
            if(contaP == 0)
            {


            mvinch(y,x);
            inch();
            l2 = inch();

            mvinch(y,x-1);
            inch();
            l1 = inch();

            mvinch(y,x+1);
            inch();
            l3 = inch();

            if(l1 == ' ' && l2 == '#' && l3 == ' ')
            {
            		if(CONT%3 == 0)
            		{
            			move(y+(rand()%1),x);
            			printw("?");
            		}
            		}

                CONT++;

           	}

  		}
  	  }
}

void GERAR_PORTAS_VERTICAL(int * MEM_XY)
{
	char l1,l2,l3;

	int CONT = 0;
    for(int y = 0;y<MEM_XY[0];y++)
    {
        int contaP = 0;
        for(int x = 0;x<MEM_XY[1];x=x+1)
       	{
            if(contaP == 0)
            {


            mvinch(y,x);
            inch();
            l2 = inch();

            mvinch(y-1,x);
            inch();
            l1 = inch();

            mvinch(y+1,x);
            inch();
            l3 = inch();

            if(l1 == ' ' && l2 == '#' && l3 == ' ')
            {
            		if(CONT%6 == 0)
            		{
            			move(y,x);
            			printw("?");
            		}
            		}

                CONT++;

           	}

  		}
  	  }
}

void GERAR_ITEM(int *MEM_XY,int leitura,char ITEM,int N_PISOS)
{

    int roleta = (rand() % (N_PISOS - 8+ 1)) + 8;
	int cronometro =0;

	for(int y = 0;y<MEM_XY[0];y++)
        {
          for(int x = 0;x<MEM_XY[1];x++)
       	  {
            mvinch(y,x);
            inch();
            leitura = inch();
            if(leitura == ' ')
            {
		cronometro++;
		if(cronometro == roleta)
		{
			mvaddch(y,x,ITEM);
			y = MEM_XY[0]+1;
			x = MEM_XY[1]+1;
		}
            }
          }
        }
}

/*void MOVIMENTOINI(int qual)
{
    puxa(qual,SALA_INICIO[qual][0],SALA_INICIO[qual][1],SALA_INICIO[qual][0], SALA_INICIO[qual][1]);
}
*/
void gerar_grama(int *yxmax)
{
    for (int y = 0; y < yxmax[0]; y ++)
    {
        for (int x = 0; x < yxmax[1]; x ++)
        {
               if(x%2==0)
               {
               move(y,x);
               printw(".");
               }
               if(x%2!=0)
               {
               move(y,x);
               printw(",");
               }
        }
    }
}


void GERAR_MAPA(int *yxmax)
{

	srand (clock());
	while(RANDOM_Q < 30||RANDOM_Q > 40)
	    {
	   	    srand (clock());
	        RANDOM_Q = rand()%40;
	    }

	GERARSALAS(RANDOM_Q,yxmax[0],yxmax[1]);
	GERAR_PORTAS_VERTICAL(yxmax);
	GERAR_PORTAS(yxmax);

	//GERAR_CORREDORES(MEM_XY);
}
int retornar_randomq()
{
    int retorno = RANDOM_Q;
    return (retorno);
}


