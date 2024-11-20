#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* createDoublyLinkedList() {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    printf("Enter values for the list (-1 to stop): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}
void insertToLeft(Node** head, int target, int data) {
    Node* temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
}

void deleteNode(Node** head, int value) {
    Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void displayList(Node* head) {
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = createDoublyLinkedList();
    displayList(head);

    int choice, value, target;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert to the left of a node\n");
        printf("2. Delete a node by value\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the target node value and new value: ");
                scanf("%d %d", &target, &value);
                insertToLeft(&head, target, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
