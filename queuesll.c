#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void enqueue(int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		printf("%d is inserted\n",data);
		return;
	}
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	printf("%d is inserted\n",data);
}
void dequeue(){
	if(head==NULL){
		printf("Queue is Empty\n");
		return;
	}
	struct node *temp=head;
	head=head->next;
	printf("%d is Deleted",temp->data);
	free(temp);
}
void display(){
	if(head==NULL){
		printf("Queue is Empty\n");
		return;
	}
	struct node *temp=head;
	printf("QUEUE : ");
	while(temp!=NULL){
		printf(" %d |",temp->data);
		temp=temp->next;
	}
}
int main(){
	int data,ch;
	do{
		printf("\n===QUEUE USING LINKED LIST===");
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
	return 0;
}
