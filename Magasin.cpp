#include "Magasin.h"

//constructor
Magasin::Magasin(){

}


Magasin::Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders){
    m_products.reserve(products.size()); //allocation de mémoire pour raison de performances
    for(auto& i : products) // passage par réference pour ne pas faire de copie
        m_products.push_back(&i); // &i est équivalent à &(m_products.at(i)) dans le cas d'une boucle for normale 

    m_clients.reserve(clients.size());
    for(auto& i : clients)
        m_clients.push_back(&i);
    
    m_orders.reserve(orders.size());
    for(auto& i : orders)
        m_orders.push_back(&i); 

}

//Constructeur qui prend en paramètre un vecteur de produit 
Magasin::Magasin(std::vector <Product>& products){
    m_products.reserve(products.size()); 
    for(auto& i : products) 
        m_products.push_back(&i);

}

//Ajout produit, client, ordre
void Magasin::addProduct(Product& product){
    m_products.push_back(&product) ;
}

void Magasin::addClient(Client& client){
    m_clients.push_back(&client) ;
}

void Magasin::addOrder(Commande& order){
    m_orders.push_back(&order) ;
}


//méthode mise à jour de la quantité d'un produit en indiquant son nom
void Magasin::updateQuantite(std::string nom_produit,int quantite){
    //on peut utiliser auto& puisque le compilateur sait déjà le type de m_products
    if(quantite >= 0){
        for(auto& i : m_products){
        //i est un pointeur, pour cela on utilise l'opérateur ->, sinon on peut utiliser *(i).
             if( i->getTitre() == nom_produit){
            i->setQuantite(quantite);
            break;
             }
        }
    }
    else 
        std::cout << "Erreur : quantité saisie est inférieure à 0 .\n";
}

void Magasin::addProductToStore(std::string nom, std::string description, float prix, int quantite){
    Product* produit = new Product(nom, description, prix, quantite);
    m_products.push_back(produit);
}

void Magasin::displayProduct(std::string nom_produit){
    for(auto& i : m_products)
        if( i->getTitre() == nom_produit){
            std::cout << "\nDetails of a product\n" ;
            std::cout << *i << "\n";
            break; //pour arrêter la boucle puisque le produit a déjà été trouvé
        }
}

void Magasin::displayProducts(){
//Affichage du haut du tableau
    std::cout << "\nProducts\n" ;
    std::cout << "Name" ;
    for(int i = 0 ; i < 15 - 4; i++)  //taille du champ total est 15 et la taille de Name est 4
        std::cout << " ";

    std::cout << "Description";
    for(int i = 0 ; i < 40 - 11 ; i++)  //taille du champ total est 15 et la taille de Description est 11
        std::cout << " ";        

    std::cout << "Quantity";
    for(int i = 0 ; i < 12 - 8; i++)  //taille du champ total est 10 et la taille de Quantity est 8
        std::cout << " ";      

    std::cout << "Price\n";    

//Affichage des produits
for(auto& i : m_products )
   std::cout << *i << std::endl;

std::cout << std::endl; 
}

void Magasin::addClient(std::string nom, std::string prenom){
    Client* client = new Client(nom,prenom);
    m_clients.push_back(client);
}


void Magasin::displayClients(){
    std::cout << "\nClients\n";
    std::cout << "Uid" ;
    //on peut utiliser des tabulations
    //Cette méthode reste mieux dans le cas où les Uid des clients comportent un nombre différent de chiffres
    for(int i = 0 ; i < 10 - 3; i++)  //taille du champ total est 10 et la taille de Uid est 3
        std::cout << " ";
    std::cout << "Identity\n";

    for(auto& i:m_clients){
        std::cout << i->getId() << std::endl;
        for(int j = 0 ; j < (int)std::to_string(i->getId()).length() - 3; j++)   
            std::cout << " ";
        std::cout << i->getPrenom() << " " << i->getNom() << std::endl ;
    }
    std::cout << std::endl;
    
}

