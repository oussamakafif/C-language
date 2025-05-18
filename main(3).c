#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct ex{
int info;
struct ex *next;
}list;

bool Identical(list **L,list **B){
bool a;
a=true;
list *q,*p;
if(*L==NULL || *B==NULL){
    printf("the lists is empty");
}
else{
    q=*L;
    p=*B;
    while(a==true && q!=NULL && p!=NULL){
        if(p->info != q->info){
            a=false;
        }
        q=q->next;
        p=p->next;
    }
}
if(q!=NULL || p!=NULL){
    a=false;
}
return(a);
}

bool inluded(list **L,list **B){
bool a=true;
bool c;
list *p,*q;
if(*L==NULL || *B==NULL){
    printf("the lists is empty");
}
else{
p=*L;
q=*B;
        while(q!=NULL && a==true){
                c=false;
            while(p!=NULL && c==false){
                if (p->info=q->info){
                    c=true;
                }
                p=p->next;
            }
            q=q->next;
            a=c;
        }
}
return(a);
}

bool sublist(list **L, list **B) {
    list *p, *q, *x, *y;
    bool a = false, b;
    if (*L == NULL || *B == NULL) {
        printf("the lists is empty");
    } else {
        p = *L;
        q = *B;
        while (q != NULL && a == false) {
            if (q->info == p->info) {
                b = true;
                x = p;
                y = q;
                while (b == true && x != NULL && y != NULL) {
                    if (x->info != y->info) {
                        b = false;
                    }
                    x = x->next;
                    y = y->next;
                }
                if (x == NULL) {
                    a = true;
                }
            }
            q = q->next;
        }
    }
    return a;
}

bool disjoint(list **L,list **B){
 bool a=true;
 list *q,*p;
 if (*L == NULL || *B == NULL) {
        printf("the lists is empty");
    } else {
    q=*L;
    while(q!=NULL && a==true){
         p=*B;
    while(p!=NULL && a==true){
        if(p->info==q->info){
            a=false;
        }
        p=p->next;
    }
    q=q->next;
    }

    }
return(a);
}

void separate(list **L,list **L2){
if(*L==NULL || *L2==NULL){
    printf("the list is empty");
}
else{
    list *q,*p;
    q=*L;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=*L2;
    q=(*L)->next;
    while(q!=NULL){
        if((q->info)%2==0){
            p=(list *)malloc(sizeof(list));
            p->info=q->info;
            p->next=(*L);
            L=p;
        }
        q=q->next;

    }
    p=*L;
    q=(*L)->next;
    while(q!=NULL && (q->info)%2==0){
        q=q->next;
        p=p->next;
    }
    if((q->info)%2==1 || q==NULL){
    p->next=NULL;
    *L2=q;
    }
}

}


int main()
{
    printf("Hello world!\n");
    return 0;
}
