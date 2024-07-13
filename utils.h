#ifndef UTILS_H
#define UTILS_H

#include "client.h"
#include "voiture.h"
#include "location.h"

void afficherVoituresFrequentes(Location* locations, int nb_locations, Voiture* voitures, int nb_voitures);
void afficherClientsFrequents(Location* locations, int nb_locations, Client* clients, int nb_clients);

#endif