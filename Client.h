#pragma once
#include <string>
#include <vector>
#include "Produit.h"

class Client{
public:
    Client();
    Client(std::string prenom, std::string nom, std::vector<Product> panier);

    //getters
    std::string getNom() const;
    std::string getPrenom() const;
    int getId() const;
    std::vector<Product> getPanier() const;

    //Ajouter un produit au panier d'achat
    void addProduct(Product produit);

    //Modifier la quantité d'un produit ajouté au panier d'achat
    void updateQuantity(Product produit,int quantite);

    //Vider le panier
    void viderPanier();

    //Supprimer un produit du panier d'achat
    void deleteProduct(Product product);

    //Surcharge d'opérateur
    friend std::ostream& operator<< (std::ostream& output, Client& client);

private:
    std::string m_prenom;
    std::string m_nom;
    int m_id;
    std::vector<Product> m_panier;

    //méthode pour fournir un identifiant unique
    int identifiant_auto_int();

};