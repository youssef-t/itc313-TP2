#include "Commande.h" // les bibliothèques vector , Client sont incluses

//constructors
    Commande::Commande(){
        m_id = identifiant_auto_int();
    }

    Commande::Commande(Client client, std::vector<Product> produits, bool livraison): m_client(client),m_livraison(livraison) {
        m_id = identifiant_auto_int();
        //valeur par défaut de la quantité de chaque produit dans le panier est 1
        for(int i = 0; i < (int)produits.size() ; i++){
            produits.at(i).setQuantite(1);
            m_products.push_back(produits.at(i));
        }
    }


//setters
    void Commande::setClient(Client& client){ m_client = client;}

    void Commande::setProduct(std::vector<Product> produits){
    supprimerProduits();
    for(int i=0; i< (int)produits.size() ; i++)
        m_products.push_back(produits.at(i));
    }
    
    void Commande::setLivraison(bool livraison){ m_livraison = livraison;}

    void Commande::supprimerProduits(){
        m_products.erase(m_products.begin(), m_products.end()); //suppression de la 1ère case jusqu'à la dernière
    }

//getters
    Client Commande::getClient()const { return m_client;}
    std::vector<Product> Commande::getProduct() const {return m_products;}
    int Commande::getId() const { return m_id;}
    bool Commande::getLivraison() const { return m_livraison;}

//Surcharge d'opérateur
    std::ostream& operator<< (std::ostream& output, Commande& commande){
    std::string status ;
    commande.m_livraison ? status = "Livrée" : status = "Pas livrée" ;
    output<<"Commande n°" << commande.getId() <<"\t Statut: " << status ;
    output << "\n\t"<< "("<<commande.getClient().getId()<<")"<<commande.getClient().getNom() 
            << "\t"<< commande.getClient().getPrenom()<<std::endl;
    for(int i=0; i < (int)commande.m_products.size(); i++)
        output<< "\t\t"<<commande.m_products.at(i)<<std::endl;
    output<<"\n";
    return output;
    }


int Commande::identifiant_auto_int(){
    static int index = 0;
    index++;
    return index ;
    }

