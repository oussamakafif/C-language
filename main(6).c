#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} Node;

typedef Node* List;

int NUMBER(List L) {
    int n = 0;
    while (L != NULL) {
        n = n * 10 + L->info;
        L = L->next;
    }
    return n;
}

List DETACHMENT(List *L) {
    List tmp;
    if (*L == NULL) return NULL;
    tmp = *L;
    *L = (*L)->next;
    tmp->next = NULL;
    return tmp;
}

List INSERTION(List L, int N) {
    List p = malloc(sizeof(Node)), q = L;
    p->info = N;
    p->next = NULL;
    if (N % 2 == 0 && N > 10) {
        p->next = L;
        return p;
    }
    if (L == NULL) return p;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
    return L;
}

List ajouter_fin(List L, int n) {
    List p = malloc(sizeof(Node)), q = L;
    p->info = n;
    p->next = NULL;
    if (L == NULL) return p;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
    return L;
}

List rotation(List L) {
    List tmp = L;
    int x = L->info;
    L = L->next;
    tmp->next = NULL;
    List q = L;
    if (q == NULL) return tmp;
    while (q->next != NULL)
        q = q->next;
    q->next = tmp;
    return L;
}

List create_LC(List LM) {
    List LC = NULL;
    int len = 0;
    List tmp = LM;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    for (int i = 0; i < len; i++) {
        int n = NUMBER(LM);
        if (n % 2 == 0)
            LC = INSERTION(LC, n);
        else
            LC = ajouter_fin(LC, n);
        LM = rotation(LM);
    }
    return LC;
}

void afficher(List L) {
    while (L != NULL) {
        printf("%d -> ", L->info);
        L = L->next;
    }
    printf("NIL\n");
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
