 #include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
void registerCustomer(string &name, int &id, string &customerType, int &meterNumber);
void displayMenu();

double calculateConsumptionCharges(int units);
double calculateGST(double amount);
double calculateIncomeTax(double amount, string customerType);
double calculateElectricityDuty(double consumptionCharges);
double calculateFixedCharges(int units);
double calculateNewConnectionCharges(string customerType, int meterNumber);

void displayCustomerDetails(string name, int id, string customerType, int meterNumber);
void displayFinalBill(string name, int id, string customerType, int units);

int main()
{
    string customerName;
    string customerType;
    int customerId;
    int meterNumber;

    registerCustomer(customerName, customerId, customerType, meterNumber);

    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch(choice)
        {
            case 1:
                {
                    int units;
                    cout << "\nEnter Units Consumed: ";
                    cin >> units;

                    displayFinalBill(customerName, customerId,
                                     customerType, units);
                    break;
                }

            case 2:
                {
                    double connectionCharges =
                    calculateNewConnectionCharges(customerType, meterNumber);

                    cout << "\nNew Connection Charges: Rs. "
                         << connectionCharges << endl;
                    break;
                }

            case 3:
                {
                    displayCustomerDetails(customerName,
                                           customerId,
                                           customerType,
                                           meterNumber);
                    break;
                }

            case 4:
                cout << "\nProgram Exited Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}

// Register Customer
void registerCustomer(string &name, int &id,
                      string &customerType,
                      int &meterNumber)
{
    cout << "---- CUSTOMER REGISTRATION ----\n";

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Customer ID: ";
    cin >> id;

    int type;

    cout << "1. Household\n";
    cout << "2. Commercial\n";
    cout << "Select Customer Type: ";
    cin >> type;

    if(type == 1)
        customerType = "Household";
    else
        customerType = "Commercial";

    cout << "1. First Meter\n";
    cout << "2. Second Meter\n";
    cout << "Select Meter Type: ";
    cin >> meterNumber;
}

// Menu
void displayMenu()
{
    cout << "\n--- LESCO MENU ---\n";
    cout << "1. Calculate Monthly Electricity Bill\n";
    cout << "2. Apply For New Connection\n";
    cout << "3. View Customer Details\n";
    cout << "4. Exit\n";
    cout << "Enter Choice: ";
}

// Consumption Charges
double calculateConsumptionCharges(int units)
{
    double slabRates[8] =
    {12.21,14.53,31.51,38.41,41.62,43.04,44.18,49.10};

    if(units <= 100)
        return units * slabRates[0];

    else if(units <= 200)
        return units * slabRates[1];

    else if(units <= 300)
        return units * slabRates[2];

    else if(units <= 400)
        return units * slabRates[3];

    else if(units <= 500)
        return units * slabRates[4];

    else if(units <= 600)
        return units * slabRates[5];

    else if(units <= 700)
        return units * slabRates[6];

    else
        return units * slabRates[7];
}

// GST
double calculateGST(double amount)
{
    return amount * 0.18;
}

// Income Tax
double calculateIncomeTax(double amount, string customerType)
{
    if(customerType == "Household")
        return amount * 0.10;
    else
        return amount * 0.15;
}

// Electricity Duty
double calculateElectricityDuty(double consumptionCharges)
{
    return consumptionCharges * 0.015;
}

// Fixed Charges
double calculateFixedCharges(int units)
{
    if(units <= 300)
        return 0;

    else if(units <= 400)
        return 200;

    else if(units <= 500)
        return 400;

    else if(units <= 600)
        return 600;

    else if(units <= 700)
        return 800;

    else
        return 1000;
}

// New Connection Charges
double calculateNewConnectionCharges(string customerType,
                                     int meterNumber)
{
    double additionalCharges;

    if(customerType == "Household")
    {
        if(meterNumber == 1)
            additionalCharges = 2500;
        else
            additionalCharges = 5000;
    }
    else
    {
        if(meterNumber == 1)
            additionalCharges = 35000;
        else
            additionalCharges = 70000;
    }

    double meterCost = 15000;
    double cableCost = 10000;
    double securityCost = 5000;
    double newConnectionCost = 250000;

    return meterCost + cableCost + securityCost
           + additionalCharges + newConnectionCost;
}

// Customer Details
void displayCustomerDetails(string name,
                            int id,
                            string customerType,
                            int meterNumber)
{
    cout << "\n---- CUSTOMER DETAILS ----\n";

    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Customer Type: "
         << customerType << endl;

    if(meterNumber == 1)
        cout << "Meter Type: First Meter\n";
    else
        cout << "Meter Type: Second Meter\n";
}

// Final Bill
void displayFinalBill(string name,
                      int id,
                      string customerType,
                      int units)
{
    double consumptionCharges =
    calculateConsumptionCharges(units);

    double duty =
    calculateElectricityDuty(consumptionCharges);

    double fixedCharges =
    calculateFixedCharges(units);

    double meterRent = 250;
    double tvFee = 35;

    double subTotal =
    consumptionCharges + duty +
    fixedCharges + meterRent + tvFee;

    double gst = calculateGST(subTotal);

    double incomeTax =
    calculateIncomeTax(subTotal, customerType);

    double totalBill =
    subTotal + gst + incomeTax;

    cout << fixed << setprecision(2);

    cout << "\n-------- LESCO ELECTRICITY BILL ---------\n";

    cout << "Customer Name: " << name << endl;
    cout << "Customer ID: " << id << endl;
    cout << "Customer Type: " << customerType << endl;
    cout << "Units Consumed: " << units << endl;

    cout << "Consumption Charges: Rs. "
         << consumptionCharges << endl;

    cout << "Electricity Duty: Rs. "
         << duty << endl;

    cout << "Fixed Charges: Rs. "
         << fixedCharges << endl;

    cout << "Meter Rent: Rs. 250\n";
    cout << "TV Fee: Rs. 35\n";

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Income Tax: Rs. "
         << incomeTax << endl;

    cout << "Total Payable Bill: Rs. "
         << totalBill << endl;

    cout << "====================================\n";
}


