#ifndef LOCATION_H
#define LOCATION_H

#include "client.h"
#include "voiture.h"

typedef enum {
    RESERVEE,
    EN_COURS,
    TERMINEE
} EtatLocation;

typedef struct {
    int numero_client;
    int code_voiture;
    char date_debut[11];
    int nb_jours;
    float tarif;
    float cout_total;
    EtatLocation etat;
} Location;

void ajouterLocation(Location* locations, int* nb_locations, Client* clients, int nb_clients, Voiture* voitures, int nb_voitures);
void afficherLocations(Location* locations, int nb_locations);
void rechercherLocationParClient(Location* locations, int nb_locations, int numero_client);
void rechercherLocationParVoiture(Location* locations, int nb_locations, int code_voiture);
void modifierEtatLocation(Location* locations, int nb_locations, Voiture* voitures, int nb_voitures);
void supprimerLocation(Location* locations, int* nb_locations, Voiture* voitures, int nb_voitures);
void sauvegarderLocations(Location* locations, int nb_locations);
void chargerLocations(Location* locations, int* nb_locations);

#endif