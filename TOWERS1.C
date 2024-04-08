#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int disks,top[3]={-1,-1,-1},arr[3][100];
void push(int data,int x)
{
 arr[x][++top[x]]=data;
}


int pop(int x)
{
 return arr[x][top[x]--];
}

void  border()
{
 int i;
 setbkcolor(0);
   setcolor(3);            //border
 line(0,0,0,470);
 line(0,470,630,470);
 line(630,470,630,0);
 line(0,0,630,0);
 setcolor(1);            //stacks
 line(10,350,200,350);
 line(220,350,410,350);
 line(430,350,620,350);
 line(105,350,105,50);
 line(315,350,315,50);
 line(525,350,525,50);
 setcolor(6);
 outtextxy(0,365,"  	        SOURCE                  INTERMEDIATE               DESTINATION");
 outtextxy(265,390,"TOWERS OF HANOI");
}

void rectangle1(int x,int y,int x1,int y1)
{
  int k;
  setcolor(3);
  for(k=y;k<=y1;k++)
  {
   line(x,k,x1,k);
  }
}

void initialize(int n)
{
 int i;
 for(i=1;i<=n;i++)
 {
  setcolor(3);
//  setfillstyle(SOLID_FILL,i);
  rectangle1(10+(6*(i-1)),329-(20*(i-1)),200-(6*(i-1)),349-(20*(i-1)));
  push(10+(6*(i-1)),0);
  push(329-(20*(i-1)),0);
 }
}

void initialize1()
{
 int t,x,y;
 //initializing source
 t=top[0];
 while(t>=0)
 {
  y=arr[0][t--];
  x=arr[0][t--];
  rectangle1(x,y,105+(105-x),y+20);
 }
  //initializing intermediate
 t=top[1];
 while(t>=0)
 {
  y=arr[1][t--];
  x=arr[1][t--];
  rectangle1(x,y,315+(315-x),y+20);
 }
  //initializing destination
 t=top[2];
 while(t>=0)
 {
  y=arr[2][t--];
  x=arr[2][t--];
  rectangle1(x,y,525+(525-x),y+20);
 }
}

void move(char source,char destination)
{
  int x,y,k,a=329;
  if(source=='s')
  {
     y=pop(0);
     x=pop(0);
     for(k=y;k>30;k--)          //moving block up from source
       {
	cleardevice();
	border();
	initialize1();
	setcolor(3);
	rectangle1(x,k,210-x,k+20);
       }
     if(destination=='i')
      {
	for(k=x;k<(210+x);k++)      //moving block to intermediate(source)
	 {
	  cleardevice();
	  border();
	  initialize1();
	  setcolor(3);
	  rectangle1(k,30,k+2*(105-x),50);
	 }
	 if(top[1]!=-1)
	  a=arr[1][top[1]]-20;
	for(k=30;k<a;k++)  //moving block down intermediate
	 {
	  cleardevice();
	  border();
	  initialize1();
	  setcolor(3);
	  rectangle1(210+x,k,420-x,20+k);
	 }
	push(210+x,1);
	push(a,1);
      }
     else
      {
	for(k=x;k<(420+x);k++)    //moving block to destination
	 {
	  cleardevice();
	  border();
	  initialize1();
	  setcolor(3);
	  rectangle1(k,30,k+2*(105-x),50);
	 }
	if(top[2]!=-1)
	  a=arr[2][top[2]]-20;
	for(k=30;k<a;k++)   //moving block down destination
	 {                               //if block exist (source)
	  cleardevice();
	  border();
	  initialize1();
	  setcolor(3);
	  rectangle1(420+x,k,630-x,20+k);
	 }
	push(420+x,2);
	push(a,2);
      }

  }
  else if(source=='i')
  {
   y=pop(1);
   x=pop(1);
    for(k=y;k>30;k--)        //moving block up from intermediate
       {
	cleardevice();
	border();
	initialize1();
	setcolor(3);
	rectangle1(x,k,630-x,k+20);
       }
   if(destination=='d')
   {
    for(k=x;k<(210+x);k++)    //moving block to destination
     {
      cleardevice();
      border();
      initialize1();
      setcolor(3);
      rectangle1(k,30,k+2*(315-x),50);
     }
     if(top[2]!=-1)
     a=arr[2][top[2]]-20;
    for(k=30;k<a;k++)   //moving block down destination
     {
      cleardevice();
      border();
      initialize1();
      setcolor(3);
      rectangle1(210+x,k,840-x,20+k);
     }
     push(210+x,2);
     push(a,2);
   }
   else
   {
     for(k=x;k>(x-210);k--)     //moving block side to source
     {
      cleardevice();
      border();
      initialize1();
      setcolor(3);
      rectangle1(k,30,k+2*(315-x),50);
     }
    if(top[0]!=-1)
      a=arr[0][top[0]]-20;
     for(k=30;k<a;k++)       //moving block down source
     {
      cleardevice();
      border();
      initialize1();
      setcolor(3);
      rectangle1(105-(315-x),k,105+(315-x),20+k);
     }
    push(105-(315-x),0);
     push(a,0);
   }
  }
  else if(source=='d')
  {
   y=pop(2);
   x=pop(2);
   for(k=y;k>30;k--)           //moving block up from destination
   {
    cleardevice();
    border();
    initialize1();
    setcolor(3);
    rectangle1(x,k,525+525-x,k+20);
   }
    if(destination=='s')
     {
       for(k=x;k>(105-(525-x));k--)   //moving block to source
       {
	cleardevice();
	border();
	initialize1();
	setcolor(3);
	rectangle1(k,30,k+2*(525-x),50);
       }
      if(top[0]!=-1)
      a=arr[0][top[0]]-20;
       for(k=30;k<a;k++)       //moving block down source
       {
	cleardevice();
	border();
	initialize1();
	setcolor(3);
	rectangle1(105-(525-x),k,105+(525-x),20+k);
       }
     push(105-(525-x),0);
     push(a,0);
     }
    else
     {
       for(k=x;k>(315-(525-x));k--)  //moving block to intermediate
       {
	cleardevice();
	border();
	initialize1();
	setcolor(3);
	rectangle1(k,30,k+2*(525-x),50);
       }
       if(top[1]!=-1)
       a=arr[1][top[1]]-20;
       for(k=30;k<a;k++)  //moving block down intermediate
	 {
	  cleardevice();
	  border();
	  initialize1();
	  setcolor(3);
	  rectangle1(315-(525-x),k,315+(525-x),20+k);
	 }
	push(315-(525-x),1);
	push(a,1);
     }
  }
}

void towers_of_hanoi(int n,char source,char intermediate,char destination)
{
 getch();
 if(n==1)
 {
//  printf("move 1 from %c to %c\n",source,destination);
  move(source,destination);
  getch();
 }
 else
 {
  towers_of_hanoi(n-1,source,destination,intermediate);
//  printf("move %d from  %c to %c\n",n,source,destination);
  move(source,destination);
  getch();
  towers_of_hanoi(n-1,intermediate,source,destination);
 }
}


void main()
{
 int gd=DETECT,gm,k;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cleardevice();
 printf("ENTER THE NUMBER OF DISKS");
 scanf("%d",&disks);
 cleardevice();
 border();
 initialize(disks);
 towers_of_hanoi(disks,'s','i','d');
 getch();
}
