#include <iostream>
#include <vector>
#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phoneNumber)
        : name(name), phoneNumber(phoneNumber) {}

    std::string getName() const {
        return name;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    void displayContact() const {
        std::cout << "Name: " << name << "\tPhone Number: " << phoneNumber << std::endl;
    }

private:
    std::string name;
    std::string phoneNumber;
};

class ContactManager {
public:
    void addContact(const std::string& name, const std::string& phoneNumber) {
        contacts.push_back(Contact(name, phoneNumber));
        std::cout << "Contact added successfully." << std::endl;
    }

    void displayContacts() const {
        if (contacts.empty()) {
            std::cout << "No contacts available." << std::endl;
        } else {
            std::cout << "Contact List:" << std::endl;
            for (const auto& contact : contacts) {
                contact.displayContact();
            }
        }
    }

private:
    std::vector<Contact> contacts;
};

int main() {
    ContactManager contactManager;

    while (true) {
        std::cout << "\nContact Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display Contacts\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phoneNumber;
                std::cout << "Enter name: ";
                std::cin.ignore(); // Clear the newline from the buffer
                std::getline(std::cin, name);

                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);

                contactManager.addContact(name, phoneNumber);
                break;
            }
            case 2:
                contactManager.displayContacts();
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}