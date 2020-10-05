#include <stdio.h>
#include <stdlib.h>
#define size 5
int queue[5];
int front=-1, rear=-1;
void enqueue (int a)
{
    if (((rear+1)%size)==front)
        printf("Overflow");
    else if (rear==-1 && front==-1)
    {
        front=rear=0;
        queue[rear]=a;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=a;
    }
}

void dequeue()
{
    if (front==-1 && rear==-1)
        printf("Underflow");
    else if (front==rear)
        front=rear=-1;
    else
        front=(front+1)%size;
}

void peek()
{
    if (front==-1 && rear==-1)
        printf("Empty");
    else
        printf("%d", queue[front]);
}

void display()
{
    if (front==-1 && rear==-1)
        printf("Empty");
    else
    {
        int i=front;
        while(1)
        {
            printf("%d", queue[i]);
            i=(i+1)%size;
            if (i==rear)
            {
                printf("%d", queue[i]);
                break;
            }
        }
    }
}
int main()
{
    while(1)
    {
        printf("Enter the command:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nChoice is:");
        int choice;
        scanf("%d", *choice);
        switch(choice)
        {
        case 1:
            {
                int val;
                printf("Enter a number to add: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                peek();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
            exit(0);
        }
    }
    return 0;
}
