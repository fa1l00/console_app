#include <iostream>
#include <vector>
#include "Warehouse.h" 
#include "OrderManager.h"
#include "PolimorphDevice.h"
#include "ServiceCenter.h"

using namespace std;

int main()
{
	int x, d, c;
	string name = "Maxim";
	cout << "" << endl;
	int choice;
	cout << "Warehouse choose 1.\nOrdermanager choose 2.\nPolymorphism demo 3.\n";
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
			{
				int UserFindID;
				cout << "Enter ID you want to find: ";
				cin >> UserFindID;
				Smart.FindSmart(UserFindID);
				break;
			}

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
				cout << endl;
				break;
			}

			case 5:
				Smart.saveLogToFile();
				cout << endl;
				break;

			case 6:
			{
				cout << "Enter ID: ";
				int id;
				cin >> id;
				cout << "Enter new price: ";
				double newPrice;
				cin >> newPrice;
				Smart.UpdateProductPrice(id, newPrice);
				cout << endl;
				break;
			}
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
			{
				int num;
				cout << "Enter how many products you want to see: ";
				cin >> num;
				Smart.ShowTopExpensive(num);
				break;
			}
			case 11:
			{
				int del_id;
				cout << "Enter ID: ";
				cin >> del_id;
				Smart.DeleteProduct(del_id);
				cout << endl;
				break;
			}
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
		int warrantyID, warrantyYears;
		string cust_name, phone;
		do
		{
			cout << "|------------------------|" << endl;
			cout << "Choose 1, 2, 3.." << endl;
			cout << "What would you like to do with this list: " << endl;
			cout << "----" << endl;
			cout << "0. EXIT PROGRAM." << endl;
			cout << "1. Show orders." << endl;
			cout << "2. Add more orders." << endl;
			cout << "3. Provide a guarantee for the user" << endl;
			cout << "4. Show order owners by ID" << endl;

			cout << "|------------------------|" << endl;
			cout << "Enter a number: ";
			cin >> d;

			switch (d)
			{
			case 0:
				cout << "Program finished" << endl;
				break;
			case 2:
			{
				cout << "Enter quantity: ";
				int CinOrd;
				cin >> CinOrd;
				Order.CinOrder(CinOrd);
				break;
			}
			case 1:
				Order.ShowOrders();
				break;
			case 3:
			{
				cout << "Enter the ID you want to give a guarantee to: ";
				cin >> warrantyID;
				cout << "Enter the number of years for the warranty: ";
				cin >> warrantyYears;
				auto myWarranty = Order.GenerateWarranty(warrantyID, warrantyYears);
				if (myWarranty != nullptr)
				{
					cout << "Enter the client's name: ";
					cin >> cust_name;
					cout << "Enter the client's phone: ";
					cin >> phone;
					shared_ptr<Customer> client = make_shared<Customer>(cust_name, phone, warrantyYears);
					Order.AssignCustomer(warrantyID, client);
				}
				else {
					cout << "ERROR: nullptr" << endl;
				}
				break;
			}
			case 4:
			{
				cout << "Enter ID to show owner: ";
				int W_ID; cin >> W_ID;
				Order.showOrderOwners(W_ID);
				break;
			}
			default:
				cout << "\nYou pressed something wrong))" << endl;
				break;
			}
		} while (d != 0);
	}
	else if (choice == 3) {
		Device device_D;
		Phone phone_P;
		Laptop laptop_L;
		Device* D_L = new Laptop();
		Device* D_P = new Phone();
		ServiceCenter SC;
		cout << "You have chosen Polymorphism demo" << endl;
		cout << "Hello, " + name << endl;
		cout << endl;
		do
		{
			cout << "|------------------------|" << endl;
			cout << "Choose 1, 2, 3.." << endl;
			cout << "----" << endl;
			cout << "0. EXIT PROGRAM" << endl;
			cout << "1. Device Diagnostics (Polymorphism demo)" << endl;
			cout << "2. Service Center Diagnostics (Polymorphism with smart pointers demo)" << endl;
			cout << "3. Fix your device at a service center by index First, you need to add it to the repair queue (select 2)" << endl;
			cout << "|------------------------|" << endl;
			cout << "Enter a number: ";
			cin >> c;

			switch (c)
			{
			case 0:
				cout << "Program finished" << endl;
				break;
			case 1:
				phone_P.Diagnose();
				laptop_L.Diagnose();
				break;
			case 2:
			{

				shared_ptr<Device> myPhone_0 = make_shared<Phone>("Iphone 15", 48);
				shared_ptr<Device> myLaptop_0 = make_shared<Laptop>("Lenovo", true);
				shared_ptr<Device> myPhone_1 = make_shared<Phone>("Iphone 14", 38);
				shared_ptr<Device> myLaptop_1 = make_shared<Laptop>("Alien", true);
				SC.addDevice(myPhone_0);
				SC.addDevice(myLaptop_0);
				SC.addDevice(myPhone_1);
				SC.addDevice(myLaptop_1);
				SC.PerformDiagnostics();
			}
				break;
			case 3:
				try {
					cout << "Index: " << endl;
					cin >> c;
					SC.FixDevice(c);
				}
				catch (const exception& e) {
					cout << "Exception caught: " << e.what() << endl;
				}
				break;
			default:
				cout << "\nYou pressed something wrong))" << endl;
				break;
			}
		} while (c != 0);
		delete D_L;
		delete D_P;
	}		
	else {
		cout << "Invalid choice. Exiting program." << endl;
		return 0;
	}

	return 0;
}