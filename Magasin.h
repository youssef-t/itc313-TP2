#pragma once
#include <vector>

class Magasin {
public:
	//constractor
	Magasin();
	Magasin(std::vector <Product*> products, std::vector <Client*> clients, std::vector <order*> orders);
	
	//setters
	void setProducts(std::vector<Products*>& products);
	void setClients(std::vector<Client*>& clients);
	void setOrders(std::vector<Order*>& orders);

	//getters
	std::vector<Product*> getProducts()const;
	std::vector<Client*> getClients()const;
	std::vector<Order*> getOrders()const;

private:
	std::vector <Product* > m_products;
	std::vector <Client* > m_clients;
	std::vector <Order* > m_orders;
};