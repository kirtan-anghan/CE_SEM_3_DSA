#include<stdio.h>
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
    printf("14 \n");                  //practical no.
    printf("Practical AIM: ");
    printf("Write a program to implement Quick Sort. \n");   //Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}

#define n 5
int main() {
  student_detail();
  int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;
  //clrscr();
  printf("Queue using Array");
  printf("\n1.Insertion \t2.Deletion \t3.Display \t4.Exit");
  while (ch) {
    printf("\nEnter the Choice:");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      if (rear == x)
        printf("\n Queue is Full");
      else {
        printf(" Enter no %d:", j++);
        scanf("%d", & queue[rear++]);
      }
      break;
    case 2:
      if (front == rear) {
        printf("\n Queue is empty");
      } else {
        printf("\n Deleted Element is %d", queue[front++]);
        x++;
      }
      break;
    case 3:
      printf("\n Queue Elements are:\n ");
      if (front == rear)
        printf("\n Queue is Empty");
      else {
        for (i = front; i < rear; i++) {
          printf("%d", queue[i]);
          printf("\t");
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