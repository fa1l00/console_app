#include "OrderManager.h"
#include "ServiceCenter.h"
#include <stdexcept>
using namespace std;

OrderManager::OrderManager() {
	orders.emplace(101, Order{"CPU", "Intel_I5", 70.5 });
	orders.emplace(102, Order{"GPU", "RTX_3060", 199.9 });
	orders.emplace(103, Order{"RAM", "Kingston_16GB", 30.5 });
}


void OrderManager::ShowOrders() {
	cout << "\n--- ORDERS ---\n" << endl;
	for (auto it = orders.begin(); it != orders.end(); ++it) {
		cout << "[" << it->first << "] " << it->second.category << ": " << it->second.name << " | " << "$" << it->second.price << endl;
	}
	cout << "\n--- FINISH ORDERS ---\n" << endl;
}

void OrderManager::CinOrder(int q) {
	cout << "\n--- CREATE ORDERS ---\n" << endl;
	if (q < 0) {
		cout << "Orders is Error" << endl;
	}
	else
	{
		for(int i = 0; i < q; ++i) {
			cout << "Order #" << (i + 1) << endl;
			cout << "Enter order ID: ";
			int id; cin >> id;
			cout << "Enter order category: ";
			string category; cin >> category;
			cout << "Enter order name: ";
			string name; cin >> name;
			cout << "Enter order price: ";
			double price; cin >> price;
			orders.emplace(id, Order{category, name, price });
		}
		this->ShowOrders();

		vector<pair<int, Order>> sortedOrders(orders.begin(), orders.end());
		sort(sortedOrders.begin(), sortedOrders.end(), [](const auto& a, const auto& b) {return a.first > b.first;});
		
		
		int count = 1;
		cout << "--- LAST ID (MAX ID) ---" << endl;
		for (size_t i = 0; i < count && i < sortedOrders.size(); ++i) {
			cout << "ID: " << "[" << sortedOrders[i].first << "]" << endl;
			cout << "Category: " << sortedOrders[i].second.category <<
				"\nName: " << sortedOrders[i].second.name << endl;
		}
	}
	cout << "\n--- FINISH CREATE ORDERS ---\n" << endl;
}

unique_ptr<Warranty>OrderManager::GenerateWarranty(int id, int years) {
	auto it = orders.find(id);
	if (it != orders.end()) {
		unique_ptr<Warranty> warranty = {make_unique<Warranty>(id, years)};
		cout << "Warranty for order " + to_string(id) + " generated for " << years << " years." << endl;
		return warranty;
	}
	else {
		cout << "such an ID does not exist" << endl;
		return {nullptr};
	}
};

void OrderManager::AssignCustomer(int orderID, shared_ptr<Customer> client) {
	auto it = orders.find(orderID);
	if (it != orders.end()) {
		orderOwners[orderID] = client; // map
		auto it_id = orderOwners.find(orderID);
		if(it_id != orderOwners.end()) {
			cout << "Client " << it_id->second->name << " is linked to order " << orderID << endl;
		}
	}
	else {
		cout << "ID: " << orderID << " not found" << endl;
	}
}

void OrderManager::showOrderOwners(int id) {
	auto it = orderOwners.find(id);
	if (it != orderOwners.end()) {
		cout << "\n--- Order ID " << id << " Found ---\n" << "Name: " << it->second->name 
			<< "\nPhone: " << it->second->phone << "\nWarranty for: " << it->second->Years << " years." << endl;
	}
	else {
		cout << "ID: not found" << endl;
	}
}


vector<shared_ptr<Device>> repairQueue;

void ServiceCenter::addDevice(shared_ptr<Device> dev) {
	repairQueue.emplace_back(dev);
}

void ServiceCenter::PerformDiagnostics() {
	for (auto dev : repairQueue) {
		dev->Diagnose();
	}
}

void ServiceCenter::FixDevice(int index) {
	size_t idx = repairQueue.size();
	if (idx > index) {
		cout << "Device " << repairQueue[index]->model << " has been fixed." << endl;
		repairQueue.erase(repairQueue.begin() + index); //0+1 = 1 deleted, example
	}
	
	else {
		throw out_of_range("Index out of range");
	}
}
