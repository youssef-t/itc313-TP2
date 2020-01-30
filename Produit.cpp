#include "Produit.h"

Product::Product(){

}

Product::Product(std::string titre, std::string description, int quantite,double prix):
m_titre(titre),m_description(description),m_quantite(quantite),m_prix(prix){

}

//getters
std::string Product::getTitre() const {return m_titre;}
std::string Product::getDescription() const{ return m_description;}
int Product::getQuantite() const {return m_quantite;}
double Product::getPrix() const {return m_prix;}

//setters
void Product::setTitre(std::string& titre){ m_titre = titre;}
void Product::setDescription(std::string& description){ m_description= description;}
void Product::setQuantite(int quantite){ 
    if(quantite > 0 || quantite ==0)
        m_quantite = quantite;
    else {
        m_quantite = 0;
        std::cout << "La valeur par défaut de la quantité du produit " << getTitre() << " est 0.\n";
    }
}
void Product::setPrix(double prix){
    while (prix < 0 || prix ==0){
        std::cout<<"Veuillez insérer un prix valide "<<std::endl;
        std::cin>>prix;
    }
    if(prix > 0)
        m_prix = prix;

}


//il est possible de ne pas utiliser les getters puisque l'opérateur est déclaré comme friend
std::ostream& operator<< (std::ostream& output, Product& produit){
    output <<"\t" << produit.getTitre();
    nEspace(output, produit.getTitre().length() , 15);

    output << produit.getDescription();
    nEspace(output, produit.getDescription().length(), 30);

    output << "(x" << produit.getQuantite()<<")" ;
    nEspace(output, std::to_string(produit.m_quantite).length(), 10) ;

    output << produit.getPrix() << " $\n";
        
    return output;
}


void nEspace(std::ostream& output, int taille_chaine_caractere, int taille_champ){
    for(int i = 0 ; i < taille_champ - taille_chaine_caractere; i++)
        output << " ";
    }
