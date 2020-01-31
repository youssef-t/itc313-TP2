#include "Produit.h" //iostream est inclus dans Produit.h

int main(){
    Product produit1("PS2","Console",2,300);
    Product produit2("MacBook Pro", "PC portable", 3, 999);

    std::cout<< produit1 << std::endl;
    std::cout<< produit2 << std::endl;

    std::cout << "Voulez-vous saisir un produit ? Si oui, veuillez taper O/o. Sinon veuillez taper un autre caractère" << std::endl;
    char aide;
    std::cin >> aide;

    if(aide == 'O' || aide == 'o'){
        std::string titre, description;
        int quantity;
        double prix;

        std::cout << "Saisir le titre du produit : ";
        std::cin >> titre ;
        std::cout << "Saisir la description du produit : ";
        std::cin >> description ;
        std::cout << "Saisir la quantité du produit : ";
        std::cin >> quantity ;
        std::cout << "Saisir le prix du produit : ";
        std::cin >> prix ;

        Product produit_saisi(titre,description,quantity,prix);

        std::cout << "Le produit saisi : \n" ;
        std::cout << produit_saisi;

    }

    return 0;
}