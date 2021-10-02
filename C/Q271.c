#include <stdio.h>
#include<stdlib.h>
#define max 50
int arr[max];
int front=-1,rear=-1;
void enqueue(int n)
{
  if(isFull())
  {
    printf("queue is ovderflow");
    return ;
  }
  if(front==-1)
  front=0;
  rear++;
  arr[rear]=n;
}
int dequeue()
{
  int item;
  if(isEmpty()){
    printf("queue is empty");
    return 0;
  }
  item=arr[front];
  front++;
  return item;
}
int peek()
{
  if(isEmpty())
  {
    return 0;
  }
  return arr[front];
}
int isEmpty()
{
  if (front==-1 || front==rear+1)
  return 1;
    else return 0;
}
int isFull()
{
  if(rear==max-1)
   return 1;
  else return 0;
}
void display()
{
  int i;
  if(isEmpty())
  {
    printf("Queue is empty");
    return ;
  }
  printf("The elements present in queue:");
  for(i=front;i<=rear;i++)
    printf("%d\t",arr[i]);
}

int main(void) {
  int choice,item ;
  while(1)
  {
    printf("\n1. push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.display\n");
    printf("5.EXIT");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter the item to be inserted:");
              scanf("%d",&item);
              enqueue(item);
              break;
      case 2: item =dequeue();
              if(item==0)
              return 0;
              else
              printf("The deleted element is %d",item);
              break;
      case 3: item =peek();
              printf("Element present at the top of the queue is %d",item);
              break; 
      case 4: 
              display();
              break;
      case 5 : exit (1);
      default : printf("Wrong choice");
       
    }

  }
  return 0;
}