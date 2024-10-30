#include <stdio.h>
#include <stdlib.h>
#define N 5

int front = -1, rear = -1;
int queue[N];
int count = 0; // Initialize count variable

void insert();
void delete();
void display();
void displayCount(); // Function to display count

int main()
{
    int choice;
    while (1)
    {
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Display Count\n5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            displayCount(); // Call to display count
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

void insert()
{
    int item;
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);

    if (((rear + 1) % N) == front)
    {
        printf("The Queue is Full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
        count++; // Increment count
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = item;
        count++; // Increment count
    }
}

void delete()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("The deleted element is %d\n", queue[front]);
        front = rear = -1;
        count--; // Decrement count
    }
    else
    {
        printf("The deleted element is %d\n", queue[front]);
        front = (front + 1) % N;
        count--; // Decrement count
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        printf("The Queue is: ");
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[i]);
    }
}

void displayCount()
{
    printf("Current number of elements in the Queue: %d\n", count);
}
