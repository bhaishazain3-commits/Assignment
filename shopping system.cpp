#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void registerUser(string &name, string &email, string &city, string &customerType);
void displayProducts(string products[], double prices[], int size);
void addProductsToCart(string products[], double prices[], int size, double &productTotal);
double calculateGST(double productTotal);
double calculateDeliveryCharges(string city);
double calculateCustomerDiscount(double productTotal, string customerType);
double calculateOrderDiscount(double productTotal);
double calculatePaymentCharges(double amount, int paymentMethod);
void displayUserDetails(string name, string email, string city, string customerType);
void displayCheckoutBill(string name, string city, string customerType,double productTotal, double gst,double deliveryCharges, double customerDiscount,  double orderDiscount,double paymentCharges, double finalAmount);

int main()
{
    string userName, email, city, customerType;

    registerUser(userName, email, city, customerType);

    string products[8] =
    {
        "T-Shirt",
        "Jeans",
        "Shoes",
        "Watch",
        "Handbag",
        "Headphones",
        "Mobile Cover",
        "Perfume"
    };

    double prices[8] =
    {
        1200,
        3500,
        5000,
        2500,
        4200,
        3000,
        700,
        2800
    };

    double productTotal = 0;

    int choice;

    do
    {
        cout << "\n\n========== ONLINE SHOPPING SYSTEM ==========\n";
        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayProducts(products, prices, 8);
                break;

            case 2:
                addProductsToCart(products, prices, 8, productTotal);
                break;

            case 3:
            {
                if(productTotal == 0)
                {
                    cout << "\nNo Products Added To Cart!\n";
                    break;
                }

                double gst = calculateGST(productTotal);
                double deliveryCharges = calculateDeliveryCharges(city);
                double customerDiscount = calculateCustomerDiscount(productTotal, customerType);
                double orderDiscount = calculateOrderDiscount(productTotal);

                int paymentMethod;

                cout << "\nSelect Payment Method:\n";
                cout << "1. Cash On Delivery\n";
                cout << "2. Debit/Credit Card\n";
                cout << "Enter Choice: ";
                cin >> paymentMethod;

                double amountAfterDiscounts =
                    productTotal + gst + deliveryCharges
                    - customerDiscount - orderDiscount;

                double paymentCharges =
                    calculatePaymentCharges(amountAfterDiscounts, paymentMethod);

                double finalAmount =
                    amountAfterDiscounts + paymentCharges;

                displayCheckoutBill(
                    userName,
                    city,
                    customerType,
                    productTotal,
                    gst,
                    deliveryCharges,
                    customerDiscount,
                    orderDiscount,
                    paymentCharges,
                    finalAmount
                );

                break;
            }

            case 4:
                displayUserDetails(userName, email, city, customerType);
                break;

            case 5:
                cout << "\nThank You For Using The System.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}

// Register User
void registerUser(string &name, string &email,
                  string &city, string &customerType)
{
    cout << "========== USER REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter User Name: ";
    getline(cin, name);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter City: ";
    getline(cin, city);

    int type;

    cout << "\nCustomer Type\n";
    cout << "1. New Customer\n";
    cout << "2. Returning Customer\n";
    cout << "Enter Choice: ";
    cin >> type;

    if(type == 1)
        customerType = "New Customer";
    else
        customerType = "Returning Customer";
}

// Display Products
void displayProducts(string products[], double prices[], int size)
{
    cout << "\n========== PRODUCT LIST ==========\n";

    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << ". "
             << products[i]
             << " - Rs. "
             << prices[i] << endl;
    }
}

// Add Products To Cart
void addProductsToCart(string products[],
                       double prices[],
                       int size,
                       double &productTotal)
{
    int productNo;
    int quantity;

    displayProducts(products, prices, size);

    cout << "\nEnter Product Number: ";
    cin >> productNo;

    if(productNo < 1 || productNo > size)
    {
        cout << "Invalid Product Number!\n";
        return;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;

    productTotal += prices[productNo - 1] * quantity;

    cout << "\nProduct Added Successfully!\n";
    cout << "Current Cart Total: Rs. "
         << productTotal << endl;
}

// GST
double calculateGST(double productTotal)
{
    return productTotal * 0.17;
}

// Delivery Charges
double calculateDeliveryCharges(string city)
{
    if(city == "Lahore" ||
       city == "Karachi" ||
       city == "Islamabad")
    {
        return 250;
    }

    return 500;
}

// Customer Discount
double calculateCustomerDiscount(double productTotal,
                                 string customerType)
{
    if(customerType == "New Customer")
        return productTotal * 0.05;

    return productTotal * 0.10;
}

// Order Discount
double calculateOrderDiscount(double productTotal)
{
    if(productTotal >= 5000 &&
       productTotal <= 10000)
    {
        return productTotal * 0.05;
    }

    else if(productTotal > 10000)
    {
        return productTotal * 0.12;
    }

    return 0;
}

// Payment Charges
double calculatePaymentCharges(double amount,
                               int paymentMethod)
{
    if(paymentMethod == 2)
    {
        return amount * 0.025;
    }

    return 0;
}

// User Details
void displayUserDetails(string name,
                        string email,
                        string city,
                        string customerType)
{
    cout << "\n========== USER DETAILS ==========\n";

    cout << "User Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "City: " << city << endl;
    cout << "Customer Type: "
         << customerType << endl;
}

// Final Bill
void displayCheckoutBill(string name,
                         string city,
                         string customerType,
                         double productTotal,
                         double gst,
                         double deliveryCharges,
                         double customerDiscount,
                         double orderDiscount,
                         double paymentCharges,
                         double finalAmount)
{
    cout << fixed << setprecision(2);

    cout << "\n\n========== ONLINE SHOPPING BILL ==========\n";

    cout << "User Name: "
         << name << endl;

    cout << "City: "
         << city << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "Product Total: Rs. "
         << productTotal << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Delivery Charges: Rs. "
         << deliveryCharges << endl;

    cout << "Customer Discount: Rs. "
         << customerDiscount << endl;

    cout << "Order Discount: Rs. "
         << orderDiscount << endl;

    cout << "Payment Charges: Rs. "
         << paymentCharges << endl;

    cout << "-------------------------------------\n";

    cout << "Final Payable Amount: Rs. "
         << finalAmount << endl;

    cout << "Thank You For Shopping :)\n";

    cout << "==========================================\n";
}

