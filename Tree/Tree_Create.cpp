// Binary Tree Code - i.e. a tree that can have 2 nodes as children 
// this is a code to just create the tree and not print it or traverse it

#include <bits/stdc++.h>
using namespace std;

// defining the structure for the tree Node

struct node 
{
    int data; 
    struct node *left = NULL;
    struct node * right = NULL;
    
    node (int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main 
{
    // create the main ROOT NODE first 
    struct node* root = new node(1);
    
    // create the nodes further with left and right values 
    
    root-> left = new node(2);
    root->right = new node(3);
    
    root->left->left = new node(4);
    
    /* The Tree looks something like this now :
    
                    1
                  /   \
                 2     3 
                / \   / \
               4   x x   x
    
    */
    
    return 0;
}
