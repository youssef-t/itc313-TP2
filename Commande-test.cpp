#include <iostream>
#include "Commande.h"

int main(){
    Product ps4("PS4","Console de jeu", 5 , 299);
    Product ps3("PS3","Console de jeu", 5 , 999);
    Product mac("MacBook Pro","PC portable", 5 , 79);
    
    std::vector<Product> produits_commandes = {mac,ps3,ps4};
    std::vector<Product> panier ; //panier vide
    
    Client client("Jean","Claude",panier);
    //par défaut les produits commandés sont de quantité 1
    Commande commande(client, produits_commandes);       
    std::cout<<commande << std::endl;

    //Après modification des quantités de produits
    produits_commandes.at(0).setQuantite(1);
    produits_commandes.at(1).setQuantite(2);
    produits_commandes.at(2).setQuantite(1);

    commande.setProduct(produits_commandes);
    std::cout << "Après changement des quantités des produits commandés\n";
    std::cout << commande << std::endl;

    
    
    return 0;
}