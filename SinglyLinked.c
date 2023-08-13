/***
 * Name:Subhrajit Das   Stream: MCS
 * Program details: Various Operations on Singly Linked List
 ***/

#include<stdio.h>
#include<stdlib.h>

//Structure Definition of each Singly Linked List Node
struct Node 
{
	int Data;                          //Data or Information Part
	struct Node *Next;                 //Holds address of Next Node(if exists else NULL)
};
typedef struct Node *Node;

Node createList();                      //function for initialization of creating a List of Singly Linked List Nodes
Node createNode();                      //function to creating each Singly Linked List node in the memory
Node sortedCreateList();				//function for sorted creation of Singly Linked List Nodes
int countNode(Node);                    //function for counting the number of nodes
Node stackOperation(Node);                  //function for doing various stack operations implemented using linked list
Node queueOperation(Node);                  //function for doing various queue operations implemented using linked list
void listOperations();                  //function for doing various linked list operations

Node insertBeginNode(Node,Node);	
Node insertEndNode(Node,Node);
Node sortedInsert(Node);
Node insertBegin(Node);                 //function for insert a element in the begining of the list
Node insertEnd(Node);                   //function for insert a element at the end of the list
Node insertMiddle(Node);                //function for insert a element in the middle of the list
Node insertAtPos(Node,int);            //function for insert a element in any  desired exisiting position of the list
Node insertAfterElement(Node);      //function for insert a element after any element in the  list
Node insertBeforeElement(Node);         //function for insert a element after any element in the  list
void insertAfterNode(Node);             //function for insert a element after a node

Node pushStack(Node);                   //function to push a element onto the stack
Node popStack(Node);                    //function to pop a element from the stack

Node insertQueue(Node);                 //function to insert a  element in the queue
Node deleteQueue(Node);                 //function to delete a  element from the queue

Node deleteBegin(Node);                 //function to delete a element from the beginning of the list
Node deleteEnd(Node);                   //function to delete a element from the end of the list
Node deletePos(Node,int);               //function to delete a element from any existing position of the list
Node deleteAll(Node);                   //function to delete all the nodes from the list
void deleteMiddle(Node);		    //function to delete the middle node from the list

void sortList(Node);
void swapList(Node,Node);
int getPos(Node,int);                   //function to get the position of a element in the list
Node concatList(Node,Node);             //function to concatenate two linked lists
Node reverseList(Node);                 //function to reverse a linked list

void printStack(Node);                  //function to print the stack
void printQueue(Node);                  //function to print the queue
void displayList(Node);                 //function to display the elements of the linked list

//main function taking no arguments and returning 0 upon successful completion of the program
int main ()
{
    listOperations();

}
//function for doing various stack operation implemented using linked list taking no arguments and return void
Node stackOperation(Node Start)
{
    char ch;
    int choice,flag=0;
    system("clear");
    printStack(Start);
    printf("\nNow, lets perform operations on to the Stack: ");
    printf("\nPress the numbers in the brackets to perform respective operations: ");
    while(flag==0) {
        printf("\n Push: (1)  Pop:  (2)   Display:   (3)   Exit:   (9) ");
        printf("\n Enter your choice:\t");
        scanf("\n%d",&choice);
        switch(choice) {
            case 1:
                do {
                    Start=pushStack(Start);
                    printStack(Start);
                    printf("\nDo you want to continue (y/n)::\t");
                    scanf("\n%c",&ch);
                } while(ch=='y' || ch=='Y');
		    system("clear");
                break;
            case 2:
                do {
                    Start=popStack(Start);
                    printStack(Start);
                    printf("\nDo you want to continue (y/n)::\t");
                    scanf("\n%c",&ch);
                } while(ch=='y' || ch=='Y');
		    system("clear");
                break;
            case 3:
                system("clear");
                printStack(Start);
                break;
            case 9:
                flag=1;
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice: TRY Again ");
        }
    }
    return Start;
}


