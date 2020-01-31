#pragma once
#include <vector>
#include "Produit.h"
#include "Client.h"
#include "Commande.h"

class Magasin {
public:
	//constractor
	Magasin();
	Magasin(std::vector <Product> products, std::vector <Client> clients, std::vector <Commande> orders);
	//On peut pas mettre des valeurs par défaut pour les deux autres paramètres, donc on déclare ce constructeur
	Magasin(std::vector <Product> products);
	
	//méthode ajout d'un produit
	void addProduct(Product& produit);
	//méthode ajout d'un client
	void addClient(Client& client);
	//méthode ajout d'une commande	
	void addOrder(Commande& order);
	//méthode affichage de tous les produits
	void displayProducts();

	//méthode affichage d'un produit indiqué par son nom
	void displayProduct(std::string nom_produit);

	//méthode mise à jour de la quantité d'un produit en indiquant son nom
	void updateQuantite(std::string nom_produit,int quantite);

	//add product to store
	void addProductToStore(std::string nom, std::string description, float prix, int quantite);

private:
	std::vector <Product* > m_products;
	std::vector <Client* > m_clients;
	std::vector <Commande* > m_orders;

};