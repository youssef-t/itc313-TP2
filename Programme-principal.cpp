#include "Programme-principal.h"


void Programme::choix(char help){
    //on peut utiliser switch()
    if(help == '1')
        gestionMagasin();
    else if(help == '2')
        gestionUtilisateurs();
   // else if (help == '3')
     //   gestionCommandes();  
}

void Programme::gestionMagasin(){
    char help = '9';
    while (help != '5'){
        std::cout << "------Menu Gestion du Magasin------\n";
        std::cout << "\t1) Ajout d'un produit ou des produits" << std::endl;
        std::cout << "\t2) Modification d'un produit" << std::endl;
        std::cout << "\t3) Affichage de tous les produits" << std::endl;
        std::cout << "\t4) Affichage d'un produit" << std::endl;
        std::cout << "\t5) Revenir au menu précédent"   << std::endl;
        std::cin >> help;
        if(help != '5')
            choixGestionMagasin(help);
    }
}

void Programme::choixGestionMagasin(char help){
    if(help == '1'){
        int nbr_produits ;
        std::cout << "Saisir le nombre de produits que vous voulez saisir : ";
        std::cin >> nbr_produits ;
        ajoutProduit(nbr_produits);
    }
    else if (help == '2')
        modificationProduit();
    else if (help == '3')
        affichageProduits();
    else if (help == '4')
        affichageProduit();        
}

void Programme::ajoutProduit(int nbr_produits){

    for(int i = 0 ; i < nbr_produits ; i++){
        std::cout << "Saisir le nom du produit : ";
        std::string titre;
        std::cin >> titre;
        std::cout << "Saisir la description du produit : ";
        std::string description;
        std::cin >> description;
        std::cout << "Saisir la quantite du produit : ";
        int quantite;
        std::cin >> quantite;
        std::cout << "Saisir le prix du produit : ";
        double prix;
        std::cin >> prix ;
        
        m_magasin.addProductToStore(titre, description, quantite, prix);
    }
}

void Programme::modificationProduit(){
    char help = '9';
    while(help != '4'){
        std::cout << "\t1) Modifier la quantité d'un produit\n";
        std::cout << "\t2) Modifier le prix d'un produit\n";
        std::cout << "\t3) Modifier la description d'un produit\n";
        std::cout << "\t4) Revenir au menu précédent\n";
        std::cin >> help;

        //vérifier si help est différent de 4
        if(help != '4'){
        if (help == '1'){
            std::cout << "Le nom du produit : ";
            std::string titre ;
            std::cin >> titre ;
            //chercher le produit dans les produits que contient le magasin
            if (m_magasin.productExist(titre)){
                Product* produit = m_magasin.productFind(titre);
                int quantite;
                std::cout << "Entrer la nouvelle quantite du produit : " ;
                std::cin >> quantite ;
                produit -> setQuantite(quantite) ;
            }
            else 
                std::cout << "Erreur: le produit n'a pas été trouvé dans le magasin. \n";
        }

        else if (help == '2'){
            std::cout << "Le nom du produit : ";
            std::string titre ;
            std::cin >> titre ;
            //chercher le produit dans les produits que contient le magasin
            if (m_magasin.productExist(titre)){
                Product* produit = m_magasin.productFind(titre);
                int prix;
                std::cout << "Entrer le nouveau prix du produit : " ;
                std::cin >> prix ;
                produit -> setPrix(prix) ;
            }
            else 
                std::cout << "Erreur: le produit n'a pas été trouvé dans le magasin. \n";
        }

        else if (help == '3'){
            std::cout << "Le nom du produit : ";
            std::string titre ;
            std::cin >> titre ;
            //chercher le produit dans les produits que contient le magasin
            if (m_magasin.productExist(titre)){
                Product* produit = m_magasin.productFind(titre);
                std::string description;
                std::cout << "Entrer la nouvelle description du produit : " ;
                std::cin >> description ;
                produit -> setDescription(description) ;
            }
            else 
                std::cout << "Erreur: le produit n'a pas été trouvé dans le magasin. \n";            
        }
        }

    }

}

void Programme::affichageProduits(){
    std::cout << "\tAffichage de tous les produits\n" ;
    m_magasin.displayProducts();
}

void Programme::affichageProduit(){
    std::cout << "Saisir le titre du produit\n";
    std::string titre;
    std::cin >> titre;
    if (m_magasin.productExist(titre)){
        std::cout << "\tAffichage du produit " << titre << std::endl;
        m_magasin.displayProduct(titre);
    }
    else
        std::cout << "Erreur: le produit n'a pas été trouvé dans le magasin. \n";  
}



void Programme::gestionUtilisateurs(){
    char help = '9';
    while( help != '5' ){
        std::cout << "------Menu Gestion des Utilisateurs------\n";
        std::cout << "\t1) Ajout d'un nouveau client" << std::endl;
        //std::cout << "\t2) Modification des données d'un client" << std::endl;
        std::cout << "\t2) Modifier le panier d'un client" << std::endl;
        std::cout << "\t3) Afficher tous les clients" << std::endl;
        std::cout << "\t4) Afficher un client" << std::endl;
        std::cout << "\t5) Revenir au menu précédent" << std::endl;

        std::cin >> help;
        if(help != '5')
            choixGestionUtilisateurs(help);
    }
}

