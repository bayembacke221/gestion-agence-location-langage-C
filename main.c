#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "voiture.h"
#include "location.h"
#include "utils.h"

void ajouterClient(Client* clients, int* nb_clients) {
    Client nouveau_client;
    printf("Entrez le numéro du client : ");
    scanf("%d", &nouveau_client.numero);

    // Vérifier si le numéro est unique
    for (int i = 0; i < *nb_clients; i++) {
        if (clients[i].numero == nouveau_client.numero) {
            printf("Erreur : Numéro client déjà utilisé\n");
            return;
        }
    }

    printf("Entrez le nom du client : ");
    scanf("%s", nouveau_client.nom);
    printf("Entrez la profession du client : ");
    scanf("%s", nouveau_client.profession);

    clients[*nb_clients] = nouveau_client;
    (*nb_clients)++;

    sauvegarderClients(clients, *nb_clients);
    printf("OK\n");
}

void afficherClients(Client* clients, int nb_clients) {
    if (nb_clients == 0) {
        printf("Erreur : Liste vide\n");
        return;
    }

    for (int i = 0; i < nb_clients; i++) {
        printf("Client Numéro : %d\n", clients[i].numero);
        printf("- Nom : %s\n", clients[i].nom);
        printf("- Profession : %s\n", clients[i].profession);
        printf("\n");
    }
}

Client* rechercherClient(Client* clients, int nb_clients, int numero) {
    for (int i = 0; i < nb_clients; i++) {
        if (clients[i].numero == numero) {
            return &clients[i];
        }
    }
    return NULL;
}

void modifierClient(Client* clients, int nb_clients) {
    int numero;
    printf("Entrez le numéro du client à modifier : ");
    scanf("%d", &numero);

    Client* client = rechercherClient(clients, nb_clients, numero);
    if (client == NULL) {
        printf("Erreur : Client non trouvé\n");
        return;
    }

    printf("Entrez le nouveau nom du client : ");
    scanf("%s", client->nom);
    printf("Entrez la nouvelle profession du client : ");
    scanf("%s", client->profession);

    sauvegarderClients(clients, nb_clients);
    printf("OK\n");
}

void supprimerClient(Client* clients, int* nb_clients) {
    int numero;
    printf("Entrez le numéro du client à supprimer : ");
    scanf("%d", &numero);

    int index = -1;
    for (int i = 0; i < *nb_clients; i++) {
        if (clients[i].numero == numero) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : Client non trouvé\n");
        return;
    }

    for (int i = index; i < *nb_clients - 1; i++) {
        clients[i] = clients[i + 1];
    }

    (*nb_clients)--;
    sauvegarderClients(clients, *nb_clients);
    printf("OK\n");
}
void ajouterVoiture(Voiture* voitures, int* nb_voitures) {
    Voiture nouvelle_voiture;
    printf("Entrez le code de la voiture : ");
    scanf("%d", &nouvelle_voiture.code);

    // Vérifier si le code est unique
    for (int i = 0; i < *nb_voitures; i++) {
        if (voitures[i].code == nouvelle_voiture.code) {
            printf("Erreur : Code voiture déjà utilisé\n");
            return;
        }
    }

    printf("Entrez la marque de la voiture : ");
    scanf("%s", nouvelle_voiture.marque);
    printf("Entrez le modèle de la voiture : ");
    scanf("%s", nouvelle_voiture.modele);
    printf("Entrez le nombre total d'exemplaires : ");
    scanf("%d", &nouvelle_voiture.nb_exemplaires_total);
    nouvelle_voiture.nb_exemplaires_disponibles = nouvelle_voiture.nb_exemplaires_total;
    printf("Entrez le tarif journalier : ");
    scanf("%f", &nouvelle_voiture.tarif_journalier);

    voitures[*nb_voitures] = nouvelle_voiture;
    (*nb_voitures)++;

    sauvegarderVoitures(voitures, *nb_voitures);
    printf("OK\n");
}

