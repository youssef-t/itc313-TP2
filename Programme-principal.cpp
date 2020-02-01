#include "Programme-principal.h"



void Programme::choix(char help){
    //on peut utiliser switch()
    if(help == '1')
        gestionMagasin();
   /* else if(help == '2')
        gestionUtilisateurs();
    else if (help == '3')
        gestionCommandes();  */
}

void Programme::gestionMagasin(){
    char help ;
    do{
        std::cout << "------Menu Gestion du Magasin------\n";
        std::cout << "\t1) Ajout d'un produit ou des produits" << std::endl;
        std::cout << "\t2) Modification d'un produit" << std::endl;
        std::cout << "\t3) Affichage de tous les produits" << std::endl;
        std::cout << "\t4) Affichage d'un produit" << std::endl;
        std::cout << "\t5) Revenir au menu précédent"   << std::endl;
        std::cin >> help;
        choixGestionMagasin(help);
    }while (help != '5');
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
    do{
        std::cout << "1) Modifier la quantité d'un produit\n";
        std::cout << "2) Modifier le prix d'un produit\n";
        std::cout << "3) Modifier la description d'un produit\n";
        std::cout << "4) Revenir au menu précédent\n";
        std::cin >> help;

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

    }while(help != 4);

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





#if 0
void Programme::gestionUtilisateurs(){
    char help;
    do{
        std::cout << "------Menu Gestion des Utilisateurs------\n";
        std::cout << "\t1) " << std::endl;
        std::cout << "\t2) " << std::endl;
        std::cout << "\t3) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;
        std::cout << "\t1) " << std::endl;

        std::cin >> help;
        choixGestionUtilisateurs(help);
    }while( help !=  );
}


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