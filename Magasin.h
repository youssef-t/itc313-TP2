#pragma once
#include <vector>
#include "Produit.h"
#include "Client.h"
#include "Commande.h"

class Magasin {
public:
	//constractor
	Magasin();
	Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders);
	//On peut pas mettre des valeurs par défaut pour les deux autres paramètres, donc on déclare ce constructeur
	Magasin(std::vector <Product>& products);
	
	//méthode ajout d'un produit en passant comme paramètre le "produit"
	void addProduct(Product& produit);
	//méthode ajout d'un client en passant comme paramètre le "client"
	void addClient(Client& client);
	//méthode ajout d'une commande en passant comme paramètre la "commande"
	void addOrder(Commande& order);
	//méthode affichage de tous les produits
	void displayProducts();

	//méthode affichage d'un produit indiqué par son nom
	void displayProduct(std::string nom_produit);

	//méthode mise à jour de la quantité d'un produit en indiquant son nom
	void updateQuantite(std::string nom_produit,int quantite);

	//add product to store
	void addProductToStore(std::string nom, std::string description, float prix, int quantite);

	//ajout d'un client en passant en paramètre son nom et prénom
	void addClient(std::string prenom, std::string nom);

	//méthode affichage des tous les clients du magasin
	void displayClients();

	//méthode affichage d'un client 
	void displayClient(std::string prenom, std::string nom);
	void displayClient(int id);

	//méthode ajout au panier d'un client
	void addProductToShoppingCart(std::string titre, std::string prenom, std::string nom);
	void addProductToShoppingCart(std::string titre, int id );

	//méthode supression d'un produit du panier d'un client
	void deleteProductClient(std::string titre, std::string prenom, std::string nom);
	void deleteProductClient(std::string titre, int id);

	//méthode modification de la  quantité d'un produit du panier d'achat d'un client
	void updateProductQuantityClient(std::string titre, int quantite, int id);
	void updateProductQuantityClient(std::string titre, int quantite, std::string prenom, std::string nom);

	//méthodes validation commande
	bool validationCommande(Client& client);
	bool validationCommande(std::string prenom, std::string nom);
	bool validationCommande(int id);

	//méthode mise à jour du statut de la commande
	bool updateCommandeStatus(int id);

private:
	std::vector <Product* > m_products;
	std::vector <Client* > m_clients;
	std::vector <Commande* > m_orders;

};