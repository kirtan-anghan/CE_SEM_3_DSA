
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void student_detail()
{
    time_t t;
    time(&t);
    printf("\nStudent’s Enrolment No. ");
    printf("210130107032 \n");       // Enrolment no.
    printf("Student’s Name: ");
    printf("Kirtan Anghan \n");      // name of the student
    printf("Practical no. ");
    printf("7 \n");                  //practical no.
    printf("Practical AIM: ");
    printf("Write a menu driven program to implement following operations on the singly linked list."

"(a) Insert a node at the front of the linked list."
"(b) Insert a node at the end of the linked list."
"(c) Insert a node such that the linked list is in ascending order.(according to info. Field)"
"(d) Delete the first node of the linked list."
"(e) Delete a node before a specified position."
"(f) Delete a node after specified position.\n");   //Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

void createList()
{
    if (start == NULL)
    {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            struct node *newnode;
            struct node *temp;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &data);
            start->info = data;

            for (int i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to"
                       " be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}

void traverse()
{
    struct node *temp;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtFront()
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;

    temp->link = start;
    start = temp;
}

void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));

    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);

    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);

    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deleteFirst()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->link;
        free(temp);
    }
}
void before_deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;

        while (i < pos)
        {
            temp = temp->link;
            i++;
        }

        position = temp->link;
        temp->link = position->link;

        free(position);
    }
}
void after_deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;

        while (i < pos - 2)
        {
            temp = temp->link;
            i++;
        }

        position = temp->link;
        temp->link = position->link;

        free(position);
    }
}

int main()
{   
    student_detail();
    int choice;
    while (1)
    {

        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at"
               " starting\n");
        printf("\t3 For insertion at"
               " end\n");
        printf("\t4 For insertion at "
               "any position\n");
        printf("\t5 For deletion of "
               "first element\n");
        printf("\t6 For deletion of "
               "element at before any position\n");
        printf("\t7 For deletion of "
               "element at after any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            before_deletePosition();
            break;
        case 7:
            after_deletePosition();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}