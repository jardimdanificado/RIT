#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include "gerar.c"
#include "save.c"
#include "portas_e_utils.c"
#include "unidades.c"


int posix = 0,posiy = 0;
int tecla;
int *MEM_XY;
int *MEM_POSI;
char leitura;
char SOLO_SALVO = '_';
char ITEM[5] = {'0','0','0','0','0'};
//int ITEM_CONTADOR = 0;
//int ITEM_ATUAL = 0;

void Teclado()
{
        mvprintw(posiy, posix,"@");
        move(posiy, posix) ;
        tecla = getch();

        switch(tecla)
        {
//--------------------------------------------------------------------------------
// TECLAS
//-------------------------------------------------------------------------------
                case KEY_RIGHT:
                {
                	mvinch(posiy,posix+1);
                	leitura = inch();
                    if( posix >= MEM_XY[1]-1 && posiy <= MEM_XY[0]-1 && leitura != '#'&&leitura != '?'&&leitura != 'W')
                    {
                            mvaddch (posiy,posix,SOLO_SALVO);
                            posix = 0;
                            mvinch(posiy,posix);
                        	inch();
                        	SOLO_SALVO = inch() ;
                  	}
                	else
                    {	
                    	if (leitura == '?')
                		{
                			ABRIR_PORTA(posiy,posix,tecla);
                		}
                		
                        if(posix < MEM_XY[1]-1&& leitura != '#'&&leitura != '?'&&leitura != 'W')
                        {
                        	mvaddch (posiy,posix,SOLO_SALVO);
                        	posix = posix + 1;
                        	mvinch(posiy,posix);
                        	inch();
                        	SOLO_SALVO = inch();
                    	}
                    	if(leitura == 'W')
                    	{
                    	    ATACAR(posiy,posix+1);
                    	    MORTE_INIMIGO();
                    	}
                    }
                move(posiy,posix);
                refresh();
                }
                break;

                case KEY_UP:
                {
                	mvinch(posiy-1,posix);
                	leitura = inch();
                	if (leitura == '?')
                	{
			        ABRIR_PORTA(posiy,posix,tecla);
                	}
                    if(posiy >= 1&& leitura != '#'&& leitura != '?'&&leitura != 'W')
                    {
                        mvaddch (posiy,posix,SOLO_SALVO);
                        posiy = posiy - 1;
                        mvinch(posiy,posix);
                        inch();
                        SOLO_SALVO = inch();
                    }
                    if(leitura == 'W')
                   	{
                    	ATACAR(posiy-1,posix);
                    	MORTE_INIMIGO();
                    }
                    move(posiy,posix);
                    refresh();
                }
                break;

                case KEY_LEFT:
                {
                	mvinch(posiy,posix-1);
                	leitura = inch();
                	if(leitura == 'W')
                    {
                    	    ATACAR(posiy,posix-1);
                    	     MORTE_INIMIGO();
                   	}
                	if (leitura == '?')
                	{
                		ABRIR_PORTA(posiy,posix,tecla);
                	}
                    if (posix != 0||posiy!=0&& leitura != '#'&&leitura != '?'&&leitura != 'W')
                    {
                        if( posix < 1&& leitura != '#')
                        {
                            	mvaddch (posiy,posix,SOLO_SALVO);
                            	posix = MEM_XY[1] -1;
                            	mvinch(posiy,posix);
                        		inch();
                        		SOLO_SALVO = inch() ;
                        }

                        else{
                            if(posix>0&& leitura != '#'&&leitura != '?'&&leitura != 'W')
                            {
                            	mvaddch (posiy,posix,SOLO_SALVO);
                            	posix = posix - 1;
                            	mvinch(posiy,posix);
                       		 	inch();
                        		SOLO_SALVO = inch() ;
                            }
                            
                        }
                    move(posiy,posix);
                    }
                    refresh();
                }
                break;

                case KEY_DOWN:
                {
                	mvinch(posiy+1,posix);
                	leitura = inch();
                	
                	
                	if(leitura == 'W')
                    	{
                    	    ATACAR(posiy+1,posix);
                    	    MORTE_INIMIGO();
                    	}
                    	
                    	
                	if (leitura == '?')
                	{
                		ABRIR_PORTA(posiy,posix,tecla);
                	}
                	
                	
                    if (posiy < MEM_XY[0]-1&& leitura != '#'&&leitura != '?'&&leitura != 'W')
                    {
                    	mvaddch (posiy,posix,SOLO_SALVO);
                    	posiy = posiy+1;
                    	mvinch(posiy,posix);
                    	inch();
                    	SOLO_SALVO = inch();
                    }
                    move(posiy,posix);
                    refresh();
                }
                break;
                
//------------------------------------------------------------------------------------------
//NUMEROS------
//-----------------------------------------------------------------------------------------
                case '1':
                {
                  if(ITEM[0]!='0')
                  {
                    ITEM[0] = DROPAR_ITEM(posiy,posix,ITEM[0]);
                    /*if(ITEM[0] == '0')
                    {
                        ITEM_CONTADOR--;
                    }*/
                  }
                }
                case '2':
                {
                  if(ITEM[1]!='0')
                  {
                    ITEM[1] = DROPAR_ITEM(posiy,posix,ITEM[1]);
                  /*  if(ITEM[1] == '0')
                    {
                        ITEM_CONTADOR--;
                    }*/
                  }
                }
                case '3':
                {
                  if(ITEM[2]!='0')
                  {
                    ITEM[2] = DROPAR_ITEM(posiy,posix,ITEM[2]);
                    /*if(ITEM[2] == '0')
                    {
                        ITEM_CONTADOR--;
                    }*/
                  }
                }
                case '4':
                {
                  if(ITEM[3]!='0')
                  {
                    ITEM[3] = DROPAR_ITEM(posiy,posix,ITEM[3]);
                   /* if(ITEM[3] == '0')
                    {
                        ITEM_CONTADOR--;
                    }*/
                  }
                }
                case '5':
                {
                  if(ITEM[4]!='0')
                  {
                    ITEM[4] = DROPAR_ITEM(posiy,posix,ITEM[4]);
                    /*if(ITEM[4] == '0')
                    {
                        ITEM_CONTADOR--;
                    }*/
                  }
                }


//----------------------------------------------------------------------------------
//              FUNÇOES
//-----------------------------------------------------------------------------------
                case  's':
                {
                    save(leitura,MEM_XY);
                }
                break;
                
                case 'c':
                {
                    
                   FECHAR_PORTA(posiy,posix,tecla);
                }
                break;
                
                 case 'g':
                {
                   for (int i = 0; i < 5; i ++)
                   {
                       if(ITEM[i] == '0')
                       {
                         ITEM[i] = PEGAR_ITEM(posiy,posix,tecla);
                         i = 6;
                       }
                   }
                   
                }
                break;
        }
	}


