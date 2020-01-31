#include "Magasin.h"

//constructor
Magasin::Magasin(){

}


Magasin::Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders){
    m_products.reserve(products.size()); //allocation de mémoire pour raison de performances
    for(auto& i : products) // passage par réference pour ne pas faire de copie
        m_products.push_back(&i); // &i est équivalent à &(m_products.at(i)) dans le cas d'une boucle for normale 

    m_clients.reserve(clients.size());
    for(auto& i : clients)
        m_clients.push_back(&i);
    
    m_orders.reserve(orders.size());
    for(auto& i : orders)
        m_orders.push_back(&i); 

}

//Constructeur qui prend en paramètre un vecteur de produit 
Magasin::Magasin(std::vector <Product>& products){
    m_products.reserve(products.size()); 
    for(auto& i : products) 
        m_products.push_back(&i);

}

//Ajout produit, client, ordre
void Magasin::addProduct(Product& product){
    m_products.push_back(&product) ;
}

void Magasin::addClient(Client& client){
    m_clients.push_back(&client) ;
}

void Magasin::addOrder(Commande& order){
    m_orders.push_back(&order) ;
}


//méthode mise à jour de la quantité d'un produit en indiquant son nom
void Magasin::updateQuantite(std::string nom_produit,int quantite){
    //on peut utiliser auto& puisque le compilateur sait déjà le type de m_products
    if(quantite >= 0){
        for(auto& i : m_products){
        //i est un pointeur, pour cela on utilise l'opérateur ->, sinon on peut utiliser *(i).
             if( i->getTitre() == nom_produit){
            i->setQuantite(quantite);
            break;
             }
        }
    }
    else 
        std::cout << "Erreur : quantité saisie est inférieure à 0 .\n";
}

void Magasin::addProductToStore(std::string nom, std::string description, float prix, int quantite){
    Product* produit = new Product(nom, description, prix, quantite);
    m_products.push_back(produit);
}

void Magasin::displayProduct(std::string nom_produit){
    for(auto& i : m_products)
        if( i->getTitre() == nom_produit){
            std::cout << "\nDetails of a product\n" ;
            std::cout << *i << "\n";
            break; //pour arrêter la boucle puisque le produit a déjà été trouvé
        }
}

void Magasin::displayProducts(){
//Affichage du haut du tableau
    std::cout << "\nProducts\n" ;
    std::cout << "Name" ;
    for(int i = 0 ; i < 15 - 4; i++)  //taille du champ total est 15 et la taille de Name est 4
        std::cout << " ";

    std::cout << "Description";
    for(int i = 0 ; i < 40 - 11 ; i++)  //taille du champ total est 15 et la taille de Description est 11
        std::cout << " ";        

    std::cout << "Quantity";
    for(int i = 0 ; i < 12 - 8; i++)  //taille du champ total est 10 et la taille de Quantity est 8
        std::cout << " ";      

    std::cout << "Price\n";    

//Affichage des produits
for(auto& i : m_products )
   std::cout << *i << std::endl;

std::cout << std::endl; 
}

