#ifndef VOITURE_H
#define VOITURE_H

typedef struct {
    int code;
    char marque[50];
    char modele[50];
    int nb_exemplaires_total;
    int nb_exemplaires_disponibles;
    float tarif_journalier;
} Voiture;

void ajouterVoiture(Voiture* voitures, int* nb_voitures);
void afficherVoitures(Voiture* voitures, int nb_voitures);
Voiture* rechercherVoiture(Voiture* voitures, int nb_voitures, int code);
void modifierVoiture(Voiture* voitures, int nb_voitures);
void supprimerVoiture(Voiture* voitures, int* nb_voitures);
void sauvegarderVoitures(Voiture* voitures, int nb_voitures);
void chargerVoitures(Voiture* voitures, int* nb_voitures);

#endif