void afficherVoitures(Voiture* voitures, int nb_voitures) {
    if (nb_voitures == 0) {
        printf("Erreur : Liste vide\n");
        return;
    }

    for (int i = 0; i < nb_voitures; i++) {
        printf("Voiture Code : %d\n", voitures[i].code);
        printf("- Marque : %s\n", voitures[i].marque);
        printf("- Modèle : %s\n", voitures[i].modele);
        printf("- Exemplaires total : %d\n", voitures[i].nb_exemplaires_total);
        printf("- Exemplaires disponibles : %d\n", voitures[i].nb_exemplaires_disponibles);
        printf("- Tarif journalier : %.2f\n", voitures[i].tarif_journalier);
        printf("\n");
    }
}

Voiture* rechercherVoiture(Voiture* voitures, int nb_voitures, int code) {
    for (int i = 0; i < nb_voitures; i++) {
        if (voitures[i].code == code) {
            return &voitures[i];
        }
    }
    return NULL;
}

void modifierVoiture(Voiture* voitures, int nb_voitures) {
    int code;
    printf("Entrez le code de la voiture à modifier : ");
    scanf("%d", &code);

    Voiture* voiture = rechercherVoiture(voitures, nb_voitures, code);
    if (voiture == NULL) {
        printf("Erreur : Voiture non trouvée\n");
        return;
    }

    printf("Entrez la nouvelle marque : ");
    scanf("%s", voiture->marque);
    printf("Entrez le nouveau modèle : ");
    scanf("%s", voiture->modele);
    printf("Entrez le nouveau nombre total d'exemplaires : ");
    scanf("%d", &voiture->nb_exemplaires_total);
    printf("Entrez le nouveau tarif journalier : ");
    scanf("%f", &voiture->tarif_journalier);

    sauvegarderVoitures(voitures, nb_voitures);
    printf("OK\n");
}

void supprimerVoiture(Voiture* voitures, int* nb_voitures) {
    int code;
    printf("Entrez le code de la voiture à supprimer : ");
    scanf("%d", &code);

    int index = -1;
    for (int i = 0; i < *nb_voitures; i++) {
        if (voitures[i].code == code) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : Voiture non trouvée\n");
        return;
    }

    for (int i = index; i < *nb_voitures - 1; i++) {
        voitures[i] = voitures[i + 1];
    }

    (*nb_voitures)--;
    sauvegarderVoitures(voitures, *nb_voitures);
    printf("OK\n");
}
void ajouterLocation(Location* locations, int* nb_locations, Client* clients, int nb_clients, Voiture* voitures, int nb_voitures) {
    Location nouvelle_location;
    printf("Entrez le numéro du client : ");
    scanf("%d", &nouvelle_location.numero_client);

    if (rechercherClient(clients, nb_clients, nouvelle_location.numero_client) == NULL) {
        printf("Erreur : Client inconnu\n");
        return;
    }

    printf("Entrez le code de la voiture : ");
    scanf("%d", &nouvelle_location.code_voiture);

    Voiture* voiture = rechercherVoiture(voitures, nb_voitures, nouvelle_location.code_voiture);
    if (voiture == NULL) {
        printf("Erreur : Voiture inconnue\n");
        return;
    }

    if (voiture->nb_exemplaires_disponibles == 0) {
        printf("Erreur : Pas d'exemplaire disponible pour cette voiture\n");
        return;
    }

    printf("Entrez la date de début (JJ/MM/AAAA) : ");
    scanf("%s", nouvelle_location.date_debut);
    printf("Entrez le nombre de jours : ");
    scanf("%d", &nouvelle_location.nb_jours);

    nouvelle_location.tarif = voiture->tarif_journalier;
    nouvelle_location.cout_total = nouvelle_location.tarif * nouvelle_location.nb_jours;
    nouvelle_location.etat = RESERVEE;

    locations[*nb_locations] = nouvelle_location;
    (*nb_locations)++;

    voiture->nb_exemplaires_disponibles--;

    sauvegarderLocations(locations, *nb_locations);
    sauvegarderVoitures(voitures, nb_voitures);
    printf("OK\n");
}

void afficherLocations(Location* locations, int nb_locations) {
    if (nb_locations == 0) {
        printf("Erreur : Liste vide\n");
        return;
    }

    for (int i = 0; i < nb_locations; i++) {
        printf("Location :\n");
        printf("- Numéro client : %d\n", locations[i].numero_client);
        printf("- Code voiture : %d\n", locations[i].code_voiture);
        printf("- Date début : %s\n", locations[i].date_debut);
        printf("- Nombre de jours : %d\n", locations[i].nb_jours);
        printf("- Tarif : %.2f\n", locations[i].tarif);
        printf("- Coût total : %.2f\n", locations[i].cout_total);
        printf("- État : %d\n", locations[i].etat);
        printf("\n");
    }
}

