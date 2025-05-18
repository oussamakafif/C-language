#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct ex{
char name[20];
int qan,p;
struct ex *next;
}list;

list* sell(list **L,char na[20]){
if(*L==NULL){
    printf("the list is empty");
}
else{
list *q,*p;
p=*L;
q=(*L)->next;
bool a=true;
int i=0;
     while((*L)->name[i]!='\0'  && na[i]!='\0' && a==true){
       if ((*L)->name[i]!=na[i]){
        a=false;
       }
       i++;
    }
if (a==true){
    p->qan=p->qan-1;
    if(p->qan==0){
        p->next=NULL;
        *L=q;
        free(p);
    }
    return(*L);
}
else{
 i=0;
 a=true;
while(q!=NULL){
    while(q->name[i]!='\0'  && na[i]!='\0' && a==true){
       if (q->name[i]!=na[i]){
        a=false;
       }
       i++;
    }
    if(a==true){
        q->qan=q->qan-1;
        }
    }
      if(q->qan==0){
           p->next=q->next;
           q->next=NULL;
           free(q);
        }
        else{
       q=q->next;
       p=p->next;
       }
       }
}
       return(*L);

}
list* buy(list **L,char na[20],int nb,int price){
    if(*L==NULL){
    list *p;
    p=(list *)malloc(sizeof(list));
        (p)->p=price;
        (p)->qan=nb;
        strcpy(p->name, na);
        (p)->next=NULL;
        *L=p;
    }
    else{
    list *q,*p;
    q=*L;
    int i=0;
    bool a=false;

    while(q=!NULL && a==false){
    a=true;
    while(q->name[i]!='\0'  && na[i]!='\0' && a==true){
       if (q->name[i]!=na[i]){
        a=false;
       }
       i++;
    }
    if(a==true){
        q->p=price;
        q->qan=nb;
    }
        }
        if (a==false){
            p=(list *)malloc(sizeof(list));
            (p)->p=price;
            (p)->qan=nb;
             strcpy(p->name, na);
            (p)->next=NULL;

            q->next=p;
        }
    }
    return(*L);
}

int main()
{
    printf("hello world");
    return 0;
}
