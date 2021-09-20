

int posi[20][2];
int qualunidade = 0;
#define cusd 4654

//posições
int unidadey(int qual)
{
    return(posi[qual][0]);

}

int unidadex(int qual)
{
    return(posi[qual][1]);

}


//movimentação
int moveup(int qual)
{
    posi[qual][0]--;

}
int movedown(int qual)
{
    posi[qual][0]++;

}
int moveleft(int qual)
{
    posi[qual][1]--;

}
int moveright(int qual)
{
    posi[qual][1]++;

}




//geração
void gerar_personagem(int *yxmax)
{
    for(int q = 0; q<20;q++)
    {
        for(int i = 0;i < 2;i++)
        {
            posi[q][i] = 0;
        }
    }
    char teste;
    for (int y = 0; y < yxmax[0]; y ++)
    {
        for (int x = 0; x < yxmax[1]; x ++)
        {
            mvinch(y,x);
            inch();
            teste =inch();
            
            if (teste == ' ')
            {
                mvprintw(y,x,"@");
                posi[0][0]=y;
                posi[0][1]=x;
                x=5645;
                y=7897;
                qualunidade++;
            }
            
        }
    }

}

void gerar_inimigo(int *yxmax)
{
    int contador = 0;
    char teste;
    srand(mix(clock(), time(NULL), cusd));
    int a = rand()%40;
    
    
    for (int y = 0; y < yxmax[0]; y ++)
    {
        
        for (int x = 0; x < yxmax[1]; x ++)
        {
            
            mvinch(y,x);
            inch();
            teste =inch();
            
            if (teste == ' ')
            {
                
                
                contador++;
                
                if(contador == a&&qualunidade<2)
                {
                    posi[qualunidade][0]=y;
                    posi[qualunidade][1]=x;
                    mvaddch(y,x,'W');
                    qualunidade++;
                    contador=0;
                }
            }
            
        }
    }

}