void Magasin::displayClient(std::string prenom, std::string nom){
    for(auto& i : m_clients){
        if( i -> getPrenom() == prenom || i->getNom() == nom){
            std::cout << "\tAffichage du client\n";
            std::cout << "Uid" ;
            for(int i = 0 ; i < 10 - 3; i++)  //taille du champ total est 10 et la taille de Uid est 3
                std::cout << " ";
            std::cout << "Identity\n";
            std::cout << i->getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i->getId()).length() - 3; j++)   
                std::cout << " ";
             std::cout << i->getPrenom() << " " << i->getNom() << std::endl ;

            break; //puisque le client a déjà été trouvé
        }
    }
}

void Magasin::displayClient(int id){
    for(auto& i : m_clients){
        if ( i -> getId() == id){
            std::cout << "\tAffichage du client\n";
            std::cout << "Uid" ;
            for(int j = 0 ; j < 10 - 3; j++)  //taille du champ total est 10 et la taille de Uid est 3
                std::cout << " ";
            std::cout << "Identity\n";
            std::cout << i->getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i->getId()).length() - 3; j++)   
                std::cout << " ";
             std::cout << i->getPrenom() << " " << i->getNom() << std::endl ;
            break; //puisque le client a déjà été trouvé
        }
    }
}

void Magasin::addProductToShoppingCart(std::string titre, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getPrenom() == prenom || j -> getNom() == nom ){
                    j -> addProduct(*i); //le produit d'origine ne sera pas modifié
                                        //une copie du produit sera ajoutée au panier
                    break;//deuxième boucle for
                }
            break;
        }
}


void Magasin::addProductToShoppingCart(std::string titre, int id ){
    //On procède presque de la même manière de la méthode précédente
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getId() == id){
                    j -> addProduct(*i); //le produit d'origine ne sera pas modifié
                                        //une copie du produit sera ajoutée au panier
                    break;//deuxième boucle for               
                }  
             break; //première boucle for
        }
}

void Magasin::deleteProductClient(std::string titre, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getPrenom() == prenom || j -> getNom() == nom){
                    j -> deleteProduct(titre);
                    break;               
                }
            break;}
}

void Magasin::deleteProductClient(std::string titre, int id){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getId() == id ){
                    j -> deleteProduct(titre);
                    break;
                }
            break;
        }
}

void Magasin::updateProductQuantityClient(std::string titre, int quantite, int id){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getId() == id ){
                    j->updateQuantity(titre, quantite);
                    break;
                }
            break;
        }
}

void Magasin::updateProductQuantityClient(std::string titre, int quantite, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i->getTitre() == titre){
            for(auto& j : m_clients)
                if( j-> getPrenom() == prenom || j -> getNom() == nom){
                    j->updateQuantity(titre, quantite);
                    break;
                }
            break;
        }  
}

//Méthodes validation commande
bool Magasin::validationCommande(Client& client){
    bool valide = true ;
    for(auto& i:client.getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j->getTitre())
                if( i.getQuantite() >= j->getQuantite()){ //la quantité du produit dans le panier est supérieur
                    valide = false;                       //à la quantité disponible dans le magasin
                    std::cout << "Erreur: la quantité disponible du produit -- " 
                              << i.getTitre() << " -- est : " << j->getQuantite();
                    }                                     

    if(valide){
        Commande* commande = new Commande(client); //les produits de la commande sont ceux qui sont
                                                    // dans le panier du client
        m_orders.push_back(commande); 
        for(auto& i :client.getPanier()) //changer la quantité des produits disponibles après validation
            for(auto& j: m_products)
                if(i.getTitre() == j->getTitre()){
                    int quantite_restee;
                    quantite_restee = j->getQuantite() - i.getQuantite();
                    j -> setQuantite(quantite_restee);
                }

        std::cout << "Commande validée" << std::endl;
    }

    else
        std::cout << "Commande non validée" << std::endl;
    
    return valide;
}