// MAIN

int main()
{
    int RES_Y,RES_X,RANDOM_Q;
    leitura = inch();
    MEM_XY = (int *) malloc(2 * sizeof(int));
    MEM_POSI = (int *) malloc(2 * sizeof(int));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    raw();
    curs_set(0);
    getmaxyx(stdscr,MEM_XY[0], MEM_XY[1]);
    resizeterm(MEM_XY[0], MEM_XY[1]);
    RES_X = MEM_XY[1];
    RES_Y = MEM_XY[0];
    //PRINTA A GRAMA
    
    //GERAR_GRAMA(MEM_XY);
    
    // RODA O SCRIPT DE GERAR O MAPA
    GERAR_MAPA(MEM_XY[0],MEM_XY[1],posiy,posix,MEM_XY);
    RANDOM_Q = retornar_randomq();
    
    
    int N_PISOS = CONTAR_CHAO(MEM_XY);
    GERAR_ITEM(MEM_XY,leitura,'/',N_PISOS);
    GERAR_ITEM(MEM_XY,leitura,'T',N_PISOS);
    
    srand((clock()));
    
    int portasy[50];
    int portasx[50];
    int random = 0;
    while(random <5)
    {
        random = rand()%15;
    }
    
    //-----------------------------------
    //gabiarra p pegar info do outro arquivo
    //--------------------------------------
    
    
    for (int i = 0; i < random; i++)
    {
          GERAR_INIMIGO(MEM_XY, leitura);
    }
    
    //------------------------
   // GERAR_INIMIGO(MEM_XY, leitura);
   // GERAR_INIMIGO(MEM_XY, leitura);
   
   //POSICIONA PERSONAGEM E ENUMERA AS PORTAS(ALEM DE DISTRIBUIR E ALOCAR) 
   	int perso = 0;
   	int num_porta = 0;
    for(int y = 0;y<MEM_XY[0];y++)
        {
        	for(int x = 0;x<MEM_XY[1];x++)
       	  {
            mvinch(y,x);
            inch();
            leitura = inch();
            if(leitura == '_'&&perso == 0)
            {
            	posiy = y;
            	posix = x;
            	move(y,x);
				perso++;
            }
            else
            {
            	if(leitura == '?')
            	{
            		DEFINIR_PORTA(y,x,num_porta);
            		num_porta++;
            	}
            }
            
    	   }
    	}

        for (int i = 0; i < 50; i ++)
        {
            portasy[i] = get_portay(i);
        }
        
        for (int i = 0; i < 50; i ++)
        {
            portasx[i] = get_portax(i);
        }
        int estados[50];
         for (int i = 0; i < 50; i ++)
        {
            estados[i] = get_estado(i);
        }
        
        
        
        
        PLEASE_PORTAS(portasy,portasx,estados);
        
	// LOOP DO TECLADO/jogo

    while(tecla != 'q')
    {
        mvprintw(posiy, posix,"@");
        move(posiy, posix);
        DEFINIR_PERSONAGEM(posiy,posix);
        
        
        for (int i = 0; i < 15; i++)
        {
           //simples(i);
           DECISAO(i);
        }
        
        
        
        if(MEM_XY[0] != RES_Y||MEM_XY[1] != RES_X)
        {
            getmaxyx(stdscr,MEM_XY[0], MEM_XY[1]);
            resizeterm(MEM_XY[0], MEM_XY[1]);
            RES_Y= MEM_XY[0];
            RES_X= MEM_XY[1];
        }
         
        else
        {
            Teclado();
        }
        MEM_POSI[0] = posix;
        MEM_POSI[1] = posiy;
    }
    free(MEM_XY);
    free(MEM_POSI);
    MEM_POSI= NULL;
    MEM_XY = NULL;
    endwin();
}
