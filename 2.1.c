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
    printf("This program has been writeen at (date and time) : %s \n\n", ctime(&t));
}

int main()
{
    student_detail();
    int *ptr;
    int n, i;

    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {

        printf("Memory successfully allocated using malloc.\n");

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
printf("\n \n");
    return 0;
}