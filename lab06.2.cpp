#include <iostream>

using namespace std;

class WaterTank {
private:
    double volume; 

public:
    WaterTank() : volume(0.0) {}

    WaterTank(double vol) : volume(vol) {}

    WaterTank(const WaterTank& other) : volume(other.volume) {}

    WaterTank& operator=(const WaterTank& other) {
        if (this != &other) {
            volume = other.volume;
        }
        return *this;
    }

    bool operator==(const WaterTank& other) const {
        return volume == other.volume;
    }

    bool operator!=(const WaterTank& other) const {
        return !(*this == other);
    }

    WaterTank operator+(const WaterTank& other) const {
        return WaterTank(volume + other.volume);
    }

    WaterTank operator-(const WaterTank& other) const {
        return WaterTank(volume - other.volume);
    }

    void addWater(double amount) {
        volume += amount;
    }

    void removeWater(double amount) {
        if (amount <= volume) {
            volume -= amount;
        } else {
            volume = 0.0; 
        }
    }

    double getVolume() const {
        return volume;
    }

    void print() const {
        cout << "Water volume: " << volume << " liters" << endl;
    }
};

int main() {
    WaterTank tank1(10.0);
    WaterTank tank2(15.0);

    WaterTank tank3 = tank1 + tank2; 
    tank3.print();

    WaterTank tank4 = tank2 - tank1; 
    tank4.print();

    if (tank1 != tank2) {
       cout << "Tanks have different volumes." << endl;
    }

    tank1 = tank2; // Присвоювання
    if (tank1 == tank2) {
        cout << "Tanks have the same volume." << endl;
    }

    return 0;
}
