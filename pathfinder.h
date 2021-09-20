char scan[4];
int solo_s[20] = {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'};

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

int gerarpath(int qual)
{
    scanear(unidadey(qual),unidadex(qual));
    
    if(unidadey(qual)<unidadey(0))
    {
        if(scan[3]== '_'||scan[3]== '0')
        {
     
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
        }
        else
        {
            if(scan[0]== '_'||scan[0]== '0')
            {
                
                        int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
            }
            else
            {
                if(scan[2]== '_'||scan[2]== '0')
                {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
                    
                }
                else
                {
                    if(scan[1]== '_'||scan[1]== '0')
                    {
                        
                    int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);
                        
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)<unidadey(0))
    {
        if(scan[3]== '_'||scan[3]== '0')
        {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
        }
        else
        {
            if(scan[2]== '_'||scan[2]== '0')
            {
                 int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
            }
            else
            {
                if(scan[0]== '_'||scan[0]== '0')
                {
                            int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
                }
                else
                {
                    if(scan[1]== '_'||scan[1]== '0')
                    {
        int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);;
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>unidadey(0))
    {
        if(scan[1]== '_'||scan[1]== '0')
        {
                int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);;
        }
        else
        {
            if(scan[0]== '_'||scan[0]== '0')
            {
            int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
            }
            else
            {
                if(scan[2]== '_'||scan[2]== '0')
                {
                     int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
                }
                else
                {
                    if(scan[3]== '_'||scan[3]== '0')
                    {
                            int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>unidadey(0))
    {
        if(scan[1]== '_'||scan[1]== '0')
        {
int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);;
        }
        else
        {
            if(scan[2]== '_'||scan[2]== '0')
            {
                 int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
            }
            else
            {
                if(scan[0]== '_'||scan[0]== '0')
                {
                            int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
                }
                else
                {
                    if(scan[3]== '_'||scan[3]== '0')
                    {
                            int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
                    }
                }
            }
        }
    }
    else if(unidadey(qual)<unidadey(0)||unidadex(qual)==unidadex(0))
    {
        if(scan[3]== '_'||scan[3]== '0')
        {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
        }
        else
        {
            if(scan[2]== '_'||scan[2]== '0')
            {
                   
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
            }
            else
            {
                if(scan[0]== '_'||scan[0]== '0')
                {

                        int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
                }
                else
                {
                    if(scan[1]== '_'||scan[1]== '0')
                    {
int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)>unidadey(0)||unidadex(qual)==unidadex(0))
    {
        if(scan[1]== '_'||scan[1]== '0')
        {
int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);
        }
        else
        {
            if(scan[2]== '_'||scan[2]== '0')
            {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
            }
            else
            {
                if(scan[0]== '_'||scan[0]== '0')
                {
                        int yy,xx;
                        yy = unidadey(qual);
                        xx = unidadex(qual);
                        mvaddch(yy,xx,solo_s[qual]);
                        solo_s[qual] = scan[0];
                        moveleft(qual);
                        return(0);
                }
                else
                {
                    if(scan[3]== '_'||scan[3]== '0')
                    {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)==unidadey(0)||unidadex(qual)>unidadex(0))
    {
        if(scan[0]== '_'||scan[0]== '0')
        {
                        int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
        }
        else
        {
            if(scan[2]== '_'||scan[2]== '0')
            {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
            }
            else
            {
                if(scan[3]== '_'||scan[3]== '0')
                {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
                }
                else
                {
                    if(scan[1]== '_'||scan[1]== '0')
                    {
                 int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);
                    }
                }
            }
        }
    }
    
    else if(unidadey(qual)==unidadey(0)||unidadex(qual)<unidadex(0))
    {
        if(scan[2]== '_'||scan[2]== '0')
        {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[2];
                    moveright(qual);
                    return(0);
        }
        else
        {
            if(scan[1]== '_'||scan[1]== '0')
            {
                 int yy,xx;
                 yy = unidadey(qual);
                 xx = unidadex(qual);
                 mvaddch(yy,xx,solo_s[qual]);
                 solo_s[qual] = scan[1];
                 moveup(qual);
                 return(0);
            }
            else
            {
                if(scan[3]== '_'||scan[3]== '0')
                {
                    int yy,xx;
                    yy = unidadey(qual);
                    xx = unidadex(qual);
                    mvaddch(yy,xx,solo_s[qual]);
                    solo_s[qual] = scan[3];
                    movedown(qual);
                    return(0);
                }
                else
                {
                    if(scan[0]== '_'||scan[1]== '0')
                    {
            int yy,xx;
            yy = unidadey(qual);
            xx = unidadex(qual);
            mvaddch(yy,xx,solo_s[qual]);
            solo_s[qual] = scan[0];
            moveleft(qual);
            return(0);
                    }
                }
            }
        }
    }
}
