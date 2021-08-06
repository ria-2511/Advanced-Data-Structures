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

void delete_start()
{
    struct node *ptr; 
    ptr = head ; 
    head = head->next; 
    delete ptr;
}

void delete_end()
{
   struct node *ptr,*preptr ; 
   ptr = head ; 
   while(ptr->next != NULL)
   {
       preptr = ptr ;
       ptr = ptr ->next;
   }
   preptr -> next = NULL ; 
   delete ptr;
}

void delete_mid(int num)
{
    struct node *ptr , *preptr; 
    ptr = head ; 
    while (ptr-> data != num)
    {
        preptr = ptr ; 
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next ; 
    delete ptr ;
}

int main() {
	insert(1);
	insert(2);
	insert(5);
	insert(9);
	insert(101);
	insert(100);
	printList();
    delete_mid(101);
    printList();
	return 0;
}
