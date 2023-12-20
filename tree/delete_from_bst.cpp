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
struct node* subTreeFirst(struct node* root)
{
    if(root == NULL)
        return NULL;
    else if(root-> left == NULL)
        return root;
    else 
        return subTreeFirst(root->left);
}

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



// inorder traversal 
void traversal(struct node* root)
{
    if(root == NULL)
        return;
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }

        struct node* temp = subTreeFirst(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
    deleteNode(root, 18);
    cout << "Inordered traversal is: ";
    traversal(root);
    cout << endl;
    return 0;
}