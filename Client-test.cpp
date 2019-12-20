#include <iostream>
#include "Client.h" // la bibliothèque Produit.h est incluse dans Client.h

int main(){
    Product ps4("PS4","Console de jeu", 5 , 299);
    Product ps3("PS3","Console de jeu", 5 , 999);
    Product ps2("PS2","Console de jeu", 5 , 79);

    std::vector<Product> panierA = {ps4};

    Client clientA("Jean","Claude",panierA);
    clientA.addProduct(ps3);
    clientA.updateQuantity(ps3,1);
    clientA.updateQuantity(ps4,2);

    std::vector<Product> panierB = {ps2,ps3};
    Client clientB("Jean","Bernard",panierB);
    clientB.updateQuantity(ps3,2);
    clientB.updateQuantity(ps2,1);


    std::cout << clientA << clientB ;

    //vider le panier du client B
    std::cout << "\nVider le panier du client B\n";
    clientB.viderPanier();
    std::cout << clientB;

    //delete ps3 
    std::cout << "\nSupprimer le produit ps3 du panier du client A\n";
    clientA.deleteProduct(ps3);
    std::cout << clientA;

    return 0;
}