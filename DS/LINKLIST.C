#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;

void create();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void display();

int main() {
    int choice;
    while (1) {
        printf("\n1. Creation\n2. Insert at beginning \n3. Insert at end \n4. Insert at position \n");
        printf("5. Delete from beginning \n6. Delete from end \n7. Delete from position \n8. Search \n");
        printf("9. Display \n10. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert_begin();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_pos();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_pos();
                break;
            case 8:
                search();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}

void create() {
    int n, item, i = 0;
    struct node *ptr, *temp;
    
    if (count == 0) {
        printf("\nEnter the number of nodes to be inserted: ");
        scanf("%d", &n);

        if (n == 0) {
            printf("\nNo nodes to create.");
            return;
        }

        while (i < n) {
            printf("\nEnter value to insert: ");
            scanf("%d", &item);

            ptr = (struct node*) malloc(sizeof(struct node));
            ptr->data = item;

            if (count == 0) {
                start = ptr;
                start->next = NULL;
                temp = start;
            } else {
                temp->next = ptr;
                temp = temp->next;
                temp->next = NULL;
            }

            count++;
            i++;
        }
    } else {
        printf("\nList already created.");
    }
}

void insert_begin() {
    int data;
    struct node* ptr;
    
    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    
    if (start == NULL) {
        start = ptr;
        start->next = NULL;
    } else {
        ptr->next = start;
        start = ptr;
    }
    count++;
}

void insert_end() {
    struct node *ptr, *temp;
    int item;
    
    ptr = (struct node*) malloc(sizeof(struct node));
    
    printf("\nEnter value: ");
    scanf("%d", &item);
    
    ptr->data = item;
    ptr->next = NULL;
    
    if (start == NULL) {
        start = ptr;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    count++;
    printf("\nNode inserted.");
}

void insert_pos() {
    int item, pos, i;
    struct node *ptr, *temp;

    printf("\nEnter value: ");
    scanf("%d", &item);
    printf("\nEnter position: ");
    scanf("%d", &pos);
    
    if (pos < 1 || pos > count + 1) {
        printf("\nInvalid position!");
        return;
    }

    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = item;

    if (pos == 1) {
        ptr->next = start;
        start = ptr;
    } else {
        temp = start;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    count++;
    printf("\nNode inserted.");
}

void delete_begin() {
    struct node* temp;
    
    if (start == NULL) {
        printf("\nList is empty.");
    } else {
        temp = start;
        start = temp->next;
        free(temp);
        count--;
        printf("\nNode deleted.");
    }
}

void delete_end() {
    struct node *temp, *ptr;
    
    if (start == NULL) {
        printf("\nList is empty.");
    } else if (start->next == NULL) {
        temp = start;
        start = NULL;
        free(temp);
        count--;
        printf("\nNode deleted.");
    } else {
        temp = start;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = NULL;
        free(ptr);
        count--;
        printf("\nNode deleted.");
    }
}

void delete_pos() {
    struct node *temp, *ptr;
    int pos, i;

    if (start == NULL) {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("\nInvalid position!");
        return;
    }

    if (pos == 1) {
        temp = start;
        start = temp->next;
        free(temp);
    } else {
        temp = start;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
    }
    count--;
    printf("\nNode deleted.");
}

void search() {
    struct node* ptr;
    int item, i = 0, found = 0;

    if (start == NULL) {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter element to search: ");
    scanf("%d", &item);

    ptr = start;
    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("\n%d found at position %d", item, i + 1);
            found = 1;
            break;
        }
        ptr = ptr->next;
        i++;
    }

    if (!found) {
        printf("\nElement not found.");
    }
}

void display() {
    struct node* ptr;

    if (start == NULL) {
        printf("\nList is empty.");
        return;
    }

    printf("\nList: ");
    ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}