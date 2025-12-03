#include "OrderManager.h"
using namespace std;

OrderManager::OrderManager() {
	orders.emplace_back(Order{ 101, "CPU", "Intel_I5", 70.5 });
	orders.emplace_back(Order{ 103, "GPU", "RTX_3060", 199.9 });
	orders.emplace_back(Order{ 102, "RAM", "Kingston_16GB", 30.5 });
}


void OrderManager::ShowOrders() {
	cout << "\n--- ORDERS ---\n" << endl;
	for (auto n : orders) {
		cout << "[" << n.id << "] " << n.category << ": " << n.name << " | " << "$" << n.price << endl;
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
			orders.emplace_back(Order{ id, category, name, price });
		}
		cout << "--- ORDERS ---" << endl;
		for (auto n : orders) {
			cout << "[" << n.id << "] " << n.category << ": " << n.name << " | " << "$" << n.price << endl;
		}
		sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {return a.id > b.id;});
		int count = 1;
		cout << "--- LAST ID (MAX ID) ---" << endl;
		for (size_t i = 0; i < count && i < orders.size(); ++i) {
			cout << "ID: " << "[" << orders[i].id << "]" << endl;
			cout << "Category: " << orders[i].category << "\nName: " << orders[i].name << endl;
		}
	}
	cout << "\n--- FINISH CREATE ORDERS ---\n" << endl;
}
