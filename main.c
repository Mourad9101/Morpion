#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char EMPTY = ' ';
const char JOUEUR = 'X';
const char PC = 'O';

void afficher_plateau(char plateau[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", plateau[i][0], plateau[i][1], plateau[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

int verifier_gagnant(char plateau[3][3], char joueur) {
    for (int i = 0; i < 3; i++)
        if ((plateau[i][0] == joueur && plateau[i][1] == joueur && plateau[i][2] == joueur) ||
            (plateau[0][i] == joueur && plateau[1][i] == joueur && plateau[2][i] == joueur))
            return 1;
    return (plateau[0][0] == joueur && plateau[1][1] == joueur && plateau[2][2] == joueur) ||
           (plateau[0][2] == joueur && plateau[1][1] == joueur && plateau[2][0] == joueur);
}

int plateau_plein(char plateau[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (plateau[i][j] == EMPTY)
                return 0;
    return 1;
}

void jouer_tour(char plateau[3][3], char joueur) {
    int case_jouer;
    if (joueur == JOUEUR) {
        printf("Choisissez une case de 0 à 8 : ");
        scanf("%d", &case_jouer);
        while (case_jouer < 0 || case_jouer > 8 || plateau[case_jouer / 3][case_jouer % 3] != EMPTY) {
            printf("Entrée invalide. Essayez à nouveau : ");
            scanf("%d", &case_jouer);
        }
    } else {
        do {
            case_jouer = rand() % 9;
        } while (plateau[case_jouer / 3][case_jouer % 3] != EMPTY);
        printf("L'ordinateur a joué la case %d\n", case_jouer);
    }
    plateau[case_jouer / 3][case_jouer % 3] = joueur;
}

int main() {
    char plateau[3][3] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    char joueur = JOUEUR;
    srand(time(NULL));

    while (1) {
        afficher_plateau(plateau);
        jouer_tour(plateau, joueur);

        if (verifier_gagnant(plateau, joueur)) {
            afficher_plateau(plateau);
            printf("C'est gagné !\n");
            break;
        }
        if (plateau_plein(plateau)) {
            afficher_plateau(plateau);
            printf("Match nul !\n");
            break;
        }
        joueur = (joueur == JOUEUR) ? PC : JOUEUR;
    }

    if (verifier_gagnant(plateau, PC)) {
        afficher_plateau(plateau);
        printf("C'est perdu !\n");
    }

    return 0;
}
