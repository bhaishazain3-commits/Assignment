#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void registerClient(string &clientName, string &businessName,
                    string &businessType, int &campaignDays);

void displayPlatforms(string platforms[], double charges[], int size);

double selectPlatform(string platforms[], double charges[],
                      int size, string &selectedPlatform);

double calculatePostDesignCost();
double calculateAdHandlingFee(double adBudget);
double calculateExtraDurationCharges(int campaignDays);
double calculateGST(double amount);
double calculateDiscount(double amount, string businessType);

void displayClientDetails(string clientName,
                          string businessName,
                          string businessType,
                          int campaignDays);

void displayFinalBill(string clientName,
                      string businessName,
                      string businessType,
                      string selectedPlatform,
                      int campaignDays,
                      double platformCharges,
                      double postDesignCost,
                      double adBudget,
                      double handlingFee,
                      double extraCharges,
                      double gst,

                      double finalCost);

int main()
{
    string clientName;
    string businessName;
    string businessType;
    string selectedPlatform = "";

    int campaignDays;

    registerClient(clientName,
                   businessName,
                   businessType,
                   campaignDays);

    string platforms[3] =
    {
        "Instagram",
        "Facebook",
        "LinkedIn"
    };

    double platformChargesArray[3] =
    {
        15000,
        12000,
        20000
    };

    double platformCharges = 0;
    double postDesignCost = 0;
    double adBudget = 0;

    int choice;

    do
    {
        cout << "\n========== SOCIAL MEDIA SYSTEM ==========\n";
        cout << "1. View Platforms\n";
        cout << "2. Select Campaign Platform\n";
        cout << "3. Calculate Campaign Cost\n";
        cout << "4. View Client Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayPlatforms(platforms,
                                 platformChargesArray,
                                 3);
                break;

            case 2:
                platformCharges =
                selectPlatform(platforms,
                               platformChargesArray,
                               3,
                               selectedPlatform);
                break;

            case 3:
            {
                if(selectedPlatform == "")
                {
                    cout << "\nPlease Select Platform First!\n";
                    break;
                }

                postDesignCost =
                calculatePostDesignCost();

                cout << "\nEnter Advertisement Budget: Rs. ";
                cin >> adBudget;

                double handlingFee =
                calculateAdHandlingFee(adBudget);

                double extraCharges =
                calculateExtraDurationCharges(campaignDays);

                double subTotal =
                platformCharges +
                postDesignCost +
                adBudget +
                handlingFee +
                extraCharges;

                double gst =
                calculateGST(subTotal);

                double discount =
                calculateDiscount(subTotal,
                                  businessType);

                double finalCost =
                subTotal + gst - discount;

                displayFinalBill(
                    clientName,
                    businessName,
                    businessType,
                    selectedPlatform,
                    campaignDays,
                    platformCharges,
                    postDesignCost,
                    adBudget,
                    handlingFee,
                    extraCharges,
                    gst,
                    discount,
                    finalCost;

                break;
            }

            case 4:
                displayClientDetails(clientName,
                                     businessName,
                                     businessType,
                                     campaignDays);
                break;

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}

// Register Client
void registerClient(string &clientName,
                    string &businessName,
                    string &businessType,
                    int &campaignDays)
{
    cout << "========== CLIENT REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter Client Name: ";
    getline(cin, clientName);

    cout << "Enter Business Name: ";
    getline(cin, businessName);

    int type;

    cout << "\nBusiness Type\n";
    cout << "1. Small Business\n";
    cout << "2. Medium Business\n";
    cout << "3. Corporate Business\n";
    cout << "Enter Choice: ";
    cin >> type;

    if(type == 1)
        businessType = "Small Business";
    else if(type == 2)
        businessType = "Medium Business";
    else
        businessType = "Corporate Business";

    cout << "Enter Campaign Duration (Days): ";
    cin >> campaignDays;
}

// Display Platforms
void displayPlatforms(string platforms[],
                      double charges[],
                      int size)
{
    cout << "\n===== AVAILABLE PLATFORMS =====\n";

    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << ". "
             << platforms[i]
             << " - Rs. "
             << charges[i]
             << endl;
    }
}

