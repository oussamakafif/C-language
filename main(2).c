#include <stdio.h>
#include <stdlib.h>

typedef struct exam{
int info;
struct exam *next;
}list;

int maxrow(int N,int j,int t[20][30]){
 int i,max;
  max=t[1][j];
  for(i=1;i<=N;i++){
    if(t[i][j]>max){
        max=t[i][j];
    }
  }

  return max;
}
int maxcolumn(int M,int i,int t[20][30]){
 int j,max;
  max=t[i][1];
  for(j=1;j<=M;j++){
    if(t[j][i]>max){
        max=t[j][i];
    }
  }

  return max;
}

void insert_lifo(list **L, int maxrow){
    list *p;
    p=(list *)malloc(sizeof (list));
      p->info=maxrow;
      p->next=NULL;
    if(*L==NULL){
      *L=p;
        }
    else{
        p->next=*L;
        p=*L;
    }
}

void insert_fifo(list **L, int maxcolumn){
    list *p,*q;
    p=(list *)malloc(sizeof(list));
    p->info=maxcolumn;
    p->next=NULL;
    if(*L==NULL){
      *L=p;
        }
    else{
        q=*L;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
