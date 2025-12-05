#pragma once
#include <iostream>
#include <string>

using namespace std;
class Device {
public:
	string model;
	Device();
	virtual void Diagnose();
	virtual ~Device();

};

class Phone : public Device {
public:
	void Diagnose() override;
	Phone();
	Phone(const string& model, int cameraMP);
	int cameraMP;

};

class Laptop : public Device {
public:
	Laptop();
	Laptop(const string& model, bool hasDiscreteGPU);
	void Diagnose() override;
	bool hasDiscreteGPU; //laptop
};