void rechercherLocationParClient(Location* locations, int nb_locations, int numero_client) {
    int trouve = 0;
    for (int i = 0; i < nb_locations; i++) {
        if (locations[i].numero_client == numero_client) {
            printf("Location trouvée :\n");
            printf("- Code voiture : %d\n", locations[i].code_voiture);
            printf("- Date début : %s\n", locations[i].date_debut);
            printf("- Nombre de jours : %d\n", locations[i].nb_jours);
            printf("- État : %d\n", locations[i].etat);
            printf("\n");
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune location trouvée pour ce client\n");
    }
}

void rechercherLocationParVoiture(Location* locations, int nb_locations, int code_voiture) {
    int trouve = 0;
    for (int i = 0; i < nb_locations; i++) {
        if (locations[i].code_voiture == code_voiture) {
            printf("Location trouvée :\n");
            printf("- Numéro client : %d\n", locations[i].numero_client);
            printf("- Date début : %s\n", locations[i].date_debut);
            printf("- Nombre de jours : %d\n", locations[i].nb_jours);
            printf("- État : %d\n", locations[i].etat);
            printf("\n");
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune location trouvée pour cette voiture\n");
    }
}

void modifierEtatLocation(Location* locations, int nb_locations, Voiture* voitures, int nb_voitures) {
    int numero_client, code_voiture;
    printf("Entrez le numéro du client : ");
    scanf("%d", &numero_client);
    printf("Entrez le code de la voiture : ");
    scanf("%d", &code_voiture);

    int index = -1;
    for (int i = 0; i < nb_locations; i++) {
        if (locations[i].numero_client == numero_client && locations[i].code_voiture == code_voiture) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : Location non trouvée\n");
        return;
    }

    int nouvel_etat;
    printf("Entrez le nouvel état (0: RESERVEE, 1: EN_COURS, 2: TERMINEE) : ");
    scanf("%d", &nouvel_etat);

    if (nouvel_etat < 0 || nouvel_etat > 2) {
        printf("Erreur : État invalide\n");
        return;
    }

    locations[index].etat = (EtatLocation)nouvel_etat;

    if (nouvel_etat == TERMINEE) {
        for (int i = 0; i < nb_voitures; i++) {
            if (voitures[i].code == code_voiture) {
                voitures[i].nb_exemplaires_disponibles++;
                break;
            }
        }
    }

    sauvegarderLocations(locations, nb_locations);
    sauvegarderVoitures(voitures, nb_voitures);
    printf("OK\n");
}

void supprimerLocation(Location* locations, int* nb_locations, Voiture* voitures, int nb_voitures) {
    int numero_client, code_voiture;
    printf("Entrez le numéro du client : ");
    scanf("%d", &numero_client);
    printf("Entrez le code de la voiture : ");
    scanf("%d", &code_voiture);

    int index = -1;
    for (int i = 0; i < *nb_locations; i++) {
        if (locations[i].numero_client == numero_client && locations[i].code_voiture == code_voiture) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : Location non trouvée\n");
        return;
    }

    for (int i = 0; i < nb_voitures; i++) {
        if (voitures[i].code == code_voiture) {
            voitures[i].nb_exemplaires_disponibles++;
            break;
        }
    }

    for (int i = index; i < *nb_locations - 1; i++) {
        locations[i] = locations[i + 1];}

    (*nb_locations)--;
    sauvegarderLocations(locations, *nb_locations);
    sauvegarderVoitures(voitures, nb_voitures);
    printf("OK\n");
}

// Gestion des fichiers

void sauvegarderClients(Client* clients, int nb_clients) {
    FILE* fichier = fopen("clients.txt", "wb");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier clients.txt\n");
        return;
    }

    fwrite(&nb_clients, sizeof(int), 1, fichier);
    fwrite(clients, sizeof(Client), nb_clients, fichier);

    fclose(fichier);
}

void chargerClients(Client* clients, int* nb_clients) {
    FILE* fichier = fopen("clients.txt", "rb");
    if (fichier == NULL) {
        *nb_clients = 0;
        return;
    }

    fread(nb_clients, sizeof(int), 1, fichier);
    fread(clients, sizeof(Client), *nb_clients, fichier);

    fclose(fichier);
}

void sauvegarderVoitures(Voiture* voitures, int nb_voitures) {
    FILE* fichier = fopen("voitures.txt", "wb");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier voitures.txt\n");
        return;
    }

    fwrite(&nb_voitures, sizeof(int), 1, fichier);
    fwrite(voitures, sizeof(Voiture), nb_voitures, fichier);

    fclose(fichier);
}

