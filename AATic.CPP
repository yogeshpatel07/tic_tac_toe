#include <graphics.h>
#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<math.h>
union REGS in,out;
int check_win(char []);
void shap_draw(int,int,char);
void hide()
{
	in.x.ax=2;
	int86(0x33,&in,&out);
}

void show()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}

void status(int *x,int *y,int *m)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*m=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
}

void create(char sing[9],char pl[20])
{
	int i;
	char ss,player[5];
	setcolor(YELLOW);
	setbkcolor(BLUE);
	setfillstyle(1,WHITE);
	bar(0,0,300,330);
	setfillstyle(1,8);
	bar(0,0,300,30);
	setcolor(BLUE);
	line(100,30,100,330);
	line(200,30,200,330);
	line(0,130,300,130);
	line(0,230,300,230);
	setfillstyle(1,RED);
	bar(270,0,300,30);
	setcolor(YELLOW);
	outtextxy(283,10,"X");
	setfillstyle(1,GREEN);
	bar(200,0,270,30);
	setcolor(YELLOW);
	outtextxy(220,10,"RETRY");
	outtextxy(10,10,"TIC TAC TOE");
	outtextxy(350,30,"player is :");
	outtextxy(440,30,pl);
	for(i=0;i<9;i++)
	{
		ss=sing[i];
		if(i==0)
		{
			shap_draw(50,80,ss);
		}
		if(i==1)
		{
			shap_draw(150,80,ss);
		}
		if(i==2)
		{
			shap_draw(250,80,ss);
		}
		if(i==3)
		{
			shap_draw(50,180,ss);
		}
		if(i==4)
		{
			shap_draw(150,180,ss);
		}
		if(i==5)
		{
			shap_draw(250,180,ss);
		}
		if(i==6)
		{
			shap_draw(50,280,ss);
		}
		if(i==7)
		{
			shap_draw(150,280,ss);
		}
		if(i==8)
		{
			shap_draw(250,280,ss);
		}
	}

}
char *com_term(char sing[],char[]);
void pl_wi2();
void pl_wi();
void main()
{
	int ch;
	while(1)
	{
		clrscr();
		printf("please enter how many player are \n1) one players\n2) two players\n");
		printf("3)to exit game  \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				pl_wi();
				break;
			case 2:
				pl_wi2();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("wrong choice ");
				delay(200);
				break;
		}

	}
}
void pl_wi()
{
	int gdriver = DETECT, gmode, errorcode;
	int x,i,y,m,chq=-1;
	char qu;
	char sing[9],player[20],Plr1[20],Plr2[20]="Computer";
	char mp[50];
	clrscr();
	printf("Enter the player name (Vs Computer) : ");
	scanf("%s",Plr1);
	strcpy(player,Plr1);

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
	for(i=0;i<9;i++)
	{
		sing[i]=' ';
	}
	sing[9]='\0';
	create(sing,player);
	while(!kbhit())
	{
		show();
		status(&x,&y,&m);
		if(m==1)
		{
			if(x>=270 && x<=300 && y>=0 && y<=30)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			if(x>=200 && x<270 && y>=0 && y<=30)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to restart the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			if(x>=0 && x<=100 && y>30 && y<=130)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[0]==' ')
					{
						sing[0]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>100 && x<=200 && y>30 && y<=130)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[1]==' ')
					{
						sing[1]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}

				}


			}
			if(x>200 && x<=300 && y>30 && y<=130)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[2]==' ')
					{
						sing[2]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}


			}
			if(x>=0 && x<=100 && y>130 && y<=230)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[3]==' ')
					{
						sing[3]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>100 && x<=200 && y>130 && y<=230)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[4]==' ')
					{
						sing[4]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>200 && x<=300 && y>130 && y<=230)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[5]==' ')
					{
						sing[5]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>=0 && x<=100 && y>230 && y<=330)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[6]==' ')
					{
						sing[6]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>100 && x<=200 && y>230 && y<=330)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[7]==' ')
					{
						sing[7]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>200 && x<=300 && y>230 && y<=330)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[8]==' ')
					{
						sing[8]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						strcpy(sing,com_term(sing,player));
						strcpy(player,Plr1);
						show();
					}
				}

			}
			chq=check_win(sing);
			if(chq==1)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				sprintf(mp,"Winner is %s (X)",Plr1);
				outtextxy(10,170,mp);
				//outtextxy(10,170,"winner is player 1 \"X\" ");
				getch();
				cleardevice();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				else
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
					chq=-1;
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			else if(chq==2)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				sprintf(mp,"Winner is %s (O)",Plr2);
				outtextxy(10,170,mp);
				//outtextxy(10,170,"winner is player 2 \"O\" ");
				getch();
				cleardevice();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				else
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
					chq=-1;
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			else if(chq==3)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"GAME DRAW");
				getch();
				cleardevice();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);

				}
				else
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
					chq=-1;
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			else
			{

			}
			cleardevice();
			hide();
			create(sing,player);
			
			show();
		}

	}
	closegraph();
}

