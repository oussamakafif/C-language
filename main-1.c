#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titre[50];
    int quantite;
} Livre;

void ajouterLivre(Livre **bibliotheque, int *nombreLivres, char *titre) {
    for (int i = 0; i < *nombreLivres; i++) {
        if (strcmp((*bibliotheque)[i].titre, titre) == 0) {
            (*bibliotheque)[i].quantite++;
            return;
        }
    }
    Livre *temp = realloc(*bibliotheque, (*nombreLivres + 1) * sizeof(Livre));
    if (temp == NULL) {
        printf("Échec d'allocation mémoire !\n");
        return;
    }
    *bibliotheque = temp;
    strcpy((*bibliotheque)[*nombreLivres].titre, titre);
    (*bibliotheque)[*nombreLivres].quantite = 1;
    (*nombreLivres)++;
}

void retirerLivre(Livre **bibliotheque, int *nombreLivres, char *titre) {
    for (int i = 0; i < *nombreLivres; i++) {
        if (strcmp((*bibliotheque)[i].titre, titre) == 0) {
            (*bibliotheque)[i].quantite--;
            if ((*bibliotheque)[i].quantite == 0) {
                for (int j = i; j < *nombreLivres - 1; j++) {
                    (*bibliotheque)[j] = (*bibliotheque)[j + 1];
                }
                Livre *temp = realloc(*bibliotheque, (*nombreLivres - 1) * sizeof(Livre));
                if (temp != NULL || *nombreLivres - 1 == 0) {
                    *bibliotheque = temp;
                }
                (*nombreLivres)--;
            }
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void afficherBibliotheque(Livre *bibliotheque, int nombreLivres) {
    if (nombreLivres == 0) {
        printf("La bibliothèque est vide.\n");
        return;
    }
    printf("Livres dans la bibliothèque :\n");
    for (int i = 0; i < nombreLivres; i++) {
        printf("%s : %d exemplaire(s)\n", bibliotheque[i].titre, bibliotheque[i].quantite);
    }
}

int main() {
    Livre *bibliotheque = NULL;
    int nombreLivres = 0;

    ajouterLivre(&bibliotheque, &nombreLivres, "T-roc");
    ajouterLivre(&bibliotheque, &nombreLivres, "Twin");
    ajouterLivre(&bibliotheque, &nombreLivres, "T-roc");

    afficherBibliotheque(bibliotheque, nombreLivres);

    retirerLivre(&bibliotheque, &nombreLivres, "T-roc");

    afficherBibliotheque(bibliotheque, nombreLivres);

    free(bibliotheque);
    return 0;
}
