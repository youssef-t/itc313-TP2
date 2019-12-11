#include "Magasin.h"
//constructor
Magasin::Magasin(){

}

Magasin::Magasin(std::vector <Product*> products, std::vector <Client*> clients, std::vector <order*> orders):
m_products(products), m_clients(clients), m_orders(orders){
}

//setters
void Magasin::setProducts(std::vector<Products*>& products){
m_products = products;
}

void Magasin::setClients(std::vector<Client*>& clients){
m_clients = clients;
}

void Magasin::setOrders(std::vector<Order*>& orders){
m_orders = orders;
}

//getters
std::vector<Product*> Magasin::getProducts()const{
    return m_products;
}

std::vector<Client*> Magasin::getClients()const{
    return m_clients;
}

std::vector<Order*> Magasin::getOrders()const{
    return m_orders;
}

//méthode ajout d'un produit
void Product::addProduct(Produit& produit){
    m_products.push_back(produit);
}

//méthode affichage de tous les produits
void Product::displayProducts(){
    for(int i=0; i < 100; i++)
        std::cout << "---" ;

    std::cout<< "\n| Products" ;
    
    for(i=0 ; i < 90;i++)  // 100 - strlen("| Products")
        std::cout<< "   ";
    std::cout<<"|"<< std::endl;
    
    std::cout<< "|";
    for(int i=0; i < 100; i++)
        std::cout << "---" ;
    std:cout<< "|" << std::endl;

    std::cout<< "| Name \t\t Description \t\t\tQuantity\t\tPrice \t |" << std::endl

    std::cout<< "|";
    for(int i=0; i < 100; i++)
        std::cout << "---" ;
    std:cout<< "|" << std::endl;

    //Affichage des produits
    for (int i=0; i < (int)m_products.size() ; i++ )
        std::cout<<"| "<< *(m_products.at(i))<<"\t |\n";

    //Afficher la dernière ligne
    for(int i=0; i < 100; i++)
        std::cout << "---" ;
    std:cout<< "|" << std::endl;
}

//méthode affichage d'un produit indiqué par son nom
void Product::displayProduct(std::string& produit){
for(int i=0; i < 100; i++)
    std::cout << "---" ;

std::cout << "\n Details of a product"
for(int i=0; i < 100-21 ;i++)
    std::cout <<"   ";
std::cout << "|";

std::cout <<"\n|"
for(int i=0; i < 100; i++)
    std::cout << "---" ;
std::cout<< "|";

std::cout<<"\n| " ;
for(i=0;i<m_products.size()<i++)
    if(*(m_products.at(i)).getTitre() == produit)
        std::cout << *(m_products.at(i)) << "\t |\n";

//Afficher la dernière ligne
for(int i=0; i < 100; i++)
    std::cout << "---" ;
    std:cout<< "|" << std::endl;
}

//méthode mise à jour de la quantité d'un produit en indiquant son nom
void Product::updateQuantite(std::string& nom_produit,int& quantite){
    if(*(m_products.at(i)).getTitre() == produit)
            *(m_products.at(i)).setQuantite(quantite);
}