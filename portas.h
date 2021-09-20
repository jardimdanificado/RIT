
int porta[60][3];

void definir_portas(int *yxmax)
{
    int cont_por = 0;
    char teste;
    for (int y = 0; y < (yxmax[0]-2); y ++)
    {
        for (int x = 0; x < (yxmax[1]-2); x ++)
        {
            mvinch(y,x);
            inch();
            teste =inch();
            
            if (teste == '?')
            {
                porta[cont_por][0] = y;
                porta[cont_por][1] = x;
                porta[cont_por][2] = 'F';
                cont_por++;
            }
            
        }
    }
}

void abrir_p(int y, int x,int tecla)
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
	
    for (int i = 0; i < 45; i ++)
    {
        if(y == porta[i][0]&&x == porta[i][1])
        {
           mvprintw(y,x,"0");
           porta[i][2] = 'F';
        }
    }

}

void abrir_cs(int y,int x)
{
    int scanv[4];
    
    //esquerda
    mvinch(y,x-1);
    scanv[0] = inch();
    
    //cima
    mvinch(y+1,x);
    scanv[1] = inch();
    
    //direita
    mvinch(y,x+1);
    scanv[2] = inch();
    
    //baixo
    mvinch(y+1,x);
    scanv[3] = inch();
    
    for(int i=0;i <4;i++)
    {
        if(scanv[i] == '?')
        {
            switch(i)
	        {
		    case 3:
	       	{
		      y = y+1;
		    }
		    break;
	
		    case 0:
		    {
		    x=x-1;
		    }
		    break;
	
		    case 1:
		    {
		    y=y-1;
		    }
		    break;
	
		    case 2:
		    {
		    x=x+1;
		    }
		    break;
	        }
	        abrir_p(y,x,'h');
        }
        
    
    }

}
