#include <stdio.h>
#include <stdlib.h>

// Depth First Search
//define a binary tree node
struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

//create a new binary tree node
struct treeNode* createNew(int value) {
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//preorder traversal
void preorder(struct treeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val); // print the root number first

    preorder(root->left); // traversal left tree of the root
    preorder(root->right); // traversal right tree of the root
}

//inorder traversal
void inorder(struct treeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

//postorder traversal
void postorder(struct treeNode* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}


int main(){
    struct treeNode* root = createNew(1);
    root->left = createNew(2);
    root->right = createNew(3);
    root->left->left = createNew(4);
    root->left->right = createNew(5);
    root->right->left = createNew(6);
    root->right->right = createNew(7);
    root->left->left->left = createNew(8);
    root->left->left->right = createNew(9);
    root->left->right->left = createNew(10);
    root->left->right->right = createNew(11);
    root->right->left->left = createNew(12);
    root->right->left->right = createNew(13);
    root->right->right->left = createNew(14);
    root->right->right->right = createNew(15);
    
    printf("Preorder: \n");
    preorder(root);
    printf("\n");

    printf("Inorder: \n");
    inorder(root);
    printf("\n");

    printf("Postorder: \n");
    postorder(root);
    printf("\n");

    return 0;

}