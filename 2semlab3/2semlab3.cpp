#include <iostream>
#include <string>

using namespace std;

// Базовый класс - простой счет в банке
class BankAccount {
protected:
    string ownerName;
    double initialBalance;
    double interestRate;
    int years;

public:
    BankAccount(string name, double balance, double rate, int years)
        : ownerName(name), initialBalance(balance), interestRate(rate), years(years) {}

    virtual double calculateBalance() {
        double balance = initialBalance * (1 + interestRate / 100) * years;
        return balance;
    }

    virtual void printInfo() {
        cout << "Owner: " << ownerName << endl;
        cout << "Initial Balance: $" << initialBalance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Years: " << years << endl;
        cout << "Calculated Balance: $" << calculateBalance() << endl;
    }
};

// Производный класс - привилегированный счет
class PrivilegedAccount : public BankAccount {
private:
    double creditRate;

public:
    PrivilegedAccount(string name, double balance, double rate, int years, double creditRate)
        : BankAccount(name, balance, rate, years), creditRate(creditRate) {}

    // Статический полиморфизм
    double calculateBalance() override {
        double balance = BankAccount::calculateBalance();
        double credit = balance * (creditRate / 100);
        return balance + credit;
    }

    // Динамический полиморфизм
    void printInfo() override {
        BankAccount::printInfo();
        cout << "Credit Rate: " << creditRate << "%" << endl;
        cout << "Total Balance with Credit: $" << calculateBalance() << endl;
    }
};

int main() {
    // Создание объектов
    BankAccount basicAccount("Andrey Bakanchev", 10000, 5, 5);
    PrivilegedAccount privilegedAccount("Nikolai Repin", 15000, 6, 3, 10);

    // Вызов функций
    cout << "Basic Account Information:" << endl;
    basicAccount.printInfo();
    cout << endl;

    cout << "Privileged Account Information:" << endl;
    privilegedAccount.printInfo();

    return 0;
}
