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
    printf("2 \n"); // practical no.
    printf("Practical AIM: ");
    printf("Introduction to Dynamic Memory Allocation. DMA functions malloc(), calloc(), free() etc. \n"); // Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}

int main()
{
    student_detail();
    int *ptr;
    int n, i;

    n = 5;
    printf("Enter number of elements: %d\n", n);

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {

        printf("Memory successfully allocated using calloc.\n");

        for (i = 0; i < n; ++i)
        {
            ptr[i] = i + 1;
        }

        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d, ", ptr[i]);
        }
    }
    printf("\n\n");
    return 0;
}
