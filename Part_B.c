#include <stdio.h>
#include <stdlib.h>

// Depth First Search
// define a binary tree node
struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

// create a new node
struct treeNode* createNew(int value) {
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// BFS traversal
void BFS(struct treeNode* root) {
    if (root == NULL) {
        return;
    }

    struct q {
        int front, rear;
        int size;
        struct treeNode** arr;
    };

    struct q* qu = (struct q*)malloc(sizeof(struct q));
    qu->front = 0;
    qu->rear = 0;
    qu->size = 100;
    qu->arr = (struct treeNode**)malloc(qu->size * sizeof(struct treeNode*));

    qu->arr[qu->rear++] = root;

    while (qu->front < qu->rear) {
        struct treeNode* node = qu->arr[qu->front++];
        printf("%d ", node->val);

        if (node->left != NULL) {
            qu->arr[qu->rear++] = node->left;
        }
        if (node->right != NULL) {
            qu->arr[qu->rear++] = node->right;
        }
    }
    free(qu->arr);
    free(qu);
}


int main() {
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

    printf("BFS: \n");
    BFS(root);

    return 0;
}