#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->value) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}
void inOrder(struct Node* root) {
    if (root!=NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}
void preOrder(struct Node* root) {
    if (root!=NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node* root) {
    if (root!=NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}
void displayTraversal(struct Node* root, int traversalOption) {
    switch(traversalOption) {
        case 1:
            printf("In-order traversal: ");
            inOrder(root);
            break;
        case 2:
            printf("Pre-order traversal: ");
            preOrder(root);
            break;
        case 3:
            printf("Post-order traversal: ");
            postOrder(root);
            break;
        default:
            printf("Invalid traversal type\n");
            return;
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int n, value,option;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("Enter value of node %d: ",i+1);
        scanf("%d",&value);
        root = insert(root,value);
    }
    do {
        printf("\nChoose traversal type:\n");
        printf("1. In-order\n");
        printf("2. Pre-order\n");
        printf("3. Post-order\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        if (option==4) {
            break;
        } else {
            displayTraversal(root,option);
        }
    } while (option!=4);

    return 0;
}
