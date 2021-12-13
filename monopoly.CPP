#include<iostream>
#include <conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<time.h>
#include<fstream>

int A=0,B=0,C=0,c=1000,a=1000,b=1000,x,p;
char ch ='Y';
char name1[25];
char name2[25];
char name3[25];
int pos[20]={4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int price[20]={0,130,70,250,240,230,120,110,230,220,260,120,110,320,230,240,100,90,300,210};
int rent [20]={0,13,7,25,24,23,12,11,23,22,26,12,11,32,23,24,10,10,30,21};
char place[20][20]={"start","Trivandrum","Agarthala","Railways","Delhi","Mumbai","Gurgon","Ranchi","Waterways","Kolkata","Chennai","Mangalore","Nagpur","Airways","Chandigarh","Goa","Raipur","Patna","Banglore","Hyderabad"};
void board ()
{ for(int i=0;i<=70;i++)
 { std::cout<<"_";
 }
 std::cout<<'\n'<<"|    START  |   TRIVANDRUM   |   AGARTHALA  |    RAILWAYS   |   DELHI  |";
std:: cout<<'\n'<<"|____0______|_______1________|_______2______|_______3_______|____4_____|";
std:: cout<<'\n'<<"| HYDERABAD |                                               |   MUMBAI |";
std:: cout<<'\n'<<"|____19_____|                                               |_____5____|";
std:: cout<<'\n'<<"| BANGLORE  |                                               |   GURGON |";
std:: cout<<'\n'<<"|____18_____|                                               |_____6____|";
 std::cout<<'\n'<<"|  PATNA    |                                               |   RANCHI |";
 std::cout<<'\n'<<"|____17_____|                                               |_____7____|";
std:: cout<<'\n'<<"|   RAIPUR  |                                               | WATERWAYS|";
std:: cout<<'\n'<<"|____16_____|                                               |_____8____|";
std:: cout<<'\n'<<"|   GOA     |                                               | KOLKATA  |";
std:: cout<<'\n'<<"|____15_____|_______________________________________________|_____9____|";
std:: cout<<'\n'<<"|CHANDIGARH |    AIRWAYS     |    NAGPUR    |    MANGLORE   |  CHENNAI |";
std:: cout<<'\n'<<"|____14_____|______13________|______12______|_______11______|____10____|"<<'\n';

}
void display()
{ board();
 std::cout <<'\n'<<"PLAYER 1 AT POSITION :"<<A<<"   MONEY IN HAND : "<<a<<'\n';
 std::cout <<"PLAYER 2 AT POSITION :"<<B<<"   MONEY IN HAND : "<<b<<'\n'<<'\n';
 std::ofstream pos;
 pos.open("pos_mon_2_player.txt");
 pos<<A<<'\n'<<a<<'\n'<<B<<'\n'<<b;
 pos.close();
}
void display1()
{board();
 std::cout <<'\n'<<"PLAYER 1 AT POSITION :"<<A<<"   MONEY IN HAND : "<<a<<'\n';
 std::cout <<"PLAYER 2 AT POSITION :"<<B<<"   MONEY IN HAND : "<<b<<'\n';
 std::cout <<"PLAYER 3 AT POSITION :"<<C<<"   MONEY IN HAND : "<<c<<'\n'<<'\n';
 std::ofstream pos;
 pos.open("pos_mon_3_player.txt");
 pos<<A<<'\n'<<a<<'\n'<<B<<'\n'<<b<<'\n'<<C<<'\n'<<c;
 pos.close();
}
void rules()
{
    system("cls");
  std::cout<<'\t'<<'\t'<<"WELCOME TO MONOPOLY"<<'\n'<<'\n';
  std:: cout<<"   RULES"<<'\n';
  std:: cout<<'\n'<<"1.This is a multiplayer game(2 or 3 players)"<<'\n'<<'\n'<<"2.The is  dice rolled at random at each players chance"<<'\n'<<'\n';
  std:: cout<<"3.You can buy places at which you land"<<'\n'<<'\n';
  std:: cout<<"4.You will first be given $1000.Each time a player crosses START the player will be given $100"<<'\n'<<'\n';
  std:: cout<<"5.If a place is already owned by the other PLAYER you will have to pay a rent"<<'\n'<<'\n';
  std:: cout<<"6.After each round you can exit the game or continue the game"<<'\n'<<'\n';
  std:: cout<<"7.The GAME comes to an END when one of the players are BANKRUPT or UNABLE to pay the RENT"<<'\n'<<'\n';
  std:: cout<<"8.In case of THREE PLAYERS GAME if a PLAYER is BANKRUPT that PLAYER is out of the game.The other TWO PLAYERS can continue the game."<<'\n'<<'\n';
  std:: cout<<"9.The Properties of the PLAYER whose is out can be bought by the other two PLAYERS";
   getch();
}
void getname(int n1)
{       if(n1==1)
    { std::ofstream fout;
      fout.open("name_2player.txt");
      system("cls");
      std:: cout<<"ENTER PLAYER 1'S NAME:";
      std::cin>>name1;
      fout<<name1<<'\n';
      std:: cout<<"ENTER PLAYER 2'S NAME:";
      std::cin>>name2;
      fout<<name2<<'\n';
      fout.close();
        }
    if(n1==2)
    { std::ofstream fout;
      fout.open("name_3player.txt");
      system("cls");
      std::cout<<"ENTER PLAYER 1'S NAME:";
      std::cin>>name1;
      fout<<name1<<'\n';
      std::cout<<"ENTER PLAYER 2'S NAME:";
      std::cin>>name2;
      fout<<name2<<'\n';
      std::cout<<"ENTER PLAYER 3'S NAME:";
      std::cin>>name3;
      fout<<name3<<'\n';
      fout.close();
    }
}
int play()
{  system("cls");
   char ch ='y';
   int l;
while (ch=='Y'||ch=='y')
{system("cls");
 display();
 int random;
 srand(time(NULL));
 x=(rand()%6+1);
 if((A+x)/20==1)
 a+=100;
 A=(A+x)%20;
 system("cls");
 display();
  std::cout <<name1<<"'s chance"<<'\n'<<'\n';
  std::cout <<"YOU ROLLED "<<x<<'\n'<<'\n';
 if (pos [A]==0)
  {

   std::cout <<"DO YOU WANT TO BUY : "<<place [A]<<" for Price $  "<<price [A]<<'\n'<<'\n';
  std:: cout <<" Y---->TO BUY      N----->TO NOT BUY"<<'\n';
  std:: cin >>ch;
     if (ch=='Y'||ch=='y')
      {
       if (a>=price [A])
	 {   pos[A]=1;
	     a-=price[A];
	}
     else
      {
       std::cout <<"NO ENOUGH MONEY"<<'\n'<<'\n';
       getch();
      }
      }
}
 else if (pos[A]==2)
 {
   if (a>=rent [A])
       {
	  std::cout <<"YOU HAVE COME TO "<<name2<<"'s POSITION :"<<place[A]<<'\n'<<'\n';
	  std::cout<<"PAY RENT : $ "<<rent[A]<<'\n'<<'\n';
	  a-=rent [A];
	  b+=rent[A];
	  getch();
       }
     else
     {  std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"GAME OVER :"<<name2<<" WINS !!!!"<<'\n';
	getch();
	system("cls");
	std::cout<<"THANK YOU";
	exit (1);
     }
 }
 else if(pos[A]==4)
 {
  std::cout<<"YOU HAVE COME TO START"<<'\n'<<'\n';
  getch();
 }
 else
 {
 std::cout<<"YOU HAVE COME TO YOUR PLACE : "<<place[A]<< '\n'<<'\n';
 getch();
 }
  system("cls");
  srand(time(NULL));
  x=(rand()%6+1);
   if((B+x)/20==1)
    b+=100;
     B=(B+x)%20;
     display();
     std::cout <<name2<<"'s chance"<<'\n'<<'\n';
     std::cout <<"YOU ROLLED "<<x<<'\n'<<'\n';
 if (pos [B]==0)
 {

  std:: cout <<"DO YOU WANT TO BUY : "<<place [B]<<"   for PRICE : $ "<<price [B]<<'\n'<<'\n';
   std::cout <<" Y---->TO BUY      N----->TO NOT BUY"<<'\n'<<'\n';
   std::cin >>ch;
     if (ch=='Y'||ch=='y')
     {
       if (b>=price [B])
      {
	   pos[B]=2;
	   b-=price[B];
		}
      else
      {
       std::cout <<"NO ENOUGH MONEY"<<'\n'<<'\n';
       getch();
      }
    }
  }
 else if (pos[B]==1)
 {
    if (b>=rent [B])
       {
	std::cout<<"YOU HAVE COME TO "<<name1<<"'s POSITION :"<<place[B]<<'\n'<<'\n';
	std::cout<<"PAY RENT : $ "<<rent[B]<<'\n'<<'\n';
	 b-=rent [B];
	 a+=rent[B];
	 getch();
       }
     else
     { std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n';
     getch();
     std::cout <<"GAME OVER :"<<name1<<" WINS !!!!"<<'\n';
     getch();
     system("cls");
     std::cout<<"THANK YOU";
     exit (1);
     }
 }
  else if(pos[B]==4)
{
  std::cout<<"YOU HAVE COME TO START"<<'\n'<<'\n';
  getch();
  }
else
{
std::cout<<"YOU HAVE COME TO YOUR PLACE : "<< place[B]<<'\n'<<'\n';
getch();
}
std::ofstream places;
places.open("places_2_player.txt");
for (l=0;l<20;l++)
  {places<<pos[l]<<'\n';
    }
 places.close();
std::cout<<"DO YOU WANT TO CONTINUE "<<'\n'<<'\n';
std::cout <<"Y----->YES         N----->NO"<<'\n';
std::cin>>ch;
}
getch();
}
int play2()
{system("cls");
char ch ='y';
int q=0;
while (ch=='Y'||ch=='y')
{
 system("cls");
 display1();
 int random;
 srand(time(NULL));
 x=(rand()%6+1);
 if((A+x)/20==1)
 a+=100;
 A=(A+x)%20;
 system("cls");
 display1();
  std::cout <<name1<<"'s chance"<<'\n'<<'\n';
  std::cout <<"YOU ROLLED "<<x<<'\n'<<'\n';
 if (pos [A]==0)
  {

   std::cout <<"DO YOU WANT TO BUY : "<<place [A]<<" for Price $  "<<price [A]<<'\n'<<'\n';
  std:: cout <<" Y---->TO BUY      N----->TO NOT BUY"<<'\n';
  std:: cin >>ch;
     if (ch=='Y'||ch=='y')
      {
       if (a>=price [A])
	 {   pos[A]=1;
	     a-=price[A];
	}
     else
      {
       std::cout <<"NO ENOUGH MONEY"<<'\n'<<'\n';
       getch();
      }
      }
}
 else if (pos[A]==2)
 {
   if (a>=rent [A])
       {
	  std::cout <<"YOU HAVE COME TO "<<name2<<"'s POSITION :"<<place[A]<<'\n'<<'\n';
	  std::cout<<"PAY RENT : $ "<<rent[A]<<'\n'<<'\n';
	  a-=rent [A];
	  b+=rent[A];
	  getch();
       }
     else
     {  std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"You ARE OUT..."<<'\n';
	getch();
	system("cls");
	std::cout<<name2<<"&"<<name3<<"CAN CONTINUE THE GAME";
	getch();
	for (q=0;q<20;q++)
    { name1[q]=name2[q];
      name2[q]=name3[q];
    }
	A=B;
	B=C;
	a=b;
	b=c;
	for (q=0;q<20;q++)
    { if(pos[q]==1)
        { pos[q]=0;
        }
    }
	play();

     }
 }
 else if (pos[A]==3)
 {
   if (a>=rent [A])
       {
	  std::cout <<"YOU HAVE COME TO "<<name3<<"'s POSITION :"<<place[A]<<'\n'<<'\n';
	  std::cout<<"PAY RENT : $ "<<rent[A]<<'\n'<<'\n';
	  a-=rent [A];
	  c+=rent[A];
	  getch();
       }
     else
     {  std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"You ARE OUT..."<<'\n';
	getch();
	system("cls");
	std::cout<<name2<<"&"<<name3<<"CAN CONTINUE THE GAME";
	getch();
	for (q=0;q<20;q++)
    { name1[q]=name2[q];
      name2[q]=name3[q];
    }
	A=B;
	B=C;
	a=b;
	b=c;
	for (q=0;q<20;q++)
    { if(pos[q]==1)
        { pos[q]=0;
        }
    }
	play();

     }
 }
 else if(pos[A]==4)
 {
  std::cout<<"YOU HAVE COME TO START"<<'\n'<<'\n';
  getch();
 }
 else
 {
 std::cout<<"YOU HAVE COME TO YOUR PLACE : "<<place[A]<< '\n'<<'\n';
 getch();
 }
  system("cls");
  srand(time(NULL));
  x=(rand()%6+1);
   if((B+x)/20==1)
   b+=100;
     B=(B+x)%20;
     display1();
     std::cout <<name2<<"'s chance"<<'\n'<<'\n';
     std::cout <<"YOU ROLLED "<<x<<'\n'<<'\n';
 if (pos [B]==0)
 {

  std:: cout <<"DO YOU WANT TO BUY : "<<place [B]<<"   for PRICE : $ "<<price [B]<<'\n'<<'\n';
   std::cout <<" Y---->TO BUY      N----->TO NOT BUY"<<'\n'<<'\n';
   std::cin >>ch;
     if (ch=='Y'||ch=='y')
     {
       if (b>=price [B])
      {
	   pos[B]=2;
	   b-=price[B];
		}
      else
      {
       std::cout <<"NO ENOUGH MONEY"<<'\n'<<'\n';
       getch();
      }
    }
  }
 else if (pos[B]==1)
 {
    if (b>=rent [B])
       {
	std::cout<<"YOU HAVE COME TO "<<name1<<"'s POSITION :"<<place[B]<<'\n'<<'\n';
	std::cout<<"PAY RENT : $ "<<rent[B]<<'\n'<<'\n';
	 b-=rent [B];
	 a+=rent[B];
	 getch();
       }
     else
     {  std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"You ARE OUT..."<<'\n';
	getch();
	system("cls");
	std::cout<<name1<<"&"<<name3<<"CAN CONTINUE THE GAME";
	getch();
	for (q=0;q<20;q++)
    { name2[q]=name3[q];
    }
	B=C;
	b=c;
	for (q=0;q<20;q++)
    { if(pos[q]==2)
        { pos[q]=0;
        }
    }
	play();

     }
 }

 else if (pos[B]==3)
 {
    if (b>=rent [B])
       {
	std::cout<<"YOU HAVE COME TO "<<name3<<"'s POSITION :"<<place[B]<<'\n'<<'\n';
	std::cout<<"PAY RENT : $ "<<rent[B]<<'\n'<<'\n';
	 b-=rent [B];
	 c+=rent[B];
	 getch();
       }
     else
     {  std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"You ARE OUT..."<<'\n';
	getch();
	system("cls");
	std::cout<<name1<<"&"<<name3<<"CAN CONTINUE THE GAME";
	getch();
	for (q=0;q<20;q++)
    { name2[q]=name3[q];
    }
	B=C;
	b=c;
	for (q=0;q<20;q++)
    { if(pos[q]==2)
        { pos[q]=0;
        }
    }
	play();

     }
 }
  else if(pos[B]==4)
{
  std::cout<<"YOU HAVE COME TO START"<<'\n'<<'\n';
  getch();
  }
else
{
std::cout<<"YOU HAVE COME TO YOUR PLACE : "<< place[B]<<'\n'<<'\n';
getch();
}

 system("cls");
  srand(time(NULL));
  x=(rand()%6+1);
   if((C+x)/20==1)
    c+=100;
     C=(C+x)%20;
     display1();
     std::cout <<name3<<"'s chance"<<'\n'<<'\n';
     std::cout <<"YOU ROLLED "<<x<<'\n'<<'\n';
 if (pos [C]==0)
 {

  std:: cout <<"DO YOU WANT TO BUY : "<<place [C]<<"   for PRICE : $ "<<price [C]<<'\n'<<'\n';
   std::cout <<" Y---->TO BUY      N----->TO NOT BUY"<<'\n'<<'\n';
   std::cin >>ch;
     if (ch=='Y'||ch=='y')
     {
       if (c>=price [C])
      {
	   pos[C]=2;
	   c-=price[C];
		}
      else
      {
       std::cout <<"NO ENOUGH MONEY"<<'\n'<<'\n';
       getch();
      }
    }
  }

 else if (pos[C]==2)
 {
    if (c>=rent [C])
       {
	std::cout<<"YOU HAVE COME TO "<<name2<<"'s POSITION :"<<place[C]<<'\n'<<'\n';
	std::cout<<"PAY RENT : $ "<<rent[C]<<'\n'<<'\n';
	 c-=rent [C];
	 b+=rent[C];
	 getch();
       }
          else
{   std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"You ARE OUT..."<<'\n';
	getch();
	system("cls");
	std::cout<<name1<<"&"<<name2<<"CAN CONTINUE THE GAME";
	getch();
	for (q=0;q<20;q++)
    { if(pos[q]==3)
        { pos[q]=0;
        }
    }
	play();

     }
 }
 else if (pos[C]==1)
 {
    if (c>=rent [C])
       {
	std::cout<<"YOU HAVE COME TO "<<name1<<"'s POSITION :"<<place[C]<<'\n'<<'\n';
	std::cout<<"PAY RENT : $ "<<rent[C]<<'\n'<<'\n';
	 c-=rent [C];
	 a+=rent[C];
	 getch();
       }
       else
{   std::cout<<"NO MONEY TO PAY RENT "<<'\n'<<'\n'<<"YOU ARE BANKRUPT"<<'\n'<<'\n';
	getch();
	std::cout <<"You ARE OUT..."<<'\n';
	getch();
	system("cls");
	std::cout<<name1<<"&"<<name2<<"CAN CONTINUE THE GAME";
	getch();
	for (q=0;q<20;q++)
    { if(pos[q]==3)
        { pos[q]=0;
        }
    }
	play();

     }
 }
  else if(pos[B]==4)
{
  std::cout<<"YOU HAVE COME TO START"<<'\n'<<'\n';
  getch();
  }
else
{
std::cout<<"YOU HAVE COME TO YOUR PLACE : "<< place[B]<<'\n'<<'\n';
getch();
}
int g;
std::ofstream plac;
plac.open("places_3_player.txt");
for (g=0;g<20;g++)
  {plac<<pos[g]<<'\n';
    }
 plac.close();
std::cout<<"DO YOU WANT TO CONTINUE "<<'\n'<<'\n';
std::cout <<"Y----->YES         N----->NO"<<'\n';
std::cin>>ch;
}


getch();
}
int menu()
{system("cls");
int p1=0,n;
while(p1==0)
{
std::cout<<'\t'<<"MENU"<<'\n';
std::cout<<"1.CONTINUE"<<'\n';
std::cout<<"2.NEW GAME"<<'\n';
std::cout<<"3.RULES"<<'\n';
std::cout<<"4.EXIT"<<'\n';
int c;
std::cin>>c;
int f=1;
if(c==1)
{ p1=1;
        f=1;
        while(f==1)
      {int r;
       system("cls");
       std::cout<<"1. 2 PLAYER GAME"<<'\n';
       std::cout<<"2. 3 PLAYER GAME"<<'\n';
       std::cin>>n;
       switch(n)
       {case 1: {f=0;
                std::ifstream fin;
                fin.open("pos_mon_2_player.txt");
                for (r=0;r<2;r++)
                {fin>>A>>a>>B>>b;
                }
                fin.close();
                 std::ifstream posi;
                posi.open("places_2_player.txt");
                for(r=0;r<20;r++)
                { posi>>pos[r];
                   }
                posi.close();
                std::ifstream nam2;
                nam2.open("name_2player.txt");
                for(r=0;r<1;r++)
                { nam2>>name1>>name2;
                   }
                nam2.close();
                play();
                break;}
        case 2:{f=0;
               std::ifstream fi1;
                fi1.open("pos_mon_3_player.txt");
                for (r=0;r<2;r++)
                {fi1>>A>>a>>B>>b>>C>>c;
                }
                fi1.close();
                 std::ifstream po1;
                po1.open("places_3_player.txt");
                for(r=0;r<20;r++)
                { po1>>pos[r];
                   }
                po1.close();
                std::ifstream na1;
                na1.open("name_3player.txt");
                for(r=0;r<1;r++)
                { na1>>name1>>name2>>name3;
                   }
                na1.close();
                play2();
                break;}
        default:system("cls");
            std::cout<<"ENTER PROPER CODE";
            getch();
            system("cls");
       }
      }
}
else if(c==2)
   {    p1=1;
        f=1;
        while(f==1)
      {   system("cls");
       std::cout<<"1. 2 PLAYER GAME"<<'\n';
       std::cout<<"2. 3 PLAYER GAME"<<'\n';
       std::cin>>n;
       switch(n)
       {case 1: f=0;
                getname(n);
                play();

                break;
        case 2:getname(n);
               play2();
               f=0;
               break;
        default:system("cls");
            std::cout<<"ENTER PROPER CODE";
            getch();
            system("cls");
        }
     }
   }
else if(c==3)
 {  p1=1;
     rules();

    int f1=1;
        while(f1==1)
      {   system("cls");
          std::cout<<"1.BACK"<<'\n';
          std::cout<<"2.EXIT"<<'\n';
          int c1;
          std::cin>>c1;
          system("cls");
       switch(c1)
       {case 1: f1=0;
                menu();
                break;
        case 2:f1=0;
               return(0);
               break;
        default:std::cout<<"ENTER PROPER CODE";
               getch();

        }
      }
      }
else if(c==4)
    {p1=1;
     return(0);
    }
else
   { system("cls");
    std::cout<<"ENTER PROPER CODE";
    getch();
    system("cls");
}
}
}
int main()
{  menu();

}
