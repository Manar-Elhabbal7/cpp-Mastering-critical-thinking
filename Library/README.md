⁘Library Management System in C++
Introduction
This project aims to develop a basic console-based library management system using C++. The system allows an administrator to manage books and users, providing functionalities like adding books, searching for books, borrowing, and returning books.

## Main Features
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
### Book Management

1. *Add a Book*:
   - Each book is identified by an ID, name, and quantity.
   - Example: ID: 101, Name: CppHowToProgram, Quantity: 7.

2. *Search for a Book*:
   - Books can be searched using a prefix of their name.
   - Example:
     - Query: Cpp ⇒ Results: CppHowToProgram, CppForDummies, CppForAdvancedLevels
     - Query: Java ⇒ Results: None (if no book names start with "Java").

3. *List All Books*:
   - Display all books, sorted by either their ID or name.
   - Example:
     - Sorted by Name: ArabicLiterature, Math1, Math2
     - Sorted by ID: Math2 (1011), Math1 (1111), ArabicLiterature (5041)

4. *List Borrowers of a Book*:
   - Input: Book Name
   - Output: List of users who have borrowed .
   - Example: For Math1, the output might be Mostafa, John, Mark, Ali.

### User Management

1. *Add a User*:
   - Each user has an ID and name.
   - Optionally, additional  like  and address can be included.

2. *Borrow a Book*:
   - The admin inputs the user name and book name.
   - If  is available (quantity > 0), the system records the borrowing and decreases the quantity by 1.
   - If no copies are available, the admin is notified.

3. *Return a Book*:
   - The system records the return of  by the user and increases the quantity by 1.

4. *Additional User Operations*:
   - List users in the system, sortable by name or ID.
   - List books borrowed by a specific user.

## How It Works

1. *Main Menu*:
   - The system displays  with all available options.
   - The admin selects an option to perform the desired operation and then returns to the main menu.

## Getting Started

### Requirements

- A C++ compiler
- Basic understanding of C++ programming
- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
- Acknowledgments

- Inspired by traditional library management systems.
- Special thanks to Mostafa S. Ibrahim for his guidance and project inspiration.
