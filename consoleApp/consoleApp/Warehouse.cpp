#include "Warehouse.h" 
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void Warehouse::addtolog(const string& message)
{
    historyLog.emplace_back(message);
}

Warehouse::Warehouse()
{
    inventory.emplace(0, Product{ "Pelmeni", "Food", 1.50 });
    inventory.emplace(1, Product{ "Cookie", "Food", 11.50 });
    inventory.emplace(2, Product{ "Cake", "Food", 12.50 });
    inventory.emplace(3, Product{ "Kettle", "Electronics", 16.30 });
    inventory.emplace(4, Product{ "Laptop", "Electronics", 42.50 });
}

void Warehouse::printlog()
{
    for (auto n : historyLog)
    {
        cout << n << endl;
    }
}

void Warehouse::printInventory()
{
    for (auto n : inventory)
    {
        cout << "id: " << n.first << " | Name: " << n.second.name << " | Category: "
            << n.second.category << " | Price: " << n.second.price << endl;
    }
}

unique_ptr<Product> Warehouse::FindSmart(int f)
{
    auto it = inventory.find(f);
    if (it != inventory.end())
    {
        unique_ptr<Product> niceSmart{ make_unique<Product>(it->second) };
        cout << "id " + to_string(f) + " Found" << endl;
        addtolog("FindSmart: id found");
        return niceSmart;
    }
    else
    {
        cout << "id " + to_string(f) + " Not Found" << endl;
        addtolog("FindSmart: id not found");
        return nullptr;
    }
}

void Warehouse::showCategoryStats()
{
    unordered_map<string, int> stats;
    for (auto s : inventory)
    {
        string category = s.second.category;
        stats[category]++;
    }
    for (auto m : stats)
    {
        cout << m.first << ": " << m.second << endl;
    }
    addtolog("showCategoryStats: Category good logs");
}

void Warehouse::saveLogToFile()
{
    ofstream File("log.txt");

    if (File.is_open())
    {
        File << "Logs: " << endl;
        for (auto m : historyLog)
        {
            File << m << endl;
        }
        File.close();
    }
}

vector<int> Warehouse::GetIDbyCategory(const string& categoryName)
{
    vector<int> categoryGood;
    bool categoryFound = false;
    for (const auto& n : inventory)
    {
        const string& it = n.second.category;
        if (it == categoryName)
        {
            categoryGood.emplace_back(n.first);
            categoryFound = true;
        }
    }

    if (!categoryFound)
    {
        cerr << "Such a category does not exist" << endl; 
        addtolog("GetIDbyCategory: Category not found"); 
    }
    else
    {
        addtolog("GetIDbyCategory: Category found"); 
    }
    return categoryGood;
}

bool Warehouse::UpdateProductPrice(int id, double newPrice)
{
    auto it = inventory.find(id);
    if (it != inventory.end())
    {
        it->second.price = newPrice;
        addtolog("UpdateProductPrice: Price for ID: " + to_string(id) + " was updated to " + to_string(newPrice)); 
        return true;
    }
    else
    {
        cout << "Price was not changed, because such an ID does not exist" << endl; 
        addtolog("UpdateProductPrice: Price was not changed, because such an ID does not exist");
        return false;
    }
}

double Warehouse::CalculateTotalValue()
{
    double calc = 0;
    for (auto n : inventory)
    {
        calc += n.second.price;
    }
    addtolog("CalculateTotalValue: Total value of the entire warehouse was calculated."); 
    return calc;
}

void Warehouse::historyClear()
{
    cout << "log.txt history cleared.";
    addtolog("historyClear: log.txt history was cleared."); 
    historyLog.clear();
}

void Warehouse::LoadInventoryFromFile(string filename)
{
    ifstream inputfile(filename);
    int id;
    string name;
    string category;
    double price;
    if (!inputfile.is_open())
    {
        cerr << "Such a file does not exist." << endl;
        addtolog("LoadInventoryFromFile: Such a file does not exist"); 
        return;
    }

    while (inputfile >> id >> name >> category >> price)
    {
        Product newProduct{ name, category, price };
        inventory.emplace(id, newProduct);
        addtolog("LoadInventoryFromFile: Added to warehouse"); 
    }
    inputfile.close();
}

void Warehouse::ShowTopExpensive(int count)
{
    vector<Product> tempProduct;
    for (auto n : inventory)
    {
        tempProduct.emplace_back(n.second);
    }
    sort(tempProduct.begin(), tempProduct.end(), [](const Product& a, const Product& b)
        { return a.price > b.price; });

    for (size_t i = 0; i < count && i < tempProduct.size(); i++)
    {
        cout << (i + 1) << ". " << tempProduct[i].name << " - " << tempProduct[i].price << " $" << endl;
    }
    addtolog("ShowTopExpensive: TOP " + to_string(count) + " products in the warehouse were displayed."); // ???? "???? ????????? ??? ..."
    cout << endl;
}

bool Warehouse::DeleteProduct(int id)
{
    auto it = inventory.find(id);
    if (it != inventory.end())
    {
        it = inventory.erase(it);
        addtolog("DeleteProduct: ID " + to_string(id) + " was deleted."); 
        return true;
    }
    else {
        cerr << "Such an ID does not exist." << endl; 
        addtolog("DeleteProduct: Such an ID does not exist."); 
        return false;
    }
}