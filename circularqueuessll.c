#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
struct Node *last=NULL;
void enqueue(int data){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	if(head==NULL){
		newnode->next=newnode;
		head=newnode;
		last=newnode;
		printf("%d inserted as head node\n",newnode->data);
		return;
	}
	newnode->next=head;
	last->next=newnode;
	last=newnode;
	printf("%d inserted\n",newnode->data);
}
void dequeue(){
	if(head==NULL){
		printf("QUEUE is empty\n");
		return;
	}
	if(head==last){
		printf("%d is deleted\n",head->data);
		head=NULL;
		last=NULL;
		return;
	}
	struct Node *temp=head;
	head=head->next;
	last->next=head;
	printf("%d is deleted\n",temp->data);
	free(temp);
}
void display(){
	struct Node *temp=head;
	do{
		printf("%d -->",temp->data);
		temp=temp->next;
	}
	while(temp!=head);
	printf(" HEAD\n");
}
int main(){
	int data,ch;
	do{
		printf("\n===CIRCULAR QUEUE USING SLL===");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("Enter Number : ");
				scanf("%d",&data);
				enqueue(data);
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				printf("Exiting......\n");
				break;
			}
		}
	}
	while(ch!=4);
}