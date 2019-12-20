#include <iostream>
#include "Client.h" // la bibliothèque Produit.h est incluse dans Client.h

int main(){
    Product ps4("PS4","Console de jeu", 5 , 299);
    Product mac_book("Mac book pro","PC portable", 5 , 999);

    std::vector<Product> panier = {ps4};

    Client client("Jean","Claude",panier);
    client.addProduct(mac_book);

    return 0;
}