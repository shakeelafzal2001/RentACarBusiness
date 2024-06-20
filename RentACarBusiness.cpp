
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
public:
    Car(string carId, string carModel) : id(carId), model(carModel), isRented(false) {}

    void display() {
        cout << "ID: " << id << " | Model: " << model << " | Status: " << (isRented ? "Rented" : "Available") << endl;
    }

    string getId() {
        return id;
    }

    bool rentCar() {
        if (isRented) {
            cout << "Car is already rented!" << endl;
            return false;
        } else {
            isRented = true;
            cout << "Car rented successfully!" << endl;
            return true;
        }
    }

    void returnCar() {
        isRented = false;
        cout << "Car returned successfully!" << endl;
    }

private:
    string id;
    string model;
    bool isRented;
};

class RentACarBusiness {
public:
    void addCar(string id, string model) {
        cars.push_back(Car(id, model));
        cout << "Car added successfully!" << endl;
    }

    void displayCars() {
        for (auto &car : cars) {
            car.display();
        }
    }

    void rentCar(string id) {
        for (auto &car : cars) {
            if (car.getId() == id) {
                car.rentCar();
                return;
            }
        }
        cout << "Car with ID " << id << " not found!" << endl;
    }

    void returnCar(string id) {
        for (auto &car : cars) {
            if (car.getId() == id) {
                car.returnCar();
                return;
            }
        }
        cout << "Car with ID " << id << " not found!" << endl;
    }

private:
    vector<Car> cars;
};

int main() {
    RentACarBusiness business;

    int choice;
    string id, model;

    do {
        cout << "\nRent A Car Business Menu\n";
        cout << "1. Add Car\n";
        cout << "2. Display Cars\n";
        cout << "3. Rent Car\n";
        cout << "4. Return Car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Car ID: ";
                cin >> id;
                cout << "Enter Car Model: ";
                cin >> model;
                business.addCar(id, model);
                break;
            case 2:
                business.displayCars();
                break;
            case 3:
                cout << "Enter Car ID to rent: ";
                cin >> id;
                business.rentCar(id);
                break;
            case 4:
                cout << "Enter Car ID to return: ";
                cin >> id;
                business.returnCar(id);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