//function for doing various queue operations implemented using linked list taking no argument and returning void
Node queueOperation(Node Start)
{
    char ch;
    int choice,flag=0;
    system("clear");
    printQueue(Start);
    printf("\nNow, lets perform operations on to the Queue: ");
    printf("\nPress the numbers in the brackets to perform respective operations: ");
    while(flag==0) {
        printf("\n Insert (1)  Delete:  (2)   Display:   (3)   Exit:   (9) ");
        printf("\n Enter your choice:\t");
        scanf("\n%d",&choice);
        switch(choice) {
            case 1:
                do {
                    Start=insertQueue(Start);
                    printQueue(Start);
                    printf("\nDo you want to continue (y/n)::\t");
                    scanf("\n%c",&ch);
                } while(ch=='y' || ch=='Y');
                system("clear");
                break;
            case 2:
                do {
                    Start=deleteQueue(Start);
                    printQueue(Start);
                    printf("\nDo you want to continue (y/n)::\t");
                    scanf("\n%c",&ch);
                } while(ch=='y' || ch=='Y');
                system("clear");
                break;
            case 3:
                system("clear");
                printQueue(Start);
                break;
            case 9:
                flag=1;
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice: TRY Again ");
        }
    }
    return Start;
}

//function for pushing a element on the stack taking the first node as a argument 'Start' and returning the 'Start'
//it calls the insertBegin() to push the element onto the stack
Node pushStack(Node Start)
{
    Start=insertBegin(Start);
    printf("\nSuccessfully pushed. ");
    return Start;
}

//function for popping out a element from the stack taking the first node as a argument 'Start' and returning the 'Start'
//it calls the deleteBegin() to pop the element from the stack
Node popStack(Node Start)
{
    Start=deleteBegin(Start);
    printf("\nSuccessfully popped. ");
    return Start;
}

//function for inserting a element in the queue taking the first node as a argument 'Start' and returning the 'Start'
//it calls the insertEnd() to insert the element in the queue
Node insertQueue(Node Start)
{
    Start=insertEnd(Start);
    printf("\nSuccessfully inserted element into the queue! ");
    return Start;
}

//function for deleting a element from the queue taking the first node as a argument 'Start' and returning the 'Start'
//it calls the deleteBegin() to delete the element from the queue
Node deleteQueue(Node Start)
{
    Start=deleteBegin(Start);
    printf("\nSuccessfully deleted a element from the queue! ");
    return Start;
}

//function for printing the elements of the Stack taking the first node as a argument 'Start' and returning void
void printStack(Node Start)
{
    Node temp=Start;
    printf("\nStack Content:");
    while(temp!=NULL){
        printf("\n%d",temp->Data);
        temp=temp->Next;
    }
}

//function for printing the elements of the Queue taking the first node as a argument 'Start' and returning void
void printQueue(Node Start)
{
    Node temp=Start;
    printf("\nQueue Content:");
    while(temp!=NULL) {
        printf(" %d   ",temp->Data);
        temp=temp->Next;
    }
}

