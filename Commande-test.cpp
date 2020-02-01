#include <iostream>
#include "Commande.h"

int main(){
    Product ps4("PS4","Console de jeu", 5 , 299);
    Product ps3("PS3","Console de jeu", 5 , 999);
    Product mac("MacBook Pro","PC portable", 5 , 79);
    
    //std::vector<Product> panier = {mac,ps3,ps4};
    
    Client client("Jean","Claude");
    client.addProduct(ps4); //valeur par défaut : 1 ps4
    client.addProduct(mac , 2 ); // 2 Mac ont été ajoutés au panier
    
    client.updateQuantity("PS4",2);
    client.deleteProduct("MacBook Pro");

    Commande commande(client);      
    std::cout<<commande << std::endl;
    
    return 0;
}