#include <iostream>
using namespace std;

// creating and printing a linked list 

struct node 
{
    struct node *next; 
    int data ; 
} *head = NULL;

int main() {
	// your code goes here
	struct node *newnode ; 
	int n ;
	cout<<"enter the number of elements"<<endl;
	cin>>n;
	int i ; 
	for(i=0;i<n;i++)
	{
	    newnode = new node ; 
	    int item; 
	    cin>>item ; 
	    newnode -> data = item ; 
	    newnode -> next = NULL ; 
	    struct node *temp;
	    if(head == NULL)
	    {
	        head = temp = newnode;
	    }
	    else 
	    {
	        temp -> next = newnode ; 
	        temp = newnode ;
	    }
	}
	
	// printing the linked list
	cout<<"the linked list is below :"<<endl;
	struct node *ptr; 
	ptr = head; 
	while(ptr != NULL)
	{
	    cout<<ptr -> data <<endl;
	    ptr = ptr -> next ;
	}
	return 0;
}
