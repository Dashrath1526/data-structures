//Author: Dashrath Chauhan (Semester 3 -> GEC Dahod)
//Last Modified: April 2014
//Program: Doubly Linekd List

				
#include<stdio.h>
#include<malloc.h>
int insfront();
int delfront();
int display();
int insend();
int delend();
int inspos();
int delpos();
			
	struct node
	{
		struct node *left;
		int info;
		struct node *right;
	}*first=NULL;
	
	main()
{
	int c;
	printf("\n\nDoubly linked list program:\n\n");
	while(c!=8)
	{
		printf("\n\n1.Insert a node at front(STACK MANNER):\n");
		printf("2.Delete a node from the front(STACK MANNER):\n");
		printf("3.Insert a node at end(QUEUE MANNER):\n");
		printf("4.Delete a node from the end(QUEUE MANNER):\n");
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
				inspos();
				break;

				case 6:
				delpos();
				break;
	
				case 7:
				display();
				break;
			}	
	}
}

/*Function that inserts a node at beginning starts here*/
	int insfront()
{
	struct node*tmp;
	int inserted_item;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Insert the element:");
	scanf("%d", &inserted_item);
	tmp->info=inserted_item;
	tmp->left=NULL;
	tmp->right=first;
	first=tmp;
}
/*Function that inserts a node at beginning ends here*/

/*Function that deletes a node from beginning startss here*/
	int delfront()
{
	struct node*tmp;
	if(first==NULL)
	{
		printf("Linked list empty. No elements to delete:\n");
		return 0;
	}
	else
	{
		tmp=first;
		printf("Deleted element is :%d", tmp->info);
		first=tmp->right;
		first->left=NULL;
		free(tmp);
	}
}
/*Function that deletes a node from beginning endss here*/

/*Function that insertes a new node at end starts here*/
	int insend()
{
	struct node*tmp, *q;
	int inserted_item;	
	q=first;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Insert the element:");
	scanf("%d", &inserted_item);
	tmp->info=inserted_item;
	tmp->right=NULL;
	if(first==NULL)
	{
		tmp->left=NULL;
		first=tmp;
	}
	else
	{
		while(q->right!=NULL)
		{
			q=q->right;
		}
		q->right=tmp;
		tmp->left=q;
	}
}
/*Function that insertes a new node at end ends here*/
	
/*Function that delete a new node from end starts here*/
	int delend()
{
	struct node*tmp, *q;
	q=first;
	if(first==NULL)
	{
		printf("Linked list is empty. No elements to delete:\n");
		return 0;
	}
	else if(q->right==NULL)
	{
		printf("Deleted element is: %d", q->info);
		first=NULL;
		free(q);
	}
	else
	{
		while(q->right!=NULL)
		{
			q=q->right;
		}
		tmp=q;
		printf("Deleted element is: %d", tmp->info);
		q->left->right=NULL;
		free(tmp);
	}
}
/*Function that delete a new node from end ends here*/

/*Function to insert a node starts here*/
	int inspos()
{
	struct node*tmp,*q;
	int inserted_item, pos, n=0, i=1;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element for adding into the linked list:");
	scanf("%d", &inserted_item);
	printf("Enter the position:");
	scanf("%d", &pos);
	tmp->info=inserted_item;
	q=first;
	while(q->right!=NULL)
	{
		n++;
		q=q->right;
	}
	if(pos<=0 || pos>=n+1)
	{
		printf("Invalid position:\n");
	}
	else
	{
		if(pos==1)
		{
			tmp->right=first;
			tmp->left=NULL;
			first=tmp;
		}
		else
		{
			q=first;
			if(pos==n+1)
			{
				while(q->right!=NULL)
				{
					q=q->right;
					i++;
				}
			tmp->left=q;
			tmp->right=NULL;
			q->right=tmp;
			}
			else
			{
				while(i!=pos)
				{
					q=q->right;
					i++;
				}
				tmp->left=q->left;
				tmp->right=q;
				q->left->right=tmp;
				q->left=tmp;
			}
		}
	}
}
/*Function to insert a node ends here*/	

/*Function to delete a node starts here*/
	int delpos()
{
	struct node*tmp, *q;
	int pos, i=1, n=0;
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
		while(q!=NULL)
		{	
			n++;
			q=q->right;
		}
		if(pos<=0 || pos>n)
		{
			printf("Invalid Position:\n");
		}
		else if(pos==1)
		{
			printf("DEleted element is: %d", tmp->info);
			first=first->right;
			first->left=NULL;
			free(tmp);
		}
		else
		{
			q=first;
			while(i!=pos)
			{
				q=q->right;
				i++;
			}
			printf("Deleted element is: %d", q->info);
			q->left->right=q->right;
			q->right->left=q->left;
			free(q);
		}
	}
}
/*Function to delete a node ends here*/

/*Function that displays linked list starts here*/
	int display()
{
	struct node*ptr;
	ptr=first;	
	if(first==NULL)
	{
		printf("Linked list underflow. Nothing to diaplay:\n");
		return 0;
	}
	else
	{
		printf("Linked list elements:\n");
		while(ptr!=NULL)
		{
			printf("%d   |\t", ptr->info);
			ptr=ptr->right;	
		}
		printf("\n");
	}
}
/*Function that displays linked list ends here*/
