#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "Order.h"
#include "Warranty.h"
#include "Customer.h"

using namespace std;

class OrderManager {
private:
    map<int, Order> orders;
	vector<string> historylog_1;
	map<int, shared_ptr<Customer>> orderOwners;
public:
	void CinOrder(int q);
	OrderManager();
	void ShowOrders();
	unique_ptr<Warranty> GenerateWarranty(int id, int years);
	void AssignCustomer(int orderID, shared_ptr<Customer> client);
	void showOrderOwners(int id);
};