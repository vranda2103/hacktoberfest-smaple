#include <stdio.h>
#define N 5
int s1[N], s2[N];
int top1=-1, top2=-1;
int count=0;

void push1(int data)
{
    if (top1==N-1)
        printf("Overflow");
    else
        s1[++top1]=data;
}

int pop1()
{
    return s1[top1--];
}

void push2(int data)
{
    if (top2==N-1)
        printf("Overflow");
    else
        s2[++top2]=data;
}

int pop2()
{
    return s2[top2--];
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if (top1==-1 && top2==-1)
        printf("Empty");
    else
    {
        int i;
        for(i=0; i<count; i++)
            push2(pop1());

        int b=pop2();
        printf("Dequeued element is %d\n", b);

        count--;
        for (i=0; i<count; i++)
            push1(pop2());
    }
}

void display()
{
    int i;
    for (i=0; i<=top1; i++)
        printf("%d ", s1[i]);
    printf("\n");
}

int main()
{
    while (1)
    {
        printf("Press 1 to add 2 to delete and 3 to print else 4");
        int choice;
        scanf("%d", *choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter value");
                int val;
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
                display();
                break;
            }
        case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}
