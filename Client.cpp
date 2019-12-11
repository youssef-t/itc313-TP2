#include "Client.h"
    Client::Client(){

    }

    Client::Client(std::string prenom, std::string::string nom, Product* produits): m_prenom(prenom),
        m_nom(nom), m_produits(produits){

        }

    //getters
    std::string Client::getNom() const{ return m_nom;}
    std::string Client::getPrenom() const{ return m_prenom;}
    int Client::getId() const { return m_id;}
    std::vector<Product*> Client::getProduit() const{return m_produits;}

    //Ajouter un produit au panier d'achat
    void Client::addProduct(Product& produit){
    
    }

    //Modifier la quantité d'un produit ajouté au panier d'achat
    void Client::updateQuantity(Product& produit);

    //Vider le panier
    void Client::viderPanier();

    //Supprimer un produit du panier d'achat
    void Client::deleteProduct(Product& product);

    //Surcharge d'opérateur
    friend std::ostream& operator<< (std::ostream& output, Client& client);


    //méthode pour fournir un identifiant unique
    int Client::identifiant_auto_int();

