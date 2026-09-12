//stacks
#include <stdio.h>
#include <stdlib.h>
#define max 5
int top=-1;
int stack[max];
void push(int val){
	if(top+1>=max){
		printf("Stack overflow");
		return;
	}
	top++;
	stack[top]=val;
	printf("Pushed %d to the stack\n",val);
}
void pop(){
	if(top==-1){
		printf("Stack underflow");
		return;
	}
	int temp= stack[top];
	stack[top]=0;
	top--;
	printf("Popped %d from the Stack\n",temp);
}
void peek(){
	if(top==-1){
		printf("Stack underflow");
		return;
	}
	printf("Top is pointing to %d",stack[top]);
}
void isFull(){
	if(top==max-1)
		printf("Stack is Full");	
	else 
		printf("Stack is not Full");
}
void isEmpty(){
	if (top==-1)
		printf("Stack is Empty");
	else 
		printf("Stack is not Empty");
}
void display(){
	if(top==-1){
		printf("Stack underflow");
		return;
	}	
	printf("\n-----STACK-----\n\n");
	for (int i=top;i>=0;i--){
		printf("| %d |\n",stack[i]);
		printf(" ____\n");
	}
}
int main(){
	int ch=0;
	int val;
	while (ch != 7){
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Is Full\n5.Is Empty\n6.Display\n7.Exit\n");
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
				isFull();
				break;
			}
			case 5:{
				isEmpty();
				break;
			}
			case 6:{
				display();
				break;
			}
			case 7:{
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

