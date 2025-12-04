ATM Simulation Project in C

A File-Based Banking System with Admin Panel

📌 Overview

This project is a console-based ATM Simulation System written in C, developed using VS Code and compiled with MinGW (GCC).
It demonstrates key programming concepts such as:

Structures

Pointers

File handling

Functions

User authentication

Modular programming

The system allows users to create accounts, log in, and perform banking operations. It also includes a password-protected Admin Panel to manage all accounts.

🚀 Features
👤 User Features

After logging into an existing account, users can:

✔ Check account balance

✔ Deposit money

✔ Withdraw money

✔ Transfer money to another account

✔ View full account details

📝 Account Management

✔ Create a new user account

✔ Login using Account Number + Password

✔ Accounts stored permanently using files (no database required)

🔐 Admin Panel

Password-protected admin dashboard with abilities to:

✔ View all registered accounts

✔ Delete any account

✔ Reload data from files automatically at startup

⚙️ Technologies Used

Component                    	Description
Language	                    C
Compiler	                    MinGW (GCC)
IDE/Editor	                  Visual Studio Code
Storage	                      File Handling (Binary/Text)
Concepts Used	                Structures, Pointers, Functions, File I/O, Conditionals

🧱 Project Workflow

🔸 1. User Registration

Enter Name

Set Password

System auto-assigns account number

Account saved in accounts.dat

🔸 2. User Login

Validate account number + password

Load user structure from file

Redirect to the ATM menu

🔸 3. ATM Menu Options

Check Balance

Deposit

Withdraw

Transfer Money

Display Account Details

Log Out

🔸 4. Admin Panel

Protected with an Admin Password (e.g. "admin123").

Admin can:

View full list of all accounts

Delete accounts by account number

View total number of users

📘 Concepts Demonstrated
✔ Structures

Used to store all user information.

✔ Pointers

Used for dynamic access & passing structures to functions.

✔ File Handling

Used to save & load account details:

fread(), fwrite()

FILE* pointers

Handling binary/text data

✔ Modular Programming

Clean separation of:

Admin functions

Account functions

File operations

Main menu

Utility helper functions

🔒 Security Features

Password-based login

Password-protected admin panel

File-based persistence

Input validation to prevent crashes

