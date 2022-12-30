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
    printf("9 \n"); // practical no.
    printf("Practical AIM: ");
    printf("Write a program to implement a queue using a linked list. \n"); // Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}
struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("Element: %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    student_detail();
    linkedListTraversal(f);
    printf("enqueuing element 34\n");
    printf("enqueuing element 4\n");
    printf("enqueuing element 7\n");
    printf("enqueuing element 17 \n\n");

    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d \n\n", dequeue());
    linkedListTraversal(f);
    return 0;
}