//function for doing various menu-driven linked list operations implemented using linked list taking no argument and returning void
//it performs various operations based on the choice value given by the user with the help of switch-case
//Operations inlclude several insert operations, delete operations
// reverse and concatenate operations and also display operation
void listOperations()
{
    Node Start,Start2;
    int choice1,choice2,temp,flag=0,flagOuter=0,flagInnerNext=0,flagInner=0,pos=0,choice;
    char ch;
    system("clear");
    printf("\nWelcome! Lets create a Linked List first then we are moving on!");
    while(flag==0) {
		printf("\nPress the numbers in the brackets to perform respective operations: ");
		printf("\n Usual Creation:  (1)    Sorted Creation:   (2) ");
		printf("\n Enter your choice:\t");
		scanf("\n%d",&choice);
		switch(choice) {
			case 1:
				Start=createList();
				flag=1;
				break;
			case 2:
				Start=sortedCreateList();
				flag=2;
				break;
			default:
				printf("\nWrong Choice! Enter correct value! ");
		}
	}
    system("clear");
    displayList(Start);
    printf("\nNow, lets perform operations on Linked List: ");
    printf("\nPress the numbers in the brackets to perform respective operations: ");
    while(flagOuter==0) {
      flagInner=0;
      while(flagInner==0) {
        printf("\nMAIN MENU\n");
        printf("\n Insert: (1)  Delete:  (2)  Concatenate:  (3)  Stack Mode:  (4)  Queue Mode:  (5)   Reverse:  (6)  Sort:   (7)    Display:   (8)   Exit:   (9) ");
        printf("\n Enter your choice:\t");
        scanf("\n%d",&choice1);

         switch(choice1) {
            case 1:
                flag=0;
               while(flag==0) {
                system("clear");
                displayList(Start);
                printf("\nPress the numbers in the brackets to perform respective operations: ");
                printf("\n Insert Beginnging: (1)  Insert End:  (2)  Insert At Any Position:  (3)");
                printf("\n  Go back to main menu:   (9) ");
                printf("\n Enter your choice:\t");
                scanf("\n%d",&choice2);

                switch(choice2) {
                    case 1:
                            Start=insertBegin(Start);
                            displayList(Start);
                            break;
                    case 2:
                            Start=insertEnd(Start);
                            displayList(Start);
                            break;
                    case 3:
                        flagInnerNext=0;
                        system("clear");
                        while(flagInnerNext==0){
                            displayList(Start);
                            printf("\n Insert Before Element:     (1)    Insert After Element:      (2)       Insert At Position:   (3)        Go back to previous menu:    (9)");
                            printf("\nEnter your choice:\t");
                            scanf("\n%d",&choice2);
                            switch(choice2) {
                                case 1:
                                    Start=insertBeforeElement(Start);
                                    displayList(Start);
                                    flagInnerNext=1;
                                    break;
                                case 2:
                                    Start=insertAfterElement(Start);
                                    displayList(Start);
                                    flagInnerNext=2;
                                    break;
                                case 3:
                                    printf("\nEnter the position in which you want to enter the element:  ");
                                    scanf("\n%d",&pos);
                                    Start=insertAtPos(Start,pos);
                                    displayList(Start);
                                    flagInnerNext=3;
                                    break;
                                case 9:
                                    printf("\nGoing back...");
                                    flagInnerNext=9;
                                default:
                                    printf("\nInvalid choice! Please try again....\t");
                            }
                        }
                        flagInner=3;
                        break;
                    case 9:
                        flag=9;
                        flagInner=9;
                        break;
                    default:
                        printf("\nInvalid choice going back to main menu...");
                }
            }
                break;
            case 2:
                flagInner=0;
              while(flagInner==0) {
                system("clear");
                displayList(Start);
                printf("\nPress the numbers in the brackets to perform respective operations: ");
                printf("\n Delete Beginnging: (1)  Delete End:  (2)  Delete At Any Position:  (3)  ");
                printf("\n Delete All:   (4)   Go back to main menu:   (9) ");
                printf("\n Enter your choice:\t");
                scanf("\n%d",&choice2);
                switch(choice2) {
                    case 1:
                            Start=deleteBegin(Start);
                        break;
                    case 2:
                            Start=deleteEnd(Start);
                        break;
                    case 3:
                            printf("\nEnter the position: ");
                            scanf("\n%d",&temp);
                            Start=deletePos(Start,temp);
                        break;
                    case 4:
                            Start=deleteAll(Start);
                        break;
                    case 9:
                        flagInner=9;
                        break;
                    default:
                        printf("\nInvalid choice going back to main menu...");
                }

              }
              break;
            case 3:
                system("clear");
                printf("For concatenation, we've to create a new list: Creating a new list... ");
                Start2=createList();
                printf("\nPerforming concatenation: ");
                Start=concatList(Start,Start2);
                printf("\nConcatenation done Successfully. ");
                flagInner=3;
                break;
            case 4:
                Start=stackOperation(Start);
                flagInner=4;
                break;
            case 5:
                Start=queueOperation(Start);
                flagInner=5;
                break;
            case 6:
                system("clear");
                printf("\nPerforming Reverse operation...");
                printf("\nReversing done!");
                Start=reverseList(Start);
                displayList(Start);
                flagInner=6;
                break;
            case 7:
                        sortList(Start);
                        system("clear");
                        printf("\nSorting done...");
                        displayList(Start);
                        flagInner=7;
                        break;
            case 8:
                system("clear");
                displayList(Start);
                flagInner=8;
                break;
            case 9:
                flagInner=9;
                flagOuter=9;
                break;
            default:
                printf("\nInvalid choice: Try again");

        }
        }
      }
    printf("\nThank you! Completed Successfully. \n");
}

