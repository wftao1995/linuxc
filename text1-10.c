#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node Node;

struct node
{
    int num;
    struct node *next;
};

void sort(Node *head);//bubble sort
void printlist(Node* head);//print a list
Node *appendlist(Node *head1,Node *head2);//append two non-decreasing lists and return a non-decreasing list.

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
    return 0;
}

Node *creatlist(void)
{
    Node *head=(Node *)malloc(sizeof(Node));
    char buf[200];//buffer
    Node *ptmp=NULL;//creat list member
    Node *pprev=head;//the pervious node
    char *toksto;//strtok_r
    char *stok;//Store the address returned by strtok_r
    int i;
    //
    printf("Please input a series of no-decreasing numbers separated by spaces:\n");
    fgets(buf,sizeof(buf),stdin);
    for(i=0;buf[i]!='\n';++i);//exclude the '\n' readed by fgets.
    buf[i]='\0';
    stok=strtok_r(buf," ",&toksto);
    while(stok)
    {
	ptmp=(Node *) malloc(sizeof(Node));
	pprev->next=ptmp;//append next node to current list
	ptmp->next=NULL;//end of new list
	ptmp->num=atoi(stok);//if the fitst chr is not a number then there will be 0 instead.
	pprev=ptmp;//make the current one becone the pervious one in the next loop.
	stok=strtok_r(NULL," ",&toksto);
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
    for(Node *p=head->next;p!=NULL;p=p->next)
	printf("%d ",p->num);
    printf("\n");
}

void sort(Node *head)
{
    int tmp;
    for(Node *p=head->next;p->next!=NULL;p=p->next)
    {
	for(Node *q=p;q->next!=NULL;q=q->next)//bubble sort
	{
	    if(q->num>q->next->num)
	    {
		tmp=q->num;
		q->num=q->next->num;
		q->next->num=tmp;
	    }
	}
    }
}