char *com_term(char sing[9],char pl[20])
{
	char ss='o';
	int a=0,b,c;
	int r,n;
	if(strcmp(pl,"Computer")==0)
	{
		if(a==0)
		{

			if(ss==sing[0] && ss==sing[1] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[2] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[4] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[8] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[3] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[6] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			}             //0 complet

			else if(ss==sing[1] && ss==sing[0] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[1] && ss==sing[2] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[1] && ss==sing[3] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[1] && ss==sing[6] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			} // 1 complet

			else if(ss==sing[2] && ss==sing[1] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[0] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[4] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[6] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[5] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[8] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}             //2 complet

			else if(ss==sing[3] && ss==sing[0] && sing[6]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[3] && ss==sing[6] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[3] && ss==sing[4] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}
			else if(ss==sing[3] && ss==sing[5] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			} // 3 complet

			else if(ss==sing[4] && ss==sing[0] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[8] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[1] && sing[7]==' ')
			{
				sing[7]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[7] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[2] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[6] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[3] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[5] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			} // 4 complet

			else if(ss==sing[5] && ss==sing[8] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[5] && ss==sing[2] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[5] && ss==sing[3] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[5] && ss==sing[4] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			} // 5 complet

			else if(ss==sing[6] && ss==sing[1] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[3] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[4] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[2] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[7] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[8] && sing[7]==' ')
			{
				sing[7]='o';
				a=1;
			}             //6 complet

			else if(ss==sing[7] && ss==sing[4] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[7] && ss==sing[1] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[7] && ss==sing[8] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[7] && ss==sing[6] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			} // 7 complet

			else if(ss==sing[8] && ss==sing[4] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[0] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[5] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[2] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[7] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[6] && sing[7]==' ')
			{
				sing[7]='o';
				a=1;
			}
				   //8 complet
			else
			{
				a=0;
			}
		}
		if(a==0)
		{
			ss='x';
			if(ss==sing[0] && ss==sing[1] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[2] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[4] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[8] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[3] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[0] && ss==sing[6] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			}             //0 complet

			else if(ss==sing[1] && ss==sing[0] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[1] && ss==sing[2] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[1] && ss==sing[3] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[1] && ss==sing[6] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			} // 1 complet

			else if(ss==sing[2] && ss==sing[1] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[0] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[4] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[6] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[5] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[2] && ss==sing[8] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}             //2 complet

			else if(ss==sing[3] && ss==sing[0] && sing[6]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[3] && ss==sing[6] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[3] && ss==sing[4] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}
			else if(ss==sing[3] && ss==sing[5] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			} // 3 complet

			else if(ss==sing[4] && ss==sing[0] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[8] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[1] && sing[7]==' ')
			{
				sing[7]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[7] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[2] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[6] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[3] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}
			else if(ss==sing[4] && ss==sing[5] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			} // 4 complet

			else if(ss==sing[5] && ss==sing[8] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[5] && ss==sing[2] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[5] && ss==sing[3] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[5] && ss==sing[4] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			} // 5 complet

			else if(ss==sing[6] && ss==sing[1] && sing[3]==' ')
			{
				sing[3]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[3] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[4] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[2] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[7] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			}
			else if(ss==sing[6] && ss==sing[8] && sing[7]==' ')
			{
				sing[7]='o';
				a=1;
			}             //6 complet

			else if(ss==sing[7] && ss==sing[4] && sing[1]==' ')
			{
				sing[1]='o';
				a=1;
			}
			else if(ss==sing[7] && ss==sing[1] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[7] && ss==sing[8] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[7] && ss==sing[6] && sing[8]==' ')
			{
				sing[8]='o';
				a=1;
			} // 7 complet

			else if(ss==sing[8] && ss==sing[4] && sing[0]==' ')
			{
				sing[0]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[0] && sing[4]==' ')
			{
				sing[4]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[5] && sing[2]==' ')
			{
				sing[2]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[2] && sing[5]==' ')
			{
				sing[5]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[7] && sing[6]==' ')
			{
				sing[6]='o';
				a=1;
			}
			else if(ss==sing[8] && ss==sing[6] && sing[7]==' ')
			{
				sing[7]='o';
				a=1;
			}
				   //8 complet
			else
			{
				a=0;
			}
		}
		if(a==0)
		{
			c=0;
			for(n=0;n<9;n++)
			{
				if(sing[n]==' ')
				{
					c++;
				}
			}
			if(c>0)
			{
				n=0;
				while(n==0)
				{
					r=random(9);
					if(sing[r]==' ')
					{
						sing[r]='o';
						n=1;
					}
				}
			}
		}

	}
	return(sing);
}