//function to create a node in the memory returning the creating node
Node createNode()
{
	Node Temp = (Node) malloc (sizeof(Node));
    if(Temp!=NULL) {
        Temp->Next=NULL;
        return Temp;
    }
}

//function for creating the initial linked list
//returns the starting node of the list to the calller
//it provides two ways for inserting the element in the list: insert begin and insert end
Node createList()
{
	char ch;
	int choice;
	Node Start=NULL;
    system("clear");
    printf("\nCreating Linked List...");
	printf("\nDo you want to do Insert at Begining (Press 1) or Insert at End (Press 2):\t");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			do {
				Start=insertBegin(Start);
				printf("\nDo you want to continue (y/n)::\t");
				scanf("\n%c",&ch);
			} while(ch=='y' || ch=='Y');
			break;
		case 2:
			do {
                Start=insertEnd(Start);
                printf("\nDo you want to continue (y/n)::\t");
                scanf("\n%c",&ch);
            } while(ch=='y' || ch=='Y');
            break;
		default:
			printf("\nInvalid choice: Run Again");
	}
	system("clear");
	printf("\nCreation Successful!\n");
	displayList(Start);
	return Start;
}

Node sortedCreateList()
{
	Node Start=NULL,temp1,temp2;
	char choice='n';
	do { 
		Start=sortedInsert(Start);
		printf("\nDo you want to continue? (y/n):\t");
		scanf("\n%c",&choice);
	}while(choice=='y' || choice=='Y');
	return Start;
}

Node sortedInsert(Node Start) 
{
		Node new_node,temp1,temp2;
		new_node=createNode();
		printf("\nEnter the data:\t");
		scanf("\n%d",&new_node->Data);
		
		if(Start==NULL) {
			Start=insertBeginNode(Start,new_node);
			return Start;
		}
		temp1=Start;
		temp2=NULL;
		while((temp1!=NULL)&&(new_node->Data>=temp1->Data)) {
			temp2=temp1;
			temp1=temp1->Next;
		}
		 if(temp2==NULL) {
			Start=insertBeginNode(Start,new_node);
			return Start;
		 }
		 else {
			if(temp1==NULL) {
				Start=insertEndNode(Start,new_node);
			}
			else {
				new_node->Next=temp2->Next;
				temp2->Next=new_node;
			}
		 }
		return Start;
}
Node insertBeginNode(Node Start, Node NewNode)
{
	if(NewNode==NULL) 
		return 0;
	if(Start==NULL)
		Start=NewNode;
	else {
		NewNode->Next=Start;
		Start=NewNode;
	}
	return Start;
}
Node insertEndNode(Node Start, Node NewNode)
{
	Node Temp;
	if(NewNode==NULL)
		return 0;
	if(Start==NULL) 
		Start=NewNode;
	else {
        Temp=Start;
		while(Temp->Next!=NULL) {
			Temp=Temp->Next;
		}
		Temp->Next=NewNode;
	}
	return Start;
}

//function to count the number of nodes while taking the starting node of the list as argument and returns the count of the node
int countNode(Node Start)
{
    int count=1;
    Node p=Start;
    while(p!=NULL){
        p=p->Next;
        count++;
    }
    return count;

}

//function to insert a element at the beginning of the list
//it takes the starting node as a argument and also returns it
Node insertBegin(Node Start) 
{
	int Value;
	Node NewNode=createNode();
	if(NewNode==NULL) 
		return 0;
	printf("\nEnter Data for insertion:\t");
	scanf("%d",&Value);
	NewNode->Data=Value;
	if(Start==NULL)
		Start=NewNode;
	else {
		NewNode->Next=Start;
		Start=NewNode;
	}
	return Start;
}

