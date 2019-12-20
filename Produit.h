#pragma once
#include <string>
#include <iostream>
class Product{
public:
//constuctor
    Product();
    Product(std::string titre, std::string description, int quantite,double prix);

//getters
    std::string getTitre() const;
    std::string getDescription()const ;
    int getQuantite() const ;
    double getPrix() const ;

//setters
    void setTitre(std::string& titre);
    void setDescription(std::string& description);
    void setQuantite(int quantite);
    void setPrix(double& prix);
    
    //operator
    friend std::ostream& operator<< (std::ostream &output, Product& product);

private:
    std::string m_titre;
    std::string m_description;
    int m_quantite;
    double m_prix;
};

