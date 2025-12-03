#include <iostream>
#include <vector>
#include "Warehouse.h" 
#include "OrderManager.h"

using namespace std;



int main()
{
    
    int x, d;
    string name = "Maxim";
    cout << "" << endl;
    int choice;
    cout << "Warehouse choose 1.\nOrdermanager choose 2.\n";
    cout << "Your choice: "; cin >> choice;
    if (choice == 1) {
        Warehouse Smart;
        cout << "You have chosen Warehouse" << endl;
        cout << "Hello, " + name + " we have a list: " << endl;
        Smart.printInventory();
        cout << endl;
        do
        {
            cout << endl;
            cout << "Choose 1, 2, 3.." << endl;
            cout << "What would you like to do with this list: " << endl;
            cout << "----" << endl;
            cout << "0. EXIT PROGRAM" << endl;
            cout << "777. Show list" << endl;
            cout << "1. Check if ID exists in list" << endl;
            cout << "2. View total number of categories" << endl;
            cout << "3. Show logs recorded in log.txt \n"
                << "To do this, you must first record and save them (this is item 5) " << endl;
            cout << "4. View category to find ID" << endl;
            cout << "5. Write and save logs" << endl;
            cout << "6. Change price by ID" << endl;
            cout << "7. Total warehouse value" << endl;
            cout << "8. Clear log.txt" << endl;
            cout << "9. Load content from data.txt to warehouse" << endl;
            cout << "10. Top expensive products (lambda)" << endl;
            cout << "11. Delete from list by ID." << endl;
            cout << "----" << endl;
            cout << "Enter a number: ";
            cin >> x;

            switch (x)
            {
            case 777:
                Smart.printInventory();
                cout << endl;
                break;

            case 0:
                cout << "Program finished" << endl;
                break;

            case 1:
                int UserFindID;
                cout << "Enter ID you want to find: ";
                cin >> UserFindID;
                Smart.FindSmart(UserFindID);
                break;

            case 2:
                Smart.showCategoryStats();
                cout << endl;
                break;

            case 3:
                Smart.printlog();
                break;

            case 4:
            {
                string CategoryUser;
                cout << "Which category do you want to find ID for: ";
                cin >> CategoryUser;
                vector<int> GetIdCategory = Smart.GetIDbyCategory(CategoryUser);
                for (auto b : GetIdCategory)
                {
                    cout << b << " ";
                }
            }
            cout << endl;
            break;

            case 5:
                Smart.saveLogToFile();
                cout << endl;
                break;

            case 6:
                cout << "Enter ID: ";
                int id;
                cin >> id;
                cout << "Enter new price: ";
                double newPrice;
                cin >> newPrice;
                Smart.UpdateProductPrice(id, newPrice);
                cout << endl;
                break;
            case 7:
                cout << "Total warehouse value: ";
                cout << Smart.CalculateTotalValue();
                cout << endl;
                break;
            case 8:
                Smart.historyClear();
                cout << endl;
                break;
            case 9:
                Smart.LoadInventoryFromFile("data.txt");
                cout << endl;
                break;
            case 10:
                int num;
                cout << "Enter how many products you want to see: ";
                cin >> num;
                Smart.ShowTopExpensive(num);
                break;
            case 11:
                int del_id;
                cout << "Enter ID: ";
                cin >> del_id;
                Smart.DeleteProduct(del_id);
                cout << endl;
                break;
            default:
                cout << "\nYou pressed something wrong))" << endl;
                break;
            }
        } while (x != 0);
    }
 
	else if (choice == 2) {
        OrderManager Order;
        cout << "You have chosen OrderManager" << endl;
        cout << "Hello, " + name + "" << endl << endl;
        do
        {
            cout << "|------------------------|" << endl;
            cout << "Choose 1, 2, 3.." << endl;
            cout << "What would you like to do with this list: " << endl;
            cout << "----" << endl;
            cout << "0. EXIT PROGRAM." << endl;
            cout << "1. Show orders." << endl;
            cout << "2. Add more orders." << endl; 
            cout << "|------------------------|" << endl;
            cout << "Enter a number: ";
            cin >> d;

            switch (d)
            {
            case 0:
                cout << "Program finished" << endl;
                break;
            case 2:
                cout << "Enter quantity: ";
                int CinOrd;
				cin >> CinOrd;
                Order.CinOrder(CinOrd);
				break;
            case 1:
                Order.ShowOrders();
                break;

            default:
                cout << "\nYou pressed something wrong))" << endl;
                break;
            }
        } while (d != 0);
    }
    else {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }


    return 0;
}