void Programme::choixGestionUtilisateurs(char help){
    //Ajout d'un nouveau client
    if(help == '1'){
        std::cout << "Saisir le prénom du client : ";
        std::string prenom;
        std::cin >> prenom;
        std::cout << "Saisir le nom du client : ";
        std::string nom;
        std::cin >> nom;
        m_magasin.addClient(prenom,nom);
    }

    //Modifier le panier d'un client
    else if(help == '2'){
        char aide = '4';
        while(aide != 3){
            std::cout << "\t1) Modifier le panier d'un client en entrant son nom et son prénom\n";
            std::cout << "\t2) Modifier le panier d'un client en entrant son ID\n";
            std::cout << "\t3) Revenir au menu précédent\n";
            std::cin >> aide;

            //vérifier si aide est différent de '3'
            if(aide != '3'){
            if(aide == '1'){
                std::cout << "Le prénom du client : ";
                std::string prenom;
                std::cin >> prenom;

                std::cout << "Le nom du client : ";
                std::string nom;
                std::cin >> nom;   

                //Voir si le client existe
                bool client_exist = false ;
                //chercher le client
                for(auto& i: m_magasin.getClients())
                    if( i -> getPrenom() == prenom || i -> getNom() == nom ){
                        client_exist = true ;
                        break;
                    }

                if(client_exist){
                    std::cout << "\t1) Ajouter un produit au panier du client\n";
                    std::cout << "\t2) Supprimer un produit du panier du client\n";
                    std::cout << "\t3) Modifier la quantité d'un produit dans le panier du client\n";
                    std::cout << "\t4) Revenir au menu précédent\n";  
                    char tmp;
                    std::cin >> tmp;

                    if(tmp != '4'){
                    std::cout << "Saisir le nom du produit : ";
                    std::string titre;
                    std::cin >> titre;
                    if (tmp == '1') {
                        m_magasin.addProductToShoppingCart(titre ,prenom, nom );
                        std::cout << "Produit ajouté au panier\n";
                    } 
                    else if(tmp == '2'){
                        m_magasin.deleteProductClient(titre, prenom, nom);
                        std::cout << "Produit supprimer du panier du clien\n";
                    }
                    else if (tmp == '3'){
                        std::cout << "Saisir la nouvelle quantité du produit\n";
                        int quantite;
                        std::cin >> quantite;
                        m_magasin.updateProductQuantityClient(titre, quantite, prenom, nom);
                    }
                    }
                }
                //Si le client n'existe pas dans le magasin
                else
                    std::cout << "Erreur : client introuvable\n" ;
            
            }

            //On procède de la même manière quand dans le premier cas
            //On utilise l'id du client au lieu de son nom et prénom
            else if(aide == '2'){
                std::cout << "L'ID du client : ";
                int id;
                std::cin >> id;

                 //Voir si le client existe
                bool client_exist = false ;
                //chercher le client
                for(auto& i: m_magasin.getClients())
                    if( i -> getId() == id ){
                        client_exist = true ;
                        break;
                    }

                if(client_exist){
                    std::cout << "\t1) Ajouter un produit au panier du client\n";
                    std::cout << "\t2) Supprimer un produit du panier du client\n";
                    std::cout << "\t3) Modifier la quantité d'un produit dans le panier du client\n";
                    std::cout << "\t4) Revenir au menu précédent\n";  
                    char tmp;                  
                    std::cin >> tmp;

                    if(tmp != '4'){
                    std::cout << "Saisir le nom du produit : ";
                    std::string titre;
                    std::cin >> titre;
                    if (tmp == '1') {
                        m_magasin.addProductToShoppingCart(titre , id);
                        std::cout << "Produit ajouté au panier\n";
                    } 
                    else if(tmp == '2'){
                        m_magasin.deleteProductClient(titre, id);
                        std::cout << "Produit supprimer du panier du clien\n";
                    }
                    else if (tmp == '3'){
                        std::cout << "Saisir la nouvelle quantité du produit\n";
                        int quantite;
                        std::cin >> quantite;
                        m_magasin.updateProductQuantityClient(titre, quantite, id);
                    }
                    }
                }

            }
            }

        }
    }

    //Afficher tous les clients
    else if(help == '3'){
        std::cout << "\tAffichage de tous les clients\n";
        m_magasin.displayClients();
    }

    //Afficher un client
    else if(help == '4'){
        std::cout << "\t1) Saisir le prénom et le nom du client\n";
        std::cout << "\t2) Saisir l'ID du client\n";
        char aide;
        std::cin >> aide ;
        
        if(aide == '1'){
            std::cout <<"Saisir le prénom du client : ";
            std::string prenom;
            std::cin >> prenom;
            std::cout << "Saisir le nom du client : ";
            std::string nom;
            std::cin >> nom;
            //test l'existance du client
            if(m_magasin.clientExist(prenom,nom)){
                std::cout << "\tAffichage du client\n";
                m_magasin.displayClient(prenom , nom );
            }  
        }

        //on procède presque de la même manière, on utilise l'ID au lieu du nom et du prénom
        if(aide == '2'){
            std::cout <<"Saisir l'ID du client : ";
            int id;
            std::cin >> id;
            //test l'existance du client
            if(m_magasin.clientExist(id)){
                std::cout << "\tAffichage du client\n";
                m_magasin.displayClient(id);
            }  
        }

    }   
}


#if 0
void Programme::gestionCommandes(){
    char help;
    do{
        std::cout << "------Menu Gestion des Commandes------\n";
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;

    
        std::cin >> help;
        choixGestionUtilisateurs(help);
    }while( help != );  

#endif 