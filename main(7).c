#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct note {
    int coef;
    float moy;
    struct note *next;
} Note;

typedef struct etudiant {
    char nom[30];
    char prenom[30];
    float moyenne;
    Note *notes;
    struct etudiant *next;
} Etudiant;

typedef Etudiant* ListeE;
typedef Note* ListeN;

float Average(ListeN L) {
    int s_coef = 0;
    float s_moy = 0;
    while (L != NULL) {
        s_coef += L->coef;
        s_moy += L->coef * L->moy;
        L = L->next;
    }
    if (s_coef == 0) return 0;
    return s_moy / s_coef;
}

void DELIB(ListeE L) {
    while (L != NULL) {
        L->moyenne = Average(L->notes);
        L = L->next;
    }
}

ListeE Delete(ListeE L) {
    ListeE tmp;
    while (L != NULL && L->moyenne < 5) {
        tmp = L;
        L = L->next;
        free(tmp);
    }
    if (L == NULL) return NULL;
    ListeE p = L;
    while (p->next != NULL) {
        if (p->next->moyenne < 5) {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }
    return L;
}

void RESULTAT(ListeE L, ListeE *LP, ListeE *LF) {
    *LP = NULL;
    *LF = NULL;
    while (L != NULL) {
        if (L->moyenne >= 10) {
            L->next = *LP;
            *LP = L;
        } else {
            L->next = *LF;
            *LF = L;
        }
        L = L->next;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
