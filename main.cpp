#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string vehicleID, brand, model, year, color, registrationNumber;

public:
    Vehicle(string vID = "null", string bd = "null", string ml = "null", string yr = "null", string clr = "null", string regNum = "null")
    {
        vehicleID = vID;
        brand = bd;
        model = ml;
        year = yr;
        color = clr;
        registrationNumber = regNum;
    }

    virtual void inputInfo()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Color: ";
        cin >> color;
        cout << "Enter Registration Number: ";
        cin >> registrationNumber;
    }

    virtual void displayInfo()
    {
        cout << "ID: " << vehicleID << ", " << brand << " " << model << " (" << year << "), Color: " << color
            << ", Reg# " << registrationNumber;
    }

    virtual string vehicleType() = 0;

    string getRegistrationNumber()
    {
        return registrationNumber;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
private:
    string transmission;
    string numberofDoors;

public:
    Car() : Vehicle()
    {
        transmission = "null";
        numberofDoors = "0";
    }

    Car(string vID, string bd, string ml, string yr, string clr, string regNum, string trns = "null", string numDoor = 0)
        : Vehicle(vID, bd, ml, yr, clr, regNum)
    {
        transmission = trns;
        numberofDoors = numDoor;
    }

    void inputInfo()
    {
        Vehicle::inputInfo();
        cout << "Enter Transmission (Manual/Automatic): ";
        cin >> transmission;
        cout << "Enter Number of Doors: ";
        cin >> numberofDoors;
    }

    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << ", Transmission: " << transmission << ", Doors: " << numberofDoors << '\n';
    }

    string vehicleType()
    {
        return "Car";
    }

    ~Car() {}
};

class Bike : public Vehicle
{
private:
    string type;
    string engineCapacity;

public:
    Bike() : Vehicle()
    {
        type = "null";
        engineCapacity = "0";
    }

    Bike(string vID, string bd, string ml, string yr, string clr, string regNum, string typ = "null", string engCap = 0)
        : Vehicle(vID, bd, ml, yr, clr, regNum)
    {
        type = typ;
        engineCapacity = engCap;
    }

    void inputInfo()
    {
        Vehicle::inputInfo();
        cout << "Type (Casual/Sport/Cruiser): ";
        cin >> type;
        cout << "Engine Capacity (cc): ";
        cin >> engineCapacity;
    }

    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << ", Kind: " << type << ", Engine: " << engineCapacity << "cc" << '\n';
    }

    string vehicleType()
    {
        return "Bike";
    }

    ~Bike() {}
};

class Truck : public Vehicle
{
private:
    string loadCapacity;
    string axleCount;

public:
    Truck() : Vehicle()
    {
        loadCapacity = "null";
        axleCount = "0";
    }

    Truck(string vID, string bd, string ml, string yr, string clr, string regNum, string ldCap = "null", string axlCnt = 0)
        : Vehicle(vID, bd, ml, yr, clr, regNum)
    {
        loadCapacity = ldCap;
        axleCount = axlCnt;
    }

    void inputInfo()
    {
        Vehicle::inputInfo();
        cout << "Load Capacity (tons): ";
        cin >> loadCapacity;
        cout << "Axle Count: ";
        cin >> axleCount;
    }

    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << ", Load: " << loadCapacity << " tons, Axles: " << axleCount << endl;
    }

    string vehicleType()
    {
        return "Truck";
    }

    ~Truck() {}
};

class Owner
{
private:
    string regNumber;
    string name;
    string cnic;
    string contact;

public:
    Owner(string reg = "null", string n = "null", string c = "null", string ct = "null")
    {
        regNumber = reg;
        name = n;
        cnic = c;
        contact = ct;
    }

    void inputOwner(string reg)
    {
        regNumber = reg;
        cout << "Enter Owner Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter CNIC: ";
        cin >> cnic;
        cout << "Enter Contact Number: ";
        cin >> contact;
    }

    void displayOwner()
    {
        cout << "Owner Name: " << name << ", CNIC: " << cnic << ", Contact: " << contact << endl;
    }

    string getRegNumber()
    {
        return regNumber;
    }

    ~Owner() {}
};

