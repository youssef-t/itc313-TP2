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