//On procède presque de la même manière
bool Magasin::validationCommande(std::string prenom, std::string nom){
    bool valide = true ;
    Client* client;
    bool client_trouve = false;
    //vérification de l'existance du client
    for(auto&i : m_clients)
        if(i->getPrenom() == prenom && i -> getNom() == nom ){
            client = i;
            client_trouve = true ;
            break; //client a déjà été trouvé, on peut arrêter la boucle
        }

    if(client_trouve)
    for(auto& i:client -> getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j->getTitre())
                if( i.getQuantite() >= j->getQuantite()){ //la quantité du produit dans le panier est supérieur
                    valide = false;                       //à la quantité disponible dans le magasin
                    std::cout << "Erreur: la quantité disponible du produit -- " 
                              << i.getTitre() << " -- est : " << j->getQuantite();
                    }                                     

    if(valide){
        Commande* commande = new Commande(*client); //les produits de la commande sont ceux qui sont
                                                    // dans le panier du client
        m_orders.push_back(commande); 
        for(auto& i :client->getPanier()) //changer la quantité des produits disponibles après validation
            for(auto& j: m_products)
                if(i.getTitre() == j->getTitre()){
                    int quantite_restee;
                    quantite_restee = j->getQuantite() - i.getQuantite();
                    j -> setQuantite(quantite_restee);
                }

        std::cout << "Commande validée" << std::endl;
    }
    else if(!client_trouve)
        std::cout << "Commande non validée, client introuvable" << std::endl;
    
    return valide;
}
bool Magasin::validationCommande(int id){
    bool valide = true ;
    Client* client;
    bool client_trouve = false;
    //vérification de l'existance du client
    for(auto&i : m_clients)
        if(i->getId() == id ){
            client = i;
            client_trouve = true ;
            break; //client a déjà été trouvé, on peut arrêter la boucle
        }


    for(auto& i:client->getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j->getTitre())
                if( i.getQuantite() >= j->getQuantite()){ //la quantité du produit dans le panier est supérieur
                    valide = false;                       //à la quantité disponible dans le magasin
                    std::cout << "Erreur: la quantité disponible du produit -- " 
                              << i.getTitre() << " -- est : " << j->getQuantite();
                    }                                     

    if(valide){
        Commande* commande = new Commande(*client); //les produits de la commande sont ceux qui sont
                                                    // dans le panier du client
        m_orders.push_back(commande); 
        std::cout << "Commande validée" << std::endl;
    }
    else if(!client_trouve)
        std::cout << "Commande non validée, client introuvable" << std::endl;
    
    return valide;
}


//méthode mise à jour du statut de la commande
bool Magasin::updateCommandeStatus(int id , bool status){
    //trouver la commande en se servant de son id
    bool commande_trouvee = false;

    for(auto&i : m_orders)
        if(i->getId() == id ){
            i -> setLivraison(status); // mettre à jour le status de la commande
            commande_trouvee = true ;
            break; //on peut arrêter la boucle
        }    
    
    if(commande_trouvee)
        std::cout << "Mise à jour du statut de la commande réussie\n";
    else
        std::cout << "Erreur: Mise à jour du statut de la commande échouée\n";

    return commande_trouvee ;   
}

//méthode affichage des commandes passées
void Magasin::affichageCommandePassees(){
    std::cout << "\t---Affichage des commandes passées---\n";
    for(auto& i : m_orders) //on peut déclarer i comme Commande&
        if(i->getLivraison()) //test si la commande est passée
            std::cout << *i << std::endl;
}

//méthode affichage des commandes d'un client donné

void Magasin::affichageCommandesClient(int id){
    std::cout << "\t---Affichage des commandes du client d'ID " << id << " ---\n";
    for(auto& i : m_orders)
        if( i->getClient()->getId() == id)
            std::cout << *i << std::endl;
}

void Magasin::affichageCommandesClient(std::string prenom, std::string nom){
    std::cout << "\t---Affichage des commandes du client " << prenom << " "<< nom << " ---\n";
    for(auto& i : m_orders)
        if( i->getClient()->getPrenom() == prenom && i->getClient()->getNom() == nom)
            std::cout << *i << std::endl;
}