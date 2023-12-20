#include<iostream>
using namespace std;

struct node{
    char data;
    struct node* right;
    struct node* left;
};

// create new node
struct node* createNode(char data) {
    struct node* newNode;
    newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// inorder traversal
// left subtree -> root -> right subtree

void traversal(struct node* root)
{
    if(root == NULL)
        return;
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}

/*
Lets create a tree like 

           A
        /    \
        B     C
       /  \  /  \
       D   E F   G
*/

int main()
{
    struct node *A = createNode('a');
    struct node *B = createNode('b');
    struct node *C = createNode('c');
    struct node *D = createNode('d');
    struct node *E = createNode('e');
    struct node *F = createNode('f');
    struct node *G = createNode('g');
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;
    traversal(A);
    cout << endl;
}