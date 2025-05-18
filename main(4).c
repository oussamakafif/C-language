#include <stdio.h>
#include <stdlib.h>
typedef struct ex2{
int info;
struct ex2 *next;
}list;

int num_of_elem(list **L){
   list *p;
   int s;
   if(*L==NULL){
    printf("the list is empty");
   }
   else{
    p=*L;
    s=0;
      while(p!=NULL){
        s++;
        p=p->next;
    }
   }
   return(s);
}

void max_and_min(list **L){
    int max,min;
    list *q;
    max=(*L)->info;
    min=(*L)->info;
    if(*L==NULL){
    printf("the list is empty");
   }
   else{
        q=*L;
    while(q!=NULL){
        if(q->info>max){
            max=q->info;
        }
        else if(q->info<min){
            min=q->info;
        }
        q=q->next;
    }
    printf("the max is :%d \n the min is :%d",max,min);
   }
}

int min(list **L){
  int min;
    list *q;
    min=(*L)->info;
    if(*L==NULL){
    return(0);
   }
   else{
        q=*L;
    while(q!=NULL){
         if(q->info<min){
            min=q->info;
        }
        q=q->next;
    }
    return(min);
     }
}

void insertval(list **L,int a){
  list *p,*q;
  p=(list *)malloc(sizeof(list));
  p->info=a;
  p->next=NULL;

   if(*L==NULL || (*L)->info<a){
    p->next=*L;
    p=*L;
   }
   else{
        q=*L;
    while(q->next!=NULL && q->info<a){
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
   }
}

void deletelement(list **L){
    list *p,*q,*s;
if(*L==NULL){
    printf("the list is empty");
   }
   else{
     q=*L;
     s=*L;
     p=(*L)->next;
     while(q!=NULL){
        p=q->next;
        s=q;
        while(p!=NULL){
            if(p->info==q->info){
                s->next=p->next;
                p->next=NULL;
                free(p);
                p=s->next;
            }
            else{
                p=p->next;
                s=s->next;
            }
        }
        q=q->next;
     }
   }
}

void find_and_delete(list **L){
     list *q,*p;
     int mine;
     mine=min(L);
     q=*L;
     p=q->next;
     if(*L==NULL){
    printf("the list is empty");
      }
     else{
        while(p!=NULL && q!=NULL){
          if(p->info==mine){
            q->next=p->next;
            p->next=NULL;
            free(p);
          }
          q=q->next;
          p=q->next;
        }
     }

}
int middle(list **L){
int s=0;
list *q;
q=*L;
  if(*L==NULL){
    printf("the list is empty");
      }
      else{
  while(q!=NULL){
    s++;
    q=q->next;
}
s=s/2;
return(s);}
}

int middle_adress(list **L){
int s,i;
list *q;
q=*L;
if(*L==NULL){
    printf("the list is empty");
      }
else{
s=middle(L);
i=0;
while(i<=s){
q=q->next;
i++;
    }
return(q);
}
}

list  *mirror(list **L){
list *p,*q,*H;
if(*L==NULL){
    printf("the list is empty");
   }
   else{
q=*L;
H=NULL;


while(q!=NULL){
    p=(list *)malloc(sizeof(list));
    p->info=q->info;
    p->next=H;
    H=p;
    q=q->next;
}
   }
   return(H);
}

list *negatif_left(list **L){
list *p,*d,*q;
if(*L==NULL){
    printf("the list is empty");
      }
      else{
      q=(*L)->next;
      d=*L;
      while(q!=NULL){
        if(q->info<0){
           p=(list *)malloc(sizeof(list));
           p->info=q->info;
           p->next=*L;
           *L=p;
           d->next=q->next;
           q->next=NULL;
           free(q);
           q=d->next;
        }
        else{
            d=q;
            q=q->next;
        }
      }
      }
      return(*L);
}

void detache(list **L){
list *d,*q;
if(*L==NULL){
    printf("the list is empty");
      }
else{
       *L= negatif_left(L);
       d=*L;
       q=(*
          .L)->next;
       while(q->info<=0){
        d=q;
        q=q->next;
       }
       d->next=NULL;
            }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
