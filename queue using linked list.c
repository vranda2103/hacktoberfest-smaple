#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *next;
}NODE;

NODE *front=NULL;
NODE *rear=NULL;

void enqueue(int x)
{
    NODE *new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=x;
    new_node->next=NULL;

    if (front=='\0' && rear=='\0')
        front=rear=new_node;
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
}

void dequeue()
{
    NODE *temp=front;
    if (front=='\0' && rear=='\0')
        printf("Underflow");
    else
    {
        printf("%d\n\n", front->data);
        front=front->next;
        free(temp);
    }
}

void peek()
{
    if (front=='\0' && rear=='\0')
        printf("Empty");
    else
        printf("%d\n\n", front->data);
}

void display()
{
    NODE *temp;
    if (front=='\0' && rear=='\0')
        printf("Empty");
    else
    {
        temp=front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}

int main()
{
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit");
        printf("\nChoice is:");
        int choice;
        scanf("%d", *choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter value:");
                int val;
                scanf("%d", &val);
                enqueue(val);
                printf("\n");
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
            {
                exit(0);
            }
        }
    }
    return 0;
}
