#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node Node;

struct node
{
    int num;
    struct node *next;
};

void sort(Node *head, Node *tail);
void printlist(Node* head);//print a list
Node *appendlist(Node *head1,Node *head2);//append two non-decreasing lists and return a non-decreasing list.
void freelist(Node *head);

int main(void)
{
    Node *head1,*head2,*finalhead;//Head pointers of two non-decreasing lists.
    Node *creatlist(void);//Create a list.
        //
    head1=creatlist();
    head2=creatlist();
    finalhead=appendlist(head1,head2);
    printlist(finalhead);
    sort(finalhead,NULL);
    //
    printlist(finalhead);
    free(finalhead);
    return 0;
}

Node *creatlist(void)
{
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    char buf[200]={'\0'};//buffer
    Node *ptmp=NULL;//creat list member
    Node *pprev=head;//the pervious node
    char *toksto;//strtok_r
    char *stok;//Store the address returned by strtok_r
    //
    printf("Please input a series of no-decreasing numbers separated by spaces:\n");
    fgets(buf,sizeof(buf),stdin);
    stok=strtok_r(buf," \n",&toksto);
    while(stok)
    {
        if(!(ptmp=(Node *) malloc(sizeof(Node))))
	{
	    printf("Memory exhausted..");
	    exit(0);
	}
	pprev->next=ptmp;//append next node to current list
	ptmp->next=NULL;//end of new list
	ptmp->num=atoi(stok);//if the fitst chr is not a number then there will be 0 instead.
	pprev=ptmp;//make the current one becone the pervious one in the next loop.
	stok=strtok_r(NULL," \n",&toksto);
    }
    sort(head,NULL);
    return head;
}

Node *appendlist(Node *head1, Node *head2)
{
    Node *p;
    for(p=head1;p->next!=NULL;p=p->next);//locate end of the first list
    p->next=head2->next;//append
    return head1;
}

void printlist(Node *head)
{
    if(head==NULL||head->next==NULL)
	return;
    for(Node *p=head->next;p!=NULL;p=p->next)
	printf("%d ",p->num);
    printf("\n");
}

void freelist(Node *head)
{
    Node *p=NULL;
    while(head)
    {
	p=head;
	head=head->next;
	free(p);
    }
}

void sort(Node *head, Node *tail)
{
    if(head==NULL||head->next==tail||head->next->next==tail)
	return;
    
    Node *mid=head->next;
    Node *left=head, *right=mid;
    Node *p=mid->next;
    int key=mid->num;
    
    while(p!=tail)
    {
	if(p->num<key)
	    left=left->next=p;
	else
	    right=right->next=p;
	p=p->next;
    }
    left->next=mid;
    right->next=tail;
    
    sort(head,mid);
    sort(mid,tail);
}
