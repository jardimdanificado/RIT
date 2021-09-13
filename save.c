#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

FILE * Salvar;

int save(char leitura,int * MEM_XY)
{
        	
  	char DEBUG[(MEM_XY[1]*MEM_XY[0])+(2*MEM_XY[0])];
   
        	
       	 for(int y = 0;y<MEM_XY[0];y++)
       	 {
       	    for(int x = 0;x<MEM_XY[1];x++)
       	  {
            mvinch(y,x);
            inch();
            leitura = inch();
            DEBUG[(y*x)+x] = leitura;
    	  }
    	  strcat(DEBUG,"\n");
    	}
        Salvar = fopen("DEBUG.txt","w");
        fputs(DEBUG, Salvar);
        fclose(Salvar);
        return(0);
}
