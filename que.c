//Author: Dashrath Chauhan (Semester 3 -> GEC Dahod)
//Last Modified: Febrauary 2014
//Program: Queue using Array

#include<stdio.h>
#define size 10
int q[size];
int front=-1;
int rear=-1;

	int insert()
{
	int x;
	
	if(rear==size-1)
	{
		printf("Queue overflow. You can not insert more elements.\n");
		return 0;
	}
	
	{
		if(front<=-1)
		{
			front=0;
		}	
		printf("Enter the element:");
		scanf("%d", &x);
		rear=rear+1;
		q[rear]=x;	
	}
	printf("\nAfter inserting:\n");
	printf("Rear = %d", rear);
	printf("\nFront = %d\n", front);		
}

	int delete()
{
	if(front<=-1 || front>rear)
	{
		printf("Queue is empty. No more elements to remove.\n");
		return 0;
	}
	else
	{
		printf("Deleted element is :%d", q[front]);
		front=front+1;
	}
	printf("\nAfter deleting:\n");
	printf("Rear = %d\n", rear);
	printf("Front = %d\n", front);
}

	int display()
{
	int i;

	if(front>rear)
	{
		printf("Queue is Empty. No elements to display.\n");
		return 0;
	}
	else
	{
	for(i=front; i<=rear; i++)
		{
			printf("%d|", q[i]);
		}
	}
}
	main()
{
	int c;
		printf("\vRear = %d", rear);
		printf("\nFront = %d", front);
	do
	{	
		printf("\n1.INSERT\n");
		printf("2.DELETE\n");
		printf("3.DISPLAY\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &c);
		
		switch(c)
		{
			case 1:
			insert();
			break;

			case 2:
			delete();
			break;
		
			case 3:
			display();
			break;

		}
	}while(c!=4);
}
