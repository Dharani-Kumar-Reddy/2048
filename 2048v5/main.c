#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
void process(int *c);
void swap(int *p,int *q);
void merge(int *c);
int z[16],zc,moves,a[4][4],undo[4][4],mergecount;
long int score,undoscore;
int checkw,endcounter;
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
int main()
{
    char playername[15],p1[8],p2[8];
    gotoxy(35,9);
    printf("******************************************************");
    gotoxy(35,10);
    printf("                         2048                         ");
    gotoxy(35,11);
    printf("******************************************************");
    gotoxy(35,12);
    printf("INSTRUCTIONS:");
    gotoxy(35,13);
    printf("1).Use UP,DOWN,LEFT,RIGHT arrow keys to move the blocks.");
    gotoxy(35,14);
    printf("2).USE  z  for undo,you can use this feature only once.");
    gotoxy(35,15);
    printf("3).Press Esc to exit from game.");
    gotoxy(35,16);
    printf("4).Any keys entered other than mentioned in menu will terminate your game.");
    delay(7);
    system("cls");
    gotoxy(35,9);
    printf("PLEASE CHOOSE YOUR CHOICE\n");
    gotoxy(35,10);
    printf("1).SINGLE PLAYER               2).MULTIPLAYER          3).EXIT\n");
    gotoxy(35,11);
    printf("Enter your choice-");
    int ch1;
    scanf("%d",&ch1);
    if(ch1==1)
    {

        system("cls");
        gotoxy(35,9);
        printf("Are you a NEWBIE?\n");
        gotoxy(35,10);
        printf("1)YES                          2).NO                  3).EXIT");
        gotoxy(35,11);
        printf("Enter your choice-");
        int ch11;
        scanf("%d",&ch11);
        if(ch11==1)
        {
            system("cls");
            gotoxy(35,9);
            printf("Do you want to continue as guest\n");
            gotoxy(35,10);
            printf("1)YES                          2).NO                  3).EXIT");
            gotoxy(35,11);
            printf("Enter your choice-");
            int ch12;
            scanf("%d",&ch12);
            if(ch12==1)
            {
                singleplayer();
            }
            else if(ch12==2)
            {
            system("cls");
            gotoxy(35,9);
            printf("Please register\n");
            gotoxy(35,10);
            printf("USER NAME        :");
            gotoxy(35,11);
            printf("PASSWORD         :          (limit it to 8 characters)");
            gotoxy(35,12);
            printf("CONFIRM PASSWORD :          (limit it to 8 characters)");
            gotoxy(53,10);
            scanf("%s",playername);
            gotoxy(53,11);
            scanf("%s",p1);
            gotoxy(53,12);
            scanf("%s",p2);
                if(strcmp(p1,p2)==0)
                {
                FILE *fp;
                fp=fopen(playername,"wb");
                fprintf(fp,"%s",p1);
                fclose(fp);
                singleplayer();
                }
            }
            else
            _exit(0);

        }
        else if(ch11==2)
        {
            int i=0;
            n:i++;
            int p2[8],p1[8];
            system("cls");
            gotoxy(35,9);
            if(i==1)
            {
                printf("Please login to play\n");
            }
            else
                printf("WRONG PASSWORD Try Again\n");
            gotoxy(35,10);
            printf("USER NAME        :");
            gotoxy(35,11);
            printf("PASSWORD         :");
            gotoxy(53,10);
            scanf("%s",playername);
            gotoxy(53,11);
            scanf("%s",p1);
            FILE *fp;
            fp=fopen(playername,"r");
            fgets(p2,"%s",fp);
            if(i==3)
            {
                gotoxy(35,12);
                printf("TOO many attempts try guest mode\n");
                delay(2);
                _exit(0);
            }
            if(strcmp(p1,p2)==0)
            {
                singleplayer();
            }
            else
            {
                    printf("wrong password try again\n");
                goto n;
            }
        }

    else
        _exit(0);
    }

    else if(ch1==2)
    {

      system("cls");
      gotoxy(35,10);
      printf("comming soon\n");
      delay(2);
      printf("Just Kidding\n");
      delay(2);

      _exit(0);
    }
    else
    {
        _exit(0);
    }
    return 0;
}
void swap(int *p,int *q)
{
	int k;
	k=*p;
	*p=*q;
	*q=k;
}
void merge(int *c)
{
	int i;
	for(i=3;i>0;i--)
	{
		if(c[i]==c[i-1])
		{
		    mergecount++;
			c[i-1]=0;
			c[i]=2*c[i];
			if(moves>=512)
			{
			    if(c[i]==2048)
                {
                   checkw=1;
                 }
			}
            score=score+c[i];
		}
	}
}
void zero(int *c)
{
	if(c[3]==0)
	{
		if(c[2]==0)
		{
			if(c[1]==0)
			{
					if(c[0]!=0)
					swap(&c[3],&c[0]);
			}
			else
			{
				if(c[0]==0)
					swap(&c[3],&c[1]);
				else
				{
					swap(&c[3],&c[1]);
					swap(&c[0],&c[2]);
				}
			}
		}
		else
		{
			if(c[1]==0)
			{
				if(c[0]==0)
					swap(&c[3],&c[2]);
				else
				{
					swap(&c[3],&c[2]);
					swap(&c[0],&c[2]);
				}
			}
			else
			{
				if(c[0]==0)
				{
					swap(&c[3],&c[2]);
					swap(&c[1],&c[2]);
				}
				else
				{
					swap(&c[3],&c[2]);
					swap(&c[1],&c[2]);
					swap(&c[1],&c[0]);
				}
			}
		}
	}
	else
	{
		if(c[2]==0)
		{
			if(c[1]==0)
			{
					if(c[0]!=0)
					swap(&c[2],&c[0]);
			}
			else
			{
					if(c[0]==0)
						swap(&c[1],&c[2]);
					else
					{
						swap(&c[2],&c[1]);
						swap(&c[0],&c[1]);
					}
			}
		}
		else
		{
			if(c[0]!=0&&c[1]==0)
				swap(&c[0],&c[1]);
		}
	}
}
void process(int *c)
{
    zero(c);
	merge(c);
	zero(c);
}
void gameover()
{
    int flag=0;
    endcounter=0;
    for(int j=0;j<4;j++)
        for(int k=0;k<4;k++)
            if(a[j][k]==0)
                flag++;
    if(flag==0)
    {
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                if(j==0&&k!=3)
                {
                    if((a[0][k]==a[0][k+1]!=0)||(a[0][k]==a[1][k]!=0))
                        endcounter++;
                }
                else if(j>0&&j<3&&k!=3)
                {
                    if((a[j][k]==a[j][k+1]!=0)||(a[j][k]==a[j+1][k]!=0))
                        endcounter++;
                }
                else if(j==3&&k!=3)
                {
                    if(a[j][k]==a[j][k+1]!=0)
                        endcounter++;

                }
                else if(k==3&&j<3)
                {
                    if(a[j][3]==a[j+1][3]!=0)
                        endcounter++;
                }
                else
                {}
            }
    if(endcounter==0)
    {
        system("cls");
        printf("You lost the game mate\n");
        printf("----------------------------------\n");
        printf("          game stats              \n");
        printf("----------------------------------\n");
        printf("score:%d\n",score);
        printf("moves:%d\n",moves);
        printf("BETTER LUCK NEXT TIME\n");
        _exit(0);
    }
}
}
void singleplayer()
{
    int i,t,ch,r,easy=4,undocount=0;
	int p[4][4],j,k;
	srand(time(NULL));
	for(i=0;i<4;i++)
		for(t=0;t<4;t++)
			a[i][t]=0;
	zc=16;
	r=rand()%zc;
	a[r/4][r%4]=easy;
	system("cls");
	gotoxy(35,9);
    printf("score:%d          moves:%d\n",score,moves);
	for(i=0;i<4;i++)
	{
	    gotoxy(35,10+i);
		for(t=0;t<4;t++)
		{
			if(a[i][t]!=0)
				printf("%d\t",a[i][t]);
			else
				printf("\t");
		}
		printf("\n");
    }
	a:
	if(kbhit())
	{
		int key=getch();
		switch(key)
		{
			case 72:
			        gameover();

			        moves++;
                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            undo[j][k]=a[j][k];
                    undoscore=score;
                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            p[j][k]=a[3-k][j];
                    mergecount=0;
                    for(j=0;j<4;j++)
                        process(p[j]);

                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            a[3-k][j]=p[j][k];
                    zc=0;
                    for(k=0;k<4;k++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(a[k][j]==0)
                            {
                                z[zc]=k*4+j;
                                zc++;
                            }
                        }
                    }


                    if(mergecount==0&&zc==0)
                    {
                        moves--;
                        break;
                    }
                    else
                    {

                        if(zc!=0)
                        {
                            r=rand()%zc;
                            a[z[r]/4][z[r]%4]=easy;
                        }

                        system("cls");
                        gotoxy(35,9);
                        printf("score:%d          moves:%d\n",score,moves);
                        for(k=0;k<4;k++)
                        {
                            gotoxy(35,10+k);
                            for(j=0;j<4;j++)
                            {
                                if(a[k][j]!=0)
                                    printf("%d\t",a[k][j]);
                                else
                                    printf("\t");
                            }
                            printf("\n");
                        }
                        if(checkw==1)
                        {

                            printf("hurrah you won the game\n");
                            delay(2);
                            _exit(0);
                        }

                        break;
                    }
			case 80:
                    gameover();
                    moves++;
                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            undo[j][k]=a[j][k];
                    undoscore=score;
                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            p[3-k][j]=a[j][k];
                    mergecount=0;
                    for(j=0;j<4;j++)
                        process(p[j]);
                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            a[j][k]=p[3-k][j];
                    zc=0;
                    for(k=0;k<4;k++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(a[k][j]==0)
                            {
                                    z[zc]=k*4+j;
                                    zc++;
                            }
                        }
                    }

                    if(mergecount==0&&zc==0)
                    {
                        moves--;
                        break;
                    }
                    else
                    {
                        if(zc!=0)
                        {
                            r=rand()%zc;
                            a[z[r]/4][z[r]%4]=easy;
                        }

                        system("cls");
                        gotoxy(35,9);
                        printf("score:%d          moves:%d\n",score,moves);
                        for(k=0;k<4;k++)
                        {
                            gotoxy(35,10+k);
                            for(j=0;j<4;j++)
                            {
                                if(a[k][j]!=0)
                                    printf("%d\t",a[k][j]);
                                else
                                    printf("\t");
                            }
                            printf("\n");
                        }
                         if(checkw==1)
                        {
                            printf("hurrah you won the game\n");
                            delay(2);
                            _exit(0);
                        }

                        break;

                    }
			case 77:
                    gameover();moves++;
                    for(j=0;j<4;j++)
                        for(k=0;k<4;k++)
                            undo[j][k]=a[j][k];
                    undoscore=score;
                    mergecount=0;
                    for(j=0;j<4;j++)
                        process(a[j]);

                        zc=0;
                        for(k=0;k<4;k++)
                        {
                            for(j=0;j<4;j++)
                            {
                                if(a[k][j]==0)
                                {
                                    z[zc]=k*4+j;
                                    zc++;
                                }
                            }
                        }

                         if(mergecount==0&&zc==0)
                            {
                                moves--;
                                break;
                            }
                    else
                    {
                        if(zc!=0)
                        {
                            r=rand()%(zc);
                            a[z[r]/4][z[r]%4]=easy;
                        }

                        system("cls");
                        gotoxy(35,9);
                        printf("score:%d          moves:%d\n",score,moves);
                        for(k=0;k<4;k++)
                        {
                            gotoxy(35,10+k);
                            for(j=0;j<4;j++)
                            {
                                if(a[k][j]!=0)
                                    printf("%d\t",a[k][j]);
                                else
                                    printf("\t");
                            }
                            printf("\n");
                        }
                         if(checkw==1)
                    {
                        system("cls");
                        printf("hurrah you won the game\n");
                        delay(2);
                        _exit(0);
                    }

                        break;
                    }

			case 75:
			    gameover();
			    moves++;
                for(j=0;j<4;j++)
					for(k=0;k<4;k++)
                        undo[j][k]=a[j][k];
                        undoscore=score;
				for(j=0;j<4;j++)
				{
					swap(&a[j][1],&a[j][2]);
					swap(&a[j][3],&a[j][0]);
				}
				mergecount=0;
				for(j=0;j<4;j++)
					process(a[j]);

				for(j=0;j<4;j++)
				{
					swap(&a[j][1],&a[j][2]);
					swap(&a[j][3],&a[j][0]);
				}
				zc=0;
				for(k=0;k<4;k++)
				{
					for(j=0;j<4;j++)
					{
						if(a[k][j]==0)
						{
							z[zc]=k*4+j;
							zc++;
						}
					}
				}

				 if(mergecount==0&&zc==0)
                    {
                        moves--;
                        break;
                    }
                    else
                    {
				if(zc!=0)
                {


				r=rand()%zc;
				a[z[r]/4][z[r]%4]=easy;
                }

				system("cls");
                gotoxy(35,9);
				printf("score:%d          moves:%d\n",score,moves);
				for(k=0;k<4;k++)
				{gotoxy(35,10+k);
					for(j=0;j<4;j++)
					{
						if(a[k][j]!=0)
							printf("%d\t",a[k][j]);
						else
							printf("\t");
					}
					printf("\n");


				}
				if(checkw==1)
                    {

                        printf("hurrah you won the game\n");
                        delay(2);
                        _exit(0);
                    }

				break;
                    }
            case 27:
				_exit(0);
            case 'z':
                    if(undocount<1)
                    {
                        undocount++;
                        for(j=0;j<4;j++)
                            for(k=0;k<4;k++)
                                a[j][k]=undo[j][k];
                        moves--;
                        system("cls");
                        gotoxy(35,9);
                        printf("score:%d          moves:%d\n",undoscore,moves);
                        for(k=0;k<4;k++)
                        {
                            gotoxy(35,10+k);
                            for(j=0;j<4;j++)
                            {
                                if(a[k][j]!=0)
                                    printf("%d\t",a[k][j]);
                                else
                                    printf("\t");
                            }
                            printf("\n");
                        }
                        break;
                    }
                    else
                    {
                        printf("You can only use undo feature once in a game\n");
                        break;
                    }
        }
	}
	goto a;
}
