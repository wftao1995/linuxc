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

void sort(Node *head);//bubble sort
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
    sort(finalhead);
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
    sort(head);
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

void sort(Node *head)
{
    int tmp;
    if(head==NULL||head->next==NULL)
	return;
    Node *p=NULL,*q=NULL;
    Node *tail=NULL;
    for(tail=head;tail->next;tail=tail->next);
    bool nordered=true;
    while(nordered)
    {
	nordered=false;
	p=head->next;
	while(p!=tail)
	{
	    q=p;
	    if(p->num>p->next->num)
	    {
		nordered=true;
		tmp=p->num;
		p->num=p->next->num;
		p->next->num=tmp;
	    }
	    p=p->next;
	}
	tail=q;
    }
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
