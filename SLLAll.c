//Author: Dashrath Chauhan (Semester 3 -> GEC Dahod)
//Last Modified: March 2014
//Program: Singyly Linekd List


#include<stdio.h>
#include<malloc.h>
int insfront();
int delfront();
int display();
int insend();
int delend();
int insert();
int delete();
			
	struct node
	{
		int info;
		struct node* link;
	}*first=NULL;
	
	main()
{
	int c;
	printf("\n\nSingly linked list program:\n\n");
	while(c!=8)
	{
		printf("\n\n1.Insert a node at front(STACK MANNER):\n");
		printf("2.Delete a node from the front(STACK MANNER):\n");
		printf("3.Insert a node at end(QUEUE MANNER):\n");
		printf("4.Delete a node in end(QUEUE MANNER):\n");
		printf("5.Insert a node at desired position:\n");
		printf("6.Delete a node at desired position:\n");
		printf("7.Display Linked List:\n\n");
		printf("Enter your choice:");
		scanf("%d", &c);
		switch(c)
			{
				case 1:
				insfront();
				break;
	
				case 2:
				delfront();
				break;
				
				case 3:
				insend();
				break;
	
				case 4:
				delend();
				break;

				case 5:
				insert();
				break;

				case 6:
				delete();
				break;
	
				case 7:
				display();
				break;
			}	
	}
}


/*Function to insert node starts here*/
int insfront()
{
	struct	node*tmp;
	int inserted_item;
	/*int front;*/

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Insert the element:");
	scanf("%d", &inserted_item);
	tmp->info=inserted_item;
	tmp->link=first;
	first=tmp;
}
/*Function to ends node ends here*/

/*Function to delete node starts here*/
int delfront()
{
	struct node*tmp;
	int front;
	if(first==NULL)
	{
		printf("Linked list empty. No elements to delete.\n");
		return 0;
	}
	else
	{
		tmp=first;
		printf("Deleted element is :%d\n", tmp->info);
		first=tmp->link;
		tmp->link=NULL;
		free(tmp);
	}
}
/*Function to delete node ends here*/

/*function to insert node starts here*/
int insend()
{
	struct node*tmp, *q;
	int inserted_item;
	q=first;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element:");
	scanf("%d", &inserted_item);
	tmp->info=inserted_item;
	tmp->link=NULL;
	
	if(first==NULL)
	{
		first=tmp;
	}
	else
	{
		while(q->link!=NULL)
		{
			q=q->link;
		}
	q->link=tmp;
	}
}

/*function to insert node ends here*/
/*function to delete node starts here*/

int delend()
{
	struct node*tmp, *q;
	q=first;
	
	if(first==NULL)
	{
		printf("Linked list empty. No elements to delete.\n");
		return 0;
	}
	else if(q->link==NULL)
	{
		printf("\nDeleted Element is %d",q->info);
		first=NULL;
		free(q);
	}
	else
	{
		while((q->link)->link!=NULL)

			q=q->link;
			tmp=q->link;
			printf("\nDeleted element is %d\n",tmp->info);
			q->link=NULL;
			free(tmp);

	}
}

/*function to delete node ends here*/
/*Function to insert a node starts here*/
	int insert()
{
	struct node*tmp,*q;
	q=first;
	int inserted_item, pos, n=0, i=1;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element for adding into the linked list:");
	scanf("%d", &inserted_item);
	printf("Enter the position:");
	scanf("%d", &pos);
	tmp->info=inserted_item;
	while(q!=NULL)
	{
		n++;
		q=q->link;
	}
	if(pos<=0 || pos>=n+1)
	{
		printf("Invalid position:\n");
	}
	else
	{
		if(pos==1)
		{
			tmp->link=first;
			first=tmp;
		}
		else
		{
			q=first;
			while(i!=pos-1)
			{
				q=q->link;
				i++;
			}
			tmp->link=q->link;
			q->link=tmp;
		}
	}
}
/*Function to insert a node ends here*/	

/*Function to delete a node starts here*/
	int delete()
{
	struct node*tmp, *q;
	int pos, i=1, n=1;
	tmp=q=first;
	if(first==NULL)
	{
		printf("Linked list underflow:\n");
		return 0;
	}
	else
	{
		printf("Enter position to delete:");
		scanf("%d", &pos);
		while(q->link!=NULL)
		{	
			n++;
			q=q->link;
		}
		if(pos<=0 || pos>n)
		{
			printf("Invalid Position:\n");
		}
		else if(pos==1)
		{
			printf("Deleted element is %d\n", tmp->info);
			first=first->link;
			free(tmp);
		}
		else
		{
			q=first;
			while(i!=pos-1)
			{
				q=q->link;
				i++;
			}
			printf("Deleted element is :%d", (q->link)->info);
			q->link=(q->link)->link;
			free(q->link);
		}
	}
}
/*Function to delete a node ends here*/

/*Function to display linked list elements starts here*/
int display()
{
	struct node *ptr;
	int front;
	ptr=first;
	if(first==NULL)
	{
		printf("Linked list Empty. No elements to display.\n");
		return 0;
	}
	else
	{
		printf("Linked list elements:\n");
		while(ptr!=NULL)
		{
			printf("%d   |\t", ptr->info);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
/*Function to display linked list elements starts here*/

