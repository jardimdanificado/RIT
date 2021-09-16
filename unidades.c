#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int INIMIGOS[15][2];
int contador_i = 0;
int PERSONAGEM[2];
char SOLO_S_INIMIGO[15] = {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'};
int vida_personagem = 100;
int vida_inimigos[15] = {100,100,100,100,100};
int QNT_CHAO = 0;
int PORTAS_UNI[50][2];
int SALAS_INICIO[40][2];
int SALAS_FINAL[40][2];


void PLEASE_PORTAS(int *y,int *x)
{
    for (int i = 0; i < 50; i ++)
    {
        PORTAS_UNI[i][0] = y[i];
        PORTAS_UNI[i][1] = x[i];
    }
    

}

void PLEASE_SALAS(int* iy,int* ix,int* fy,int* fx)
{
    for (int i = 0; i < 40; i ++)
    {
        SALAS_INICIO[i][0] = iy[i];
        SALAS_INICIO[i][1] = ix[i];
        SALAS_FINAL[i][0] = fy[i];
        SALAS_FINAL[i][1] = fx[i];
    }
    

}
int MENORDISTANCIAX[15], MENORDISTANCIAY[15];

void CALCULAR_PORTA(int quem)
{
     if (PERSONAGEM[0] > INIMIGOS[quem][0])
     {
         if (PERSONAGEM[1] > INIMIGOS[quem][1])
         {
           MENORDISTANCIAX[quem] = 23098382,MENORDISTANCIAY[quem] = 492801242;  
           
            
                for (int i = 0; i < 50; i ++)
                {
                   
                    
                    
                    if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAY[quem]>INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAX[quem]>INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                }
            
            
         }
         if (PERSONAGEM[1] < INIMIGOS[quem][1])
         {
                
         MENORDISTANCIAX[quem] = 23098382,MENORDISTANCIAY[quem] = 492801242;
                for (int i = 0; i < 50; i ++)
                {

                    if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAY[quem]>INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAX[quem]<INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                }
         }
     }
     if (PERSONAGEM[0] < INIMIGOS[quem][0])
     {
         if (PERSONAGEM[1] > INIMIGOS[quem][1])
         {
         MENORDISTANCIAX[quem] = 23098382,MENORDISTANCIAY[quem] = 492801242;
         for (int i = 0; i < 50; i ++)
                {
                 
                    if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAY[quem]<INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAX[quem]>INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                }
         }
         if (PERSONAGEM[1] < INIMIGOS[quem][1])
         {
         
         
             MENORDISTANCIAX[quem] = 23098382,MENORDISTANCIAY[quem] = 492801242;
         
                for (int i = 0; i < 50; i ++)
               {
                    
                    
                    if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAY[quem]<INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else if(MENORDISTANCIAY[quem]>PORTAS_UNI[i][0]&&MENORDISTANCIAX[quem]>PORTAS_UNI[i][1]&&MENORDISTANCIAX[quem]<INIMIGOS[quem][0])
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                    else
                    {
                        MENORDISTANCIAY[quem] = PORTAS_UNI[i][0];
                        MENORDISTANCIAX[quem] = PORTAS_UNI[i][1];
                    }
                }
            
         }
     }
     
     
     
}

void ATACAR(int posiy, int posix)
{
  int dano = rand()%30;
  for (int i = 0; i < 15; i ++)
	{
			if(INIMIGOS[i][0] == posiy && INIMIGOS[i][1] == posix)
			{
				vida_inimigos[i] = vida_inimigos[i] - dano;
		  }
	}


}

void MORTE_INIMIGO()
{
 for (int i = 0; i < 15; i ++)
	{
	
			if(vida_inimigos[i] <20)
			{
				mvaddch(INIMIGOS[i][0],INIMIGOS[i][1],SOLO_S_INIMIGO[i]);
				INIMIGOS[i][0] = -1;
				INIMIGOS[i][1] = -1;
		  }
		 
	}

}


void DEFINIR_PERSONAGEM(int  posiy, int posix) 
{
  PERSONAGEM[0] = posiy;
  PERSONAGEM[1] = posix;
}

int CONTAR_CHAO(int *MEM_XY)
{
 for(int y = 0; y < MEM_XY[0]; y++) 
 {
    for(int x = 0; x < MEM_XY[1]; x++) 
    {
      mvinch(y, x);
      inch();
      int leitur = inch();
      if(leitur == '_')
      {
      QNT_CHAO++;
      
      }
    }
 }

}

//GERA E DEFINE UM INIMIGOS
void GERAR_INIMIGO(int *MEM_XY, int leitura) 
{
  int roleta = (rand() % (QNT_CHAO- 8+ 1)) + 8;
  int cronometro = 0;

  for(int y = 0; y < MEM_XY[0]; y++) {
    for(int x = 0; x < MEM_XY[1]; x++) {
      mvinch(y, x);
      inch();
      leitura = inch();
      if(leitura == '_') {
        cronometro++;
        if(cronometro == roleta) {
          mvaddch(y, x, 'W');
          INIMIGOS[contador_i][0] = y;
          INIMIGOS[contador_i][1] = x;
          contador_i++;
          y = MEM_XY[0]+1;
          x = MEM_XY[1]+1;
        }
      }
    }
  }

}



int INIMIGO_MOVE(int quem) {

  char SCAN_INIMIGO[5];

  //centro
  mvinch(INIMIGOS[quem][0], INIMIGOS[quem][1]);
  inch();
  SCAN_INIMIGO[0] = inch();

  //esquerda
  mvinch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1);
  inch();
  SCAN_INIMIGO[1] = inch();

  //cima
  mvinch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1]);
  inch();
  SCAN_INIMIGO[2] = inch();

  //direita
  mvinch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1);
  inch();
  SCAN_INIMIGO[3] = inch();

  //baixo
  mvinch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1]);
  inch();
  SCAN_INIMIGO[4] = inch();
  
  if(SCAN_INIMIGO[1] == '?'||SCAN_INIMIGO[2] == '?'||SCAN_INIMIGO[3] == '?'||SCAN_INIMIGO[4] == '?')
  {
    if(SCAN_INIMIGO[1] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0], INIMIGOS[quem][1]-1);
        return (0);
    }
    if(SCAN_INIMIGO[2] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0]-1, INIMIGOS[quem][1]);
        return (0);
    }
    if(SCAN_INIMIGO[3] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0], INIMIGOS[quem][1]+1);
        return (0);
    }
    if(SCAN_INIMIGO[4] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0]+1, INIMIGOS[quem][1]);
        return (0);
    }
    
  }
  if(SCAN_INIMIGO[1] == '@'||SCAN_INIMIGO[2] == '@'||SCAN_INIMIGO[3] == '@'||SCAN_INIMIGO[4] == '@')
  {
    if(SCAN_INIMIGO[1] == '@')
    {
        return (0);
    }
    if(SCAN_INIMIGO[2] == '@')
    {
        return (0);
    }
    if(SCAN_INIMIGO[3] == '@')
    {
        return (0);
    }
    if(SCAN_INIMIGO[4] == '@')
    {
        return (0);
    }
    
  }
  //POSIY > POSIY
  if(INIMIGOS[quem][0] < PERSONAGEM[0]) {
    if(INIMIGOS[quem][1] == PERSONAGEM[1]) {
      if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
        mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][0] = INIMIGOS[quem][0]+1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
      }
    }
    else
    {


      if(INIMIGOS[quem][1] > PERSONAGEM[1])//POSIX > POSIX
      {

        if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
          INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
          SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

        }

        else
        {
          if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
              mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
            }
          }

          else {
            if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
              }
            }
            else
            {
              if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
              }
            }



          }

        }
      }

      //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA DIRETA(caso o personagem esteja pra DIREITA)
      else {
        if(INIMIGOS[quem][1] < PERSONAGEM[1])//POSIX < POSIX
        {
          if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
          }
          else
          {
            if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
              }
            }
            else
            {
              if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
                if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                  mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];

                }
              }
              else
              {
                if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];
                }
              }
            }
          }
        }
      }



    }

  }
  if(INIMIGOS[quem][0] > PERSONAGEM[0]) {
    if(INIMIGOS[quem][1] == PERSONAGEM[1]) {
      if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
        if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
          mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
          INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
          SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
        }
      }
    }
    else
    {


      if(INIMIGOS[quem][1] > PERSONAGEM[1])//POSIX > POSIX
      {
        //vai pra esquerda
        if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
          INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
          SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

        }
        //vai pra baixo
        else
        {
          if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
              mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
            }
          }
          else {
            if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
                mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
              }
            }
            else
            {
              if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
              }
            }

          }

        }
      }

      //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA DIRETA(caso o personagem esteja pra DIREITA)
      else {
        if(INIMIGOS[quem][1] < PERSONAGEM[1])//POSIX < POSIX
        {
          if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
          }
          else
          {
            if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
              }
            }
            else
            {
              if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
                if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                  mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];

                }
              }
              else
              {
                if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];
                }
              }
            }
          }
        }
      }
    }
  }


  if(INIMIGOS[quem][0] == PERSONAGEM[0]) {
    if(INIMIGOS[quem][1] > PERSONAGEM[1])//POSIX > POSIX
    {
      //vai pra esquerda
      if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

      }
      //vai pra baixo
      else
      {
        if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
          if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
            mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
          }
        }
        // nao der nada ele tenta ir p direita
        else {
          if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
              mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
            }
          }
          else
          {
            if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
              }
            }
            else
            {
              if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
              }
            }
          }

        }
      }

    }
  }


  else {
    if(INIMIGOS[quem][1] < PERSONAGEM[1])//POSIX < POSIX
    {
      if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
      }
      else
      {
        if(PERSONAGEM[0] < INIMIGOS[quem][0]) {
          if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
            mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
          }
        }
        else
        {
          if(PERSONAGEM[0] > INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
              mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];

            }
          }
          else if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

          }
        }
      }
    }
  }
}


