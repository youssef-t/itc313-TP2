#include "Magasin.h"
//constructor
Magasin::Magasin(){

}

/*Magasin::Magasin(std::vector <Product*> products, std::vector <Client*> clients, std::vector <order*> orders):
m_products(products), m_clients(clients), m_orders(orders){
}*/

//Ajout produit, client, ordre
void Magasin::addProduct(Product& product){
m_products.push_back() = &product;
}

void Magasin::addClient(Client& client){
m_clients.push_back() = &client;
}

void Magasin::addOrder(Order& order){
m_orders.push_back() = &order;
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

//méthode affichage de tous les produits
void Product::displayProducts(){
    tiretTableau();

    std::cout<< "\n| Products" ;
    
    espace(100-10); // 100 - strlen("| Products")

    std::cout<<"|"<< std::endl;
    
    std::cout<< "|";
    tiretTableau();
    std:cout<< "|" << std::endl;

    std::cout<< "| Name \t\t Description \t\t\tQuantity\t\tPrice \t |" << std::endl

    std::cout<< "|";
    tiretTableau();
    std:cout<< "|" << std::endl;

    //Affichage des produits
    for (int i=0; i < (int)m_products.size() ; i++ )
        std::cout<<"| "<< *(m_products.at(i))<<"\t |\n";

    //Afficher la dernière ligne
    tiretTableau();
    std:cout<< "|" << std::endl;
}

//méthode affichage d'un produit indiqué par son nom
void Product::displayProduct(std::string& produit){
tiretTableau();

std::cout << "\n Details of a product"
espace(100-21);
std::cout << "|";

std::cout <<"\n|"
tiretTableau();
std::cout<< "|";

std::cout<<"\n| " ;
for(i=0;i<m_products.size()<i++)
    if(*(m_products.at(i)).getTitre() == produit)
        std::cout << *(m_products.at(i)) << "\t |\n";

//Afficher la dernière ligne
tiretTableau();
std:cout<< "|" << std::endl;
}

//méthode mise à jour de la quantité d'un produit en indiquant son nom
void Product::updateQuantite(std::string& nom_produit,int& quantite){
    if(*(m_products.at(i)).getTitre() == produit)
            *(m_products.at(i)).setQuantite(quantite);
};



void Product::espace(int nbr_tiret){
    for(int i=0;i<nbr_tiret;i++)
        std::cout<<" ";
    std::cout<<"\n";
}

void Product::tiretTableau(int nbr_tiret){
    for(int i=0; i < nbr_tiret ; i++)
        std::cout<<"-";
}

void Product::tiretTableau(){
    for(int i=0; i < 100;i++)
        std::cout<<"-";
    std::cout<<"\n"
}