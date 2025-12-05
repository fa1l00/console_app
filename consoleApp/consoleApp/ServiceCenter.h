#pragma once
#include <vector>
#include <memory>
#include "PolimorphDevice.h"

using namespace std;

class ServiceCenter {
private: 
	vector<shared_ptr<Device>> repairQueue;
public:
	void addDevice(shared_ptr<Device> dev);
	void PerformDiagnostics();
	void FixDevice(int index);

};