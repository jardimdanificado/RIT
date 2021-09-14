#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>


//FALANDO EM RANDOM KKKKKKK 
//num = (rand() % (upper - lower + 1)) + lower
//CODIGO DA NET, GERA NUMERO ALEATORIO ENTRE LOWER E UPPER


int RANDOM_X,RANDOM_H, RANDOM_W, RANDOM_Y;

int var_y = 0, var_x = 0;

void corredor(int startrow,int startcol,int height,int width,int maxx)
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

void printret(int startrow,int startcol,int height,int width,int maxx)
{
 for(int r=startrow;r<=startrow+height;r++)
 {
  for(int c=startcol;c<=startcol+width;c++)
  {
   move(r,c);
   printw("#");
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
   printw("_");
  }
 }
}


void GERARSALAS(int quantas,int maxy,int maxx,int posiy,int posix,int *MEM_POSI)
{
	int apenas1 = 0;
	for (int i = 0; i < quantas; i ++ )
	{
	    RANDOM_W = 0;
	    RANDOM_H = 0;
	   // srand (time(NULL));
	    srand (clock()); 
	    RANDOM_X = 1+(var_x-1);
	    while(RANDOM_Y < 1 )
	    {
	    RANDOM_Y = (rand() % (maxy/2));
	    }
	    srand ((clock())*2);
	    
	    while(RANDOM_H < 3||RANDOM_W < 3)
	    {
	       RANDOM_W = rand() % 16;
	       RANDOM_H = rand() % 14;
	    }
	    var_x = RANDOM_X+ RANDOM_W;
	    
	    printret(RANDOM_Y, RANDOM_X,RANDOM_H,RANDOM_W,maxx);
	    printretfuro(RANDOM_Y+1, RANDOM_X+1,RANDOM_H-2,RANDOM_W-2,maxx);
	    if (apenas1==0)
	    {
	    	MEM_POSI[0] = RANDOM_Y+1;
	    	MEM_POSI[1] = RANDOM_X+1;
	    	apenas1++;
	    }
	   // RANDOM_X = RANDOM_X + 1;
	}
}

void GERAR_PORTAS(int * MEM_XY)
{
	char l1,l2,l3;
	
	int CONT = 0;
    for(int y = 0;y<MEM_XY[0];y=y+2)
    {
        	for(int x = 0;x<MEM_XY[1];x++)
       	{
    		char yps[12];
            mvinch(y,x);
            inch();
            //LADOS E centro
            l2 = inch();
            mvinch(y,x-1);
            inch();
            l1 = inch();
            mvinch(y,x+1);
            inch();
            l3 = inch();
            //Y ESCROTO
            for (int i = 0; i <= 5; i ++ )
            {	
            	
            	mvinch((y-i),x);
            	inch();
            	yps[i] = inch();
            }
            for (int i = 6; i <= 11; i ++ )
            {
            	mvinch((y+i),x);
            	inch();
            	yps[i] = inch();
            }
            if(l1 == '_' && l2 == '#' && l3 == '_')
            {
              //if(x%2 == 0)
             // {
            	if(yps[0] != '0'&&yps[1] != '0'&&yps[2] != '0'&&yps[3] != '0'&&yps[4] != '0'&&yps[5] != '0'&&yps[6] != '0'&&yps[7] != '0'&&yps[8] != '0'&&yps[9] != '0'&&yps[10] != '0'&&yps[11] != '0')
            	{
            		if(CONT%3 == 0)
            		{
            			move(y+1,x);
            			printw("?");
            		}
            		else 
            		{
            			if(CONT%2 == 0)
            			{
            				move(y+(rand()%2),x);
            				printw("?");
            			}
            			else
            			{
            				move(y+(rand()%4),x);
            				printw("?");
            			
            			}
            		}         	
            	}
            CONT++;
             // }
           	}
  		}
   	}	    
}

void GERAR_ARMA(int *MEM_XY,int leitura)
{

        int roleta = (rand() % (15- 8+ 1)) + 8;
	int cronometro =0;
	
	for(int y = 0;y<MEM_XY[0];y++)
        {
          for(int x = 0;x<MEM_XY[1];x++)
       	  {
            mvinch(y,x);
            inch();
            leitura = inch();
            if(leitura == '_')
            {
		cronometro++;
		if(cronometro == roleta)
		{
			mvaddch(y,x,'/');
			y = MEM_XY[0]+1;
			x = MEM_XY[1]+1;
		}
            }
          }
        }
}


void GERAR_MAPA(int maxy,int maxx,int posiy,int posix,int* MEM_XY,int *MEM_POSI)
{
	int RANDOM_Q = 0;
	srand (clock());
	while(RANDOM_Q < 3||RANDOM_Q > 7)
	    {
	   	srand (clock());
	        RANDOM_Q = rand()%10;
	    }
	
	GERARSALAS(RANDOM_Q,maxy,maxx,posiy,posix,MEM_POSI);
	GERAR_PORTAS(MEM_XY);
	
	// RETORNA UMA POSIÇÃO ALEATORIA DENTRO DAS SALAS
	/*int ROLETA;
	
	srand (clock());
	ROLETA = (rand() % (7- 3+ 1)) + 3;
	
	int lowery = POSI_FURO_INICIAL[(2*ROLETA)];
	int uppery = POSI_FURO_FINAL[(2*ROLETA)+1];
	
	int lowerx = POSI_FURO_INICIAL[(2*ROLETA)];
	int upperx = POSI_FURO_FINAL[(2*ROLETA)+1];
	int posicaox,posicaoy;
	posicaoy = (rand() % (uppery - lowery + 1)) + lowery;
	posicaox = (rand() % (upperx - lowerx + 1)) + lowerx;*/
	
}





