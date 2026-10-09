#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

struct Expense {
    string category;
    double amount;
};

bool readPositiveAmount(double &amount) {
    string line;
    if (!getline(cin, line)) return false;

    stringstream ss(line);
    char extra;
    if (!(ss >> amount) || (ss >> extra) || amount <= 0) {
        return false;
    }
    return true;
}

int readMenuChoice() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int choice;
    char extra;
    if (!(ss >> choice) || (ss >> extra)) return -1;
    return choice;
}

string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

void addExpense(vector<Expense> &expenses) {
    string category;
    cout << "Enter category: ";
    getline(cin, category);
    category = trim(category);

    if (category.empty()) {
        cout << "Category cannot be empty. Expense not added.\n";
        return;
    }

    cout << "Enter amount (greater than 0): Rs. ";
    double amount;
    if (!readPositiveAmount(amount)) {
        cout << "Invalid amount. Enter a number greater than 0. Expense not added.\n";
        return;
    }

    expenses.push_back({category, amount});
    cout << "Expense added successfully!\n";
}

void listExpenses(const vector<Expense> &expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << "\n--- All Expenses ---\n";
    cout << left << setw(5) << "No." << setw(24) << "Category" << right << setw(12) << "Amount (Rs.)\n";
    cout << string(41, '-') << "\n";
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << left << setw(5) << i + 1
             << setw(24) << expenses[i].category
             << right << setw(12) << expenses[i].amount << "\n";
    }
}

void showCategoryTotals(const vector<Expense> &expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    map<string, double> totals;
    for (const auto &expense : expenses) {
        totals[expense.category] += expense.amount;
    }

    cout << "\n--- Totals by Category ---\n";
    cout << fixed << setprecision(2);
    for (const auto &entry : totals) {
        cout << entry.first << ": Rs. " << entry.second << "\n";
    }
}

void showOverallTotal(const vector<Expense> &expenses) {
    double total = 0.0;
    for (const auto &expense : expenses) {
        total += expense.amount;
    }
    cout << fixed << setprecision(2);
    cout << "Overall expense total: Rs. " << total << "\n";
}

int main() {
    vector<Expense> expenses;
    bool running = true;

    while (running) {
        cout << "\n===== EXPENSE TRACKER =====\n"
             << "1. Add Expense\n"
             << "2. List Expenses\n"
             << "3. Category Total\n"
             << "4. Overall Total\n"
             << "5. Exit\n"
             << "Enter your choice: ";

        int choice = readMenuChoice();

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                listExpenses(expenses);
                break;
            case 3:
                showCategoryTotals(expenses);
                break;
            case 4:
                showOverallTotal(expenses);
                break;
            case 5:
                running = false;
                cout << "Thank you for using Expense Tracker!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }
    }

    return 0;
}
