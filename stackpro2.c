//program 2 implement opretions of stack push,pop,peep,modify,display
#include<stdio.h>
#include<conio.h>
#define MAX 10

int a[MAX], top = -1;
void push();
void pop();
void peep();
void change();
void display();

void main()
{
  int ch;
  while(1) {
     printf("\n1. PUSH or INSERT");
  printf("\n2. POP or DELETE");
  printf("\n3. PEEP or SEARCH");
  printf("\n4. CHANGE or UPDATE");
  printf("\n5. Display");
  printf("\n6. End program");
     printf("\nEnter Choice : ");
     scanf("%d",&ch);
     
     switch(ch)
     {
       case 1:
 {
    push();
    break;
 }
       case 2:
 {
    pop();
    break;
 }
 case 3:
       {
   peep();
   break;
       }
       case 4:
       {
   change();
   break;
       }
       case 5:
 {
    display();
    break;
 }
       case 6:
 {
    exit(0);
 }
       default:
 printf("\ninvalid choice !!!");
     } // switch close
     getch();
  }
  //getch();
}

void push(){
  int data;
  if(top==MAX-1)
  {
     printf("\noverflow or stack is full !!!");
  }
  else
  {
     printf("\nEnter the element : ");
     scanf("%d",&data);
     top++;
     a[top]=data;
  }
}

void pop()
{
  if(top==-1)
  {
    printf("\nunder flow STACK or STACK is empty");
  }

  else
  {
    printf("\nPOP or DELETE element :  %d",a[top]);
    top--;
  }
}

void display()
{
   int i;
   if(top>=0)
   {
       printf("\nElemets : ");
       for(i=top; i>=0; i--)
       {
  printf("\n%d",a[i]);
       }
   }
   else
   {
       printf("\nThe STACK is Empty");
   }
}
void peep()
{
   int p;
   printf("\nEnter the position : ");
   scanf("%d",&p);
   if(top-p<=-1)
   {
      printf("\nSTACK is overflow !!!");
   }
   else
   {
      printf("\nThe Elements is : %d",a[top-p]);
   }
}
void change()
{
  int v1,v2;
  printf("\nEnter Position for change : ");
  scanf("%d",&v1);
  printf("\nEneter the Number for change : ");
  scanf("%d",&v2);
  if(top-v1<=-1)
  {
     printf("\nSTACK is overflow !!!");
  }
  else
  {
    a[top-v1]=v2;
    printf("\nCHANGE successfull !!!");
  }
}

        
