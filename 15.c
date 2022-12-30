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
    printf("15 \n");                  //practical no.
    printf("Practical AIM: ");
    printf("Write a program to implement Merge Sort \n");   //Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}

void mergeSort(int[], int, int, int);
void partition(int[], int, int);

int main() {
 student_detail();
  int list[50];
  int i, size;

  printf("Enter Total Number of Elements:");
  scanf("%d", & size);
  printf("Enter The Elements:\n");
  for (i = 0; i < size; i++) {
    scanf("%d", & list[i]);
  }
  partition(list, 0, size - 1);
  printf("After Merge Sort:\n");
  for (i = 0; i < size; i++) {
    printf("%d   ", list[i]);
  }

  return 0;
}

void partition(int list[], int low, int high) {
  int mid;

  if (low < high) {
    mid = (low + high) / 2;
    partition(list, low, mid);
    partition(list, mid + 1, high);
    mergeSort(list, low, mid, high);
  }
}

void mergeSort(int list[], int low, int mid, int high) {
  int i, mi, k, lo, temp[50];

  lo = low;
  i = low;
  mi = mid + 1;
  while ((lo <= mid) && (mi <= high)) {
    if (list[lo] <= list[mi]) {
      temp[i] = list[lo];
      lo++;
    } else {
      temp[i] = list[mi];
      mi++;
    }
    i++;
  }
  if (lo > mid) {
    for (k = mi; k <= high; k++) {
      temp[i] = list[k];
      i++;
    }
  } else {
    for (k = lo; k <= mid; k++) {
      temp[i] = list[k];
      i++;
    }
  }

  for (k = low; k <= high; k++) {
    list[k] = temp[k];
  }
}