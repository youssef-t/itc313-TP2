#include<iostream>
#include "Programme-principal.h"

//il est possible d'utiliser des fonctions directement au lieu d'utiliser une classe
//au lieu de ne pas utiliser des fonctions (en écrivant tout le code dans la fonction main)
//et au lieu d'utiliser une variable globale, on a opté à utiliser une classe comprenant 
//un magasin qui va être modifié durant le programme et des méthodes qui permettront cette manipulation

int main(){
    Programme programme;
    char help = '9'; //on peut l'initialiser à n'importe quel caractère différent de 0, 
                    //voir ne pas l'initialiser

    while(help != '4'){
        programme.writeProducts(); //à chaque fois que 
        programme.writeClients();
        programme.writeOrders();
        std::cout << "\n------MENU PRINCIPAL------\n";
        std::cout << "\t1) Gestion du magasin \n";
        std::cout << "\t2) Gestion des utilisateurs \n";
        std::cout << "\t3) Gestion des commandes \n";
        std::cout << "\t4) Quitter le menu\n";

        std::cin >> help;        
        programme.choix(help);

    }


    return 0;
}

