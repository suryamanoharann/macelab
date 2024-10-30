#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL, *temp, *newnode;

void create();
void display();
void ins_beg();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();

int main() {
    int ch;
    while(1) {
        printf("1.Create\n2.Display\n3.Insert at Beginning\n4.Insert at End\n5.Insert at Position\n6.Delete at Beginning\n7.Delete at End\n8.Delete at Position\n9.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: ins_beg(); break;
            case 4: ins_end(); break;
            case 5: ins_pos(); break;
            case 6: del_beg(); break;
            case 7: del_end(); break;
            case 8: del_pos(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void create() {
    int choice;
    head = NULL;
    tail = NULL; // Initialize tail to NULL at the start
    while (1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL) {
            head = tail = newnode; // For the first node, both head and tail are the same
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do You Want To Continue (0/1)? ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
    }
}

void display() {
    temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void ins_beg() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL) {
        head = tail = newnode; // If the list is empty, update both head and tail
    } else {
        head->prev = newnode;
        head = newnode;
    }
    count++;
}

void ins_end() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail != NULL) {
        tail->next = newnode;
    }
    tail = newnode;

    if (head == NULL) {
        head = newnode;
    }
    count++;
}

void ins_pos() {
    int pos, i = 1;
    printf("Enter Position: ");
    scanf("%d", &pos);

    // If position is 1, call ins_beg
    if (pos == 1) {
        ins_beg();
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    temp = head;

    // Traverse to the position just before where the new node is to be inserted
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    // If the position is invalid (beyond the end of the list)
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    // Insert the new node
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    } else {
        // If inserting at the end, update the tail
        tail = newnode;
    }

    temp->next = newnode;
    count++;
}


void del_beg() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // If the list becomes empty, reset the tail as well
        }
        free(temp);
    }
}

void del_end() {
    if (tail == NULL) {
        printf("List is empty\n");
    } else {
        temp = tail;
        tail = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL; // If the list becomes empty, reset the head as well
        }
        free(temp);
    }
}

void del_pos() {
    int pos, i = 1;
    printf("Enter Position: ");
    scanf("%d", &pos);

    // If position is 1, call del_beg
    if (pos == 1) {
        del_beg();
        return;
    }

    temp = head;

    // Traverse to the position to be deleted
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    // If the position is invalid
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Adjust pointers to remove the node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        // If deleting the last node, update the tail
        tail = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    count--;
}

