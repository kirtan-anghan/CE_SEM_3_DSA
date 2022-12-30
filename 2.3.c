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

int main()
{
    student_detail();
    int *ptr, *ptr1;
    int n, i;

    n = 5;
    printf("Enter number of elements: %d\n", n);

    ptr = (int *)malloc(n * sizeof(int));

    ptr1 = (int *)calloc(n, sizeof(int));

    if (ptr == NULL || ptr1 == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {

        printf("Memory successfully allocated using malloc.\n");

        free(ptr);
        printf("Malloc Memory successfully freed.\n");

        printf("\nMemory successfully allocated using calloc.\n");

        free(ptr1);
        printf("Calloc Memory successfully freed.\n");
    }
    printf("\n\n");
    return 0;
}
