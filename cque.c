			    /* Circluar Queue*/
#include<stdio.h>
#define size 5
int cq[size];
int F=-1;
int R=-1;
	
	/*If rear=size-1 then we set the value of Rear to zero and add the element at 0th position of the array otherwise the element
	will be added same as in linear queue. If queue is initially empty then we set the value 0 to Front and Rear and then add the 
	element	in queue otherwise we increase the value of Rear only and the the element will be added in queue.*/
	int insert()
{
	int x;
	if(F==0 && R==size-1||(F==R+1))
	{
		printf("\nQueue is Overflow. You cannot insert more elements:\n");
		return 0;
	}
	
	if(F==-1)
	{
		F=0;
		R=0;
	}

	else
	{
		if(R==size-1)
		{
			R=0;
		}
		else
		{
			R++;
		}
	}

	printf("\nEnter element:");
	scanf("%d",&x);
	cq[R]=x;
	printf("After inserting:\n");
	printf("F=%d\n", F);
	printf("R=%d\n", R);
}

	/*If Front=size-1 then delete the element from queue and set the value of Front t 0. If there is only one element in queue 
	then we delete the element from queue and set the value of Front and Rear to -1. */
	int del()
{

	if(F==-1 && R==-1)
	{
		printf("\nQueue Underflow. No more elements to delete.\n");
		return 0;
	}
	/*printf("\nRemoved Element is %d\n",cq[F]);*/
	if(F==R)
	{
		F=-1;
		R=-1;
	}

	else if(F==size-1 && R!=0)
		{
			F=-1;
			R=-1;
		}
		else if(F<size-1)
		{
			F++;
		}
	printf("After deleting:\n");
	printf("F=%d\n", F);
	printf("R=%d\n", R);
}

	void display()
{

	int i;
	printf("\n\n\t***QUEUE STATUS***\n\n");

	if(F==-1)
	{
		printf("\n Queue Empty. No more elements to display.");
	}

	else if(F<=R)
	{
		for(i=F;i<=R;i++)
		{
			printf("%d|",cq[i]);
		}
	}

	else
	{
		while(F<=size-1)
		{
			printf("%d|",cq[F]);
			F++;
		}
		while(i<=R)
		{
			printf("%d|",cq[i]);
			i++;
		}
	}
	printf("\n\nF=%d\n", F);
	printf("R=%d\n", R);
}

	main()
{
	int c;
	printf("\n\nF=%d\n", F);
	printf("R=%d\n", R);
	while(c!=4)
	{
		printf("\n\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\n Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			insert();
			break;
			
			case 2:
			del();
			break;

			case 3:
			display();
			break;
		}
	}
}

