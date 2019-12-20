#include "Commande.h" // les bibliothèques vector , Client sont incluses

//constructors
    Commande::Commande(){
        m_id = identifiant_auto_int();
    }

    Commande::Commande(Client client, std::vector<Product> produits, bool livraison): m_client(client),m_products(produits),m_livraison(livraison) {
        m_id = identifiant_auto_int();
    }


//setters
    void Commande::setClient(Client& client){ m_client = client;}

    void Commande::setProduct(std::vector<Product> produits){
    for(int i=0; i< (int)produits.size() ; i++)
        m_products.push_back( produits.at(i));
    }
    
    void Commande::setLivraison(bool livraison){ m_livraison = livraison;}

//getters
    Client Commande::getClient()const { return m_client;}
    std::vector<Product> Commande::getProduct() const {return m_products;}
    int Commande::getId() const { return m_id;}
    bool Commande::getLivraison() const { return m_livraison;}

//Surcharge d'opérateur
    std::ostream& operator<< (std::ostream& output, Commande& commande){
    std::string livre ;
    commande.m_livraison ? livre = "Livrée" : livre = "Pas livrée" ;
    output<<"Commande n°" << commande.getId() <<"\t Statut: " << livre ;
    output << "\n\t"<< "("<<commande.getClient().getId()<<")"<<commande.getClient().getNom() << "\t"<< commande.getClient().getPrenom()<<std::endl;
    for(int i=0; i < (int)commande.m_products.size(); i++)
        output<< "\t\t"<<commande.m_products.at(i)<<std::endl;
    output<<"\n";
    return output;}


int Commande::identifiant_auto_int(){
    static int index = 0;
    index++;
    return index -1;
    }

