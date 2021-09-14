#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int INIMIGOS[2][2];
int contador_i = 0;
int PERSONAGEM[2];
char SOLO_S_INIMIGO[2] = {'*', '*'};


int DEFINIR_PERSONAGEM(int  posiy, int posix)
{
        PERSONAGEM[0] = posiy;
        PERSONAGEM[1] = posix;
}

//GERA E DEFINE UM INIMIGOS
void GERAR_INIMIGO(int *MEM_XY,int leitura)
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
            if(leitura == '*')
            {
		cronometro++;
		if(cronometro == roleta)
		{
			mvaddch(y,x,'W');
			INIMIGOS[contador_i][0]= y;
			INIMIGOS[contador_i][1]= x;
			contador_i++;
			y = MEM_XY[0]+1;
			x = MEM_XY[1]+1;
		}
            }
          }
        }
        
}

int INIMIGO_MOVE()
{

        char SCAN_INIMIGO[5];
        
        //centro
        mvinch(INIMIGOS[0][0],INIMIGOS[0][1]);
        inch();
        SCAN_INIMIGO[0] = inch();
        
        //esquerda
        mvinch(INIMIGOS[0][0],INIMIGOS[0][1]-1);
        inch();
        SCAN_INIMIGO[1] = inch();
        
        //cima
        mvinch(INIMIGOS[0][0]-1,INIMIGOS[0][1]);
        inch();
        SCAN_INIMIGO[2] = inch();
        
        //direita
        mvinch(INIMIGOS[0][0],INIMIGOS[0][1]+1);
        inch();
        SCAN_INIMIGO[3] = inch();
        
        //baixo
        mvinch(INIMIGOS[0][0]+1,INIMIGOS[0][1]);
        inch();
        SCAN_INIMIGO[4] = inch();
        
        //POSIY > POSIY
        if(INIMIGOS[0][0] > PERSONAGEM[0])
        {
                if (SCAN_INIMIGO[4]== '*'||SCAN_INIMIGO[4] == '0')
                {
                        mvaddch(INIMIGOS[0][0]+1,INIMIGOS[0][1],'W');
                        mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                        INIMIGOS[0][0] = INIMIGOS[0][0]+1;
                        SOLO_S_INIMIGO[0] = SCAN_INIMIGO[4];
                }
                else
                {
                        //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA ESQUERDA(caso o personagem esteja pra esquerda)
                        
                        if(INIMIGOS[0][1] > PERSONAGEM[1])//POSIX > POSIX
                        {
                                //vai pra esquerda
                              if (SCAN_INIMIGO[1]== '*'||SCAN_INIMIGO[1] == '0')
                                {   
                                   mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]-1,'W');
                                   mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                   INIMIGOS[0][1] = INIMIGOS[0][1] - 1;
                                   SOLO_S_INIMIGO[0] = SCAN_INIMIGO[1];
                                
                                }
                                //vai pra cima
                                else
                                {
                                              if (SCAN_INIMIGO[2]== '*'||SCAN_INIMIGO[2] == '0')
                                              {   
                                                    mvaddch(INIMIGOS[0][0]-1,INIMIGOS[0][1],'W');
                                                    mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                    INIMIGOS[0][0] = INIMIGOS[0][0] - 1;
                                                    SOLO_S_INIMIGO[0] = SCAN_INIMIGO[2];
                                              }
                                              // nao der nada ele tenta ir p direita
                                              else{
                                                    if (SCAN_INIMIGO[3]== '*'||SCAN_INIMIGO[3] == '0')
                                                    {   
                                                       mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]+1,'W');
                                                       mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                       INIMIGOS[0][1] = INIMIGOS[0][1] + 1;
                                                       SOLO_S_INIMIGO[0] = SCAN_INIMIGO[3];
                                                    }
                                              
                                                  }  
                                
                                }
                        }
                        
                        //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA DIRETA(caso o personagem esteja pra DIREITA)
                        else{
                                if(INIMIGOS[0][1] < PERSONAGEM[1])//POSIX < POSIX
                                {
                                         if (SCAN_INIMIGO[3]== '*'||SCAN_INIMIGO[3] == '0')
                                         {   
                                            mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]+1,'W');
                                            mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                            INIMIGOS[0][1] = INIMIGOS[0][1] + 1;
                                            SOLO_S_INIMIGO[0] = SCAN_INIMIGO[3];
                                         }
                                         else
                                         {
                                              if (SCAN_INIMIGO[2]== '*'||SCAN_INIMIGO[2] == '0')
                                              {   
                                                mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]+1,'W');
                                                mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                INIMIGOS[0][0] = INIMIGOS[0][0] - 1;
                                                SOLO_S_INIMIGO[0] = SCAN_INIMIGO[2];
                                              }
                                              else
                                              {
                                                if (SCAN_INIMIGO[1]== '*'||SCAN_INIMIGO[1] == '0')
                                                {   
                                                    mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]-1,'W');
                                                    mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                    INIMIGOS[0][1] = INIMIGOS[0][1] - 1;
                                                    SOLO_S_INIMIGO[0] = SCAN_INIMIGO[1];
                                
                                                }
                                              }        
                                         }
                                }
                            }
                        
                        
                
                }
                
        }
        if(INIMIGOS[0][0] < PERSONAGEM[0])
        {
                if (SCAN_INIMIGO[2]== '*'||SCAN_INIMIGO[2] == '0')
                {
                        mvaddch(INIMIGOS[0][0]-1,INIMIGOS[0][1],'W');
                        mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                        INIMIGOS[0][0] = INIMIGOS[0][0] - 1;
                        SOLO_S_INIMIGO[0] = SCAN_INIMIGO[2];
                }
                else
                {
                        //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA ESQUERDA(caso o personagem esteja pra esquerda)
                        
                        if(INIMIGOS[0][1] > PERSONAGEM[1])//POSIX > POSIX
                        {
                                //vai pra esquerda
                              if (SCAN_INIMIGO[1]== '*'||SCAN_INIMIGO[1] == '0')
                                {   
                                   mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]-1,'W');
                                   mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                   INIMIGOS[0][1] = INIMIGOS[0][1] - 1;
                                   SOLO_S_INIMIGO[0] = SCAN_INIMIGO[1];
                                
                                }
                                //vai pra baixo
                                else
                                {
                                              if (SCAN_INIMIGO[4]== '*'||SCAN_INIMIGO[4] == '0')
                                              {   
                                                    mvaddch(INIMIGOS[0][0]+1,INIMIGOS[0][1],'W');
                                                    mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                    INIMIGOS[0][0] = INIMIGOS[0][0] + 1;
                                                    SOLO_S_INIMIGO[4] = SCAN_INIMIGO[4];
                                              }
                                              
                                              // nao der nada ele tenta ir p direita
                                              else{
                                                    if (SCAN_INIMIGO[3]== '*'||SCAN_INIMIGO[3] == '0')
                                                    {   
                                                       mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]+1,'W');
                                                       mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                       INIMIGOS[0][1] = INIMIGOS[0][1] + 1;
                                                       SOLO_S_INIMIGO[0] = SCAN_INIMIGO[3];
                                                    }
                                              
                                                  }  
                                
                                }
                        }
                        
                        //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA DIRETA(caso o personagem esteja pra DIREITA)
                        else{
                                if(INIMIGOS[0][1] < PERSONAGEM[1])//POSIX < POSIX
                                {
                                         if (SCAN_INIMIGO[3]== '*'||SCAN_INIMIGO[3] == '0')
                                         {   
                                            mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]+1,'W');
                                            mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                            INIMIGOS[0][1] = INIMIGOS[0][1] + 1;
                                            SOLO_S_INIMIGO[0] = SCAN_INIMIGO[3];
                                         }
                                         else
                                         {
                                              if (SCAN_INIMIGO[2]== '*'||SCAN_INIMIGO[2] == '0')
                                              {   
                                                mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]+1,'W');
                                                mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                INIMIGOS[0][0] = INIMIGOS[0][0] - 1;
                                                SOLO_S_INIMIGO[0] = SCAN_INIMIGO[2];
                                              }
                                              else
                                              {
                                                if (SCAN_INIMIGO[1]== '*'||SCAN_INIMIGO[1] == '0')
                                                {   
                                                    mvaddch(INIMIGOS[0][0],INIMIGOS[0][1]-1,'W');
                                                    mvaddch(INIMIGOS[0][0],INIMIGOS[0][1],SOLO_S_INIMIGO[0]);
                                                    INIMIGOS[0][1] = INIMIGOS[0][1] - 1;
                                                    SOLO_S_INIMIGO[0] = SCAN_INIMIGO[1];
                                
                                                }
                                              }        
                                         }
                                }
                            }
                        
                        
                
                }
                
        }
     //   mvaddch(INIMIGOS[0][0],INIMIGOS[0][0]);
    //    INIMIGOS[0][0] = 

}

