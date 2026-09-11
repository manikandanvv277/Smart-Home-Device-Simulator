#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
private:
    bool status;

public:
    SmartDevice() {
        status = false;
    }

    virtual ~SmartDevice() {}

    void turnOn() {
        status = true;
    }

    void turnOff() {
        status = false;
    }

    bool isOn() const {
        return status;
    }

    virtual void display() const = 0;
};

class Light : public SmartDevice {
public:
    void display() const override {
        cout << "----- SMART HOME -----\n";
        cout << "Device: Light\n";
        cout << "Status: " << (isOn() ? "ON" : "OFF") << "\n";
        cout << "Light is " << (isOn() ? "glowing" : "off") << "\n";
    }
};

class Fan : public SmartDevice {
private:
    int speed;

public:
    Fan() {
        speed = 0;
    }

    void setSpeed(int s) {
        speed = s;
    }

    void display() const override {
        cout << "----- SMART HOME -----\n";
        cout << "Device: Fan\n";
        cout << "Status: " << (isOn() ? "ON" : "OFF") << "\n";
        cout << "Speed : " << speed << "\n";

        if (isOn())
            cout << "Fan is running at speed level " << speed << "\n";
        else
            cout << "Fan is off\n";
    }
};

class AC : public SmartDevice {
private:
    int temperature;

public:
    AC() {
        temperature = 24;
    }

    void setTemperature(int temp) {
        temperature = temp;
    }

    void display() const override {
        cout << "----- SMART HOME -----\n";
        cout << "Device: AC\n";
        cout << "Status: " << (isOn() ? "ON" : "OFF") << "\n";
        cout << "Temperature: " << temperature << " C\n";

        if (isOn())
            cout << "AC is cooling at " << temperature << " C\n";
        else
            cout << "AC is off\n";
    }
};

int main() {
    int choice, operation;

    cout << "Choose Device:\n";
    cout << "1. Light\n";
    cout << "2. Fan\n";
    cout << "3. AC\n";
    cout << "Choice: ";
    cin >> choice;

    SmartDevice* device = nullptr;

    if (choice == 1) {
        device = new Light();
    }
    else if (choice == 2) {
        Fan* fan = new Fan();

        int speed;
        cout << "Enter Speed: ";
        cin >> speed;

        fan->setSpeed(speed);
        device = fan;
    }
    else if (choice == 3) {
        AC* ac = new AC();

        int temperature;
        cout << "Enter Temperature: ";
        cin >> temperature;

        ac->setTemperature(temperature);
        device = ac;
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    cout << "Enter 1 to turn ON or 0 to turn OFF: ";
    cin >> operation;

    if (operation == 1)
        device->turnOn();
    else
        device->turnOff();

    device->display();

    delete device;

    return 0;
}
