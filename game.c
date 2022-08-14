#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int run(int,int,int,int);
int main();

int down=2,right=2;
 
int demo()
{
    int i,i1; 
    for(i=1;i<=25;i++)
    {
        if(i==1 || i==25)
        {
            printf("|________________________________________________|");
        }
        else if (i==2)
        {
            printf("|O                                               |");
        }
        else
        {
            printf("|");
            for(i1=2;i1<=49;i1++)
            {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
    return 0;
}

int snake(char n,int ranx,int rany)
{
    int i,i1,c=0;
    for(i=1;i<=25;i++)
    {
        if(i==1 || i==25)
        {
            printf("|________________________________________________|");
        }
        else
        {
            printf("|");
            if(n=='d')
            {
            for(i1=2;i1<=49;i1++)
            {
             run(i,i1,ranx,rany);
            }
            if(c==0)
            {
            right+=1;
            c=1;
            }
            }
            if(n=='a')
            {
            for(i1=2;i1<=49;i1++)
            {
             run(i,i1,ranx,rany);
            }
            if(c==0)
            {
            right-=1;
            c=1;
            }
            }
            if(n=='s')
            {
            for(i1=2;i1<=49;i1++)
            {
             run(i,i1,ranx,rany);
            }
            if(c==0)
            {
            down+=1;
            c=1;
            }
            }
            if(n=='w')
            {
            for(i1=2;i1<=49;i1++)
            {
             run(i,i1,ranx,rany);
            }
            if(c==0)
            {
            down-=1;
            c=1;
            }
            }
            printf("|");
        }
        printf("\n");
    }
    return 0;
}

int run(int i,int i1,int ranx,int rany)
{
    if(i==down && i1==right)
    {
        printf("O");
    }
    else if (i==ranx && i1==rany)
    {
        printf("+");
    }
    else
    {
        printf(" ");
    }
    return 0;
}


int main()
{
    char n;
    int ranx,rany,score=0;
    demo();
    n=getch();
    ranx=rand()%23;
    rany=rand()%48;
    system("cls");
ac: while(!kbhit())
    {
        if(down==ranx && right==rany)
        {
ae:         ranx=rand()%24;
            rany=rand()%49;
            if(ranx==0 || rany==0 ||ranx==1 ||rany==1)
            {
                goto ae;
            }
            score+=8;
        }
    if(down<2 || down>25  ||right<2 ||right>50 )
    {
        printf("GAME OVER\n");
        printf("SCORE = %d",score);
        goto ab;
    }
    snake(n,ranx,rany);
    printf("SCORE = %d",score);
    Sleep(10);
    system("cls");
    }

    n=getch();
 ad:if(n!='a' && n!='w' && n!='d' && n!='s')
    {
        printf("invalid key");
        n=getch();
        goto ad;
    }
    goto ac;
ab: return 0;
}