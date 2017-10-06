#include<stdio.h>
#include<conio.h>
struct node{
int data;
struct node *next;
}*start;

void Create(int num)
{
    struct node *q,*t;
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->data=num;
        start->next=NULL;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        t=(struct node*)malloc(sizeof(struct node));
        t->data=num;
        t->next=NULL;
        q->next=t;
    }

}
void Display()
{
    struct node *q;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        for(q=start;q!=NULL;q=q->next)
        {
            printf("\t%d",q->data);
        }
    }
}
void Count()
{
    int n=0;
    struct node *q;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        for(q=start;q!=NULL;q=q->next)
        {
            n++;
        }
        printf("\n%d",n);
    }
}
void AddAtBeginning(int num)
{
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q->data=num;
    q->next=start;
    start=q;
}
void AddAtPos(int pos,int num)
{
    int i;
    struct node *q,*t;
    q=start;
    for(i=1;i<pos;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("\nThere are less than %d elements",pos);
        }
    }
    t=(struct node*)malloc(sizeof(struct node));
    t->data=num;
    t->next=q->next;
    q->next=t;
}
void Delete(int num)
{
    struct node *q,*t;
    q=start;
    if(q==NULL)
    {
        printf("\nList is empty");
    }
    if(q->data==num)
    {
        start=q->next;
        printf("\nElement removed");
        free(q);
    }
    t=q;
    q=q->next;
    while(q!=NULL)
    {
        if(q->data==num)
        {
            t->next=q->next;
            printf("\nItem removed");
            free(q);
        }
        t=q;
        q=q->next;
    }
    printf("\nItem not found");
}
main()
{
    int choice,num,pos;
    start=NULL;
    do
    {
    printf("\n\tEnter your choice:");
    printf("\n1-To create the linked list");
    printf("\n2-To display all the elements of linked list");
    printf("\n3-To count the no. of nodes");
    printf("\n4-To insert the elements at the beginning of linked list");
    printf("\n5-To insert an element after specified position");
    printf("\n6-To delete the specified element");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("\nEnter num to add in a list");
        scanf("%d",&num);
        Create(num);
        break;

        case 2:printf("\nDisplaying linked list");
        Display();
        break;

        case 3:Count();
        break;

        case 4:printf("\nEnter item to add at beginning:");
        scanf("%d",&num);
        AddAtBeginning(num);
        break;

        case 5:printf("\nEnter position after which you want to add:");
        scanf("%d",&pos);
        printf("\nEnter item");
        scanf("%d",&num);
        AddAtPos(pos,num);
        break;

        case 6:printf("\nEnter item you want to remove from the list");
        scanf("%d",&num);
        Delete(num);
        break;

        case 7:exit(0);

        default:printf("\nWrong choice");
    }
    }while(1);
}
