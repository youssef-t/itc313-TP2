#include <iostream>
#include "Commande.h"

int main(){
    Product ps4("PS4","Console de jeu", 5 , 299);
    Product ps3("PS3","Console de jeu", 5 , 999);
    Product ps2("PS2","Console de jeu", 5 , 79);
    
    std::vector<Product> produits_commandes = {ps2,ps3,ps4};
    produits_commandes.at(0).setQuantite(1);
    produits_commandes.at(1).setQuantite(2);
    produits_commandes.at(2).setQuantite(1);
    std::vector<Product> panier ; //panier vide
    
    Client client("Jean","Claude",panier);
    Commande commande(client, produits_commandes);
    
    std::cout<<commande;



    
    
    return 0;
}