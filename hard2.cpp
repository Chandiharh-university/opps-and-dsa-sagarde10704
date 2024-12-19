#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Vehicle
class Vehicle {
protected:
    string make;
    string model;
    int year;
    double fuel;

public:
    Vehicle(string make, string model, int year, double fuel)
        : make(make), model(model), year(year), fuel(fuel) {}

    // Pure virtual function for starting the vehicle
    virtual void start() = 0;

    // Pure virtual function for stopping the vehicle
    virtual void stop() = 0;

    // Virtual function to display vehicle details
    virtual void displayDetails() const {
        cout << "Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Fuel: " << fuel << "L" << endl;
    }

    // Virtual destructor
    virtual ~Vehicle() {}
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;
    bool hasSunroof;

public:
    Car(string make, string model, int year, double fuel, int numDoors, bool hasSunroof)
        : Vehicle(make, model, year, fuel), numDoors(numDoors), hasSunroof(hasSunroof) {}

    void start() override {
        cout << "Starting car..." << endl;
    }

    void stop() override {
        cout << "Stopping car..." << endl;
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Doors: " << numDoors << ", Sunroof: " << (hasSunroof ? "Yes" : "No") << endl;
    }
};

// Derived class Truck
class Truck : public Vehicle {
private:
    double cargoCapacity;
    bool hasTrailer;

public:
    Truck(string make, string model, int year, double fuel, double cargoCapacity, bool hasTrailer)
        : Vehicle(make, model, year, fuel), cargoCapacity(cargoCapacity), hasTrailer(hasTrailer) {}

    void start() override {
        cout << "Starting truck..." << endl;
    }

    void stop() override {
        cout << "Stopping truck..." << endl;
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Cargo Capacity: " << cargoCapacity << "kg, Trailer: " << (hasTrailer ? "Yes" : "No") << endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(string make, string model, int year, double fuel, bool hasSidecar)
        : Vehicle(make, model, year, fuel), hasSidecar(hasSidecar) {}

    void start() override {
        cout << "Starting motorcycle..." << endl;
    }

    void stop() override {
        cout << "Stopping motorcycle..." << endl;
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

int main() {
    // Create a vector to hold pointers to different types of vehicles
    vector<Vehicle*> vehicles;

    // Adding different vehicle objects to the vector
    vehicles.push_back(new Car("Toyota", "Camry", 2020, 50, 4, true));
    vehicles.push_back(new Truck("Ford", "F-150", 2022, 100, 3000, true));
    vehicles.push_back(new Motorcycle("Harley-Davidson", "Iron 883", 2023, 15, false));

    // Demonstrating polymorphism: calling start, stop, and displayDetails for each vehicle
    for (Vehicle* vehicle : vehicles) {
        vehicle->start();          // Start the vehicle
        vehicle->stop();           // Stop the vehicle
        vehicle->displayDetails(); // Display the vehicle details
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
