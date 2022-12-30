#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void student_detail()
{
    time_t t;
    time(&t);
    printf("\nStudent’s Enrolment No. ");
    printf("210130107032 \n"); // Enrolment no.
    printf("Student’s Name: ");
    printf("Kirtan Anghan \n"); // name of the student
    printf("Practical no. ");
    printf("1 \n"); // practical no.
    printf("Practical AIM: ");
    printf("Introduction to pointers. Call by Value and Call by reference. \n"); // Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}
struct node
{
    int data;
    struct node *next;
} *head;
void insertEnd(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->data = val;
    if (newNode == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
}
void insertBefore(int val, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    struct node *prev;
    newNode->data = val;
    int i = 1;
    if (position == i)
    {
        insertEnd(val);
    }
    else
    {
        while (position != i)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = newNode;
        newNode->next = temp;
    }
}
void deleteFirst()
{
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
}
void deleteAfter(int position)
{
    struct node *temp = head;
    struct node *prev;
    while (position--)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev->next == head)
    {
        temp = head;
        head = head->next;
        prev->next = head;
        free(temp);
        return;
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}
void display()
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("Circular linked-list is empty\n");
    }
    else
    {
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}
int main()
{
    student_detail();
    int choice, val, position;
    do
    {
        printf("\n1.Insert a node at the end of circular linked list\n");
        printf("2.Insert a node before specified position of circular linked list\n");
        printf("3.Delete a first node of circular linked list\n");
        printf("4.Delete a node of after specified position\n");
        printf("5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value of new node\n");
            scanf("%d", &val);
            insertEnd(val);
            display();
            break;
        case 2:
            printf("Enter value of new node\n");
            scanf("%d", &val);
            printf("Enter the position\n");
            scanf("%d", &position);
            insertBefore(val, position);
            display();
            break;
        case 3:
            deleteFirst();
            display();
            break;
        case 4:
            printf("Enter the position\n");
            scanf("%d", &position);
            deleteAfter(position);
            display();
            break;
        case 5:
            display();
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}