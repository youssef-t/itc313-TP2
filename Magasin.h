#pragma once
#include <vector>
#include "Produit.h"
class Magasin {
public:
	//constractor
	Magasin();
	Magasin(std::vector <Product*> products, std::vector <Client*> clients, std::vector <order*> orders);
	
	//setters
	void setProducts(std::vector<Products*>& products);
	void setClients(std::vector<Client*>& clients);
	void setOrders(std::vector<Order*>& orders);

	//getters
	std::vector<Product*> getProducts()const;
	std::vector<Client*> getClients()const;
	std::vector<Order*> getOrders()const;
	
	//méthode ajout d'un produit
	void addProduct(Produit& produit);

	//méthode affichage de tous les produits
	void displayProducts();

	//méthode affichage d'un produit indiqué par son nom
	void displayProduct(std::string& produit);

	//méthode mise à jour de la quantité d'un produit en indiquant son nom
	void updateQuantite(std::string& nom_produit,int& quantite);

private:
	std::vector <Product* > m_products;
	std::vector <Client* > m_clients;
	std::vector <Order* > m_orders;
};