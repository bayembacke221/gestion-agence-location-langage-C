#ifndef CLIENT_H
#define CLIENT_H

typedef struct {
    int numero;
    char nom[50];
    char profession[50];
} Client;

void ajouterClient(Client* clients, int* nb_clients);
void afficherClients(Client* clients, int nb_clients);
Client* rechercherClient(Client* clients, int nb_clients, int numero);
void modifierClient(Client* clients, int nb_clients);
void supprimerClient(Client* clients, int* nb_clients);
void sauvegarderClients(Client* clients, int nb_clients);
void chargerClients(Client* clients, int* nb_clients);

#endif