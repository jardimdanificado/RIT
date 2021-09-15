#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int INIMIGOS[5][2];
int contador_i = 0;
int PERSONAGEM[2];
char SOLO_S_INIMIGO[2] = {
  '_',
  '_'
};
int vida_personagem = 100;
int vida_inimigos[5] = {100,100,100,100,100};

void ATACAR(int posiy, int posix)
{
  int dano = rand()%30;
  for (int i = 0; i < 5; i ++)
	{
			if(INIMIGOS[i][0] == posiy && INIMIGOS[i][1] == posix)
			{
				vida_inimigos[i] = vida_inimigos[i] - dano;
		  }
	}


}

void MORTE_INIMIGO(int posiy,int posix,int SOLO_SALVO)
{
 mvinch(posiy,posix);
 inch();
 int seila = inch();
 for (int i = 0; i < 6; i ++)
	{
	  
	  /*  if(seila == '@')
	    {
	      if(membros[i][z] <20)
		  	{
				mvaddch(posiy,posix,SOLO_SALVO);
		    }
	    }*/
			if(vida_inimigos[i] <20)
			{
				mvaddch(posiy,posix,SOLO_S_INIMIGO[i]);
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

//GERA E DEFINE UM INIMIGOS
void GERAR_INIMIGO(int *MEM_XY, int leitura) 
{
  int roleta = (rand() % (15- 8+ 1)) + 8;
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

void INIMIGO_MOVE(int quem) {

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
