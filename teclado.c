#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "save.c"

extern int *MEM_POSI;
extern int *MEM_XY;
extern char leitura;
extern int tecla;

void Teclado()
        mvprintw(MEM_POSI[0], MEM_POSI[1],"@");
        move(MEM_POSI[0], MEM_POSI[1]) ;
        tecla = getch();
		int SOLO_SALVO = '*';
		
        switch(tecla)
        {
                case KEY_RIGHT:
                {
                	mvinch(MEM_POSI[0], MEM_POSI[1]+1);
                	leitura = inch();
                    if( MEM_POSI[1] >= MEM_XY[1]-1 && MEM_POSI[1] <= MEM_XY[0]-1 && leitura != '#')
                        {
                            mvaddch (MEM_POSI[1], MEM_POSI[1],SOLO_SALVO);
                            MEM_POSI[1] = 0;
                            mvinch(MEM_POSI[0], MEM_POSI[1]);
                            inch();
                        	SOLO_SALVO = inch() ;
                  			}
                	else
                    {
                        if(MEM_POSI[1] < MEM_XY[1]-1&& leitura != '#')
                        {
                        	mvaddch (MEM_POSI[0], MEM_POSI[1],SOLO_SALVO);
                        	MEM_POSI[1] = MEM_POSI[1] + 1;
                        	mvinch(MEM_POSI[0], MEM_POSI[1]);
                        	inch();
                        	SOLO_SALVO = inch()  ;
                    		}
                    }
                move(MEM_POSI[0], MEM_POSI[1]);
                refresh();
                }
                break;

                case KEY_UP:
                {
                	mvinch(MEM_POSI[0]-1, MEM_POSI[1]);
                	leitura = inch();
                    if(MEM_POSI[0] >= 1&& leitura != '#')
                    {
                        mvaddch (MEM_POSI[0],MEM_POSI[1],SOLO_SALVO);
                        MEM_POSI[0] = MEM_POSI[0] - 1;
                        mvinch(MEM_POSI[0],MEM_POSI[1]);
                        inch();
                        SOLO_SALVO = inch() ;
                    }
                    move(MEM_POSI[0],MEM_POSI[1]);
                    refresh();
                }
                break;

                case KEY_LEFT:
                {
                	mvinch(MEM_POSI[0],MEM_POSI[1]-1);
                	leitura = inch();
                    if (MEM_POSI[1] != 0||MEM_POSI[0]!=0&& leitura != '#'){
                        if( MEM_POSI[1] < 1&& leitura != '#')
                        {
                            mvaddch (MEM_POSI[0],MEM_POSI[1],SOLO_SALVO);
                            MEM_POSI[1] = MEM_XY[1] -1;
                            mvinch(MEM_POSI[0],MEM_POSI[1]);
                        	inch();
                        	SOLO_SALVO = inch() ;
                        }

                        else{
                            if(MEM_POSI[1]>0&& leitura != '#')
                            {
                            mvaddch (MEM_POSI[0],MEM_POSI[1],SOLO_SALVO);
                            MEM_POSI[1] = MEM_POSI[1] - 1;
                            mvinch(MEM_POSI[0],MEM_POSI[1]);
                       		 	inch();
                        		SOLO_SALVO = inch() ;
                            }
                        }
                    move(MEM_POSI[0],MEM_POSI[0]);
                        }
                    refresh();
                }
                break;

                case KEY_DOWN:
                {
                	mvinch(MEM_POSI[0]+1,MEM_POSI[1]);
                	leitura = inch();
                    if (MEM_POSI[0] < MEM_XY[0]-1&& leitura != '#')
                    {
                    	mvaddch (MEM_POSI[0],MEM_POSI[1],SOLO_SALVO);
                    	MEM_POSI[0] = MEM_POSI[0]+1;
                    	mvinch(MEM_POSI[0],MEM_POSI[1]);
                    	inch();
                    	SOLO_SALVO = inch() ;
                    }
                    move(MEM_POSI[0],MEM_POSI[1]);
                    refresh();
                }
                break;

                case  's':
                {
                    save(leitura,MEM_XY);
                }
                break;
                
        }
	}
