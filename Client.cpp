#include "Client.h"

    Client::Client(){
        m_id = identifiant_auto_int();
    }

    Client::Client(std::string prenom, std::string nom, std::vector<Product> panier): m_prenom(prenom),
        m_nom(nom), m_panier(panier){
        m_id = identifiant_auto_int();
    }

    //getters
    std::string Client::getNom() const{ return m_nom;}
    std::string Client::getPrenom() const{ return m_prenom;}
    int Client::getId() const { return m_id;}
    std::vector<Product> Client::getPanier() const{return m_panier;}

    //Ajouter un produit au panier d'achat
    void Client::addProduct(Product produit){
    m_panier.push_back(produit);
    }

    //Modifier la quantité d'un produit ajouté au panier d'achat
    void Client::updateQuantity(Product produit,int quantite){
    for(int i =0 ; i< (int)m_panier.size() ; i++)
        if( m_panier.at(i).getTitre() == produit.getTitre()){
            m_panier.at(i).setQuantite(quantite);
            break;
        }
    }

    //Vider le panier
    void Client::viderPanier(){
    m_panier.erase(m_panier.begin(), m_panier.end()); //suppression de la 1ère case jusqu'à la dernière
    }

    //Supprimer un produit du panier d'achat
    void Client::deleteProduct(Product product){
    for(int i=0; i< (int)m_panier.size(); i++)
        if( (m_panier.at(i)).getTitre() == product.getTitre()){
            m_panier.erase(m_panier.begin()+i);
            break;
        }
    }


    //Surcharge d'opérateur
    std::ostream& operator<< (std::ostream& output, Client& client){
    output << "ID(" << client.getId() << ") "<< client.getPrenom() << "\t" << client.getNom();
    output << "\n \tPanier:" ;
    for(int i=0 ; i< (int)client.m_panier.size();i++)
        output << "\n \t\t" << client.m_panier.at(i) ;
    output << "\n";

    return output;
    }

    //méthode pour fournir un identifiant unique
    int Client::identifiant_auto_int(){
        static int index=0;
	    index++ ;
	    return index-1;
    }

