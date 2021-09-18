#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int POSI_PORTA[50][2];
int INIMIGOS[15][2];
int contador_i = 0;
int PERSONAGEM[2];
char SOLO_S_INIMIGO[15] = {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'};
int vida_personagem = 100;
int vida_inimigos[15] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
int QNT_CHAO = 0;
int PORTAS_UNI[50][2];
int INICIO_DASALA[15][2],FINAL_DASALA[15][2];
int PORTAS_ESTADO[50];

void PLEASE_PORTAS(int *y,int *x,int *g)
{
    for (int i = 0; i < 50; i ++)
    {
        PORTAS_UNI[i][0] = y[i];
        PORTAS_UNI[i][1] = x[i];
    }
    for (int i = 0; i < 50; i ++)
    {
        PORTAS_ESTADO[i] = g[i];
    }
    

}

int PROCURAR_PORTA_CIMA(int quem)
{
    int contadorlocal =0;
    int lerr;
    //parede de cima
    for (int i = INICIO_DASALA[quem][1];  i <= FINAL_DASALA[quem][1];  i ++)
    {
      mvinch(INICIO_DASALA[quem][0], i);
      inch();
      lerr = inch();
      if(lerr == '?'||lerr == '0')
      {
        POSI_PORTA[quem][0]=INICIO_DASALA[quem][0];
        POSI_PORTA[quem][1]=i;
        contadorlocal++;
      }
    }
    if(contadorlocal != 0)
    {
        return(1);
    }
    else
    {
        return(0);
    }

}

int PROCURAR_PORTA_BAIXO(int quem)
{
    int contadorlocal = 0;
    int lerr;
    //parede de baixo
    for (int i = INICIO_DASALA[quem][1];  i <= FINAL_DASALA[quem][1];  i ++)
    {
      mvinch(FINAL_DASALA[quem][0], i);
      inch();
      lerr = inch();
      if(lerr == '?'||lerr == '0')
      {
        POSI_PORTA[quem][0]=INICIO_DASALA[quem][0];
        POSI_PORTA[quem][1]=i;
        contadorlocal++;
      }
    }
    if(contadorlocal != 0)
    {
        return(1);
    }
    else
    {
        return(0);
    }

}

int PROCURAR_PORTA_D(int quem)
{
    int contadorlocal = 0;
    int lerr;
    //parede dedireita
    for (int i = INICIO_DASALA[quem][0];  i <= FINAL_DASALA[quem][0];  i ++)
    {
      mvinch(i, FINAL_DASALA[quem][1]);
      inch();
      lerr = inch();
      if(lerr == '?'||lerr == '0')
      {
        POSI_PORTA[quem][0]=i;
        POSI_PORTA[quem][1]=FINAL_DASALA[quem][1];
        contadorlocal++;
      }
      
    }
    if(contadorlocal != 0)
    {
        return(1);
    }
    else
    {
        return(0);
    }

}

int PROCURAR_PORTA_E(int quem)
{
int contadorlocal = 0;
int lerr;
    //parede de esquerda
    for (int i = INICIO_DASALA[quem][0];  i <= FINAL_DASALA[quem][0];  i ++)
    {
      mvinch(i, INICIO_DASALA[quem][1]);
      inch();
      lerr = inch();
      if(lerr == '?'||lerr == '0')
      {
        POSI_PORTA[quem][0]=i;
        POSI_PORTA[quem][1]=INICIO_DASALA[quem][1];
        contadorlocal++;
      }
    }
    
    if(contadorlocal != 0)
    {
        return(1);
    }
    else
    {
        return(0);
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
  srand(clock());
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
  
 /* if(SCAN_INIMIGO[1] == '?'||SCAN_INIMIGO[2] == '?'||SCAN_INIMIGO[3] == '?'||SCAN_INIMIGO[4] == '?')
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
    
  }*/
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



//--------------------------------------------------------------------
//******************************************************************
//-----------------------------------------------------------------
int INIMIGO_SCANEIA(int quem)
{
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
  
  //4distancias
  int distancias[4];
  char lerr; 
  int variavel = 0;
  //distancia p cima
  
  for (int i = INIMIGOS[quem][0]; i < INIMIGOS[quem][0]-14; i=i-1)
  {
      mvinch(i, INIMIGOS[quem][1]);
      inch();
      lerr = inch();
      variavel++;
      if(lerr == '#')
      {
        distancias[1] = variavel;
        i = 8500;
      }
      
      
  }
  //p baixo
  variavel = 0;
  for (int i = INIMIGOS[quem][0]; i < INIMIGOS[quem][0]+14; i++)
  {
      mvinch(i, INIMIGOS[quem][1]);
      inch();
      lerr = inch();
      variavel++;
      if(lerr == '#')
      {
        distancias[3] = variavel;
        i = 8500;
      }
  }
  //distancia pesquerda
  variavel = 0;
  for (int i = INIMIGOS[quem][1]; i < INIMIGOS[quem][1]-14; i--)
  {
      mvinch(INIMIGOS[quem][0], i);
      inch();
      lerr = inch();
      variavel++;
      if(lerr == '#')
      {
        distancias[0] = variavel;
        i = 8500;
      }
  }
  //p direita
  variavel = 0;
  for (int i = INIMIGOS[quem][1]; i < INIMIGOS[quem][1]+14; i++)
  {
      mvinch(INIMIGOS[quem][0], i);
      inch();
      lerr = inch();
      variavel++;
      if(lerr == '#')
      {
        distancias[2] = variavel;
        i = 8500;
      }
  }
  INICIO_DASALA[quem][0] = INIMIGOS[quem][0]-distancias[1];
  INICIO_DASALA[quem][1] = INIMIGOS[quem][1]-distancias[0];
  FINAL_DASALA[quem][0] = INIMIGOS[quem][0]+distancias[3];
  FINAL_DASALA[quem][1] = INIMIGOS[quem][1]+distancias[2];
}

unsigned long mixa(unsigned long a, unsigned long b, unsigned long c)
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

int armazena_ultimo = 0;

int ABRIR_PORTA_EN(int y, int x)
{
	
	for (int i = 0; i < 50; i ++)
	{
			if(PORTAS_UNI[i][0] == y && PORTAS_UNI[i][1] == x)
			{
				if(PORTAS_ESTADO[i]== 'F')
				{
					PORTAS_ESTADO[i]= 'A';
					mvaddch(y,x,'0');
					return(1);
					i = 55;
				}
			}
	}
}


int simples(int quem)
{
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
        unsigned long cusd = 4654;
	    unsigned long semente = mixa(clock(), time(NULL), cusd);
        
        int cont = -4;
       
         srand(semente);
         cont = rand()%4;
   if(armazena_ultimo == 0)  
   {
      if(SCAN_INIMIGO[1] == '?'||SCAN_INIMIGO[2] == '?'||SCAN_INIMIGO[3] == '?'||SCAN_INIMIGO[4] == '?')
      {
        if(SCAN_INIMIGO[1] == '?')
        {
        ABRIR_PORTA_EN(INIMIGOS[quem][0], INIMIGOS[quem][1]-1);
        return (0);
        }
        if(SCAN_INIMIGO[2] == '?')
        {
        ABRIR_PORTA_EN(INIMIGOS[quem][0]-1, INIMIGOS[quem][1]);
        return (0);
        }
        if(SCAN_INIMIGO[3] == '?')
        {
        ABRIR_PORTA_EN(INIMIGOS[quem][0], INIMIGOS[quem][1]+1);
        return (0);
        }
        if(SCAN_INIMIGO[4] == '?')
        {
        ABRIR_PORTA_EN(INIMIGOS[quem][0]+1, INIMIGOS[quem][1]);
        return (0);
        }
      }
      
      if(SCAN_INIMIGO[1] == '0'||SCAN_INIMIGO[2] == '0'||SCAN_INIMIGO[3] == '0'||SCAN_INIMIGO[4] == '0')
      {
        if(SCAN_INIMIGO[1] == '0')
        {
        if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') 
                {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
                }
        armazena_ultimo=1;
        }
        if(SCAN_INIMIGO[2] == '0')
        {
        if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') 
                 {
                  mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0]-1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
                 }
        armazena_ultimo = 2;
        }
        if(SCAN_INIMIGO[3] == '0')
        {
        if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') 
           {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
           };
        armazena_ultimo = 3;
        }
        if(SCAN_INIMIGO[4] == '0')
        {
         if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') 
              {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
              }
        armazena_ultimo = 4;
        }
      }
        
        
        
        switch(cont)
        {
            case 0:
            {
                if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') 
                {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
                }
            }
            case 1:
            {
                if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') 
                 {
                  mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0]-1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
                 }
            }
            case 2:
            {   
                if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') 
           {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
           }
            }
            case 3:
            {
                if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') 
              {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
              }
            }
        }
    }
    else
    {
        switch(armazena_ultimo)
        {
          case 1:
            {
                if (SCAN_INIMIGO[1] == '_' || SCAN_INIMIGO[1] == '0') 
                {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]-1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] - 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
                armazena_ultimo = 0;
                }
            }
            case 2:
            {
                if (SCAN_INIMIGO[2] == '_' || SCAN_INIMIGO[2] == '0') 
                 {
                  mvaddch(INIMIGOS[quem][0]-1, INIMIGOS[quem][1], 'W');
                  mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                  INIMIGOS[quem][0] = INIMIGOS[quem][0]-1;
                  SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[2];
                  armazena_ultimo = 0;
                 }
            }
            case 3:
            {   
                if (SCAN_INIMIGO[3] == '_' || SCAN_INIMIGO[3] == '0') 
           {
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1]+1, 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][1] = INIMIGOS[quem][1] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[3];
                armazena_ultimo = 0;
           }
            }
            case 4:
            {
                if (SCAN_INIMIGO[4] == '_' || SCAN_INIMIGO[4] == '0') 
              {
                mvaddch(INIMIGOS[quem][0]+1, INIMIGOS[quem][1], 'W');
                mvaddch(INIMIGOS[quem][0], INIMIGOS[quem][1], SOLO_S_INIMIGO[quem]);
                INIMIGOS[quem][0] = INIMIGOS[quem][0] + 1;
                SOLO_S_INIMIGO[quem] = SCAN_INIMIGO[4];
                armazena_ultimo = 0;
              }
            }
        
        
        }
    }

}

int QUAL_EST(int quem)
{


}


int DECISAO(int quem)
{
    int fator;
  //  INIMIGO_SCANEIA(quem);
    fator = 0;
    int ler2;
    for (int y = INIMIGOS[quem][0]-2; y < INIMIGOS[quem][0]+2; y ++)
    {
       for (int x = INIMIGOS[quem][1]-2; x < INIMIGOS[quem][1]+2; x ++)
        {
            mvinch(y,x);
            inch();
            ler2 = inch();
            if(ler2=='@')
            {
                fator = 1;
            }
        } 
    }
    
    
    if(fator ==1)
    {
        INIMIGO_MOVE(quem);
    }
    else
    {
        simples(quem);
    }
}  
   
