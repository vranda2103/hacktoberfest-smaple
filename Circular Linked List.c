#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

/*
    User Defined Functions
*/

NODE * insert_at_first(NODE *head,int value)
{
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data=value;
    if (head==NULL)
    {
        head=new_node;
        new_node->next=head;
    }
    else
    {
        NODE *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        new_node->next = head;
        head = new_node;
        temp->next=head;
    }
    return head;
}

NODE* insert_at_last(NODE *head,int value)
{
    NODE *temp;
    temp=head;
    while(temp->next!=head)
        temp=temp->next;
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = value;
    new_node->next=head;
    temp->next=new_node;
    return head;
}

NODE *insert_before(int key,int value, NODE *head)
{
    NODE *temp=head, *prev_node;
    NODE *new_node = (NODE*)malloc(sizeof (NODE));
    new_node->data=value;
    while(temp->data!=key)
    {
        prev_node=temp;
        temp=temp->next;
    }
    new_node->next=temp;
    prev_node->next=new_node;
    return head;
}


NODE * delete_at_first(NODE *head)
{
    NODE *temp = head;
    if (head==head->next)
        head=NULL;
    else
    {

        NODE *last=head;
        while (last->next!=head)
            last=last->next;
        head=head->next;
        last->next=head;
        free(temp);
    }
    return head;
}

NODE * delete_at_end(NODE *head)
{
    NODE *temp=head, *prev_node;
    while(temp->next!=head)
    {
        prev_node=temp;
        temp=temp->next;
    }
    prev_node->next=head;
    free(temp);
    return head;
}

NODE * delete_at_pos(NODE *head, int inf)
{
    NODE *temp=head, *prev_node;
    while (temp->data!=inf)
    {
        prev_node=temp;
        temp=temp->next;
    }
    prev_node->next=temp->next;
    free(temp);
    return head;
}

void search_item(NODE *head, int value)
{
    NODE *searchNode = head;
    int flag = 0;
    while(searchNode->next!=head)
    {
        if(searchNode->data==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }
    if(searchNode->data==value)
    {
        printf("%d is present in this list. Memory address is %d\n", value, searchNode);
        flag = 1;
    }
    if(flag==0)
        printf("Item not found\n");
}


void print_linked_list(NODE *head)
{
    printf("\nYour full linked list is\n");
    NODE *myList;
    myList = head;
    if (head==NULL)
    {
        printf("Empty");
    }
    else
    {
        while(myList->next!=head)
        {
            printf("%d ", myList->data);
            myList = myList->next;
        }
        printf("%d ", myList->data);
    }
}

/*
    Main function
*/

int main()
{
    NODE *head=NULL;
    int key, value;

    int choice1, f=1;
    printf("Enter the command you want to perform:\n1.Insertion\t2.Deletion\t3.Search\t4.Display\nEnter -1 to exit.");
    scanf("%d", *choice1);
    if (choice1==-1)
        f=0;
    while(f)
    {
        switch (choice1)
        {
            //Insertion
            case 1:
            {
                char ch;
                printf("Where do you want to insert?:\na.At the beginning\tb.At the end\tc.At a particular position with known value\n");
                fflush(stdin);
                scanf("%c", &ch);
                switch(ch)
                {
                    //At the beginning
                    case 'a':
                    {
                        int value;
                        printf("Enter the value you want to insert:");
                        scanf("%d", &value);
                        head=insert_at_first(head,value);
                        break;
                    }
                    //At the ending
                    case 'b':
                    {
                        int value;
                        printf("Enter the value you want to insert:");
                        scanf("%d", &value);
                        head=insert_at_last(head,value);
                        break;
                    }
                    //At a position
                    case 'c':
                    {
                        int key, value;
                        printf("Enter the value you want to insert:");
                        scanf("%d", &value);
                        printf("Enter the value before which you want to insert:");
                        scanf("%d", &key);
                        head=insert_before(key, value,head);
                        break;
                    }
                }
                break;
            }
            //Deletion
            case 2:
            {
                char ch;
                printf("Where do you want to delete?:\na.At the beginning\tb.At the end\tc.At a particular position with known value\n");
                fflush(stdin);
                scanf("%c", &ch);
                switch(ch)
                {
                    //At the beginning
                    case 'a':
                    {
                        head=delete_at_first(head);
                        break;
                    }
                    //At the ending
                    case 'b':
                    {
                        head=delete_at_end(head);
                        break;
                    }
                    //At a position
                    case 'c':
                    {
                        int value;
                        printf("Enter the value you want to delete:");
                        scanf("%d", &value);
                        head=delete_at_pos(head, value);
                        break;
                    }
                }
                break;
            }
            //Searching
            case 3:
            {
                printf("Enter the value you want to search for:");
                int value;
                scanf("%d", &value);
                search_item(head, value);
                break;
            }
            //Printing
             case 4:
            {
                print_linked_list(head);
                break;
            }
        }
        printf("Enter the command you want to perform:\n1.Insertion\t2.Deletion\t3.Search\t4.Display\nEnter -1 to exit.");
        scanf("%d", &choice1);
        if (choice1==-1)
            f=0;
    }
    return 0;
}
