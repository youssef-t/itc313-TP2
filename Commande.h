#pragma once
#include "Client.h"
#include <vector>
class Commande {
public:
//constructors
    Commande();
    Commande(Client client, std::vector<Product> produits, bool livraison = false);

//setters
    void setClient(Client& client);
    void setProduct(std::vector<Product> produits);
    void setLivraison(bool livraison);

//getters
    Client getClient() const;
    std::vector<Product> getProduct() const;
    int getId() const;
    bool getLivraison() const;

//Surcharge d'opérateur
    friend std::ostream& operator<< (std::ostream& output, Commande& commande);

private:
    Client m_client;
    std::vector<Product> m_products;
    bool m_livraison; //true si la commande est livrée, sinon false
    int m_id;
    int identifiant_auto_int();
};