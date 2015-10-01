#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    int num;
    struct node *next;
};
typedef struct node Node;

int main(void)
{
    Node *head1,*head2,*finalhead;//Head pointers of two non-decreasing lists.
    Node *creatlist(void);//Create a list.
    Node *appendlist(Node *head1,Node *head2);//append two non-decreasing lists and return a non-decreasing list.
    void printlist(Node* head);
    //
    head1=creatlist();
    head2=creatlist();
    finalhead=appendlist(head1,head2);
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
    char *stok1;//Check if the list is non-decreasing
    char *stok;//Store the address returned by strtok_r
    int i;
    //
    printf("Please input a series of no-decreasing numbers separated by spaces:\n");
    fgets(buf,sizeof(buf),stdin);
    for(i=0;buf[i]!='\n';++i);
    buf[i]='\0';
    stok=strtok_r(buf," ",&toksto);
    while(1)
    {
	ptmp=(Node *) malloc(sizeof(Node));
	pprev->next=ptmp;//append next node to current list
	ptmp->next=NULL;//end of new list
	ptmp->num=atoi(stok);//if the fitst chr is not a number then there will be 0 instead.
	pprev=ptmp;
	stok1=stok;//check if the list is non-decreasing.
	stok=strtok_r(NULL," ",&toksto);
	if(stok==NULL)
	    break;
	if(strcmp(stok1,stok)>0)
	{
	    printf("The list is not non-decreasing!");
	    exit(0);
	}
    }
    return head;
}

Node *appendlist(Node *head1, Node *head2)
{
    for(Node *p=head1;p->next!=NULL;p=p->next);
    p->next=head2->next;
    return head1;
}

void printlist(Node *head)
{
    for(Node *p=head->next;p->next!=NULL;p=p->next)
	printf("%d ",p->num);
}

