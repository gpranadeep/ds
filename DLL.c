#include <stdio.h>
#include <stdlib.h>
//double linked list
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head = NULL;
void insertionAtFront(int v){
	struct Node *newnode= (struct Node*)malloc(sizeof(struct Node));
	newnode->data=v;
	newnode->next=head;
	newnode->prev=NULL;
	head=newnode;
}
void insertionAtEnd(int v){
	struct Node *newnode= (struct Node*)malloc(sizeof(struct Node));
	newnode->data=v;
	struct Node *temp=head;
	if(head==NULL){
	insertionAtFront(v);
	return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next=NULL;
}
void insertionAtPos(int v,int p){
	int c=1;
	struct Node *temp=head;
	if(p<=1){
		insertionAtFront(v);
		return;
	}
	while(c<p-1){
		if(temp==NULL){
			printf("POSITION NOT FOUND");
			return;
		}
		temp=temp->next;
		c++;	
	}
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	
	newnode->data=v;
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next=newnode;
}
void deleteAtFront(){
	struct Node *temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);

}
void deleteAtEnd(){
	struct Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
void deleteAtPos(int p){
	int c=1;
	struct Node *temp=head;
	if(p<=1){
		deleteAtFront();
		return;
	}
	while(c<p&&temp!=NULL){
		temp=temp->next;
		c++;	
	}
	temp=temp->next;
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}
void display(){
	struct Node *temp=head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
	while(temp!=NULL)
	{
	printf(" %d<->",temp->data);
	temp=temp->next;
    }
    printf("NULL");
	
}
int main(){
	insertionAtEnd(111);
	insertionAtFront(10);
	insertionAtFront(101);
	insertionAtFront(1);
	insertionAtEnd(111);
	insertionAtPos(40,3);
	deleteAtFront();
	deleteAtEnd();
	deleteAtPos(3);
	display();
	return 0;
}
