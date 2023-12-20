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
    newNode = new struct node;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* 
Subtree first Algorithum 
- go to left
    node = node.letf
untill we fild 
    node.left = null
*/

struct node* subTreeFirst(struct node* root)
{
    if(root == NULL)
        return NULL;
    else if(root-> left == NULL)
        return root;
    else 
        return subTreeFirst(root->left);
}

/*
successor => next after node tree's traversal in inorder

Algorithum:
if node.right:
    return subtree_first(node.righ)
else 
    walk up in the tree untill you go to left brach
    (node == node)
    return node
*/
struct node* successor(struct node* root, struct node* target) {
    if (target == NULL)
        return NULL;

    if (target->right != NULL) {
        return subTreeFirst(target->right);
    } else {
        
        struct node* parent = NULL;
        struct node* current = root;

        while (current != NULL && current != target) {
            if (target->data < current->data) {
                parent = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return parent;
    }
}

int main()
{
    
/*
Lets create a tree like 

           A
        /    \
        B     C
       /  \  /  \
       D   E F   G
*/
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

    return 0;
}