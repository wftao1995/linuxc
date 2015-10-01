#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct man
    {
        char name[20];
        char phone[20];
    };
    char sename[20];
    int count=1;
    typedef struct man man;
    man members[20];
    printf("Please input a man's name and his phone number\n");
    printf("Please use enter to separate name and phone:\n");
    fgets(members[0].name,sizeof(man),stdin);
    fgets(members[0].phone,sizeof(man),stdin);
    for(int i=1;i<20;++i)
    {
        printf("Please input a man's name and his phone number\n");
        printf("Please use enter to separate name and phone:\n");
        printf("Please enter $%$ when you enter the name to end the input\n");
        fgets(members[i].name,sizeof(man),stdin);
        fgets(members[i].phone,sizeof(man),stdin);
        if(!strcmp(members[i].name,"$%$\n"))
            break;
        count++;
    }
    printf("Please input the name:\n");
    fgets(sename,sizeof(sename),stdin);
    for(int i=0,j;i<count;++i)
    {
        if(!strcmp(members[i].name,sename))
        {
            for(j=0;members[i].name[j]!='\n';j++);
            members[i].name[j]='\0';
            printf("%s's phone number is %s",members[i].name,members[i].phone);
            return 0;
        }
    }
    printf("Person %s not found",sename);
    return 0;
}