void chargerVoitures(Voiture* voitures, int* nb_voitures) {
    FILE* fichier = fopen("voitures.txt", "rb");
    if (fichier == NULL) {
        *nb_voitures = 0;
        return;
    }

    fread(nb_voitures, sizeof(int), 1, fichier);
    fread(voitures, sizeof(Voiture), *nb_voitures, fichier);

    fclose(fichier);
}

void sauvegarderLocations(Location* locations, int nb_locations) {
    FILE* fichier = fopen("locations.txt", "wb");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier locations.txt\n");
        return;
    }

    fwrite(&nb_locations, sizeof(int), 1, fichier);
    fwrite(locations, sizeof(Location), nb_locations, fichier);

    fclose(fichier);
}

void chargerLocations(Location* locations, int* nb_locations) {
    FILE* fichier = fopen("locations.txt", "rb");
    if (fichier == NULL) {
        *nb_locations = 0;
        return;
    }

    fread(nb_locations, sizeof(int), 1, fichier);
    fread(locations, sizeof(Location), *nb_locations, fichier);

    fclose(fichier);
}

// Fonctions optionnelles

void afficherVoituresFrequentes(Location* locations, int nb_locations, Voiture* voitures, int nb_voitures) {
    int* compteurs = (int*)calloc(nb_voitures, sizeof(int));
    if (compteurs == NULL) {
        printf("Erreur : Allocation mémoire impossible\n");
        return;
    }

    for (int i = 0; i < nb_locations; i++) {
        for (int j = 0; j < nb_voitures; j++) {
            if (locations[i].code_voiture == voitures[j].code) {
                compteurs[j]++;
                break;
            }
        }
    }

    // Tri simple par sélection
    for (int i = 0; i < nb_voitures - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < nb_voitures; j++) {
            if (compteurs[j] > compteurs[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            int temp_count = compteurs[i];
            compteurs[i] = compteurs[max_idx];
            compteurs[max_idx] = temp_count;

            Voiture temp_voiture = voitures[i];
            voitures[i] = voitures[max_idx];
            voitures[max_idx] = temp_voiture;
        }
    }

    printf("Voitures les plus fréquemment louées :\n");
    for (int i = 0; i < nb_voitures && i < 5; i++) {
        printf("%d. %s %s (Code: %d) - %d locations\n", 
               i+1, voitures[i].marque, voitures[i].modele, voitures[i].code, compteurs[i]);
    }

    free(compteurs);
}

void afficherClientsFrequents(Location* locations, int nb_locations, Client* clients, int nb_clients) {
    int* compteurs = (int*)calloc(nb_clients, sizeof(int));
    if (compteurs == NULL) {
        printf("Erreur : Allocation mémoire impossible\n");
        return;
    }

    for (int i = 0; i < nb_locations; i++) {
        for (int j = 0; j < nb_clients; j++) {
            if (locations[i].numero_client == clients[j].numero) {
                compteurs[j]++;
                break;
            }
        }
    }

    // Tri simple par sélection
    for (int i = 0; i < nb_clients - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < nb_clients; j++) {
            if (compteurs[j] > compteurs[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            int temp_count = compteurs[i];
            compteurs[i] = compteurs[max_idx];
            compteurs[max_idx] = temp_count;

            Client temp_client = clients[i];
            clients[i] = clients[max_idx];
            clients[max_idx] = temp_client;
        }
    }

    printf("Clients ayant effectué le plus de locations :\n");
    for (int i = 0; i < nb_clients && i < 5; i++) {
        printf("%d. %s (Numéro: %d) - %d locations\n", 
               i+1, clients[i].nom, clients[i].numero, compteurs[i]);
    }

    free(compteurs);
}

// Fonction principale

int main() {
    Client clients[100];
    Voiture voitures[100];
    Location locations[1000];
    int nb_clients = 0, nb_voitures = 0, nb_locations = 0;

    chargerClients(clients, &nb_clients);
    chargerVoitures(voitures, &nb_voitures);
    chargerLocations(locations, &nb_locations);

    char commande[50];
    while (1) {
        printf("Entrez une commande : ");
        scanf("%s", commande);

        if (strcmp(commande, "ajoutClient") == 0) {
            ajouterClient(clients, &nb_clients);
        } else if (strcmp(commande, "afficheClients") == 0) {
            afficherClients(clients, nb_clients);
        } else if (strcmp(commande, "rechercheClient") == 0) {
            int numero;
            printf("Entrez le numéro du client : ");
            scanf("%d", &numero);
            Client* client = rechercherClient(clients, nb_clients, numero);
            if (client != NULL) {
                printf("Client trouvé : %s (Profession: %s)\n", client->nom, client->profession);
            } else {
                printf("Client non trouvé\n");
            }
        } else if (strcmp(commande, "modifieClient") == 0) {
            modifierClient(clients, nb_clients);
        } else if (strcmp(commande, "supprimeClient") == 0) {
            supprimerClient(clients, &nb_clients);
        } else if (strcmp(commande, "ajoutVoiture") == 0) {
            ajouterVoiture(voitures, &nb_voitures);
        } else if (strcmp(commande, "afficheVoitures") == 0) {
            afficherVoitures(voitures, nb_voitures);
        } else if (strcmp(commande, "rechercheVoiture") == 0) {
            int code;
            printf("Entrez le code de la voiture : ");
            scanf("%d", &code);
            Voiture* voiture = rechercherVoiture(voitures, nb_voitures, code);
            if (voiture != NULL) {
                printf("Voiture trouvée : %s %s (Disponibles: %d)\n", voiture->marque, voiture->modele, voiture->nb_exemplaires_disponibles);
            } else {
                printf("Voiture non trouvée\n");
            }
        } else if (strcmp(commande, "modifieVoiture") == 0) {
            modifierVoiture(voitures, nb_voitures);
        } else if (strcmp(commande, "supprimeVoiture") == 0) {
            supprimerVoiture(voitures, &nb_voitures);
        } else if (strcmp(commande, "ajoutLocation") == 0) {
            ajouterLocation(locations, &nb_locations, clients, nb_clients, voitures, nb_voitures);
        } else if (strcmp(commande, "afficheLocations") == 0) {
            afficherLocations(locations, nb_locations);
        } else if (strcmp(commande, "rechercheLocationClient") == 0) {
            int numero_client;
            printf("Entrez le numéro du client : ");
            scanf("%d", &numero_client);
            rechercherLocationParClient(locations, nb_locations, numero_client);
        } else if (strcmp(commande, "rechercheLocationVoiture") == 0) {
            int code_voiture;
            printf("Entrez le code de la voiture : ");
            scanf("%d", &code_voiture);
            rechercherLocationParVoiture(locations, nb_locations, code_voiture);
        } else if (strcmp(commande, "modifieEtatLocation") == 0) {
            modifierEtatLocation(locations, nb_locations, voitures, nb_voitures);
        } else if (strcmp(commande, "supprimeLocation") == 0) {
            supprimerLocation(locations, &nb_locations, voitures, nb_voitures);
        } else if (strcmp(commande, "voituresFrequentes") == 0) {
            afficherVoituresFrequentes(locations, nb_locations, voitures, nb_voitures);
        } else if (strcmp(commande, "clientsFrequents") == 0) {
            afficherClientsFrequents(locations, nb_locations, clients, nb_clients);
        } else if (strcmp(commande, "quitter") == 0) {
            break;
        } else {
            printf("Commande non reconnue\n");
        }
    }

    sauvegarderClients(clients, nb_clients);
    sauvegarderVoitures(voitures, nb_voitures);
    sauvegarderLocations(locations, nb_locations);

    return 0;
}