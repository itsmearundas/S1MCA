#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;  // Initialize head to NULL
struct node *tail = NULL;  // Initialize tail to NULL

void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void displayfrombeg();
void displayfromend();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at the specific position\n4. Delete from beginning\n5. Delete from end\n6. Delete from specific position\n7. Display from beginning\n8. Display from end\n9. Exit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                deletion_beginning();
                break;
            case 5:
                deletion_last();
                break;
            case 6:
                deletion_specified();
                break;
            case 7:
                displayfrombeg();
                break;
            case 8:
                displayfromend();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
    return 0;
}

void insertion_beginning() {
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Item value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->prev = NULL;
        ptr->next = head;

        if (head != NULL) {
            head->prev = ptr; // Update the previous head's prev
        } else {
            tail = ptr; // If the list was empty, set tail as well
        }

        head = ptr; // Update head to new node
        printf("\nNode inserted\n");
    }
}

void insertion_last() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;

        if (head == NULL) {
            ptr->prev = NULL;
            head = ptr;
            tail = ptr; // Set tail to the new node
        } else {
            temp = tail; // Start from the tail
            temp->next = ptr;
            ptr->prev = temp;
            tail = ptr; // Update tail to the new node
        }
        printf("\nNode inserted\n");
    }
}

void insertion_specified() {
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        temp = head;
        printf("Enter the location (0 for beginning): ");
        scanf("%d", &loc);
        if (loc == 0) {
            insertion_beginning();
            return;
        }

        for (i = 0; i < loc - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\nThere are less than %d elements\n", loc);
                free(ptr);
                return;
            }
        }

        printf("Enter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = ptr; // Update next node's previous
        } else {
            tail = ptr; // If inserting at the end, update tail
        }

        temp->next = ptr;
        printf("\nNode inserted\n");
    }
}

void deletion_beginning() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else {
        ptr = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // If the list becomes empty, set tail to NULL
        }
        free(ptr);
        printf("\nNode deleted from the beginning\n");
    }
}

void deletion_last() {
    struct node *ptr, *temp;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == NULL) {
        head = NULL;
        tail = NULL;
        free(head);
        printf("\nOnly node deleted from the list\n");
    } else {
        temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        ptr = tail;
        tail = temp;
        tail->next = NULL;
        free(ptr);
        printf("\nNode deleted from the end\n");
    }
}

void deletion_specified() {
    struct node *ptr, *temp;
    int loc, i;
    printf("Enter the location (1 for beginning): ");
    scanf("%d", &loc);
    if (loc == 1) {
        deletion_beginning();
        return;
    }

    temp = head;
    for (i = 0; i < loc - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("\nThere are less than %d elements\n", loc);
            return;
        }
    }

    ptr = temp->next;
    temp->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = temp; // Update next node's previous
    } else {
        tail = temp; // If deleting the last node, update tail
    }
    free(ptr);
    printf("\nNode deleted from the specified location\n");
}

void displayfrombeg() {
    struct node *temp;
    temp = head;
    printf("\nElements from beginning: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayfromend() {
    struct node *temp;
    temp = tail;
    printf("\nElements from end: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void search() {
    struct node *temp;
    int item, flag = 0;
    printf("Enter item to search: ");
    scanf("%d", &item);
    temp = head;
    while (temp != NULL) {
        if (temp->data == item) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1) {
        printf("\nItem found\n");
    } else {
        printf("\nItem not found\n");
    }
}