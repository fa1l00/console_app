#pragma once
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>
#include "Product.h" 

using namespace std;

class Warehouse
{
private:
    map<int, Product> inventory;
    vector<string> historyLog;

    void addtolog(const string& message);

public:
    Warehouse();

    void printlog();
    void printInventory();
    unique_ptr<Product> FindSmart(int f);
    void showCategoryStats();
    void saveLogToFile();
    vector<int> GetIDbyCategory(const string& categoryName);
    bool UpdateProductPrice(int id, double newPrice);
    double CalculateTotalValue();
    void historyClear();
    void LoadInventoryFromFile(string filename);
    void ShowTopExpensive(int count);
    bool DeleteProduct(int id);
};