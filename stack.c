//Author: Dashrath Chauhan (Semester 3 -> GEC Dahod)
//Last Modified: Febrauray 2014
//Program: Stack using Array

#include<stdio.h>
#define size 5
int a[size];
int top=-1;

	int push()
{
	int i;
	
	if(top==size-1)
	{
		printf("Stack overflow. You can not insert more elements into stack.\n");
		return 0;
	}
	else
	{
		top=top+1;
		printf("\nEnter element into stack:\n");
		scanf("%d", &i);
		a[top]=i;
		printf("\nTop=%d", top);	
	}
}

	int pop()
{
	int i;
	if(top==-1)
	{
		printf("Stack underflow.No elements to delete.\n");
		return 0;
	}
	else
	{
		printf("Element popped is :%d", a[top]);
		top=top-1; 
		printf("\nTop=%d", top);
	}
}

	void display()
{
	
	int i;
	if(top==-1)
	{
		printf("Stack is empty no elements to display.\n");	
	}
	else{
	printf("Elements of stack are:\n");
	for(i=top; i>=0; i--)
	{
		printf("%d|", a[i]);
	}
	}
}

main()
{
	int c;
	while(c!=4)
	{
	printf("\n1. PUSH\n");
	printf("2. POP\n");
	printf("3. DISPLAY\n");
	printf("4.Exit\n");
	printf("Enter your choice:");
	scanf("%d", &c);

	switch(c)
	{
		case 1:
		push();
		break;

		case 2:
		pop();
		break;

		case 3:
		display();
		break;
	}
	}
}
