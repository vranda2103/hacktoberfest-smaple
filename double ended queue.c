#include<stdio.h>
#define size 5
int c[5];
int rear=-1,front=-1;
void renqueue(int a)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        c[rear]=a;
    }
    else if((rear+1)%size==front)
        printf("OVERFLOW\n");
    else
    {
        rear=(rear+1)%size;
        c[rear]=a;
    }
}
void fenqueue(int a)
{
    if((rear+1)%size==front)
        printf("OVERFLOW\n");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        c[front]=a;
    }
    else
    {
        front=(front+size-1)%size;
        c[front]=a;
    }
}
void fdequeue()
{
    if(front==-1&&rear==-1)
        printf("UNDERFLOW");
    else if(front==rear)
        front=rear=0;
    else
    front=(front+1)%size;
}
void rdequeue()
{
    if(front==-1&&rear==-1)
    printf("UNDERFLOW");
    else if(front==rear)
    front=rear=-1;
    else
    rear=(rear-1+size)%size;
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1)
    printf("No elements in the queue\n");
    else if(front==rear)
    printf("%d",c[rear]);
    else
    while(1)
    {
        if(i==rear)
        {
            printf("%d\n",c[i]);
            break;
        }
        printf("%d\t",c[i]);
        i=(i+1)%size;
    }
}
int main()
{
    while(1)
    {
        int b,d;
        printf("Enter\n 1 to front enqueue\n 2 to rear enqueue\n 3 to front dequeue\n 4 to rear dequeue\n 5 to display\n 6 to exit\n");
        scanf("%d",&b);
        switch(b)
        {
            case 1:
               // int d;
                printf("Enter an element to be enqueued\n");
                scanf("%d",*d);
                fenqueue(d);
                break;
            case 2:
               // int d;
                printf("Enter an element to be enqueued\n");
                scanf("%d",&d);
                renqueue(d);
                break;
            case 3:
                fdequeue();
                break;
            case 4:
                rdequeue();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
