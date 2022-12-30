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
    printf("1 \n");                  //practical no.
    printf("Practical AIM: ");
    printf("Introduction to pointers. Call by Value and Call by reference. \n");   //Aim of practical
    printf("This program has been writeen at (date and time) : %s \n\n", ctime(&t));
}

void swap(int *, int *);  
int main()  
{  
student_detail();
    int a = 10;  
    int b = 20;   
    printf("Before swapping the values in main a = %d, b = %d\n",a,b); 
    swap(&a, &b);
    printf("After swapping values in main a = %d, b = %d\n",a,b); 
    printf("\n\n"); 
}  
void swap (int *a, int *b)  
{  
    int temp;   
    temp = *a;  
    *a=*b;  
    *b=temp;  
    printf("After swapping values in function a = %d, b = %d\n",*a,*b); 
}  