//function to insert a element at the end of the list
//it takes the starting node as a argument and also returns it
Node insertEnd(Node Start)
{
	int Value;
	Node Temp;
	Node NewNode=createNode();
	if(NewNode==NULL)
		return 0;
	printf("\nEnter Data for insertion:\t");
	scanf("%d",&Value);
	NewNode->Data=Value;
	if(Start==NULL) 
		Start=NewNode;
	else {
        Temp=Start;
		while(Temp->Next!=NULL) {
			Temp=Temp->Next;
		}
		Temp->Next=NewNode;
	}
	return Start;
}

//function to insert a element in the middle of the list
//it takes the starting node as a argument and also returns it
Node insertMiddle(Node Start)
{
    Node temp1,temp2;
    temp1=temp2=Start;
    while(temp2->Next->Next!=NULL) {
        temp1=temp1->Next;
        temp2=temp2->Next->Next;
    }
    insertAfterNode(temp1);
    return Start;
}

//function for insert a element after a node
//it takes the address of the node as a argument
void insertAfterNode(Node p)
{
      Node q=createNode();
      printf("\nEnter Data:  ");
      scanf("\n%d",&q->Data);
      q->Next=p->Next;
      p->Next=q;
}


//function for insert a element at the specific existing position in the list
//it takes the starting node and the position as arguments and returns the starting node
Node insertAtPos(Node Start, int pos)
{
    Node p,q;
    int i,n=countNode(Start);
    if(pos>=1) {                        // if pos>count of nodes it will be inserted at the last
        if(pos==1)
            Start=insertBegin(Start);
        else
            if(pos>=n)
                insertEnd(Start);
            else {
                p=Start;
                i=1;
                while(i<=pos-2) {
                    p=p->Next;
                    i++;
                }
                q=createNode();
                printf("\nEnter Data:  ");
                scanf("\n%d",&q->Data);
                q->Next=p->Next;
                p->Next=q;
            }
    }
    else
        printf("\nInsertion not possible: Either Empty or Invalid Position (or Data not found for Insert Before/After Element)\n");
    return Start;
}


//function for insert a element after a specific existing element in the list
//it takes the starting node and the element as arguments and returns the starting node
Node insertAfterElement(Node Start)
{
    int pos,ele;
    printf("\nEnter the element: ");
    scanf("\n%d",&ele);
    pos=getPos(Start,ele);
    if(pos==1)
        Start=insertAtPos(Start,2);
    else
        Start=insertAtPos(Start,pos);
    return Start;
}
//function for insert a element before a specific existing element in the list
//it takes the starting node and the element as arguments and returns the starting node
Node insertBeforeElement(Node Start)
{
    int pos,ele;
    printf("\nEnter the element: ");
    scanf("\n%d",&ele);
    pos=getPos(Start,ele);
    if(pos>1){
        Start=insertAtPos(Start,pos-1);
        return Start;
    }
    if(pos==1) {
        Start=insertBegin(Start);
        return Start;
    }
    printf("\nInsert not possible! ");
    return Start;
}

//function to get the position of a element in the list
int getPos(Node Start, int ele)
{
    Node temp;
    int count=1;
    if(Start==NULL){
        printf("\nEmpty List");
        return -1;
    }
    if(Start->Data==ele){
            return count;
        }
    temp=Start;
    while(temp!=NULL){
        if(temp->Data==ele){
            return ++count;
        }
        ++count;
        temp=temp->Next;
    }
    printf("\nData not found!");
    return 0;
}

//function to delete all the elements of the linked list. it deletes all the elements using deleteBegin(), takes the starting element of the linked list and returns the updated starting
//element i.e. NULL
Node deleteAll(Node Start) {
    while(Start!=NULL) {
        Start=deleteBegin(Start);
    }
    printf("\nDeleted all nodes Successfully! ");
    return Start;
}

