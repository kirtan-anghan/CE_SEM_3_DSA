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
    printf("17 \n");                  //practical no.
    printf("Practical AIM: ");
    printf("Write a program to implement Binary Search. \n");   //Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}



int main() {
  student_detail();
  int c, first, last, middle, n, search, array[100];

  printf("How Many Element You Want To Add:");
  scanf("%d", &n);

  printf("Enter %d Integer Elements\n", n);

  for (c = 0; c < n; c++)
    scanf("%d",  &array[c]);

  printf("Enter Value to Find\n");
  scanf("%d", &search);

  first = 0;
  last = n - 1;
  middle = (first + last) / 2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("%d found at location %d.\n", search, middle + 1);
      break;
    } else
      last = middle - 1;

    middle = (first + last) / 2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);

}