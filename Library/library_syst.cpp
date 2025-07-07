#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//global variables
int book_count = 0;
int user_count = 0;
int borrow_count = 0;

struct book
{
    int id;
    string name;
    int quantity;
    string category;
};

struct user
{
    int id;
    string name;
};

struct userborrow
{
    int user_id;
    string book_name;
};

book books[100];
user users[100];
userborrow borrows[100];

int menu()
{
    int choice = -1;
    cout << "Library menu \n";//done
    cout << "1) Add a new book\n";//done
    cout << "2) Search books by prefix\n";//done
    cout << "3) Print who borrowed books by name\n";//done
    cout << "4) Print library by ID\n";//done
    cout << "5) Print library by name\n";//done
    cout << "6) Print books by categories\n";//done
    cout << "7) Add a user\n";//done
    cout << "8) User borrow book\n";//done
    cout << "9) User return book\n";//done
    cout << "10) Print users\n";//done
    cout << "11) Exit\n";//done
    cout << "Enter your choice [1-11]: ";
    cin >> choice;
    if (choice > 11 || choice < 1) {
        cout << "Invalid choice, try again.\n";
        choice = -1;
    }
    return choice;
}

void add_book()
{
    cout << "Enter book ID, book name, quantity, category: ";
    cin >> books[book_count].id >> books[book_count].name >> books[book_count].quantity >> books[book_count].category;
    book_count++;
}

void print_all_books()
{
    cout << "Books in the library by categories:\n";
    for (int i = 0; i < book_count; i++) {
        cout << i + 1 << ") " << books[i].name << " (" << books[i].category << ")\n";
    }
}

void search_books()
{
    string prefix;
    cout << "Enter the prefix of the book: ";
    cin >> prefix;

    for (int i = 0; i < book_count; i++)
    {
        if (books[i].name.find(prefix) == 0)
        {
            cout << books[i].name << endl;
        }
    }
}

bool compare_by_id(const book& b1, const book& b2)
{
    return b1.id < b2.id;
}

bool compare_by_name(const book& b1, const book& b2)
{
    return b1.name < b2.name;
}

void print_by_id()
{
    sort(books, books + book_count, compare_by_id);
    for (int i = 0; i < book_count; i++)
    {
        cout << "ID: " << books[i].id << " Name: " << books[i].name << " Quantity: " << books[i].quantity << endl;
    }
}

void print_by_name()
{
    sort(books, books + book_count, compare_by_name);
    for (int i = 0; i < book_count; i++)
    {
        cout << books[i].name << endl;
    }
}

void add_user()
{
    cout << "Enter user name and ID: ";
    cin >> users[user_count].name >> users[user_count].id;
    user_count++;
}

void user_borrow()
{
    int user_id;
    string book_name;
    cout << "Enter user ID and book name: ";
    cin >> user_id >> book_name;

    // Check if book is available
    for (int i = 0; i < book_count; i++)
    {
        if (books[i].name == book_name && books[i].quantity > 0) 
        {
            borrows[borrow_count].user_id = user_id;
            borrows[borrow_count].book_name = book_name;
            books[i].quantity--; // Decrease the book quantity
            borrow_count++;
            cout << "Book borrowed successfully. Happy to see you .\n";
            return;
        }
    }
    cout << "Book not available.\n";
}

void user_return()
{
    int user_id;
    string book_name;
    cout << "Enter user ID and book name to return: ";
    cin >> user_id >> book_name;

    // Check if user has borrowed the book
    for (int i = 0; i < borrow_count; i++)
    {
        if (borrows[i].user_id == user_id && borrows[i].book_name == book_name)
        {
            borrows[i] = borrows[borrow_count - 1]; // Remove borrow record by swapping with the last record
            borrow_count--;

            // Increase the book quantity
            for (int j = 0; j < book_count; j++)
            {
                if (books[j].name == book_name)
                {
                    books[j].quantity++;
                    break;
                }
            }
            cout << "Book returned successfully.Thanks for your responsibility \n";
            return;
        }
    }
    cout << "Book not found in borrow records.\n";
}

void print_who_borrowed()
{
    for (int i = 0; i < borrow_count; i++)
    {
        cout << "User ID: " << borrows[i].user_id << " borrowed book: " << borrows[i].book_name << endl;
    }
}

void print_users()
{
    for (int i = 0; i < user_count; i++)
    {
        cout << "User ID: " << users[i].id << " Name: " << users[i].name << endl;
    }
}

void library()
{
    while (true)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            add_book();
            break;
        case 2:
            search_books();
            break;
        case 3:
            print_who_borrowed();
            break;
        case 4:
            print_by_id();
            break;
        case 5:
            print_by_name();
            break;
        case 6:
            print_all_books();
            break;
        case 7:
            add_user();
            break;
        case 8:
            user_borrow();
            break;
        case 9:
            user_return();
            break;
        case 10:
            print_users();
            break;
        case 11:
            return;
        }
    }
}

int main()
{
    //practice makes perfect
    //done -> 30/7/2024
    library();
    return 0;
}
