#include <stdio.h>
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
    printf("16\n");                  //practical no.
    printf("Practical AIM: ");
    printf("Write a program to implement Bubble Sort. \n");   //Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
  student_detail();
	int arr[] = { 5, 1, 4, 2, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
  printf("\n");
	return 0;
}