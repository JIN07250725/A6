// ------------- FILE HEADER -------------
// Author: Yusong Jin
// Assignment: 6
// Date: August 5
// Description: Coffee/Tea vending machine simulator
// Sources: 

// ------------- ZYBOOKS SCORES -------------
// https://learn.zybooks.com/zybook/PCCCS161ASummer25
// Chapter: 6
// Participation: 100%
// Challenge: 100%
// Labs: 100%

// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count: 1
// Links (Optional): 

// ------------- DESIGN DOCUMENT -------------
// A. INPUT [yes/no]: yes
// B. OUTPUT [yes/no]: yes
// C. CALCULATIONS [yes/no]: yes
// D. LOGIC and ALGORITHMS [yes/no]: yes
//    (Optional) flow chart link or file name: 

// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS [yes/no]: yes
// (Optional) Additional tests count:   

// ------------- CODE -------------
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double COST = 0.25; // Price per item
    cout << "Welcome to my Coffee/Tea Vending Machine!\n\n";

    double balance = 0.0;
    int coin = -1;

    // First coin insertion
    do {
        cout << "Enter coins - 5, 10, or 25 only: ";
        cin >> coin;

        while (coin != 0 && 
               coin != 5 && 
               coin != 10 && 
               coin != 25) {
            cout << "Invalid coin! Please enter 5, 10, or 25 only: ";
            cin >> coin;
        }
        if (coin != 0) {
            balance += coin / 100.0;
        }
    } 
    while (coin != 0);

    cout << fixed << setprecision(2);
    cout << "\nYour balance is $" << balance << "\n\n";

    char choice;
    int quantity;
    double totalCost;
    bool quit = false;

    while (!quit) {
        // Menu selection
        cout << "Please pick an option ($0.25 each):\n";
        cout << "    C/c: Coffee\n";
        cout << "    T/t: Tea\n";
        cout << "    Q/q: Quit\n";
        cout << ">> ";
        cin >> choice;

        while (choice != 'C' && choice != 'c' &&
               choice != 'T' && choice != 't' &&
               choice != 'Q' && choice != 'q') {
            cout << "Invalid Option! Please choose a valid option!\n";
            cout << ">> ";
            cin >> choice;
        }

        // Quit option
        if (choice == 'Q' || choice == 'q') {
            cout << "\nYour total is $0\n";
            cout << "Your balance is $" << balance << "\n";
            quit = true;
            continue;
        }

        // Quantity input
        cout << "\nHow many would you like?\n>> ";
        cin >> quantity;
        while (cin.fail() || quantity <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Option!\n";
            cout << "How many would you like?\n>> ";
            cin >> quantity;
        }

        totalCost = quantity * COST;

        // Not enough money → insert more coins → return to menu
        if (totalCost > balance) {
            cout << "\nYour total is $" << totalCost << "\n";
            cout << "Your balance is $" << balance << "\n";
            cout << "Not enough change!! Please add more coins.\n\n";

            int moreCoin = -1;
            do {
                cout << "Enter coins - 5, 10, or 25 only: ";
                cin >> moreCoin;

                while (moreCoin != 0 && moreCoin != 5 &&
                       moreCoin != 10 && moreCoin != 25) {
                    cout << "Invalid coin! Please enter 5, 10, or 25 only: ";
                    cin >> moreCoin;
                }
                if (moreCoin != 0) {
                    balance += moreCoin / 100.0;
                }
            } 
            while (moreCoin != 0);

            cout << "\nYour balance: $" << balance << "\n\n";
            continue; // Back to menu
        }

        // Enough money → purchase and end
        balance -= totalCost;
        cout << "\nYour total is $" << totalCost << "\n";
        cout << "Your balance is $" << balance << "\n";
        quit = true; // End after purchase
    }
    cout << endl;
    cout << "Thank you for using my Vending Machine Program!\n";
    return 0;
}