//function to delete the first element of the linked list. it takes the starting element of the linked list and returns the starting element of the updated Linked listw
Node deleteBegin(Node Start)
{
    Node temp;
    int data;
    if(Start==NULL) {
        printf("\nEmpty Linked List: Nothing to delete! ");
    }
    else {
        temp=Start;
        Start=Start->Next;
        data=temp->Data;
        free(temp);
        printf("\nData deleted: %d ",data);
    }
    return Start;
}

//function to delete the ending element of the linked list. it takes the starting element of the linked list and returns the starting element of the updated Linked list
Node deleteEnd(Node Start)
{
    Node temp,p;
    int data;
    if(Start==NULL){
        printf("\nDeletion not possible! Empty!");
        return Start;
    }
    temp=Start;
    if(temp->Next==NULL){
        data=temp->Data;
        Start=NULL;
        free(temp);
        printf("\nData deleted: %d ",data);
        return Start;
    }
    if(temp->Next->Next==NULL) {
        p=temp->Next;
        temp->Next=NULL;
        data=p->Data;
        free(p);
        printf("\nData deleted: %d ",data);
        return Start;
    }
    while(temp->Next->Next!=NULL)
        temp=temp->Next;
    p=temp->Next;
    temp->Next=NULL;
    data=p->Data;
    free(p);
    printf("\nData deleted: %d ",data);
    return Start;

}

//function to delete the middle element of linked list. it takes the starting element as argument.
void deleteMiddle(Node Start)
{
    int data;
    Node temp1,temp2,temp3;
    temp1=temp2=Start;
    while(temp2->Next->Next) {
        temp3=temp1;
        temp1=temp1->Next;
        temp2=temp2->Next->Next;
    }
    temp3->Next=temp1->Next;
    if(temp2==NULL) {
        printf("\nDeletion not possible! ");
        return;
    }
    data=temp1->Data;
    free(temp1);
    printf("\nData deleted: %d ",data);
}

//function to delete the element of existing position. it takes starting element of list and the position of the element to be deleted as arguments and returns the starting element of linked list
Node deletePos(Node Start, int pos)
{
    Node p,q;
    int i,data,n=countNode(Start);
    if(pos>=1 && pos <=n) {
        if(pos==1)
            Start=deleteBegin(Start);
        else
            if(pos==n)
                Start=deleteEnd(Start);
            else {
                p=Start;
                i=1;
                while(i<=pos-2) {
                    p=p->Next;
                    i++;
                }
                q=p->Next;
                data=q->Data;
                p->Next=q->Next;
                q->Next=NULL;
                free(q);
                printf("\nData deleted: %d ",data);
            }
    }
    else
        printf("\nDeletion not possible: Either Empty or Invalid Position ");
    return Start;
}

//function to concatenate two linked list. it takes two linked lists as argument and returns the starting element of the concatenated linked list
Node concatList(Node p, Node q)
{
    Node r;
    if(p==NULL)
        return q;
    if(q==NULL)
        return p;
    r=p;
    while(p->Next!=NULL)
        p=p->Next;
    p->Next=q;
    return r;
}

void swapList(Node p, Node q) {
    int t;
    t=p->Data;
    p->Data=q->Data;
    q->Data=t;
}

void sortList(Node Start)
{
    Node p,q;
    if(Start==NULL)
        printf("\nEmpty List! ");
    else {
        for(p=Start;p!=NULL;p=p->Next) {
            for(q=p->Next;q!=NULL;q=q->Next) {
                if(p->Data>q->Data) {
                    swapList(p,q);}
            }
        }
    }
}

//function to reverse the order of the elements of the linked list
//it takes the strating node as input and returns the starting node of the reversed list
Node reverseList(Node Start)
{
    Node p,q,r;
    p=r=NULL;
    q=Start;
    while(q!=NULL) {
        p=q->Next;
        q->Next=r;
        r=q;
        q=p;
    }
    Start=r;
    return Start;
}

//function to print the elements of the linked list
//it takes the starting node as in the input and displays the linked list element
void displayList(Node Temp)
{	
	printf("\nLinked List Data: \n");
	while(Temp!=NULL) {
		printf(" %d--->",Temp->Data);
	        Temp=Temp->Next;	
	}
	printf("NULL\n");	
}

