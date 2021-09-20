#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>


#include "gerar.h"
#include "portas.h"
#include "unidades.h"
#include "pathfinder.h"
#include "teclado.h"


#define SETAS_DO_TECLADO tecla==KEY_DOWN||tecla==KEY_LEFT||tecla==KEY_RIGHT||tecla==KEY_UP


int main() 
{
    //definir memoria dinamica
    int *yxmax;    
    yxmax = (int *)malloc(2*sizeof(int));
    
    //iniciar ncurses e definir algumas coisas do cenario
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    raw();
    curs_set(0);
    
    //pegar tamanho maximo do terminal e redimensionar p ele
    getmaxyx(stdscr,yxmax[0],yxmax[1]);
    resizeterm(yxmax[0],yxmax[1]);
    
    //iniciar variaveis geral
    int tecla = '0';
    char mapa[yxmax[0]*yxmax[1]];
    
    
    //chamar gerar_mapa autoexplicativo
    gerar_grama(yxmax);
    GERAR_MAPA(yxmax);
    definir_portas(yxmax);
    gerar_personagem(yxmax);
    gerar_inimigo(yxmax);
    
    //ler a tela e definir o mapa[]];
    
    for (int y = 0; y < yxmax[0]; y ++)
    {
        for (int x = 0; x < yxmax[1]; x ++)
        {
            mvinch(y,x);
            inch();
            mapa[x + (x*y)] = inch();
        }
    }
    
    
    
    //loop do teclado
    while(tecla!='q')
    {
        tecla = Teclado(unidadey(0),unidadex(0),mapa);
        for(int i = 1;i<19;i++)
        {
            
            gerarpath(i);
            mvaddch(unidadey(i),unidadex(i),'W');
            refresh();
            //traduzirpath(i);
            /*if(unidadey(i)==0&&unidadex(i)==0)
            {
                i=3123;
            }*/
        }
        refresh();   
    }
    endwin();
    
    free(yxmax);
}
