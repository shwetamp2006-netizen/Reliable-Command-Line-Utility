# Reliable Command-Line Utility: Expense Tracker

## Objective
A menu-driven C++ expense tracker demonstrating variables, loops, functions, collections, and defensive input validation.

## Features
- Add an expense with a category and positive amount.
- List all recorded expenses.
- Display totals for each category.
- Display the overall expense total.
- Reject empty categories, invalid amounts, and invalid menu choices without crashing.

## Requirements
- A C++ compiler supporting C++11 or later (C++17 recommended).

## Build and run

### Linux / macOS
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o expense_tracker
./expense_tracker
```

### Windows (MinGW)
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o expense_tracker.exe
expense_tracker.exe
```

You can also paste `main.cpp` into an online C++ compiler and run it.

## Sample run
```text
===== EXPENSE TRACKER =====
1. Add Expense
2. List Expenses
3. Category Total
4. Overall Total
5. Exit
Enter your choice: 1
Enter category: Food
Enter amount (greater than 0): Rs. 150
Expense added successfully!

===== EXPENSE TRACKER =====
1. Add Expense
2. List Expenses
3. Category Total
4. Overall Total
5. Exit
Enter your choice: 1
Enter category: Travel
Enter amount (greater than 0): Rs. 50
Expense added successfully!

===== EXPENSE TRACKER =====
1. Add Expense
2. List Expenses
3. Category Total
4. Overall Total
5. Exit
Enter your choice: 3

--- Totals by Category ---
Food: Rs. 150.00
Travel: Rs. 50.00

===== EXPENSE TRACKER =====
1. Add Expense
2. List Expenses
3. Category Total
4. Overall Total
5. Exit
Enter your choice: 4
Overall expense total: Rs. 200.00
```

## Submission checklist
- [ ] Upload `main.cpp` and this `README.md` to a GitHub repository.
- [ ] Set the repository visibility to Public, if you are comfortable making the code public and the task requires a public link.
- [ ] Run the program and take screenshots of a successful run, including adding expenses and showing totals.
- [ ] Paste the GitHub repository URL into EdVyro's Project URL field and select **Submit for review**.

Note: Expenses are stored in memory while the program runs; they are not saved after exiting. Persistent file storage was not required by the task brief shown in the dashboard.
