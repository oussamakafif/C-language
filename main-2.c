#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int heures;
    int minutes;
    int secondes;
} Heure;

void ajouterHeure(Heure *temps, int heuresAjoutees) {
    temps->heures = (temps->heures + heuresAjoutees) % 24;
}

void ajouterMinutes(Heure *temps, int minutesAjoutees) {
    ajouterHeure(temps, (temps->minutes + minutesAjoutees) / 60);
    temps->minutes = (temps->minutes + minutesAjoutees) % 60;
}

void ajouterSecondes(Heure *temps, int secondesAjoutees) {
    ajouterMinutes(temps, (temps->secondes + secondesAjoutees) / 60);
    temps->secondes = (temps->secondes + secondesAjoutees) % 60;
}

void afficherHeure(Heure *temps) {
    printf("Heure actuelle = %02d:%02d:%02d\n", temps->heures, temps->minutes, temps->secondes);
}

int main() {
    Heure temps = {23, 36, 45};
    int heuresAjoutees, minutesAjoutees, secondesAjoutees;

    printf("Entrez les heures à ajouter : ");
    scanf("%d", &heuresAjoutees);
    printf("Entrez les minutes à ajouter : ");
    scanf("%d", &minutesAjoutees);
    printf("Entrez les secondes à ajouter : ");
    scanf("%d", &secondesAjoutees);

    ajouterHeure(&temps, heuresAjoutees);
    ajouterMinutes(&temps, minutesAjoutees);
    ajouterSecondes(&temps, secondesAjoutees);

    afficherHeure(&temps);

    return 0;
}
