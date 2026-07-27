#include <string>
using namespace std;

const int MAX_ENTRIES = 20;

// Authentication Data
string registeredUsername = "";
string registeredPassword = "";

// Diary Arrays
string titles[MAX_ENTRIES];
string contents[MAX_ENTRIES];
int totalEntries = 0;

// Function Prototypes
void registerUser();
bool loginUser();

void createEntry();
void viewAllEntries();
void readFullEntry();
void editEntry();
void deleteOneEntry();
void deleteAllEntries();

void displayMenu();

int main()
{
    int authChoice;

    cout << "========== PERSONAL STUDENT DIARY ==========\n";

    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter Choice: ";
    cin >> authChoice;

    cin.ignore();

    if(authChoice == 1)
    {
        registerUser();
    }

    if(!loginUser())
    {
        cout << "\nLogin Failed!\n";
        return 0;
    }

    int choice;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                createEntry();
                break;

            case 2:
                viewAllEntries();
                break;

            case 3:
                readFullEntry();
                break;

            case 4:
                editEntry();
                break;

            case 5:
                deleteOneEntry();
                break;

            case 6:
                deleteAllEntries();
                break;

            case 7:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}

// Register Function
void registerUser()
{
    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter Username: ";
    getline(cin, registeredUsername);

    cout << "Enter Password: ";
    getline(cin, registeredPassword);

    cout << "\nRegistration Successful!\n";
}

// Login Function
bool loginUser()
{
    string username;
    string password;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter Username: ";
    getline(cin, username);

    cout << "Enter Password: ";
    getline(cin, password);

    if(username == registeredUsername &&
       password == registeredPassword)
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    return false;
}

// Menu
void displayMenu()
{
    cout << "\n\n========== DIARY MENU ==========\n";
    cout << "1. Create New Diary Entry\n";
    cout << "2. View All Entries\n";
    cout << "3. Read Full Entry\n";
    cout << "4. Edit An Entry\n";
    cout << "5. Delete One Entry\n";
    cout << "6. Delete All Entries\n";
    cout << "7. Exit\n";
    cout << "Enter Choice: ";
}

// Create Entry
void createEntry()
{
    if(totalEntries >= MAX_ENTRIES)
    {
        cout << "\nDiary Full! Maximum 20 Entries Allowed.\n";
        return;
    }

    cout << "\nEnter Title: ";
    getline(cin, titles[totalEntries]);

    if(titles[totalEntries].empty())
    {
        cout << "Title Cannot Be Empty!\n";
        return;
    }

    cout << "Enter Content: ";
    getline(cin, contents[totalEntries]);

    if(contents[totalEntries].empty())
    {
        cout << "Content Cannot Be Empty!\n";
        return;
    }

    totalEntries++;

    cout << "\nEntry Added Successfully!\n";
}

// View All Entries
void viewAllEntries()
{
    if(totalEntries == 0)
    {
        cout << "\nNo Entries Found!\n";
        return;
    }

    cout << "\n===== ALL ENTRIES =====\n";

    for(int i = 0; i < totalEntries; i++)
    {
        cout << i + 1 << ". "
             << titles[i] << endl;
    }

    cout << "\nTotal Entries: "
         << totalEntries << endl;
}

// Read Full Entry
void readFullEntry()
{
    if(totalEntries == 0)
    {
        cout << "\nNo Entries Available!\n";
        return;
    }

    int entryNumber;

    cout << "\nEnter Entry Number: ";
    cin >> entryNumber;
    cin.ignore();

    if(entryNumber < 1 ||
       entryNumber > totalEntries)
    {
        cout << "Invalid Entry Number!\n";
        return;
    }

    cout << "\n===== ENTRY DETAILS =====\n";

    cout << "Title: "
         << titles[entryNumber - 1] << endl;

    cout << "Content: "
         << contents[entryNumber - 1] << endl;
}

// Edit Entry
void editEntry()
{
    if(totalEntries == 0)
    {
        cout << "\nNo Entries Available!\n";
        return;
    }

    int entryNumber;

    cout << "\nEnter Entry Number To Edit: ";
    cin >> entryNumber;
    cin.ignore();

    if(entryNumber < 1 ||
       entryNumber > totalEntries)
    {
        cout << "Invalid Entry Number!\n";
        return;
    }

    cout << "Enter New Title: ";
    getline(cin, titles[entryNumber - 1]);

    cout << "Enter New Content: ";
    getline(cin, contents[entryNumber - 1]);

    cout << "\nEntry Updated Successfully!\n";
}

// Delete One Entry
void deleteOneEntry()
{
    if(totalEntries == 0)
    {
        cout << "\nNo Entries Available!\n";
        return;
    }

    int entryNumber;

    cout << "\nEnter Entry Number To Delete: ";
    cin >> entryNumber;
    cin.ignore();

    if(entryNumber < 1 ||
       entryNumber > totalEntries)
    {
        cout << "Invalid Entry Number!\n";
        return;
    }

    for(int i = entryNumber - 1;
        i < totalEntries - 1;
        i++)
    {
        titles[i] = titles[i + 1];
        contents[i] = contents[i + 1];
    }

    totalEntries--;

    cout << "\nEntry Deleted Successfully!\n";
}

// Delete All Entries
void deleteAllEntries()
{
    if(totalEntries == 0)
    {
        cout << "\nNo Entries Available!\n";
        return;
    }

    char choice;

    cout << "\nAre You Sure? (Y/N): ";
    cin >> choice;
    cin.ignore();

    if(choice == 'Y' || choice == 'y')
    {
        totalEntries = 0;
        cout << "\nAll Entries Deleted Successfully!\n";
    }
    else
    {
        cout << "\nOperation Cancelled.\n";
    }
}

