#include<stdio.h>
#include<stdlib.h>

struct node { 
	float coeff;
	int expo;
	struct node *next;
};
typedef struct node* node;

node createNode();
node add(node, node);
node createList();
node insertBegin(node);                 //function for insert a element in the begining of the list
void displayList(node);
node insertEnd(node);
void swapList(node,node);
node insertBeginNode(node);
void sortList(node);
node multiply(node,node);
void removeDuplicate(node);
int main() {
	node p1,p2,r;
	int flag1,flag2,choice;
	system("clear");
	printf("\nPolynomial 1");
	p1=createList();
	printf("\nPolynomial 2");
	p2=createList();
	sortList(p1);
	sortList(p2);
	removeDuplicate(p1);
	removeDuplicate(p2);
	printf("\nP1:\t");
	displayList(p1);
	printf("\nP2:\t");
	displayList(p2);
	flag1=0;
	while(flag1==0) {
		printf("\nPress the numbers in the bracket to perform respective operations:\t");
		printf("\nAddition:\t(1)\tMultiplication:\t(2)\tNew Creation:\t(3)\tExit:\t(9)");
		printf("\nEnter your choice:\t");
		scanf("\n%d",&choice);
		switch(choice) {
			case 1:
				printf("\nPerforming Addition...");
				r=add(p1,p2);
				printf("\nSum:\t");
				sortList(r);
				displayList(r);
				break;
			case 2:
				printf("\nPerforming Multiplication...");
				r=multiply(p1,p2);
				printf("\nProduct:\t");
				sortList(r);
				displayList(r);
				break;
			case 3:
				printf("\nPolynomial 1");
				p1=createList();
				printf("\nPolynomial 2");
				p2=createList();
				sortList(p1);
				sortList(p2);
				removeDuplicate(p1);
				removeDuplicate(p2);
				printf("\nP1:\t");
				displayList(p1);
				printf("\nP2:\t");
				break;
			case 9:
				flag1=9;
				break;
			default:
				printf("\nError! Invalid choice...");
		}
	}
	printf("\nExiting...");
	return 0;
	
}

node createNode() {
	node temp=(node )malloc(sizeof(node));
	if(temp!=NULL) {
		temp->coeff=temp->expo=0;
		temp->next=NULL;
		return temp;
	}
	printf("\nMemory Overflow!");
	return NULL;
}

node createList()
{
	char ch;
	node Start=NULL;
    printf("\nCreating Linked List...");
	do {
		Start=insertBegin(Start);
		printf("\nDo you want to continue (y/n)::\t");
		scanf("\n%c",&ch);
	} while(ch=='y' || ch=='Y');
	system("clear");
	printf("\nCreation Successful!\n");
	return Start;
}
//function to insert a element at the beginning of the list
//it takes the starting node as a argument and also returns it
node insertBegin(node Start) 
{
	node NewNode=createNode();
	if(NewNode==NULL) 
		return 0;
	printf("\nEnter Coefficient:\t");
	scanf("\n%f",&NewNode->coeff);
	printf("\nEnter Exponent:\t");
	scanf("\n%d",&NewNode->expo);
	if(Start==NULL)
		Start=NewNode;
	else {
		NewNode->next=Start;
		Start=NewNode;
	}
	return Start;
}
//function to insert a element at the end of the list
//it takes the starting node as a argument and also returns it
node insertEnd(node Start)
{
	node Temp;
	node NewNode=createNode();
	if(NewNode==NULL)
		return 0;
	printf("\nEnter Coefficient:\t");
	scanf("\n%f",&NewNode->coeff);
	printf("\nEnter Exponent:\t");
	scanf("\n%d",&NewNode->expo);
	if(Start==NULL) 
		Start=NewNode;
	else {
        Temp=Start;
		while(Temp->next!=NULL) {
			Temp=Temp->next;
		}
		Temp->next=NewNode;
	}
	return Start;
}

void swapList(node p, node q) {
    int expo;
	float coeff;
    expo=p->expo;
	coeff=p->coeff;
    p->coeff=q->coeff;
	p->expo=q->expo;
    q->coeff=coeff;
	q->expo=expo;
}

void sortList(node Start)
{
    node p,q;
    if(Start==NULL)
        printf("\nEmpty List! ");
    else {
        for(p=Start;p!=NULL;p=p->next) {
            for(q=p->next;q!=NULL;q=q->next) {
                if(p->expo<q->expo) {
                    swapList(p,q);
				}
            }
        }
    }
}

node add(node p1, node q1) {
	node p,q,r=NULL;
	p=p1;
	q=q1;
	while(p!=NULL && q!=NULL) {
		if(p->expo==q->expo)	{
			r=insertBeginNode(r);
			r->expo=p->expo;
			r->coeff=p->coeff+q->coeff;
			p=p->next;
			q=q->next;
		}else {
			if(p->expo>q->expo) {
				r=insertBeginNode(r);
				r->expo=p->expo;
				r->coeff=p->coeff;
				p=p->next;
			}
			else {
				r=insertBeginNode(r);
				r->expo=q->expo;
				r->coeff=q->coeff;
				q=q->next;
			}
		}
	}
	while(p!=NULL) {
		r=insertBeginNode(r);
		r->expo=p->expo;
		r->coeff=p->coeff;
		p=p->next;
	}
	while(q!=NULL) {
		r=insertBeginNode(r);
		r->expo=q->expo;
		r->coeff=q->coeff;
		q=q->next;
	}
	return r;
}

node multiply(node p, node q) {
	node p1,q1,r=NULL;
	p1=p;
	q1=q;
	while(p1) {
		while(q1) {
			r=insertBeginNode(r);
			r->coeff=p1->coeff*q1->coeff;
			r->expo=p1->expo+q1->expo;
			q1=q1->next;
		}
		q1=q;
		p1=p1->next;
	}
	removeDuplicate(r);
	return r;
}

void removeDuplicate(node p) {
	node temp1,temp2,x;
	temp1=p; 
	while(temp1!=NULL&&temp1->next!=NULL){
		temp2=temp1;
		while(temp2->next!=NULL) {
			if(temp1->expo==temp2->next->expo) {
				temp1->coeff=temp1->coeff+temp2->next->coeff;
				x=temp2->next;
				temp2->next=temp2->next->next;
				free(x);
			}
			else
				temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	printf("OK");
}

//function to print the elements of the linked list
//it takes the starting node as in the input and displays the linked list element
void displayList(node Temp)
{	
	while(Temp!=NULL) {
		printf(" |%f| |%d| --->",Temp->coeff,Temp->expo);
	        Temp=Temp->next;	
	}
	printf("NULL\n");	
}

node insertBeginNode(node Start)
{
	node NewNode=createNode();
	if(NewNode==NULL){
		printf("\nCreate node failed!");
		return NULL;
	}
	if(Start==NULL)
		Start=NewNode;
	else {
		NewNode->next=Start;
		Start=NewNode;
	}
	return Start;
}