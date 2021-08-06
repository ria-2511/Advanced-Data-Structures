#include <iostream>
using namespace std;

// implementing a linked list using functions 

struct node 
{
    struct node *next; 
    int data ; 
} *head = NULL;

void insert(int item)
{
    struct node *newnode ; 
    newnode = new node ; 
    newnode -> data = item ; 
    newnode -> next = NULL ;
    struct node *temp;
    if (head == NULL)
    {
        head = temp = newnode ;
    }
    else 
    {
        temp -> next = newnode ; 
        temp = newnode;
    }
}

void printList()
{
    struct node *ptr1 ; 
    ptr1 = head ; 
    while (ptr1 != NULL)
    {
        cout<< ptr1 -> data <<endl;
        ptr1 = ptr1 -> next;
    }
}

void insert_start(int num)
{
    struct node *newnode1 ; 
    newnode1 = new node ; 
    newnode1 -> data = num ; 
    newnode1 -> next = head ; 
    head = newnode1;
}

void insert_end(int num)
{
    struct node *newnode1; 
    newnode1 = new node ; 
    newnode1 -> data = num ; 
    newnode1 -> next = NULL ; 
    struct node *ptr;
    ptr = head ; 
    while (ptr->next != NULL)
    {
        ptr = ptr -> next ;
    }
    ptr -> next = newnode1;
}

void insert_after(int num , int element)
{
    struct node *newnode1;
    newnode1 = new node ; 
    newnode1 -> data = num ; 
    newnode1 -> next = NULL ; 
    struct node *ptr2 , *preptr;
    ptr2 = head ; 
    preptr= ptr2 ; 
    while (preptr->data != element)
    {
        preptr = ptr2; 
        ptr2 = ptr2 -> next ;
    }
    preptr -> next = newnode1;
    newnode1-> next = ptr2;
}

int main() {
	insert(1);
	insert(2);
	insert(5);
	insert(100);
	printList();
	insert_start(0);
	printList();
	insert_end(1000);
	printList();
	insert_after(18,2);
	printList();
	return 0;
}
