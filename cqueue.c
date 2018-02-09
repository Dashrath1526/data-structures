//Author: Viren Patel (Head of Department, Computer Engineering Deaprtment, GEC Dahod)
//Last Modified: February 2014
//Program: Circluar Queue using Array


#include<stdio.h>
#define N 5

printQ(int *p){
	int i;
	printf("\n********QUEUE STATUS\n");
	for(i=0;i<N;i++){
		printf("%d|",*p);
		p++;
	}

}

int main(){

	int q[N],F=-1,R=-1,choice, *p;
	p = q;

	printf("\nThis is a circular queue program\n");

	do{

		printf("Enter your choice for circular queue functions:\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Exit\n");
		scanf("%d",&choice);


		switch(choice){

			case 1: printf("\nBefore insert F=%d , R=%d\n",F,R);	
	
				if(((R == N-1) && (F == 0)) || (R==F-1)){
					printf("\nQueue is full\nYou cannot insert.");
					break;
				}else{
					if((F == R) && (F == -1)){
						F=0;R=0;
						printf("\nThe queue is empty\n");
						printf("\nEnter the integer:");
						scanf("%d",&q[R]);
					
					}else if((F == R) && (R != -1) && (R< N-1)){
						R +=1;
						printf("\nThere was only one element in queue\n");
						printf("\nEnter the integer:");
						scanf("%d",&q[R]);
					
					}else if((R == N-1) && (N-F < N)){
						R = 0;
						printf("\nEnter the integer:");
						scanf("%d",&q[R]);
					}else if(R <= N-1){
						R +=1;
						printf("\nEnter the integer:");
						scanf("%d",&q[R]);
					}
				}	

				

				printQ(p);
				printf("\nAfter insert F=%d , R=%d\n",F,R);	
				break;

			case 2: printf("\nBefore delete F=%d , R=%d\n",F,R);	

				if((F==-1) && (R==-1)){
					printf("\nThe queue is empty !!\n");
					break;			

				}else{
					if(F==R){
						printf("\nThis was the last element in queue !!\n");
							q[F] = 0;
							F = -1;	R = -1;				
					}else{
						if(F == N-1 && R !=0){
							q[F] = 0;
							F = 0;
						}else if(F < N-1){
							q[F] = 0;
							F +=1;
						}
					}

				}
			
				printf("\nAfter delete F=%d , R=%d\n",F,R);	
				printQ(p);
				break;
		}

	}while(choice!=3);

}

