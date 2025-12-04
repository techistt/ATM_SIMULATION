/*
ATM Simulation:
1.Simulate basic ATM operations
2.Structure for account info (name, PIN, balance)
3.Strings for PINs and names
4.Arrays for multiple accounts
Functions:
1.Create Account
2.Login
3.Deposit Money
4.Withdraw Money
5.Check Balance
6.Change PIN
7.Display Account Details
8.Transfer Money
9.Save/Load data to/from file
10.Admin Panel for account management
*/
/*
Algorithm:
Step 1:Start
Step 2:Define a structure Account with:
        accNo : integer storing account number
        name : character array storing account holder name
        balance : float storing current balance
Step 3:Declare an array of Account structures to hold multiple accounts.
Step 4:Declare integer n  to store total accounts.
Step 5:Call loadFromFile() to load stored account details from file into the array.
Step 6:Begin an infinite loop to display the Main Menu.
Step 7:Display Main Menu:
       1.Create New Account
       2.Login to Account
       3.Admin Panel
       4.Exit
Step 8:Read user's choice.
Step 9:If choice = 1 (Create Account):
       a. Call createAccount()
       b. Add new account to array and increment n
       c. Return to the main menu
Step 10:Else if choice = 2 (Login to Account):
       a. Ask for account number and PIN
       b. Call login() to validate
       c. If invalid, show “Invalid Login”
       d. If valid, store the index of the logged-in account
Step 11:Display ATM Operations Menu:
       1.Check Balance
       2.Deposit Money
       3.Withdraw Money
       4.Change PIN
       5.Display Account Details
       6.Transfer Money
       7.Logout
Step 12:Read ATM menu choice.
       Perform ATM operation:
        a. If Check Balance,  call checkBalance()
        b. If Deposit Money,  call deposit(), saveToFile()
        c. If Withdraw Money,  call withdraw(), saveToFile()
        d. If Change PIN,  call changePin(), saveToFile()
        e. If Display Account Details,  call displayAccount()
        f. If Transfer Money, call transfer(), saveToFile()
        g. If Logout → exit ATM menu loop
Step 13:Else if choice = 3 (Admin Panel):
       a. Ask admin password
       b. If incorrect, return to main menu
       c. If correct, show Admin Menu:
           1. Show Accounts
           2. Delete Account
           3. Logout
       d. Read admin choice
           Admin operations:
            a. Show Accounts 
       b. Delete Account
       c. Logout,  saveToFile() and exit admin panel
Step 14:Else if choice = 4 (Exit):
       a. Save all accounts to file
       b. Show exit message
       c. End program
Step 15:If invalid choice, display “Invalid option”.
Step 16:Stop
*/
#include <stdio.h> //Standard input-output header file
#include <string.h> //String header file
struct Account // Structure to store account details
{
    int accNo; // To store account number
    char name[50]; // To store account holder name
    int pin; // To store account PIN
    float balance; // To store account balance
};
// Function declarations
void createAccount(struct Account *a);
int login(struct Account acc[],int n,int accNo,int pin);
void deposit(struct Account *a);
void withdraw(struct Account *a);
void checkBalance(struct Account a);
void changePin(struct Account *a);
void displayAccount(struct Account a);
void displayAccounts(struct Account a);
void saveToFile(struct Account acc[],int n);
void loadFromFile(struct Account acc[],int *n);
void adminPanel(struct Account acc[], int *n);
void transfer(struct Account acc[], int n, int fromIndex);
int main() // Main function
{
    struct Account acc[100];
    int n = 0,choice,accNo,index;
    int pin;
    loadFromFile(acc, &n); // Load existing account data from file
    while(1) // Infinite loop for ATM operations
    {
        printf("\n~       ATM MENU          ~\n");
        printf("1. Create New Account\n");
        printf("2. Login to Account\n");
        printf("3. Admin Panel\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        if (choice==1) 
        {
            createAccount(&acc[n]);
            n++;
        }
        else if (choice==2) 
        {
            printf("Enter Account Number: ");// To accept account number and pin for verification
            scanf("%d",&accNo);
            printf("Enter PIN: ");
            scanf("%d",&pin);
            index=login(acc,n,accNo,pin);
            if (index==-1) 
            {
                printf("Invalid Login! Try again.\n");
            } 
            else 
            {
                int atmChoice; // To store ATM operation choice
                do 
                {
                    printf("\n~     ATM OPERATIONS      ~\n"); // Display ATM operations menu
                    printf("1. Check Balance\n");
                    printf("2. Deposit Money\n");
                    printf("3. Withdraw Money\n");
                    printf("4. Change PIN\n");
                    printf("5. Display Account Details\n");
                    printf("6. Transfer Money\n");
                    printf("7. Logout\n");
                    printf("Choose an option: ");
                    scanf("%d",&atmChoice);
                    switch (atmChoice) //To accept choice of action from the user
                    {
                        case 1: checkBalance(acc[index]);
                                 break;
                        case 2: deposit(&acc[index]);
                                saveToFile(acc, n); 
                                 break;
                        case 3: withdraw(&acc[index]); 
                                saveToFile(acc, n);
                                 break;
                        case 4: changePin(&acc[index]); 
                                saveToFile(acc, n);
                                 break;
                        case 5: displayAccount(acc[index]); 
                                 break;
                        case 6: transfer(acc, n, index);
                                saveToFile(acc, n);
                                 break;
                        case 7: printf("Logged out.\n");
                                 break;
                        default: printf("Invalid option!\n");
                    }
                } while (atmChoice!=7);
            }
        }
        else if (choice == 3) 
        {
          adminPanel(acc, &n);
          saveToFile(acc, n);
        }
        else if (choice==4) 
        {
            printf("Exiting program...\n");
            saveToFile(acc, n);
            break;
        }
        else 
        {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
void createAccount(struct Account *a) // Function to create new accounts
{
    printf("\n~    Create New Account    ~\n");
    printf("Enter Account Number: ");
    scanf("%d",&(*a).accNo);
    printf("Enter Name: ");
    getchar();
    scanf("%[^\n]", (*a).name); 
    printf("Create PIN: ");
    scanf("%d",&(*a).pin);
    (*a).balance=0;
    printf("Account Created Successfully!\n");
}
int login(struct Account acc[],int n,int accNo,int pin) // Function for user login
{   
    for (int i=0;i<n;i++) 
    {
        if (acc[i].accNo==accNo) 
        { 
            if(acc[i].pin==pin)
            {
            return i;
            }
        }
    }
    return -1;
}
void deposit(struct Account *a) // Function to deposit money
{
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f",&amount);
    (*a).balance=(*a).balance+amount;
    printf("Amount Deposited Successfully!\n");
}
void withdraw(struct Account *a) // Function to withdraw money
{
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f",&amount);
    if (amount>(*a).balance) 
    {
        printf("Insufficient Balance!\n");
    } 
    else 
    {
        (*a).balance=(*a).balance-amount;
        printf("Withdrawal Successful!\n");
    }
}
void checkBalance(struct Account a) // Function to check balance
{
    printf("Current Balance:%.2f\n",a.balance);
}
void changePin(struct Account *a) // Function to change PIN
{
    int newPin;
    printf("Enter New PIN: ");
    scanf("%d",&newPin);
    (*a).pin=newPin;
    printf("PIN Changed Successfully!\n");
}
void displayAccount(struct Account a) // Function to display account details
{
    printf("\n~    Account Details    ~\n");
    printf("Account Number: %d\n",a.accNo);
    printf("Name: %s\n", a.name);
    printf("Balance: %.2f\n",a.balance);
}
void saveToFile(struct Account acc[],int n) // Function to save account data to file 
{
    FILE *fp = fopen("ATM.txt", "w");
      if (fp==NULL)
      {
          return;
      }
     fprintf(fp, "%d ", n);
     for (int i=0;i<n;i++) 
     {
       fprintf(fp, "%d %s %d %.2f\n",acc[i].accNo,acc[i].name,acc[i].pin,acc[i].balance);
     }
     fclose(fp);
}
void loadFromFile(struct Account acc[],int *n) // Function to load account data from file
{
  FILE *fp = fopen("ATM.txt", "r");
   if (fp==NULL) 
   {
      return;
   }
   fscanf(fp, "%d",n);
    for (int i=0;i<*n;i++) 
    {
        fscanf(fp, "%d %s %d %f",&acc[i].accNo,acc[i].name,&acc[i].pin,&acc[i].balance);
    }
    fclose(fp);
}
void displayAccounts(struct Account a) // Function to display all availabe accounts
{
    printf(" %d \t \t %s \t %.2f\n", a.accNo, a.name, a.balance);
}
void transfer(struct Account acc[], int n, int fromIndex) // Function to transfer money between accounts
{
    int toAccNo;
    float amount;
    printf("Enter Account Number to transfer to: ");
    scanf("%d",&toAccNo);  
    int toIndex=-1;
    for(int i=0;i<n;i++)
    {
        if (acc[i].accNo==toAccNo)  // Search receiver account
        {
            toIndex = i;
            break;
        }
    }
    if (toIndex==-1)
    {
        printf("Account Not Found!\n");
        return;
    }
    if (toIndex==fromIndex)
    {
        printf("Cannot transfer to the same account!\n");
        return;
    }
    printf("Enter amount to transfer: ");
    scanf("%f",&amount);
    if (amount>acc[fromIndex].balance)
    {
        printf("Insufficient Balance!\n");
        return;
    }
    acc[fromIndex].balance=acc[fromIndex].balance-amount;
    acc[toIndex].balance=acc[toIndex].balance+amount;
    printf("%.2f Transferred Successfully to Account %d!\n",amount,acc[toIndex].accNo);
}
void adminPanel(struct Account acc[], int *n) // Function for admin panel accesing
{
    char adPass[20];
    printf("Enter Admin Password: ");
    scanf("%s",adPass);
    if(strcmp(adPass,"admin123")!=0)
    {
      return;
    }
    int adChoice; // To store Admin operation choice
    while(1)
    {
    printf("\n~     ADMIN OPERATIONS     ~\n"); // Display Admin operations menu
    printf("1. Show Accounts\n");
    printf("2. Delete Accounts\n");
    printf("3. Logout\n");
    printf("Choose an option: ");
    scanf("%d",&adChoice);
    if(adChoice==1) // Show accounts functionality
    {
       if (*n==0)
       {
           printf("No accounts available.\n");
       }
       else
       {
          printf("\n~   ALL ACCOUNTS    ~\n");
          printf("Account Number \t Name \t Balance\n");
          for (int i=0;i<*n;i++)
          {
              displayAccounts(acc[i]);
          }
       }
    }
    else if(adChoice==2) // Delete account functionality
    {
        int delAcc;
        printf("Enter Account Number to delete: ");
        scanf("%d", &delAcc);
        int found = -1;
        for (int i=0;i<*n;i++)
        {
          if (acc[i].accNo==delAcc)
           {
             found = i;
             break;
           }
        }
        if (found!=-1)
        {
          for (int i=found;i<*n-1;i++)
          {
            acc[i] = acc[i + 1];
          }
          (*n)--;
          printf("Account Deleted.\n");
        }
        else
        {
           printf("Account not found!\n");
        }

    }
    else if(adChoice==3)
    {
        printf("Exiting admin panel...\n");
        saveToFile(acc,*n);
        break;
    }
    else
    {
        printf("Invalid choice! Try again.\n");
    }
   }
}
/*
Variable Descriptions:
1.accNo – Account number of each user.
2.name[50] – Account holder name.
3.pin – PIN number of each account used for authentication.
4.balance – Current balance stored in the user’s account.
5.acc[100] – Array of Account structures used to store details of up to 100 accounts.
6.n – Integer variable that stores the total number of accounts created or loaded from file.
7.choice – Stores the user’s menu selection in the main menu.
8.accNo – Temporarily holds the account number entered during login or deletion.
9.pin – Temporarily holds the PIN entered during login.
10.index – Stores the index of the matching account in the array after successful login.
11.atmChoice – Stores the user’s selected option inside the ATM operations menu.
12.amount – Used during deposit, withdrawal and transfer operations to store the entered transaction amount.
13.newPin – Temporarily stores the new PIN entered by the user when changing the PIN.
14.fp – File pointer used for reading and writing account data to the file.
15.adPass[20] – Stores the password entered for accessing the admin panel.
16.adChoice – Stores the selection inside the admin panel operations menu.
17.delAcc – Temporarily holds the account number entered for deletion in admin mode.
18.found – Tracks the index location of an account to be deleted (or -1 if not found).
19.i – Used as a loop counter when iterating through the account list.
20.toAccNo – Stores the account number to which the logged-in user wants to transfer money.
21.toIndex – Stores the index of the receiver account after searching.
22.fromIndex – Stores the index of the sender (logged-in user).
*/
