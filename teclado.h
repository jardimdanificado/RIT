#include <ncurses.h>



char solo = ' ';

      
int Teclado(int ppy,int ppx,char *mapa)
{      
        int tecla = getch();
        int tela;
        switch(tecla)
        {
        		case 'q':
        		{
        			return(tecla);
        		}
        		break;
        		
                case KEY_UP:
                {
                	
                	mvinch(ppy-1,ppx);
                	inch();
                	tela = inch();
                	
                	if (tela== '?')
                	{
                	    abrir_p(ppy,ppx,tecla);
                	    return(0);
                	}
                	
                	else if(tela == ' '||tela== '0')
                	{
                	mvaddch(ppy,ppx,solo);
                	mvinch(ppy-1,ppx);
                	inch();
                	solo = inch();
                	moveup(0);
                	int y = unidadey(0);
                	int x = unidadex(0);
                	mvaddch(y,x,'@');
                	return(tecla);
                	}
                }
                break;
                
                case KEY_DOWN:
                {
                	
                	mvinch(ppy+1,ppx);
                	inch();
                	tela = inch();
                	if (tela== '?')
                	{
                	    abrir_p(ppy,ppx,tecla);
                	}
                	
                	else if(tela == ' '||tela== '0')
                	{
                	mvaddch(ppy,ppx,solo);
                	mvinch(ppy+1,ppx);
                	inch();
                	solo = inch();
                	movedown(0);
                	int y = unidadey(0);
                	int x = unidadex(0);
                	mvaddch(y,x,'@');
                	return(tecla);
                	}
        		  
                }
                break;
                
                case KEY_RIGHT:
                {
                	
                	mvinch(ppy,ppx+1);
                	inch();
                	tela = inch();
                	if (tela== '?')
                	{
                	    abrir_p(ppy,ppx,tecla);
                	}
                	
                	else if(tela == ' '||tela== '0')
                	{
                	mvaddch(ppy,ppx,solo);
                	mvinch(ppy,ppx+1);
                	inch();
                	solo = inch();
                	moveright(0);
                	int y = unidadey(0);
                	int x = unidadex(0);
                	mvaddch(y,x,'@');
                	return(tecla);
                	}
                }
                break;
                
                case KEY_LEFT:
                {
                	
                	mvinch(ppy,ppx-1);
                	inch();
                	tela = inch();
                	if (tela== '?')
                	{
                	    abrir_p(ppy,ppx,tecla);
                	}
                	
                	else if(tela == ' '||tela== '0')
                	{
                	mvaddch(ppy,ppx,solo);
                	mvinch(ppy,ppx-1);
                	inch();
                	solo = inch();
                	moveleft(0);
                	int y = unidadey(0);
                	int x = unidadex(0);
                	mvaddch(y,x,'@');
                	return(tecla);
                	}

                }
                break;
                
                

                
                
         }
            
}
