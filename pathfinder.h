char scan[4];
int solo_s[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int portaperto[30][2];


int scanear(int y,int x)
{
    //esquerda
    mvinch(y,x-1);
    scan[0] = inch();
    
    //cima
    mvinch(y+1,x);
    scan[1] = inch();
    
    //direita
    mvinch(y,x+1);
    scan[2] = inch();
    
    //baixo
    mvinch(y+1,x);
    scan[3] = inch();
}

char arredores(int qual)
{
    int cont = 0,var,contporta=0;
    for(int y = unidadey(qual)-7;y < unidadey(qual)-7;y++)
    {
        for(int x = unidadex(qual)-7;x < unidadex(qual)-7;x++)
        {
            mvinch(y,x);
            var = inch();
            if(var == '@')
            {
                cont++;
                return('S');
            }
            if(var == '?')
            {
                portaperto[contporta][0]=y;
                portaperto[contporta][1]=x;
                contporta++;
            }
            
        }
    }
    if(cont == 0)
    {
        return('N');
        
    }
}


int gerarpath(int qual)
{
    scanear(unidadey(qual),unidadex(qual));
    char perto = arredores(qual);
  if(perto == 'S'||scan[0]=='0'||scan[1]=='0'||scan[2]=='0'||scan[3]=='0')
  {
    if(scan[0]=='?'||scan[1]=='?'||scan[2]=='?'||scan[3]=='?')
    {
                abrir_cs(unidadey(qual),unidadex(qual));
                mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
    }
    
    if(unidadey(qual)<unidadey(0)&&unidadex(qual)>unidadex(0))
    {
        
        if(scan[3]== ' '||scan[3]== '0')
        {
     
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[0]== ' '||scan[0]== '0')
            {
                
                        
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[2]== ' '||scan[2]== '0')
                {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {
                        
                    
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                        
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)<unidadey(0)&&unidadex(qual)<unidadex(0))
    {
    
        if(scan[3]== ' '||scan[3]== '0')
        {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                 
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {
                            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {
        
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);;
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>unidadey(0)&&unidadex(qual)>unidadex(0))
    {
        if(scan[1]== ' '||scan[1]== '0')
        {
                
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);;
        }
        else
        {
            if(scan[0]== ' '||scan[0]== '0')
            {
            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[2]== ' '||scan[2]== '0')
                {
                     
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[3]== ' '||scan[3]== '0')
                    {
                            
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>unidadey(0)&&unidadex(qual)<unidadex(0))
    {
        if(scan[1]== ' '||scan[1]== '0')
        {

                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);;
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                 
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {
                            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[3]== ' '||scan[3]== '0')
                    {
                            
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    else if(unidadey(qual)<unidadey(0)&&unidadex(qual)==unidadex(0))
    {
        if(scan[3]== ' '||scan[3]== '0')
        {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                   
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {

                        
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {

                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>unidadey(0)&&unidadex(qual)==unidadex(0))
    {
        if(scan[1]== ' '||scan[1]== '0')
        {

                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {
                        
                        mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                        solo_s[qual] = scan[0];
                        moveleft(qual);
                        mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[3]== ' '||scan[3]== '0')
                    {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)==unidadey(0)&&unidadex(qual)>unidadex(0))
    {
        if(scan[0]== ' '||scan[0]== '0')
        {
                        
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[3]== ' '||scan[3]== '0')
                {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {
                 
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)==unidadey(0)&&unidadex(qual)<unidadex(0))
    {
        if(scan[2]== ' '||scan[2]== '0')
        {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[1]== ' '||scan[1]== '0')
            {
                 
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[3]== ' '||scan[3]== '0')
                {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[0]== ' '||scan[1]== '0')
                    {
            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  else
  {
    if(scan[0]=='?'||scan[1]=='?'||scan[2]=='?'||scan[3]=='?')
    {
                abrir_cs(unidadey(qual),unidadex(qual));
                for(int i= 0;i<30;i++)
                {
                    portaperto[i][0]=0;
                    portaperto[i][0]=0;
                }
                mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
    }
    //portasd(qual);
    int p_sel[2];
    for(int i = 0;i<30;i++)
        {
          
          if(unidadey(qual)<portaperto[i][0]&&unidadex(qual)>portaperto[i][1])
          {
            p_sel[0] = portaperto[i][0];
            p_sel[1] = portaperto[i][1];
          }
          else if(unidadey(qual)<portaperto[i][0])
          {
            p_sel[0] = portaperto[i][0];
            p_sel[1] = portaperto[i][1];
          }
        }
        
    
    if(unidadey(qual)<p_sel[0]&&unidadex(qual)>p_sel[1])
    {
        
        if(scan[3]== ' '||scan[3]== '0')
        {
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[0]== ' '||scan[0]== '0')
            {
                
                        
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[2]== ' '||scan[2]== '0')
                {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {
                        
                    
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                        
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)<p_sel[0]&&unidadex(qual)<p_sel[1])
    {
    
        if(scan[3]== ' '||scan[3]== '0')
        {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                 
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {
                            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {
        
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);;
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>p_sel[1]&&unidadex(qual)>p_sel[1])
    {
        if(scan[1]== ' '||scan[1]== '0')
        {
                
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);;
        }
        else
        {
            if(scan[0]== ' '||scan[0]== '0')
            {
            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[2]== ' '||scan[2]== '0')
                {
                     
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[3]== ' '||scan[3]== '0')
                    {
                            
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>p_sel[0]&&unidadex(qual)<p_sel[1])
    {
        if(scan[1]== ' '||scan[1]== '0')
        {

                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);;
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                 
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {
                            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[3]== ' '||scan[3]== '0')
                    {
                            
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    else if(unidadey(qual)<p_sel[0]&&unidadex(qual)==p_sel[1])
    {
        if(scan[3]== ' '||scan[3]== '0')
        {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                   
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {

                        
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {

                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>p_sel[0]&&unidadex(qual)==p_sel[1])
    {
        if(scan[1]== ' '||scan[1]== '0')
        {

                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[0]== ' '||scan[0]== '0')
                {
                        
                        mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                        solo_s[qual] = scan[0];
                        moveleft(qual);
                        mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[3]== ' '||scan[3]== '0')
                    {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)==p_sel[0]&&unidadex(qual)>p_sel[1])
    {
        if(scan[0]== ' '||scan[0]== '0')
        {
                        
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[2]== ' '||scan[2]== '0')
            {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[3]== ' '||scan[3]== '0')
                {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[1]== ' '||scan[1]== '0')
                    {
                 
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)==p_sel[0]&&unidadex(qual)<p_sel[1])
    {
        if(scan[2]== ' '||scan[2]== '0')
        {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
        }
        else
        {
            if(scan[1]== ' '||scan[1]== '0')
            {
                 
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
            }
            else
            {
                if(scan[3]== ' '||scan[3]== '0')
                {
                    
                    mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                }
                else
                {
                    if(scan[0]== ' '||scan[1]== '0')
                    {
            
            mvaddch(unidadey(qual),unidadex(qual),solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            mvaddch(unidadey(qual),unidadex(qual),'W');
                return(0);
                    }
                }
            }
        }
    }
  }
}
