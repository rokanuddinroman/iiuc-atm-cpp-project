#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class atm {
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    long int getAccountNo() {
        return account_No;
    }

    string getName() {
        return name;
    }

    int getPIN() {
        return PIN;
    }

    double getBalance() {
        return balance;
    }

    string getMobileNo() {
        return mobile_No;
    }

    void setMobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_No) {
            mobile_No = mob_new;
            cout << endl << "Successfully Updated Mobile no.";
            cin.get(); // Equivalent to _getch()
        }
        else {
            cout << endl << "Incorrect !!! Old Mobile no";
            cin.get(); // Equivalent to _getch()
        }
    }

    void cashWithDraw(int amount_a) {
        if (amount_a > 0 && amount_a < balance) {
            balance -= amount_a;
            cout << endl << "Please Collect Your Cash";
            cout << endl << "Available Balance: " << balance;
            cin.get(); // Equivalent to _getch()
        }
        else {
            cout << endl << "Invalid Input or Insufficient Balance";
            cin.get(); // Equivalent to _getch()
        }
    }
};

int main() {
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");
    atm user1;
    user1.setData(987654321, "Rokan", 1234, 50000, "+8801714422777");

    do {
        system("cls");
        cout << endl << "****Welcome to IIUC ATM*****" << endl;
        cout << endl << "Enter Your Account No ";
        cin >> enterAccountNo;

        cout << endl << "Enter PIN ";
        cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())) {
            do {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                cout << endl <<endl << "**** Welcome to IIUC ATM *****" << endl;
                cout << endl << "Select Options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash withdraw";
                cout << endl << "3. Show User Details";
                cout << endl << "4. Update Mobile no.";
                cout << endl << "5. Exit" << endl;
                cout << endl << "Select an Option: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << endl << "Your Bank balance is: " << user1.getBalance();
                        cin.get();
                        break;

                    case 2:
                        cout << endl << "Enter the amount :";
                        cin >> amount;
                        user1.cashWithDraw(amount);
                        break;

                    case 3:
                        cout << endl << "User Details are :- "<<endl;
                        cout << endl << "-> Account no :" << user1.getAccountNo();
                        cout << endl << "-> Name      :" << user1.getName();
                        cout << endl << "-> Balance   :" << user1.getBalance();
                        cout << endl << "-> Mobile No. :" << user1.getMobileNo();
                        cin.get();
                        break;

                    case 4:
                        cout << endl << "Enter Old Mobile No. ";
                        cin >> oldMobileNo;
                        cout << endl << "Enter New Mobile No. ";
                        cin >> newMobileNo;
                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;

                    case 5:
                        exit(0);

                    default:
                        cout << endl << "Enter Valid Data !!!";
                }
            } while (1);
        }
        else {
            cout << endl << "User Details are Invalid !!! ";
            cin.get();
        }
    } while (1);

    return 0;
}
