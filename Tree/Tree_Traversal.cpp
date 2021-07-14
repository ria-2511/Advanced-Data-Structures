// code for the types of traversals of a binary tree 
#include <iostream>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorder_traversal(TreeNode *root) 
{
    /* this means that placing all the nodes in the leftmost sides first and then placing the others  */
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}

void preorder_traversal(TreeNode *root)
{
    /* this means that printing from the root till the leaf node of every subsequent node */
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(TreeNode *root)
{
    /* travel till the end of eevry node and then print the leaf nodes first and then backtrack */
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << " ";
}

int main()
{
    TreeNode* root = new TreeNode('A'); // create root node and keep inserting nodes 
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->left = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->right = new TreeNode('C');
    root->right->right->right = new TreeNode('E');

    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder_traversal(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder_traversal(root);
    return 0;
}