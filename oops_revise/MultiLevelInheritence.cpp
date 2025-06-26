#include <bits/stdc++.h>
using namespace std;

class Company
{
private:
    int min_salary, company_registration_number, total_profit;
    string company_name, parent_company, owner_name, cofounder, company_location;
    bool Inprofit, have_cofounder, have_parent_company;

public:
    Company(int min_salary = 28000, int company_registration_number = 0, int total_profit = 0, string company_name = "N/A", string parent_company = "N/A", string owner_name = "N/A", string cofounder = "N/A", string company_loc = "N/A", bool made_profit = false, bool had_cofounder = false, bool had_parent_company = false)
    {
        this->min_salary = min_salary;
        this->company_registration_number = company_registration_number;
        this->total_profit = total_profit;
        this->company_name = company_name;
        this->parent_company = parent_company;
        this->owner_name = owner_name;
        this->cofounder = cofounder;
        this->company_location = company_loc;
        this->Inprofit = made_profit;
        this->have_cofounder = had_cofounder;
        this->have_parent_company = had_parent_company;
    }

    void GetDetails()
    {
        cout << "Enter Details for Company Registration:\n";
        cout << "Company Name: ";
        getline(cin >> ws, company_name);

        cout << "Owner Name: ";
        getline(cin >> ws, owner_name);

        cout << "Company Registration Number: ";
        cin >> company_registration_number;

        cout << "Minimum Salary Offered: ";
        cin >> min_salary;

        cout << "Total Profit Earned: ";
        cin >> total_profit;

        cout << "Company Location: ";
        getline(cin >> ws, company_location);

        char choice;

        cout << "Did the company make profit? (y/n): ";
        cin >> choice;
        Inprofit = (choice == 'y' || choice == 'Y');

        cout << "Does the company have a cofounder? (y/n): ";
        cin >> choice;
        have_cofounder = (choice == 'y' || choice == 'Y');
        if (have_cofounder)
        {
            cout << "Enter Cofounder Name: ";
            getline(cin >> ws, cofounder);
        }

        cout << "Is there a parent company? (y/n): ";
        cin >> choice;
        have_parent_company = (choice == 'y' || choice == 'Y');
        if (have_parent_company)
        {
            cout << "Enter Parent Company Name: ";
            getline(cin >> ws, parent_company);
        }
    }

    void DisplayDetails()
    {
        cout << "\n--- Company Information ---\n";
        cout << "Company Name: " << company_name << endl;
        cout << "Owner Name: " << owner_name << endl;
        cout << "Registration Number: " << company_registration_number << endl;
        cout << "Minimum Salary: " << min_salary << endl;
        cout << "Total Profit: " << total_profit << endl;
        cout << "Company Location: " << company_location << endl;
        cout << "In Profit: " << (Inprofit ? "Yes" : "No") << endl;
        cout << "Has Cofounder: " << (have_cofounder ? "Yes" : "No") << endl;
        if (have_cofounder)
            cout << "Cofounder Name: " << cofounder << endl;
        cout << "Has Parent Company: " << (have_parent_company ? "Yes" : "No") << endl;
        if (have_parent_company)
            cout << "Parent Company: " << parent_company << endl;
    }
};

class Employee : protected Company
{
private:
    int EmployeeId, holidays_left, daily_working_hours, hours_extra_worked, Employee_Salary;
    string Employee_address, Employee_contact, designation, Employee_name;
    bool has_dependants, has_medical_insurance;

public:
    Employee()
    {
        cout << "Register Yourself : " << endl;
        cout << "\n--- Employee Registration ---\n";
        cout << "Employee ID: ";
        cin >> EmployeeId;
        cout << "Name: ";
        cin.ignore();
        getline(cin, Employee_name);
        cout << "Address: ";
        getline(cin, Employee_address);
        cout << "Contact: ";
        getline(cin, Employee_contact);
        cout << "Designation: ";
        getline(cin, designation);
        cout << "Salary: ";
        cin >> Employee_Salary;
        cout << "Holidays Left: ";
        cin >> holidays_left;
        cout << "Daily Working Hours: ";
        cin >> daily_working_hours;
        cout << "Extra Hours Worked: ";
        cin >> hours_extra_worked;

        char ch;
        cout << "Has Dependants? (y/n): ";
        cin >> ch;
        has_dependants = (ch == 'y' || ch == 'Y');

        cout << "Has Medical Insurance? (y/n): ";
        cin >> ch;
        has_medical_insurance = (ch == 'y' || ch == 'Y');
    }

    Employee(int id, string name, string address, string contact, string desig,
             int salary, int holidays, int work_hours, int extra_hours,
             bool dependants, bool insurance)
    {
        EmployeeId = id;
        Employee_name = name;
        Employee_address = address;
        Employee_contact = contact;
        designation = desig;
        Employee_Salary = salary;
        holidays_left = holidays;
        daily_working_hours = work_hours;
        hours_extra_worked = extra_hours;
        has_dependants = dependants;
        has_medical_insurance = insurance;

        cout << "Saved Employee Data of: " << Employee_name << endl;
    }

    void ShowEmployeeInfo()
    {
        cout << "\n--- Employee Information ---\n";
        cout << "ID: " << EmployeeId << "\nName: " << Employee_name << "\nDesignation: " << designation << endl;
        cout << "Contact: " << Employee_contact << "\nAddress: " << Employee_address << endl;
        cout << "Salary: " << Employee_Salary << " | Holidays Left: " << holidays_left << endl;
        cout << "Daily Working Hours: " << daily_working_hours << " | Extra Worked: " << hours_extra_worked << " hrs" << endl;
        cout << "Dependants: " << (has_dependants ? "Yes" : "No") << endl;
        cout << "Medical Insurance: " << (has_medical_insurance ? "Yes" : "No") << endl;

        cout << endl
             << endl;
        DisplayDetails();
    }
};

class Manager : protected Employee
{
private:
    int team_size;
    string department;
    bool has_stock_options;
    int meetings_per_week;

public:
    Manager()
    {
        cout << "\nRegister Manager Details:\n";
    }

    Manager(int id, string name, string address, string contact, string desig, int salary,
            int holidays, int work_hours, int extra_hours, bool dependants, bool insurance,
            int team_size, string dept, bool stock_options, int meetings)
        : Employee(id, name, address, contact, desig, salary, holidays, work_hours, extra_hours, dependants, insurance)
    {
        cout << "Department: ";
        cin.ignore();
        getline(cin, department);

        cout << "Team Size: ";
        cin >> team_size;

        char ch;
        cout << "Has Stock Options? (y/n): ";
        cin >> ch;
        has_stock_options = (ch == 'y' || ch == 'Y');

        cout << "Meetings per Week: ";
        cin >> meetings_per_week;

        cout << "Manager registered: " << name << endl;
    }


    void ShowManagerDetails()
    {
        ShowEmployeeInfo();
        cout << "--- Manager Specific Info ---\n";
        cout << "Department: " << department << endl;
        cout << "Team Size: " << team_size << endl;
        cout << "Stock Options: " << (has_stock_options ? "Yes" : "No") << endl;
        cout << "Meetings per Week: " << meetings_per_week << endl;
    }
};

int main()
{
    Manager * m = new Manager();
    m->ShowManagerDetails();

    return 0;
}