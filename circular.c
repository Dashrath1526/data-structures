
//Author: Dashrath Chauhan (Semester 3 -> GEC Dahod)
//Last Modified: January 27 2018 11:28
//Program: Circular linked list

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node * createList(struct node *last);
struct node * addToEmptyList(struct node *last, int value);
struct node * addAtBeginning(struct node *last, int value);
struct node * addAtMiddle(struct node *last, int value, int item);
struct node * addAtEnd(struct node *last, int value);
struct node * deleteNode(struct node *last, int value);
void display(struct node *last);


void main(void){
	
	int choice;
	struct node *last = NULL;
	int value, item;
	
	while(1){
		
		printf("\n 1. Create list.");
		printf("\n 2. Display list");
		printf("\n 3. Add element to empty list.");
		printf("\n 4. Add element at the beginnig.");
		printf("\n 5. Add element at the end.");
		printf("\n 6. Add element into the middle of the list.");
		printf("\n 7. Delete element.");
		printf("\n 8. Exit.");
		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				last = createList(last);
				break;
			
			case 2:
				display(last);
				break;
			
			case 3:
				printf("\nEnter number to add into the list: ");
				scanf("%d", &value);
				last = addToEmptyList(last,value);
				break;
			
			case 4:
				printf("\nEnter number to add into the list: ");
				scanf("%d", &value);
				last = addAtBeginning(last,value);
				break;
			
			case 5:
				printf("\nEnter number to add into the list: ");
				scanf("%d", &value);
				last = addAtEnd(last,value);
				break;
			
			case 6:
				printf("\nEnter number to add into the list: ");
				scanf("%d", &value);
				printf("\nEnter the value of item after which you want to add the element: ");
				scanf("%d", &item);
				last = addAtMiddle(last,value,item);
				break;
			
			case 7:
				printf("\nEnter value of element to be deleted from the list: ");
				scanf("%d", &value);
				last = deleteNode(last,value);
				break;
			
			case 8:
				 exit(0);
				 
			default:
				printf("Invalid choice.");
		}//end of switch
	}//end of while
}//end of main


//Function to initialize list
struct node * createList(struct node *last){
	
	int elements, firstValue, value;
	int i;
	
	printf("\n\nNumbers of element to insert into the list: ");
	scanf("%d", &elements);
	printf("\nFirst element of the list: ");
	scanf("%d", &firstValue);
	
	last = addToEmptyList(last,firstValue);
	for(i=2; i<=elements; i++){
		printf("\nEnter data for the list: ");
		scanf("%d", &value);
		last = addAtEnd(last,value);
	}
	return(last);
}


//Function to display all the elements of list
void display(struct node *last){
	
	struct node * temp;
	
	if(last==NULL)
		printf("\nEmpty List...\n");
	else{
		temp = last->next;
		do{
			//printf("%d | %p\n", temp->data, temp);
			printf("\nData:\t %d \n", temp->data);
			printf("Address of current node: %p\n", temp);
			printf("Address of next node:\t %p\n", temp->next);
			temp = temp->next;
		}while(temp != last->next);
	}
}


//Function to add element at the beginning of the list
struct node * addAtBeginning(struct node *last, int value){
	
	struct node *New;
	New  = malloc(sizeof(struct node));
	
	New->data = value;
	New->next = last->next;
	last->next = New;
	return(last);
}


//Function to add element into the empty list
struct node * addToEmptyList(struct node *last, int value){
	
	struct node *New;
	New  = malloc(sizeof(struct node));
	
	New->data = value;
	last = New;
	//last->next = new;
	last->next = last;
	return(last);
}


//Function to add element at the end of the list
struct node * addAtEnd(struct node *last, int value){
	
	struct node *New;
	New  = malloc(sizeof(struct node));
	
	New->data = value;
	New->next = last->next;
	last->next = New;
	last = New;
	return(last);
}


//Function to add element at middle
struct node * addAtMiddle(struct node *last, int value, int item){
	
	struct node *New;
	struct node *temp;
	temp = last->next;
	//new = malloc(sizeof(struct node));
	do{
		if(temp->data == item){
			New = malloc(sizeof(struct node));
			New->data = value;
			New->next = temp->next;
			temp->next = New;
			if(temp == last)
				last = New;
				
			return(last);
		}
		temp = temp->next;
	}while(temp != last->next);
	printf("\n%d is not in the list...\n", item);
	return(last);
}


//Delete an element from the list
struct node * deleteNode(struct node *last, int value){
	
	struct node *p;
	struct node *t;
	
	if(last == NULL){
		printf("\nList is empty...\n");
		return(last);
	}
	
	//if only single element in the list
	if(last == last->next && last->data == value){
		t = last;
		last = NULL;
		free(t);
		return(last);
	}
	
	//if element to delete is at the beginnig of the list
	if(last->next->data == value){
		t = last->next;
		last->next = t->next;
		free(t);
		return(last);
	}
	
	//delete from the list if above special cases fails
	p = last->next;
	while(p->next != last){
		if(p->next->data == value){
			t = p->next;
			p->next = t->next;
			free(t);
			return(last);
		}
		p = p->next;
	}
	
	if(last->data == value){
		t = last;
		p->next = last->next;
		last = p;
		free(t);
		return(last);
	}
	
	printf("\n%d is not found in the list...\n", value);
}
