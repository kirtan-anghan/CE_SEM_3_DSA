#include <stdio.h>
#include <stdlib.h>
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
    printf("13 \n");                  //practical no.
    printf("Practical AIM: ");
    printf("Implement recursive and non-recursive tree traversing methods inorder, preorder and post-order traversal. \n");   //Aim of practical
    printf("This program has been written at (date and time) : %s \n\n", ctime(&t));
}
struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}
void enqueue(struct queue *q, struct node *x)
{
    if (q->rear == q->size - 1)
        printf("queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
struct node *dequeue(struct queue *q)
{
    struct node *x = NULL;
    if (q->front == q->rear)
        printf("queue is empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    return q.front == q.rear;
}
struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
};
struct node *root = NULL;
struct stack{
    int size;
    int top;
    struct node **s;
};
void stackcreate(struct stack *st,int size){
    st->size=size;
    st->top=-1;
    st->s=(struct node **)malloc(st->size*sizeof(struct node *));

}
void push(struct stack *st,struct node  *x){
    if(st->top==st->size-1)
    printf("stack is overflow");
    else{
        st->top++;
        st->s[st->top]=x;
    }
}
struct node * pop(struct stack*st){
    struct node * x=NULL;
    if(st->top==-1)
    printf("stack is underflow");
    else{
        x=st->s[st->top--];
    }
    return x;
}
int isemptystack(struct stack st){
    if(st.top==-1)
    return 1;
    return 0;
}
int isfullstack(struct stack st){
    return st.top==st.size-1;
}
void treecreate()
{
    struct node *t, *p;
    int x;
    struct queue q;
    create(&q, 100);
    printf("enter the value of root");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isempty(q)){
        p = dequeue(&q);
        printf("enter left child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct node *p)
{
    if (p){
        printf("%d\t", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if (p){
        inorder(p->lchild);
        printf("%d\t", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if (p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d\t", p->data);
    }
}
void ipreorder(struct node *p)
{
    struct stack stk;
    stackcreate(&stk, 100);
    while (p || !isemptystack(stk)){
        if (p){
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else{
            p = pop(&stk);
            p = p->rchild;
        }
    }
}
void iinorder(struct node *p){
    struct stack stk;
    stackcreate(&stk, 100);
    while (p || !isemptystack(stk)){
        if (p){
            push(&stk, p);
            p = p->lchild;
        }
        else{
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
int main()
{   student_detail();
    treecreate();
    printf("pre order\n");
    ipreorder(root);
    printf("\ninorder order\n");
    iinorder(root);
    return 0;
}