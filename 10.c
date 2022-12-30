#include <stdio.h>
#include<stdlib.h>
#include<time.h>

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
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}
struct node {
int data;
struct node *next;
struct node *prev;
}
*head;
void insertNodeFront(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Overflow\n");
    }
    else {
        newNode->data = val;
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL){
            head->prev = newNode;
        }
        head = newNode;
    }
    printf("%d inserted at front of linked list\n", val);
}
void insertNodeEnd(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->data = val;
    if (head == NULL){
        insertNodeFront(val);
    }
    else{
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        newNode->prev = temp;
    }
    printf("%d inserted a node at the end of linked list\n", val);
}
void deleteNodeLast(){
    struct node *temp = head;
    if (head == NULL){
        printf("Underflow\n");
    }
    if (head->next == NULL){
        head = NULL;
        free(head);
    }
    else{
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    printf("last node deleted\n");
}
void deleteNodeBefore(int position){
    struct node *temp = head;
    int i = 1;
    if (position == 1){
        printf("Can't delete no pervious node\n");
        return;
    }
    if (position == 2){
        printf("%d deleted node\n", head->data);
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else{
        while (i < position - 1){
            temp = temp->next;
            i++;
        }
        printf("%d deleted node\n", temp->data);
        temp->prev->next = temp->next;
        free(temp);
    }
}
void Display(){
    struct node *current = head;
    if (head == NULL){
        printf("List is empty\n");
    }
    else{
        while (current != NULL){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
int main(){
    int val, choice, position;
    student_detail();
    do{
        printf("\n1.Insert a node at the front of linked list\n");
        printf("2.Insert a node at the end of linked list\n");
        printf("3.Delete a last node of linked list\n");
        printf("4.Delete a node before specificed position\n");
        printf("5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter the element\n");
            scanf("%d", &val);
            insertNodeFront(val);
            Display();
            break;
        case 2:
            printf("Enter the element\n");
            scanf("%d", &val);
            insertNodeEnd(val);
            Display();
            break;
        case 3:
            deleteNodeLast();
            Display();
            break;
        case 4:
            printf("Enter the position\n");
            scanf("%d", &position);
            deleteNodeBefore(position);
            Display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        Output:
            break;
        }
    } while (choice != 6);
    return 0;
}