# SocialFeedSim

## Description
This is a C++ console-based application that allows users to register with their name and date of birth. The program then validates the date of birth, determines whether users are adults or minors, and provides various functionalities related to user information.

## Features
- Register users with name and date of birth.
- Validate the entered date of birth.
- Display all registered users.
- Identify and display adult users (18+ years old).
- Identify and display minor users (under 18 years old).

## Technologies Used
- C++ Standard Library (iostream, string, vector, ctime)

## How to Run
1. Clone the repository:
   ```bash
   git clone <repository_url>
   ```
2. Navigate to the project directory:
   ```bash
   cd <repository_name>
   ```
3. Compile the program using g++:
   ```bash
   g++ -o user_management main.cpp
   ```
4. Run the executable:
   ```bash
   ./user_management
   ```

## Usage
1. Enter the number of users to register.
2. Input user details (name and date of birth in YYYY MM DD format).
3. Choose an option from the menu:
   - **1:** Display all registered users.
   - **2:** Validate user birthdates.
   - **3:** Display adult users.
   - **4:** Display minor users.
   - **0:** Exit the program.

## Example Output
```
Enter the number of users: 2
User's Name: John Doe
Date of birth (YYYY MM DD): 2000 05 15
User's Name: Jane Smith
Date of birth (YYYY MM DD): 2010 08 22

Select an Option:
1. User Info
2. Date of birth Validation
3. Display Adults
4. Display Minors
0. Exit
Option: 3

Adults:
ID: 1, Name: John Doe, Age: 24
```

## Author
Developed by Dumitru Vlad-Mihai

