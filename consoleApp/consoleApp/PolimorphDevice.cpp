#include <iostream>
#include "PolimorphDevice.h"

using namespace std;

Device::Device() {	
	model = "Unkown Device";
}
Device::~Device() {}

void Device::Diagnose() {
	cout << "---" << endl;
	cout << "Device: General power check... OK" << endl;
}


Phone::Phone() {
	model = "Iphone";
	cameraMP = 12;
}
Phone::Phone(const string& model_, int cameraMP_) {
	model = model_;
	cameraMP = cameraMP_;
}
void Phone::Diagnose() {
	Device::Diagnose();
	cout << "Phone " << model << ": Checking camera " << cameraMP << " MP... Photo taken." << endl;
}
Laptop::Laptop() {
	model = "Asus";
	hasDiscreteGPU = true;
}
Laptop::Laptop(const string& model_, bool hasDiscreteGPU_) {
	model = model_;
	hasDiscreteGPU = hasDiscreteGPU_;
}

void Laptop::Diagnose() {
	Device::Diagnose();
	cout << "Laptop " << model << ": Checking GPU... " << (hasDiscreteGPU ? "Found" : "None") << endl;
}