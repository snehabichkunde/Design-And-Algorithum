#include<iostream>
#include<algorithm>
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

// function to calculate the height of the tree
int height(struct node* root)
{
    if(root == NULL)
        return 0;
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height)+1;
    }
}


// for a depth of a node
int depth(struct node* root, char key, int level) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return level;
    }

    int leftDepth = depth(root->left, key, level + 1);
    if (leftDepth != 0) {
        return leftDepth;
    }

    return depth(root->right, key, level + 1);
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
    cout << "Height of the tree is: " << height(A) << endl;
    char key = 'd';
    cout << "Depth of node '" << key << "': " << depth(A, key, 1) << endl;

    return 0;
}