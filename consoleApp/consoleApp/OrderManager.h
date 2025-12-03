#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Order.h"

using namespace std;

class OrderManager {
private:
    vector<Order> orders;
public:
	void CinOrder(int q);
	OrderManager();
	void ShowOrders();
};