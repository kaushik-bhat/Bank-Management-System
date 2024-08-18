# Bank Management System README

Welcome to the Bank Management System project! This C++ application simulates a simple banking system where users can create accounts, manage their funds, and access account details. It also includes an administrative feature that allows admins to view the details of all user accounts.

## Features

- **Account Management:**
  - **Create an Account:** Users can create a new bank account with an initial deposit and a secure password.
  - **Deposit and Withdraw:** Users can deposit and withdraw funds from their accounts after verifying their credentials.
  - **View Account Details:** Users can view their account information, including account number, holder's name, and balance, after logging in.

- **Admin Features:**
  - **Admin Login:** Admins can log in using unique credentials to access additional functionalities.
  - **View All Accounts:** Admins can view the details of all user accounts in the system.

- **Security:**
  - **Password Protection:** User accounts are protected by hashed passwords, ensuring secure access to account operations.
  - **Admin-User Differentiation:** The system differentiates between regular users and admins, granting admins special privileges.

## Project Structure

The project is organized into the following directories and files:

- **include/**: Contains header files.
  - `account.h`: Header file for the Account class.
  - `bank.h`: Header file for the Bank class.
  - `utils.h`: Header file for utility functions.
  
- **src/**: Contains the source code.
  - `account.cpp`: Implementation of the Account class.
  - `bank.cpp`: Implementation of the Bank class.
  - `main.cpp`: The main driver code for the application.
  - `utils.cpp`: Implementation of utility functions.

- **data/**: Contains data files used by the application.
  - `accounts.txt`: Stores account information, including account number, holder's name, and balance.
  - `adminCredentials.txt`: Stores hashed credentials for admin login.
  - `userCredentials.txt`: Stores hashed credentials for user login.

## How to Use

1. **Compile the Project:**
   - Use your preferred C++ compiler to compile the project. Ensure that all source files and headers are correctly linked.

2. **Run the Application:**
   - Execute the compiled binary. The application will prompt you to choose between user and admin operations.

3. **User Operations:**
   - **Create Account:** Enter your name, initial deposit, and password to create an account. You will receive an account number.
   - **Login:** Use your account number and password to access your account. You can deposit, withdraw, or view your account details.

4. **Admin Operations:**
   - **Login:** Use a unique 4-digit admin ID and password to log in. Admins can view all user accounts in the system.

## Admin Credentials

To ensure the security and integrity of the Bank Management System, admin credentials are securely hashed before being stored in the `adminCredentials.txt` file

## Security Notes

- All passwords are hashed before being stored in the system to ensure secure authentication.
- Admin credentials are stored in the `adminCredentials.txt` file, and user credentials are stored in the `userCredentials.txt` file.
- NOTE: A very basic inbuilt hash function in used, better implementations required for a more secure system.

## Future Enhancements

- **Transaction History:** Adding a feature to track and display a history of user transactions.
- **Enhanced Security:** Implementing two-factor authentication for added security.
- **Graphical User Interface:** Creating a GUI for a more user-friendly experience.

## Contributing

Feel free to contribute to the project by submitting pull requests or reporting issues. Your feedback and suggestions are highly appreciated!
