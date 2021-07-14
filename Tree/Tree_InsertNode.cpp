// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
 
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
/* Function to create a new node */
 
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
/* Function to insert element in binary tree */
 
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q; // create a queue of the datatype 'Node'
    q.push(root); // put the root node as the first node in the queue 
 
    while (!q.empty()) 
    {
        /* Note about this loop - 
        This loop starts to view the node from root and searches for a NULL node. The moment it finds a NULL 
        node , it creates a new node there and then returns. if it does not find a NULL node then it continues
        with the loop and goes on until it finds one. order of Searching is ROOT , LEFT and then RIGHT of 
        each respective node.
        */
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
 
/* Inorder traversal of a binary tree */
 
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
    /*
    By inorder traversal they mean that first the LEFTMOST nodes will be printed starting from the leaf 
    nodes and then the other ones will be printed. 
    */ 
}
 
// Driver code
int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = InsertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
 
    return 0;
}