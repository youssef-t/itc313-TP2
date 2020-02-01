/*NOTE :
        On a opté à utiliser une classe puisque toutes ces fonctions affectent
        une variable magasin 
        Pour ne pas utiliser une classe, il suffit d'avoir une variable globale
        de type Magasin sauf qu'il peut y avoir des erreurs
        Alors par prévention, on utilise une classe
*/
#pragma once

#include <iostream>
#include <fstream> //pour manipuler des fichiers
#include "Magasin.h" //les bibliothèques Produit.h , Client.h et Commande.h 
                     // sont incluses dans Magasin.h ainsi que string et vector


class Programme{
public:
//La première méthode qui s'éxuctera lors du programme principal
    void choix(char help);

//méthodes pour écrire les données
    void writeOrders();
    void writeClients();
    void writeProducts();

//méthode pour lire les données





private:
    //toutes ces méthodes privées seront pas utilisées "directement" par l'utilisateur
    //elles servent à découper notre programme en morceaux
    void gestionMagasin();
    void choixGestionMagasin(char help);
    void ajoutProduit(int nbr_produits);
    void modificationProduit();
    void affichageProduits();
    void affichageProduit();

    void gestionUtilisateurs();
    void choixGestionUtilisateurs(char help);

    void gestionCommandes();  
    void choixGestionCommandes(char help);


private :
    //variable membre
    Magasin m_magasin;
};
