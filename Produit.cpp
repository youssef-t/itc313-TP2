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
void Product::setPrix(double& prix){
    while (prix < 0 || prix ==0){
        std::cout<<"Veuillez insérer un prix valide "<<std::endl;
        std::cin>>prix;
    }
    if(prix > 0)
        m_prix = prix;

}

std::ostream& operator<< (std::ostream& output, Product& produit){
    output<< produit.getTitre() << "\t\t" << produit.getDescription() << "\t\t(x" << produit.getQuantite()<<")\t\t"<< produit.getPrix()<<" $";
    return output;
}