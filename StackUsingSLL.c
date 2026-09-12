#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *top=NULL;
void push(int val){
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data=val;
	if(top==NULL){
		newnode->next=NULL;
	}
	else
		newnode->next=top;
	top=newnode;
	printf("Pushed %d to the stack\n",val);
}
void pop(){
	if(top==NULL){
		printf("Stack Underflow");
		return;
	}
	struct Node *temp=top;
	top=top->next;
	printf("Popped %d from the Stack\n",temp->data);
	free(temp);
}
void peek(){
	if(top==NULL){
		printf("Stack Underflow");
		return;
	}	
	printf("Top is pointing to %d",top->data);
}
void display(){
	if(top==NULL){
		printf("Stack Underflow");
		return;
	}
	struct Node *temp=top;
	printf("\n-----STACK-----\n\n");
	while(temp!=NULL){
		printf("| %d |\n",temp->data);
		printf(" ____\n");
		temp=temp->next;
	}	
}
int main(){
	int ch=0;
	int val;
	while (ch != 5e4){
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:{

				printf("Enter Element to Push : ");
				scanf("%d",&val);
				push(val);
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				peek();
				break;
			}
			case 4:{
				display();
				break;
			}
			case 5:{
				printf("Exiting program..");
				break;
			}
			default :{
				printf("Invalid Choice");
				break;	
			}
		}
	}
	return 0;
}