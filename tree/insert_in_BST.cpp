#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* right;
    struct node* left;
};

// create new node
struct node* createNode(char data) {
    struct node* newNode;
    newNode = new struct node;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* root, int key)
{
    if(root == NULL)
        return createNode(key);
    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

// inorder traversal 
void traversal(struct node* root)
{
    if(root == NULL)
        return;
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 13);
    insert(root, 18);
    insert(root, 11);
    insert(root, 3);
    insert(root, 20);

    cout << "Inordered traversal is: ";
    traversal(root);
    cout << endl;
    return 0;
}