#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>


//PORTAS auto explicativo
//PORTA_XY[num_porta][0]=y;
//PORTA_XY[num_porta][1]=x;
//assim sao salva as posicoes
//PORTA_ESTADO[num_porta] varia entre F(echado) e A(berto)
//

int PORTA_XY[10][2];
char PORTA_ESTADO[10];

void DEFINIR_PORTA(int y,int x, int num_porta)
{
	PORTA_XY[num_porta][0]=y;
	PORTA_XY[num_porta][1]=x;
	PORTA_ESTADO[num_porta] = 'F';
}

//ESSA FUNÇÃO RETORNA SE A PORTA ESTA FECHADA OU ABERTA, E SE TIVER ABERTA ABRE.
// O=FECHADA 1=ABERTA
int ABRIR_PORTA(int y, int x,int tecla)
{
	switch(tecla)
	{
		case KEY_DOWN:
		{
		y = y+1;
		}
		break;
	
		case KEY_LEFT:
		{
		x=x-1;
		}
		break;
	
		case KEY_UP:
		{
		y=y-1;
		}
		break;
	
		case KEY_RIGHT:
		{
		x=x+1;
		}
		break;
	}
	
	for (int i = 0; i < 10; i ++)
	{
			if(PORTA_XY[i][0] == y && PORTA_XY[i][1] == x)
			{
				if(PORTA_ESTADO[i]== 'F')
				{
					PORTA_ESTADO[i]= 'A';
					mvaddch(y,x,'0');
					return(1);
					i = 11;
				}
				else
				{
					return(0);
					i = 11;
				}
			}
	}
}

void FECHAR_PORTA(int y, int x,int tecla)
{
        tecla = getch();
        switch(tecla)
	{
		case KEY_DOWN:
		{
		y = y+1;
		}
		break;
	
		case KEY_LEFT:
		{
		x=x-1;
		}
		break;
	
		case KEY_UP:
		{
		y=y-1;
		}
		break;
	
		case KEY_RIGHT:
		{
		x=x+1;
		}
		break;
	}
	
	for (int i = 0; i < 10; i ++)
	{
			if(PORTA_XY[i][0] == y && PORTA_XY[i][1] == x)
			{
				if(PORTA_ESTADO[i]== 'A')
				{
					PORTA_ESTADO[i]= 'F';
					mvaddch(y,x,'?');
					i = 11;
				}
				else
				{
					i = 11;
				}
			}
	}

}

char PEGAR_ITEM(int yc, int xc,int tecla)
{
        tecla = getch();
        switch(tecla)
	{
		case KEY_DOWN:
		{
		yc = yc+1;
		}
		break;
	
		case KEY_LEFT:
		{
		xc=xc-1;
		}
		break;
	
		case KEY_UP:
		{
		yc=yc-1;
		}
		break;
	
		case KEY_RIGHT:
		{
		xc=xc+1;
		}
		break;
	 }
		
		mvinch(yc,xc);
		char ler;
		ler = inch();
		
		if(ler != '_'&&ler != '#'&&ler !='?'&&ler!='0')
		{
        		mvprintw(yc,xc,"_");
        		return(ler);
		}
		else
		{
		        return('0');
		}
}

char DROPAR_ITEM(int yd, int xd,int ITEM)
{
                int ler;
               ler = getch();
               switch(ler)
        	{
       		case KEY_DOWN:
       		{
       		yd = yd+1;
       		}
       		break;
       	
       		case KEY_LEFT:
       		{
       		xd=xd-1;
       		}
       		break;
       	
       		case KEY_UP:
       		{
       		yd=yd-1;
       		}
       		break;

	        case KEY_RIGHT:
	        {
                	xd=xd+1;
	        }
        	break;
       	 }
       	 mvinch(yd,xd);
         ler = inch();

       	 if(ler != '#'||ler != '0'||ler != '?')
         {
                mvaddch(yd,xd,ITEM);
                return('0');
	 }

}

//GERA GRAMA
void GERAR_GRAMA(int *MEM_XY)
{
 for (int y = 0; y < MEM_XY[0]; y ++)
    {
    	for (int i = 0; i < MEM_XY[1]; i ++)
    	{
    		if (i%2 != 0)
    		{
    			move(y,i);
    			printw(".");
    		}
    		else
    		{
    			move(y,i);
    			printw(",");
    		}
    	}
    }	
}


// UNIDADES-------------------------