// ------------- DESIGN -------------
/* 
Program Name: Vending Machine

Program Description: Coffee/Tea vending machine simulator 

Design:
A. INPUT
Define the input variables including name data type. 
int coin;
char choice;
int quantity;

B. OUTPUT
Define the output variables including data types. 
double balance;
double totalCost;
string message;

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
Convert coin input to dollars and add to balance:
balance = balance + (coin / 100.0)

Calculate total cost based on quantity:
totalCost = quantity * COST

Update balance after purchase:
balance = balance - totalCost

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 

BEGIN
SET COST = 0.25
PRINT "Welcome to my Coffee/Tea Vending Machine!"

SET balance = 0.0

// First coin input loop
REPEAT
    PROMPT "Enter coins - 5, 10, or 25 only: "
    READ coin
    WHILE coin is not 0, 5, 10, or 25
        PRINT "Invalid coin! Please enter 5, 10, or 25 only: "
        READ coin
    END WHILE
    IF coin is not 0
        ADD coin / 100 to balance
    END IF
UNTIL coin == 0

PRINT "Your balance is $" + balance (2 decimal places)

// Main menu loop
SET quit = false
WHILE quit is false
    // Show menu
    PRINT "Please pick an option ($0.25 each):"
    PRINT "    C/c: Coffee"
    PRINT "    T/t: Tea"
    PRINT "    Q/q: Quit"
    PROMPT ">> "
    READ choice

    // Validate menu choice
    WHILE choice not in (C, c, T, t, Q, q)
        PRINT "Invalid Option! Please choose a valid option!"
        PROMPT ">> "
        READ choice
    END WHILE

    // If quit
    IF choice is Q or q
        PRINT "Your total is $0"
        PRINT "Your balance is $" + balance
        SET quit = true
        CONTINUE to next loop iteration
    END IF

    // Ask quantity
    PRINT "How many would you like?"
    PROMPT ">> "
    READ quantity
    WHILE quantity <= 0 OR invalid number
        CLEAR invalid input
        PRINT "Invalid Option!"
        PRINT "How many would you like?"
        PROMPT ">> "
        READ quantity
    END WHILE

    CALCULATE totalCost = quantity * COST

    // If not enough money
    IF totalCost > balance
        PRINT "Your total is $" + totalCost
        PRINT "Your balance is $" + balance
        PRINT "Not enough change!! Please add more coins."

        // Add coins until user enters 0
        REPEAT
            PROMPT "Enter coins - 5, 10, or 25 only: "
            READ moreCoin
            WHILE moreCoin is not 0, 5, 10, or 25
                PRINT "Invalid coin! Please enter 5, 10, or 25 only: "
                READ moreCoin
            END WHILE
            IF moreCoin != 0
                ADD moreCoin / 100 to balance
            END IF
        UNTIL moreCoin == 0

        PRINT "Your balance: $" + balance
        CONTINUE to menu
    END IF

    // Enough money
    SUBTRACT totalCost from balance
    PRINT "Your total is $" + totalCost
    PRINT "Your balance is $" + balance
    SET quit = true
END WHILE

PRINT "Thank you for using my Vending Machine Program!"
END



SAMPLE RUNS
Copy from assignment document.
Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.80

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> k
Invalid Option! Please choose a valid option!
>> 9
Invalid Option! Please choose a valid option!
>> c
How many would you like?
>> f
Invalid Option!
How many would you like?
>> 2

Your total: $0.50
Your balance: $0.30
Thank you for using my Vending Machine Program!



Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.30

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> c

How many would you like?
>> 2

Your total is $0.50
Your balance is $0.30
Not enough change!! Please add more coins.

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance: $0.60

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> T

How many would you like?
>> 1

Your total is $0.25
Your balance is $0.35

Thank you for using my Vending Machine Program!




Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0
Your balance is $0.30

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> q

Your total is $0
Your balance is $0.30

Thank you for using my Vending Machine Program!
*/