int main()
{
    int choice;
    string reg;
    int found = -1;
    Vehicle* vptr;
    Car cars[33];
    Bike bikes[33];
    Truck trucks[33];

    cars[0] = Car{ "VCID2883", "Toyota", "Supra", "2025", "Black", "76328", "Automatic", "2" };
    cars[1] = Car{ "VCID2167", "Toyota", "Corolla", "2024", "White", "34245", "Manual", "4" };
    cars[2] = Car{ "VCID2543", "Audi", "RS8", "2019", "Red", "29313", "Automatic", "4" };
    cars[3] = Car("VCID4213", "Honda", "Civic", "2019", "Silver", "92742", "Automatic", "4");
    cars[4] = Car{ "VCID9933", "Ford", "Explorer", "2015", "Maroon", "86342", "Automatic", "4" };

    bikes[0] = Bike{ "VBID3421", "Yamaha", "YBR125", "2025", "Black", "56733", "Sport", "125" };
    bikes[1] = Bike{ "VBID8231", "Honda", "CD70", "2000", "Red", "71235", "Casual", "70" };
    bikes[2] = Bike{ "VBID5798", "Kawasaki", "Ninja", "2021", "Black", "51242", "Sport", "1000" };
    bikes[3] = Bike{ "VBID1163", "Harley Davidson", "Sportster S", "2021", "Black", "86345", "Cruiser", "1250" };
    bikes[4] = Bike{ "VBID5536", "BMW", "S1000RR", "2025", "White", "98633", "Sport", "1000" };

    trucks[0] = Truck{ "VTID6786", "Tesla", "Semi", "2030", "White", "22263", "40.5", "3" };
    trucks[1] = Truck{ "VTID5123", "Mercedes", "Brabus", "2025", "Black", "94311", "5", "3" };
    trucks[2] = Truck{ "VTID9900", "Isuzu", "Giga", "2020", "White", "32244", "15", "3" };

    Owner owners[99] = {
        Owner("76328", "Ali Raza", "35202-1234567-8", "0300-1234567"),    // Car 1
        Owner("34245", "Sana Malik", "35201-9876543-2", "0333-9876543"),  // Car 2
        Owner("29313", "Bilal Ahmed", "35303-1112233-4", "0321-7654321"), // Car 3
        Owner("92742", "Tania Asif", "35204-4445566-7", "0342-8899776"),  // Car 4
        Owner("86342", "Fahad Iqbal", "35103-9998877-1", "0307-4455667"), // Car 5

        Owner("56733", "Zainab Khan", "36101-4567890-1", "0301-1111222"),   // Bike 1
        Owner("71235", "Rameen Fatima", "35206-9988776-4", "0312-4433221"), // Bike 2
        Owner("51242", "Hamza Qureshi", "35209-6677889-3", "0306-7788990"), // Bike 3
        Owner("86345", "Usama Shah", "35200-1122334-6", "0346-2233445"),    // Bike 4
        Owner("98633", "Areeba Sheikh", "35208-6655443-9", "0305-1122998"), // Bike 5

        Owner("22263", "Kashif Mehmood", "35207-4455667-2", "0322-3344556"), // Truck 1
        Owner("94311", "Tariq Javed", "35104-3332211-6", "0345-9988776"),    // Truck 2
        Owner("32244", "Imran Riaz", "35305-2233445-0", "0308-5566778")      // Truck 3
    };

    int ownerCount = 13;

    int carCount = 5, bikeCount = 5, truckCount = 3;


    cout << "            _     _      _                                                                 _     __           _                 \n";
    cout << " /\\   /\\___| |__ (_) ___| | ___    /\\/\\   __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  / _\\_   _ ___| |_ ___ _ __ ___  \n";
    cout << " \\ \\ / / _ \\ '_ \\| |/ __| |/ _ \\  /    \\ / _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __| \\ \\| | | / __| __/ _ \\ '_ ` _ \\ \n";
    cout << "  \\ V /  __/ | | | | (__| |  __/ / /\\/\\ \\ (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_  _\\ \\ |_| \\__ \\ ||  __/ | | | | |\n";
    cout << "   \\_/ \\___|_| |_|_|\\___|_|\\___| \\/    \\/\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| \\__/\\__, |___/\\__\\___|_| |_| |_|\n";
    cout << "                                                           |___/                                    |___/                       \n";

    do
    {
        cout << "               .----------------------------------------------------------------------------------------------.\n";
        cout << "               |                                              Menu                                            |\n";
        cout << "               |----------------------------------------------------------------------------------------------|\n";
        cout << "               |       1. Display Vehicle Information                                                         |\n"
            << "               |       2. Search for a Vehicle                                                                |\n"
            << "               |       3. Add New Entry                                                                       |\n"
            << "               |       4. Delete Entry                                                                        |\n"
            << "               |       5. Edit Vehicle Information                                                            |\n"
            << "               |       6. Owner Information                                                                   |\n"
            << "               |       0. Exit                                                                                |\n";
        cout << "               *----------------------------------------------------------------------------------------------*\n";

        choice = -1;
        cout << "Select an option. \n>> ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "      .----------------------------------------------------------------------------------------------------------------.\n";
            cout << "      |                                                 Vehicle Information                                            |\n";
            cout << "      *----------------------------------------------------------------------------------------------------------------*\n";

            do
            {
                cout << "      |                                                        Cars                                                    |\n";
                cout << "      *----------------------------------------------------------------------------------------------------------------*\n";

                if (carCount == 0)
                {
                    cout << "         No records available.                                                                                    \n";
                }
                else
                {
                    for (int i = 0; i < carCount; i++)
                    {
                        cout << "         " << i + 1 << ") ";
                        cars[i].displayInfo();
                    }
                }

                cout << "      .----------------------------------------------------------------------------------------------------------------.\n";
                cout << "      |                                                       Bikes                                                    |\n";
                cout << "      *----------------------------------------------------------------------------------------------------------------*\n";

                if (bikeCount == 0)
                {
                    cout << "         No records available.                                                                                    \n";
                }
                else
                {
                    for (int i = 0; i < bikeCount; i++)
                    {
                        cout << "         " << i + 1 << ") ";
                        bikes[i].displayInfo();
                    }
                }

                cout << "      .----------------------------------------------------------------------------------------------------------------.\n";
                cout << "      |                                                       Trucks                                                   |\n";
                cout << "      *----------------------------------------------------------------------------------------------------------------*\n";

                if (truckCount == 0)
                {
                    cout << "         No records available.                                                                                     \n";
                }
                else
                {
                    for (int i = 0; i < truckCount; i++)
                    {
                        cout << "         " << i + 1 << ") ";
                        trucks[i].displayInfo();
                    }
                }
                cout << "      .----------------------------------------------------------------------------------------------------------------.\n";
                cout << "      *----------------------------------------------------------------------------------------------------------------*\n";

                cout << "Press '0' to exit. \n>> ";
                cin >> choice;
            } while (choice != 0);
            choice = -1;

            break;

        case 2:
            // Search Vehicle

            do
            {

                cout << "               .----------------------------------------------------------------------------------------------.\n";
                cout << "               |                                             Search                                           |\n";
                cout << "               |----------------------------------------------------------------------------------------------|\n";
                cout << "               |                                Choose type of vehicle to search.                             |\n"
                    << "               |       1. Car                                                                                 |\n"
                    << "               |       2. Bike                                                                                |\n"
                    << "               |       3. Truck                                                                               |\n"
                    << "               |       0. Exit                                                                                |\n";
                cout << "               *----------------------------------------------------------------------------------------------*\n";

                cout << "Select an option. \n>> ";
                cin >> choice;

                switch (choice)
                {
                case 0:
                    break;

                case 1:
                    cout << "Input the registeration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < carCount; i++)
                    {
                        if (cars[i].getRegistrationNumber() == reg)
                        {
                            cars[i].displayInfo();
                            found = 1;
                            cout << "Press '1' to continue. \n>> ";
                            cin >> choice;
                            break;
                        }
                    }

                    if (found != 1)
                    {
                        cout << "Invalid registration number. \n";
                    }
                    choice = -1;
                    found = -1;
                    break;

                case 2:
                    cout << "Input the registeration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < bikeCount; i++)
                    {
                        if (bikes[i].getRegistrationNumber() == reg)
                        {
                            bikes[i].displayInfo();
                            found = 1;
                            cout << "Press '1' to continue. \n>> ";
                            cin >> choice;
                            break;
                        }
                    }

                    if (found != 1)
                    {
                        cout << "Invalid registration number. \n";
                    }
                    found = -1;
                    choice = -1;
                    break;

                case 3:
                    cout << "Input the registeration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < truckCount; i++)
                    {
                        if (trucks[i].getRegistrationNumber() == reg)
                        {
                            trucks[i].displayInfo();
                            found = 1;
                            cout << "Press '1' to continue. \n>> ";
                            cin >> choice;
                            break;
                        }
                    }

                    if (found != 1)
                    {
                        cout << "Invalid registration number. \n";
                    }
                    found = -1;
                    choice = -1;
                    break;

                default:
                    cout << "Invalid choice!\n";
                }
            } while (choice != 0);

            choice = -1;
            break;

        case 3:

            //Add Vehicle

            do
            {
                cout << "               .----------------------------------------------------------------------------------------------.\n";
                cout << "               |                                            New entry                                         |\n";
                cout << "               |----------------------------------------------------------------------------------------------|\n";
                cout << "               |                                  Choose type of vehicle to add.                              |\n"
                    << "               |       1. Car                                                                                 |\n"
                    << "               |       2. Bike                                                                                |\n"
                    << "               |       3. Truck                                                                               |\n"
                    << "               |       0. Exit                                                                                |\n";
                cout << "               *----------------------------------------------------------------------------------------------*\n";

                cout << "Select an option. \n>> ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cars[carCount].inputInfo();
                    carCount++;
                    break;

                case 2:
                    bikes[bikeCount].inputInfo();
                    bikeCount++;
                    break;

                case 3:
                    trucks[truckCount].inputInfo();
                    truckCount++;
                    break;

                case 0:
                    break;

                default:
                    cout << "Invalid choice!\n";
                }
            } while (choice != 0);

            choice = -1;
            break;

        case 4:
            //Delete Vehicle
            do
            {
                cout << "               .----------------------------------------------------------------------------------------------.\n";
                cout << "               |                                          Delete entry                                        |\n";
                cout << "               |----------------------------------------------------------------------------------------------|\n";
                cout << "               |                                Choose type of vehicle to delete.                             |\n"
                    << "               |       1. Car                                                                                 |\n"
                    << "               |       2. Bike                                                                                |\n"
                    << "               |       3. Truck                                                                               |\n"
                    << "               |       0. Exit                                                                                |\n";
                cout << "               *----------------------------------------------------------------------------------------------*\n";

                cout << "Select an option. \n>> ";
                cin >> choice;

                switch (choice)
                {
                case 0:
                    break;

                case 1:
                    cout << "Input the registeration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < carCount; i++)
                    {
                        if (cars[i].getRegistrationNumber() == reg)
                        {
                            cars[i].displayInfo();
                            found = i;
                            break;
                        }
                    }

                    if (found != -1)
                    {
                        cout << "Do you wish to delete this entry? (1 for Yes/0 for No)\n>> ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            for (int i = found; i < carCount - 1; i++)
                            {
                                cars[i] = cars[i + 1];
                            }
                            cars[carCount - 1] = Car();
                            carCount--;
                        }
                    }
                    else
                    {
                        cout << "Invalid registration number. \n";
                    }

                    found = -1;
                    choice = -1;
                    break;

                case 2:
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < bikeCount; i++)
                    {
                        if (bikes[i].getRegistrationNumber() == reg)
                        {
                            bikes[i].displayInfo();
                            found = i;
                            break;
                        }
                    }

                    if (found != -1)
                    {
                        cout << "Do you wish to delete this entry? (1 for Yes/0 for No)\n>> ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            for (int i = found; i < bikeCount - 1; i++)
                            {
                                bikes[i] = bikes[i + 1];
                            }
                            bikes[bikeCount - 1] = Bike();
                            bikeCount--;
                        }
                    }
                    else
                    {
                        cout << "Invalid registration number.  \n";
                    }

                    found = -1;
                    choice = -1;
                    break;

                case 3:
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < truckCount; i++)
                    {
                        if (trucks[i].getRegistrationNumber() == reg)
                        {
                            trucks[i].displayInfo();
                            found = i;
                            break;
                        }
                    }

                    if (found != -1)
                    {
                        cout << "Do you wish to delete this entry? (1 for Yes/0 for No)\n>> ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            for (int i = found; i < truckCount - 1; i++)
                            {
                                trucks[i] = trucks[i + 1];
                            }
                            trucks[truckCount - 1] = Truck();
                            truckCount--;
                        }
                    }
                    else
                    {
                        cout << "Invalid registration number. \n";
                    }
                    found = -1;
                    choice = -1;
                    break;

                default:
                    cout << "Invalid choice!\n";
                }
            } while (choice != 0);

            choice = -1;
            break;

        case 5:
            //Edit Vehicle
            do
            {
                cout << "               .----------------------------------------------------------------------------------------------.\n";
                cout << "               |                                           Edit entry                                         |\n";
                cout << "               |----------------------------------------------------------------------------------------------|\n";
                cout << "               |                                 Choose type of vehicle to edit.                              |\n"
                    << "               |       1. Car                                                                                 |\n"
                    << "               |       2. Bike                                                                                |\n"
                    << "               |       3. Truck                                                                               |\n"
                    << "               |       0. Exit                                                                                |\n";
                cout << "               *----------------------------------------------------------------------------------------------*\n";

                cout << "Select an option. \n>> ";
                cin >> choice;

                switch (choice)
                {
                case 0:
                    break;

                case 1:
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < carCount; i++)
                    {
                        if (cars[i].getRegistrationNumber() == reg)
                        {
                            cars[i].displayInfo();
                            found = i;
                            break;
                        }
                    }

                    if (found != -1)
                    {
                        cars[found].inputInfo();
                    }
                    else
                    {
                        cout << "Invalid registration number. \n";
                    }
                    found = -1;
                    break;

                case 2:
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < bikeCount; i++)
                    {
                        if (bikes[i].getRegistrationNumber() == reg)
                        {
                            bikes[i].displayInfo();
                            found = i;
                            break;
                        }
                    }

                    if (found != -1)
                    {
                        bikes[found].inputInfo();
                    }
                    else
                    {
                        cout << "Invalid registration number. \n";
                    }
                    found = -1;
                    break;

                case 3:
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;

                    for (int i = 0; i < truckCount; i++)
                    {
                        if (trucks[i].getRegistrationNumber() == reg)
                        {
                            trucks[i].displayInfo();
                            found = i;
                            break;
                        }
                    }

                    if (found != -1)
                    {
                        trucks[found].inputInfo();
                    }
                    else
                    {
                        cout << "Invalid registration number. \n";
                    }
                    found = -1;
                    break;

                default:
                    cout << "Invalid choice!\n";
                }
            } while (choice != 0);

            choice = -1;
            break;

        case 6:
        {
            //User Info

            int ownerChoice;
            do
            {
                cout << "               .----------------------------------------------------------------------------------------------.\n";
                cout << "               |                                       Owner Information                                      |\n";
                cout << "               |----------------------------------------------------------------------------------------------|\n";
                cout << "               |                                 Choose type of vehicle to add.                               |\n"
                    << "               |       1. Search by Registration Number                                                       |\n"
                    << "               |       2. Add/Edit by Registration Number                                                     |\n"
                    << "               |       0. Exit                                                                                |\n";
                cout << "               *----------------------------------------------------------------------------------------------*\n";

                cin >> ownerChoice;

                if (ownerChoice == 1)
                {
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;

                    // Display Vehicle Info
                    found = -1;
                    for (int i = 0; i < carCount; i++)
                    {
                        if (cars[i].getRegistrationNumber() == reg)
                        {
                            cars[i].displayInfo();
                            found = 1;
                            break;
                        }
                    }
                    for (int i = 0; i < bikeCount && found == -1; i++)
                    {
                        if (bikes[i].getRegistrationNumber() == reg)
                        {
                            bikes[i].displayInfo();
                            found = 1;
                            break;
                        }
                    }
                    for (int i = 0; i < truckCount && found == -1; i++)
                    {
                        if (trucks[i].getRegistrationNumber() == reg)
                        {
                            trucks[i].displayInfo();
                            found = 1;
                            break;
                        }
                    }

                    if (found == -1)
                    {
                        cout << "No vehicle found with this registration number.\n";
                        continue;
                    }

                    // Display Owner Info
                    found = -1;
                    for (int i = 0; i < ownerCount; i++)
                    {
                        if (owners[i].getRegNumber() == reg)
                        {
                            cout << "\nOwner Information:\n";
                            owners[i].displayOwner();
                            found = 1;
                            break;
                        }
                    }

                    if (found == -1)
                    {
                        cout << "No owner info found.\nAdd new owner? (1 for Yes / 0 for No)\n>> ";
                        int addOwner = 0;
                        cin >> addOwner;
                        if (addOwner == 1)
                        {
                            owners[ownerCount].inputOwner(reg);
                            ownerCount++;
                            cout << "Owner info added successfully.\n";
                        }
                    }
                }

                else if (ownerChoice == 2)
                {
                    cout << "Input the registration number. \n>> ";
                    cin >> reg;
                    found = -1;
                    for (int i = 0; i < ownerCount; i++)
                    {
                        if (owners[i].getRegNumber() == reg)
                        {
                            cout << "Current Owner Info:\n";
                            owners[i].displayOwner();

                            cout << "\nEnter new details:\n";
                            owners[i].inputOwner(reg);

                            cout << "Owner info updated successfully.\n";
                            found = 1;
                            break;
                        }
                    }

                    if (found == -1)
                    {
                        cout << "No owner found with that registration number.\n";
                    }
                }

                else if (ownerChoice == 0)
                {
                    cout << "Exiting Owner Info Menu.\n";
                }

                else
                {
                    cout << "Invalid choice!\n";
                }

            } while (ownerChoice != 0);
            break;
        }

        case 0:
            cout << "Exiting program.";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}