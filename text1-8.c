/*
从键盘上读取不定数目的浮点值并计算其平均值.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct numbers
{
  float num;
  struct numbers *next;
};

typedef struct numbers numbers;

int main(void)
{
    numbers *head;  //这是一个表头节点指针.
    numbers *p,*q;  //指向节点的指针变量.
    char buffer[100]={'\0'};
    int i=0,count=0; //计数器
    float sum=0.0f;
    p=(numbers*) malloc(sizeof(numbers));  //申请一个表头节点.
    p->next=NULL;
    head=p;
    while(1)
    {
        printf("\nPlease input the %d%s float number(use anything else than numbers to stop):",++i,i%10==1?"st":(i%10==2?"nd":(i%10==3?"rd":"th")));
        fgets(buffer,sizeof(buffer),stdin);
        for(int i=0;buffer[i]!='\n';++i)
            if((buffer[i]>'9'||buffer[i]<'0')&&buffer[i]!='.')
                goto out;
        if(!(q=(numbers*) malloc(sizeof(numbers))))
	{
	    printf("Memory exhausetd..");
	    exit(0);
	}
        p->next=q;
        q->next=NULL;
        p=q;
        p->num=atof(buffer);
        count++;
    }
out:
    q=head->next;
    free(head);
    while(q)
    {
        sum+=q->num;
        printf("\n%f",q->num);
	p=q;
        q=q->next;
	free(p);
    }
    printf("\nSum is %f\nAverage is %f",sum,(float)(sum/count));
    return 0;
}

