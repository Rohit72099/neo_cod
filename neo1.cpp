#include <iostream>

using namespace std;

class partA {
private:
    string name;
    string pan;

public:
    partA() {}
    partA(string name, string pan) : name(name), pan(pan) {}

    void print() {
        cout << "Account Holder Name: " << name << endl;
        cout << "PAN: " << pan << endl;
    }
};

class partB : public partA {
private:
    int grossSalary;
    int otherIncome;

public:
    partB() {}
    partB(string name, string pan, int grossSalary, int otherIncome) : partA(name, pan), grossSalary(grossSalary), otherIncome(otherIncome) {}

    void print() {
        partA::print();
        cout << "Gross Salary: " << grossSalary << endl;
        cout << "Income from Other Sources: " << otherIncome << endl;
    }
};

class partC : public partA {
private:
    int deductions;

public:
    partC() {}
    partC(string name, string pan, int deductions) : partA(name, pan), deductions(deductions) {}

    void print() {
        partA::print();
        cout << "Deductions: " << deductions << endl;
    }
};

class taxComp : public partB, public partC {
public:
    taxComp() {}
    taxComp(string name, string pan, int grossSalary, int otherIncome, int deductions) : partB(name, pan, grossSalary, otherIncome), partC(name, pan, deductions) {}

    float calculateTax() {
        float taxableIncome = grossSalary + otherIncome - deductions;
        return taxableIncome * 0.3;
    }

    void print() {
        partB::print();
        partC::print();

        float tax = calculateTax();
        cout << "Taxable Income (computed): " << tax << endl;
        cout << "Tax Payable (computed): " << tax << endl;
    }
};

int main() {
    string name, pan;
    int grossSalary, otherIncome, deductions;

    cout << "Enter account holder name: ";
    cin >> name;

    cout << "Enter PAN: ";
    cin >> pan;

    cout << "Enter gross salary: ";
    cin >> grossSalary;

    cout << "Enter income from other sources: ";
    cin >> otherIncome;

    cout << "Enter deductions: ";
    cin >> deductions;

    // Creating partA
    partA partAObj(name, pan);

    // Creating partB
    partB partBObj(name, pan, grossSalary, otherIncome);

    // Creating partC
    partC partCObj(name, pan, deductions);

    // Creating taxComp
    taxComp taxCompObj(name, pan, grossSalary, otherIncome, deductions);

    // Printing the details
    cout << "Constructor sequence:" << endl;
    cout << "partA -> partB -> partC -> taxComp" << endl;
    cout << endl;

    cout << "Account details:" << endl;
    taxCompObj.print();

    cout << endl;

    // Printing the destructor sequence
    cout << "Destructor sequence:" << endl;
    cout << "taxComp -> partC -> partB -> partA" << endl;

    return 0;
}