//------------------------------------------------------------------
//******************************************************************
//-------------------------------------------------------------------

int INIMIGO_MOVE_PORTA(int quem) {

  char SCAN_INIMIGO[5];

  //centro
  mvinch(INIMIGOS[quem][0], INIMIGOS[quem][1]);
  inch();
  SCAN_INIMIGO[0] = inch();

  //esquerda
  mvinch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1);
  inch();
  SCAN_INIMIGO[1] = inch();

  //cima
  mvinch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1]);
  inch();
  SCAN_INIMIGO[2] = inch();

  //direita
  mvinch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1);
  inch();
  SCAN_INIMIGO[3] = inch();

  //baixo
  mvinch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1]);
  inch();
  SCAN_INIMIGO[4] = inch();
  
  if(SCAN_INIMIGO[1] == '?'||SCAN_INIMIGO[2] == '?'||SCAN_INIMIGO[3] == '?'||SCAN_INIMIGO[4] == '?')
  {
    if(SCAN_INIMIGO[1] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0], INIMIGOS[quem][1]-1);
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];
        return (0);
    }
    if(SCAN_INIMIGO[2] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0]-1, INIMIGOS[quem][1]);
        mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
        return (0);
    }
    if(SCAN_INIMIGO[3] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0], INIMIGOS[quem][1]+1);
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
        return (0);
    }
    if(SCAN_INIMIGO[4] == '?')
    {
        ABRIR_PORTA_INIMIGO(INIMIGOS[quem][0]+1, INIMIGOS[quem][1]);
        mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][0] = INIMIGOS[quem][0]+1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
        return (0);
      }
    
  }
  //POSIY > POSIY
  if(INIMIGOS[quem][0] < MENORDISTANCIAY[quem]) {
    if(INIMIGOS[quem][1] == MENORDISTANCIAX[quem]) {
      if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
        mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][0] = INIMIGOS[quem][0]+1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
      }
    }
    else
    {


      if(INIMIGOS[quem][1] > MENORDISTANCIAX[quem])//POSIX > POSIX
      {

        if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
          INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
          SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

        }

        else
        {
          if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
              mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
            }
          }

          else {
            if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
              }
            }
            else
            {
              if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
              }
            }



          }

        }
      }

      //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA DIRETA(caso o personagem esteja pra DIREITA)
      else {
        if(INIMIGOS[quem][1] < MENORDISTANCIAX[quem])//POSIX < POSIX
        {
          if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
          }
          else
          {
            if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
              }
            }
            else
            {
              if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
                if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                  mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];

                }
              }
              else
              {
                if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];
                }
              }
            }
          }
        }
      }



    }

  }
  if(INIMIGOS[quem][0] > MENORDISTANCIAY[quem]) {
    if(INIMIGOS[quem][1] == MENORDISTANCIAX[quem]) {
      if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
        if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
          mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
          INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
          SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
        }
      }
    }
    else
    {


      if(INIMIGOS[quem][1] > MENORDISTANCIAX[quem])//POSIX > POSIX
      {
        //vai pra esquerda
        if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
          mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
          INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
          SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

        }
        //vai pra baixo
        else
        {
          if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
              mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
            }
          }
          else {
            if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
                mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
              }
            }
            else
            {
              if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
              }
            }

          }

        }
      }

      //CASO PARA BAIXO ESTEJA BLOAQUEADO, VAI PARA DIRETA(caso o personagem esteja pra DIREITA)
      else {
        if(INIMIGOS[quem][1] < MENORDISTANCIAX[quem])//POSIX < POSIX
        {
          if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
          }
          else
          {
            if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
              }
            }
            else
            {
              if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
                if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                  mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];

                }
              }
              else
              {
                if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];
                }
              }
            }
          }
        }
      }
    }
  }


  if(INIMIGOS[quem][0] == MENORDISTANCIAY[quem]) {
    if(INIMIGOS[quem][1] > MENORDISTANCIAX[quem])//POSIX > POSIX
    {
      //vai pra esquerda
      if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

      }
      //vai pra baixo
      else
      {
        if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
          if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
            mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
          }
        }
        // nao der nada ele tenta ir p direita
        else {
          if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
              mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] - 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
            }
          }
          else
          {
            if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
              if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
              }
            }
            else
            {
              if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
              }
            }
          }

        }
      }

    }
  }


  else {
    if(INIMIGOS[quem][1] < MENORDISTANCIAX[quem])//POSIX < POSIX
    {
      if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') {
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
        mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
        INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
        SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
      }
      else
      {
        if(MENORDISTANCIAY[quem] < INIMIGOS[quem][0]) {
          if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') {
            mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
          }
        }
        else
        {
          if(MENORDISTANCIAY[quem] > INIMIGOS[quem][0]) {
            if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') {
              mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
              mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
              INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
              SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];

            }
          }
          else if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') {
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
            mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
            INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
            SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[1];

          }
        }
      }
    }
  }
}
  
  
  
  
int NAMESMASALA(int quem,int ARMAZEM_INICIOY,int ARMAZEM_INICIOX,int ARMAZEM_FIMY,int ARMAZEM_FIMX)
{
   if(PERSONAGEM[0]>=ARMAZEM_INICIOY&&PERSONAGEM[1]>=ARMAZEM_INICIOX&&PERSONAGEM[0]<=ARMAZEM_FIMY&&PERSONAGEM[1]<=ARMAZEM_FIMX)   
   {
        INIMIGO_MOVE(quem);
   }
   else
   {
       INIMIGO_MOVE_PORTA(quem);
   
   }
}   