// Select Platform
double selectPlatform(string platforms[],
                      double charges[],
                      int size,
                      string &selectedPlatform)
{
    int choice;

    displayPlatforms(platforms,
                     charges,
                     size);

    cout << "\nSelect Platform: ";
    cin >> choice;

    if(choice >= 1 && choice <= size)
    {
        selectedPlatform =
        platforms[choice - 1];

        cout << "\nPlatform Selected Successfully!\n";

        return charges[choice - 1];
    }

    cout << "\nInvalid Choice!\n";
    return 0;
}

// Post Design Cost
double calculatePostDesignCost()
{
    int staticPosts;
    int reelPosts;
    int carouselPosts;

    cout << "\nEnter Number of Static Posts: ";
    cin >> staticPosts;

    cout << "Enter Number of Reel/Video Posts: ";
    cin >> reelPosts;

    cout << "Enter Number of Carousel Posts: ";
    cin >> carouselPosts;

    return (staticPosts * 1000)
         + (reelPosts * 2500)
         + (carouselPosts * 1800);
}

// Ad Handling Fee
double calculateAdHandlingFee(double adBudget)
{
    if(adBudget < 50000)
        return adBudget * 0.05;

    else if(adBudget <= 100000)
        return adBudget * 0.08;

    else
        return adBudget * 0.10;
}

// Extra Duration Charges
double calculateExtraDurationCharges(int campaignDays)
{
    if(campaignDays > 30)
    {
        return (campaignDays - 30) * 500;
    }

    return 0;
}

// GST
double calculateGST(double amount)
{
    return amount * 0.16;
}

// Discount
double calculateDiscount(double amount,
                         string businessType)
{
    if(businessType == "Small Business")
        return amount * 0.05;

    else if(businessType == "Medium Business")
        return amount * 0.08;

    else
        return amount * 0.10;
}

// Client Details
void displayClientDetails(string clientName,
                          string businessName,
                          string businessType,
                          int campaignDays)
{
    cout << "\n========== CLIENT DETAILS ==========\n";

    cout << "Client Name: "
         << clientName << endl;

    cout << "Business Name: "
         << businessName << endl;

    cout << "Business Type: "
         << businessType << endl;

    cout << "Campaign Duration: "
         << campaignDays << " Days" << endl;
}

// Final Bill
void displayFinalBill(string clientName,
                      string businessName,
                      string businessType,
                      string selectedPlatform,
                      int campaignDays,
                      double platformCharges,
                      double postDesignCost,
                      double adBudget,
                      double handlingFee,
                      double extraCharges,
                      double gst,
                      double discount,
                      double finalCost)
{
    cout << fixed << setprecision(2);

    cout << "\n\n========== SOCIAL MEDIA CAMPAIGN BILL ==========\n";

    cout << "Client Name: "
         << clientName << endl;

    cout << "Business Name: "
         << businessName << endl;

    cout << "Business Type: "
         << businessType << endl;

    cout << "Selected Platform: "
         << selectedPlatform << endl;

    cout << "Campaign Duration: "
         << campaignDays << " Days" << endl;

    cout << "Platform Management Charges: Rs. "
         << platformCharges << endl;

    cout << "Post Design Cost: Rs. "
         << postDesignCost << endl;

    cout << "Ad Budget: Rs. "
         << adBudget << endl;

    cout << "Ad Handling Fee: Rs. "
         << handlingFee << endl;

    cout << "Extra Duration Charges: Rs. "
         << extraCharges << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Discount: Rs. "
         << discount << endl;

    cout << "--------------------------------------------\n";

    cout << "Final Campaign Cost: Rs. "
         << finalCost << endl;

    cout << "============================================\n";
}

