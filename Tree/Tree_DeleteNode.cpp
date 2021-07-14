// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
    int key;
    struct Node *left, *right;
};
 
/* function to create a new node of tree and
return pointer */
struct Node* newNode(int key) // to create a node 
{
    struct Node* temp = new Node; // create node 
    temp->key = key; // place data 
    temp->left = temp->right = NULL; // make both left and right as NULL
    return temp;
};
 
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
    /* start printing from the leftmost nodes of the tree */
}
 
/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(struct Node* root,
                  struct Node* d_node)
{
    queue<struct Node*> q; // create a queue of the datatype 'Node'
    q.push(root); // push the root node in it 
 
    // Do level order traversal until last node
    struct Node* temp; // create a temp pointer in the temp 
    while (!q.empty()) 
    {
        temp = q.front(); // point temp at the start of the node 
        q.pop(); // point the root node 
        if (temp == d_node) // if the deepest node is TEMP
        {
            temp = NULL; make temp NULL
            delete (d_node); // delete the deepest node 
            return; 
        }
        if (temp->right) // if there is a right node of temp  
        {
            if (temp->right == d_node) // and if that right node is the one to be deleted 
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right); // continue the same process with right of temp 
        }
 
        if (temp->left) 
        {
            // do the same process as the right node in the one 
            if (temp->left == d_node) 
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
 
/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key)
{
    if (root == NULL) // if tree is NULL
        return NULL;
 
    if (root->left == NULL && root->right == NULL) // the tree only has a root node and no more nodes 
    {
        if (root->key == key) // if root node is the one being deleted then simply return NULL
            return NULL;
        else
            return root; // else return root 
    }
 
    queue<struct Node*> q; // make a queue of the datatype 'NODE'
    q.push(root); // push root in it 
 
    struct Node* temp; // make a pointer of the type NODE 
    struct Node* key_node = NULL; // another pointer and initialise it to NULL
 
    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty()) 
    {
        /*
        IMPORTANT - 
        Since in Binary trees we don't have any order of nodes then we simply locate the deepest node and 
        then replace the node to deleted by it. 
        */
        temp = q.front(); // point temp at the start of the queue 
        q.pop(); // pop the root element from the queue 
 
        if (temp->key == key) // if temp points to the element being deleted 
            key_node = temp; // then point key_node i.e. another pointer to temp i.e to KEY
 
        if (temp->left) // if the temp has a left element 
            q.push(temp->left); // insert that element into the queue 
 
        if (temp->right) // if temp right has a right element
            q.push(temp->right); // then insert the value into the queue 
    }
    
    // here we are basically using temp to locate the deepest node 
    // and then using the delete deepest node we will delete the node 
 
    if (key_node != NULL) // i.e. we have found the node to be deleted  
    {
        int x = temp->key; // let x be the data of temp pointer i.e of the deepest node 
        deletDeepest(root, temp); // delete temp , i.e. delete the deeptest node 
        key_node->key = x; // replace the data of the node to be deleted with that of the deepest node  
    }
    return root;
    /* think of deletion as deleting the deepest node and storing it's data. 
    then replacing the data of the node to be deleted with that of the deepest Node*/
}
 
// Driver code
int main()
{
    struct Node* root = newNode(10); // start creating the tree and insert nodes 
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
 
    int key = 11;
    root = deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);
 
    return 0;
}
