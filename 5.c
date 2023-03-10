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
    printf("5 \n"); // practical no.
    printf("Practical AIM: ");
    printf("Write a program to implement QUEUE using arrays that performs following operations (a)	INSERT (b) DELETE (c) DISPLAY \n"); // Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}

#define n 5
int main()
{
    student_detail();
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;
    printf("\n--------------------\n");
    printf("Queue using Array");
    printf("\n--------------------\n");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit\n");
    printf("\n--------------------\n");
    while (ch)
    {
        printf("\nEnter the Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (rear == x)
                printf("\n Queue is Full");
            else
            {
                printf("\n Enter no %d:", j++);
                scanf("%d", &queue[rear++]);
            }
            break;
        case 2:
            if (front == rear)
            {
                printf("\n Queue is empty");
            }
            else
            {
                printf("\n Deleted Element is %d", queue[front++]);
                x++;
            }
            break;
        case 3:
            printf("\n Queue Elements are:\n ");
            if (front == rear)
                printf("\n Queue is Empty");
            else
            {
                for (i = front; i < rear; i++)
                {
                    printf("%d", queue[i]);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
            }
        }
    }
}