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

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
    return NULL;
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
    return 0;
}

int main()
{
    student_detail();
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    linkedListTraversal(top);
    printf("\n");
    int element = pop(top);
    printf("Popped element is %d\n", element);
    printf("\n");
    linkedListTraversal(top);
    printf("\n");
    return 0;
}