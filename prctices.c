//singly linked list
/*#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void inbeg(struct node **head,int newdata)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=*head;
    *head=newnode;
}

void inend(struct node **head,int newdata)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    temp=*head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=0;
}

void afpos(struct node **head,int newdata)
{
    struct node *newnode,*temp;
    int i=0,n;
    printf("after which position u want to enter 3=");
    scanf("%d",&n);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    temp=*head;
    while(i<n-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void delbeg(struct node **head)
{
    struct node *temp;
    temp=*head;
    *head=temp->next;
    free(temp);
}

void delend(struct node **head)
{

    struct node *temp;
    temp=*head;
    while(temp->next->next!=0)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=0;
}

void delpos(struct node *head)
{
    struct node *temp1,*temp2;
    temp1=head;
    int n,i=1;
    printf("\nenter the position from where u want to delete the no.=");
    scanf("%d",&n);
    while(i<n-1)
    {
        i++;
        temp1=temp1->next;
    }
    temp2=temp1->next->next;
    free(temp1->next);
    temp1->next=temp2;
}

void reversing(struct node **head)
{
    struct node *change,*reverse,*preserve;
    change=*head;
    reverse=0;
    while(change!=0)
    {
        preserve=change->next;
        change->next=reverse;
        reverse=change;
        change=preserve;
    }
    *head=reverse;
}

void print(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=0)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice;
    struct node *head,*newnode,*temp;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data=");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue 1 or 0=");
        scanf("%d",&choice);
    }

    inbeg(&head,8);
    inend(&head,0);
    afpos(&head,9);
    printf("entered data(with insertion operation)=");
    print(head);

    delbeg(&head);
    delend(&head);
    delpos(head);
    printf("entered data(with deletion operation)=");
    print(head);

    reversing(&head);
    printf("\nreversed linked list=");
    print(head);

    return 0;

}*/


//doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *pre;
    struct node *next;
};

void inbeg(struct node **head,int newdata)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->pre=0;
    newnode->next=(*head);
    *head=newnode;
}

void inend(struct node *head,int newdata)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->data=newdata;
    while(head->next!=0)
    {
        head=head->next;
    }
    head->next=newnode;
    newnode->pre=head;
}

void afpos(struct node *head,int newdata)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    int n,i=1;
    printf("\nenter the position after which u want to enter the new data=");
    scanf("%d",&n);
    while(i!=n)
    {
        head=head->next;
        i++;
    }
    newnode->pre=head;
    newnode->next=head->next;
    head->next=newnode;
    head->next->pre=newnode;
}

void delbeg(struct node **head)
{
    *head=(*head)->next;
    free((*head)->pre);
    (*head)->pre=0;
}

void delend(struct node *head)
{
    while(head->next!=0)
    {
        head=head->next;
    }
    head->pre->next=0;
    free(head);
}

void delpos(struct node *head)
{
    int i=1,n;
    printf("\nenter the position from where node have to be deleted=");
    scanf("%d",&n);
    while(i!=n)
    {
        head=head->next;
        i++;
    }
    printf("%d %d %d",head->next->data,head->pre->data,head->data);
    (head->pre)->next=head->next;
    (head->next)->pre=head->pre;
    free(head);
}

void reversing(struct node **head)
{
    while((*head)->next==0)
    {
        (*head)=(*head)->next;
        printf(" %d ",(*head)->data);
    }
    printf("reversed linked list=");
    struct node *temp=*head;
    while(temp!=0)
    {
        printf(" %d ",temp->data);
        temp=temp->pre;
    }
}
del_node_pos()
{
    Node *loc;
    int n,i = 1;

    cout << "\n ENTER POSTION TO DELETE:";
    cin  >> n;

    loc = start;
    while(i!=n)
    {
        loc = loc -> next;
        i++;
    }

    loc -> prev -> next = loc -> next;
    loc -> next -> prev = loc -> prev;
    delete loc;

    cout << "\n NODE " << n << "DELTED!";
    char ch = cin.get();

}

void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=0)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice;
    struct node *head,*newnode,*temp;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data=");
        scanf("%d",&newnode->data);
        newnode->pre=newnode->next=0;
        if(head==0)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            newnode->pre=temp;
            temp=temp->next;
        }
        printf("do u want to new data 1 or 0=");
        scanf("%d",&choice);
    }

    printf("entered no. are =");
    print(head);

    inbeg(&head,8);
    inend(head,0);
    afpos(head,9);
    printf("linked list(insertion operation)=");
    print(head);

    delbeg(&head);
    delend(head);
    delpos(head);
    printf("linked list(deletion operation)=");
    print(head);

    reversing(&head);


    return 0;
}