void shap_draw(int x,int y,char ss)
{
	float t1,k1,k2;
	int po[24];
	if(ss=='x')
	{
		t1=225*(3.1416/180);
		k1=cos(t1);
		k2=sin(t1);
		po[0]=((x-5)+20*(k1));
		po[1]=((y)+20*(k2));
		po[2]=((x)+20*(k1));
		po[3]=((y-5)+20*(k2));
		po[4]=x;
		po[5]=y-5;

		t1=315*(3.1416/180);
		k1=cos(t1);
		k2=sin(t1);
		po[6]=((x)+20*(k1));
		po[7]=((y-5)+20*(k2));
		po[8]=((x+5)+20*(k1));
		po[9]=((y)+20*(k2));
		po[10]=x+5;
		po[11]=y;

		t1=45*(3.1416/180);
		k1=cos(t1);
		k2=sin(t1);
		po[12]=((x+5)+20*(k1));
		po[13]=((y)+20*(k2));
		po[14]=((x)+20*(k1));
		po[15]=((y+5)+20*(k2));
		po[16]=x;
		po[17]=y+5;

		t1=135*(3.1416/180);
		k1=cos(t1);
		k2=sin(t1);
		po[18]=((x)+20*(k1));
		po[19]=((y+5)+20*(k2));
		po[20]=((x-5)+20*(k1));
		po[21]=((y)+20*(k2));
		po[22]=x-5;
		po[23]=y;

		setfillstyle(1,RED);
		fillpoly(12,po);
	}
	if(ss=='o')
	{
		setfillstyle(1,RED);
		fillellipse(x,y,20,20);
		setfillstyle(1,WHITE);
		fillellipse(x,y,15,15);

	}
}
int check_win(char sing[9])
{
	int a=0,b,c=0;
	char ss;
	for(b=0;b<9;b++)
	{
		ss=sing[b];
		if(ss==' ')
		{
			c=1;
		}
		if(ss=='x' || ss=='o')
		{
			if(b==0)
			{
				if(ss==sing[1] && ss==sing[2])
				{
					a=1;
					break;
				}
				if(ss==sing[3] && ss==sing[6])
				{
					a=1;
					break;
				}
				if(ss==sing[4] && ss==sing[8])
				{
					a=1;
					break;
				}

			}
			if(b==1)
			{
				if(ss==sing[0] && ss==sing[2])
				{
					a=1;
					break;
				}
				if(ss==sing[4] && ss==sing[7])
				{
					a=1;
					break;
				}
			}
			if(b==2)
			{
				if(ss==sing[0] && ss==sing[1])
				{
					a=1;
					break;
				}
				if(ss==sing[5] && ss==sing[8])
				{
					a=1;
					break;
				}
				if(ss==sing[4] && ss==sing[6])
				{
					a=1;
					break;
				}
			}
			if(b==3)
			{
				if(ss==sing[0] && ss==sing[6])
				{
					a=1;
					break;
				}
				if(ss==sing[4] && ss==sing[5])
				{
					a=1;
					break;
				}
			}
			if(b==4)
			{
				if(ss==sing[0] && ss==sing[8])
				{
					a=1;
					break;
				}
				if(ss==sing[1] && ss==sing[7])
				{
					a=1;
					break;
				}
				if(ss==sing[2] && ss==sing[6])
				{
					a=1;
					break;
				}
				if(ss==sing[3] && ss==sing[5])
				{
					a=1;
					break;
				}
			}
			if(b==5)
			{
				if(ss==sing[2] && ss==sing[8])
				{
					a=1;
					break;
				}
				if(ss==sing[3] && ss==sing[4])
				{
					a=1;
					break;
				}
			}
			if(b==6)
			{
				if(ss==sing[0] && ss==sing[3])
				{
					a=1;
					break;
				}
				if(ss==sing[2] && ss==sing[4])
				{
					a=1;
					break;
				}
				if(ss==sing[7] && ss==sing[8])
				{
					a=1;
					break;
				}

			}
			if(b==7)
			{
				if(ss==sing[1] && ss==sing[4])
				{
					a=1;
					break;
				}
				if(ss==sing[6] && ss==sing[8])
				{
					a=1;
					break;
				}
			}
			if(b==8)
			{
				if(ss==sing[0] && ss==sing[4])
				{
					a=1;
					break;
				}
				if(ss==sing[2] && ss==sing[5])
				{
					a=1;
					break;
				}
				if(ss==sing[6] && ss==sing[7])
				{
					a=1;
					break;
				}

			}
		}
	}
	if(ss=='o' && a==1)
	{
		a=2;
	}
	if(c==0 && a==0)
	{
		a=3;
	}
	return a;
}
void pl_wi2()
{
	int gdriver = DETECT, gmode, errorcode;
	int x,i,y,m,chq=-1;
	char qu;
	char sing[9],player[20],Plr1[20],Plr2[20];
	char mp[50];
	clrscr();
	printf("Enter the 1st player name : ");
	scanf("%s",Plr1);
	printf("Enter the 2nd player name : ");
	scanf("%s",Plr2);
	stpcpy(player,Plr1);
	
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
	for(i=0;i<9;i++)
	{
		sing[i]=' ';
	}
	sing[9]='\0';
	create(sing,player);
	while(!kbhit())
	{
		show();
		status(&x,&y,&m);
		if(m==1)
		{
			if(x>=270 && x<=300 && y>=0 && y<=30)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			if(x>=200 && x<270 && y>=0 && y<=30)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to restart the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			if(x>=0 && x<=100 && y>30 && y<=130)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[0]==' ')
					{
						sing[0]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[0]==' ')
					{
						sing[0]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>100 && x<=200 && y>30 && y<=130)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[1]==' ')
					{
						sing[1]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[1]==' ')
					{
						sing[1]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>200 && x<=300 && y>30 && y<=130)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[2]==' ')
					{
						sing[2]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[2]==' ')
					{
						sing[2]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>=0 && x<=100 && y>130 && y<=230)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[3]==' ')
					{
						sing[3]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[3]==' ')
					{
						sing[3]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>100 && x<=200 && y>130 && y<=230)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[4]==' ')
					{
						sing[4]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[4]==' ')
					{
						sing[4]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>200 && x<=300 && y>130 && y<=230)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[5]==' ')
					{
						sing[5]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[5]==' ')
					{
						sing[5]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>=0 && x<=100 && y>230 && y<=330)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[6]==' ')
					{
						sing[6]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[6]==' ')
					{
						sing[6]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>100 && x<=200 && y>230 && y<=330)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[7]==' ')
					{
						sing[7]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[7]==' ')
					{
						sing[7]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			if(x>200 && x<=300 && y>230 && y<=330)
			{
				if(strcmp(player,Plr1)==0)
				{
					if(sing[8]==' ')
					{
						sing[8]='x';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr2);
						show();
					}
				}
				else
				{
					if(sing[8]==' ')
					{
						sing[8]='o';
						cleardevice();
						hide();
						create(sing,player);
						strcpy(player,Plr1);
						show();
					}
				}

			}
			chq=check_win(sing);
			if(chq==1)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				sprintf(mp,"Winner is %s (X)",Plr1);
				outtextxy(10,170,mp);
				//outtextxy(10,170,"winner is player 1 \"X\" ");
				getch();
				cleardevice();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				else
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
					chq=-1;
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			else if(chq==2)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				sprintf(mp,"Winner is %s (O)",Plr2);
				outtextxy(10,170,mp);
				//outtextxy(10,170,"winner is player 2 \"O\" ");
				getch();
				cleardevice();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				else
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
					chq=-1;
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			else if(chq==3)
			{
				hide();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"GAME DRAW");
				getch();
				cleardevice();
				create(sing,player);
				setcolor(YELLOW);
				setfillstyle(1,RED);
				bar(0,130,300,230);
				outtextxy(10,170,"press \"Y\" to exit the game ");
				outtextxy(10,200,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);

				}
				else
				{
					for(i=0;i<9;i++)
					{
						sing[i]=' ';
					}
					strcpy(player,Plr1);
					chq=-1;
				}
				cleardevice();
				create(sing,player);
				
				show();
			}
			else
			{

			}
			cleardevice();
			hide();
			create(sing,player);
			
			show();
		}

	}
	closegraph();
}