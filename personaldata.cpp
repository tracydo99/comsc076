#include <iostream>
#include <string>

class PersonData {
private:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;

public:
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getAddress() const { return address; }
    std::string getCity() const { return city; }
    std::string getState() const { return state; }
    std::string getZip() const { return zip; }
    std::string getPhone() const { return phone; }

    void setLastName(const std::string &lname) { lastName = lname; }
    void setFirstName(const std::string &fname) { firstName = fname; }
    void setAddress(const std::string &addr) { address = addr; }
    void setCity(const std::string &c) { city = c; }
    void setState(const std::string &s) { state = s; }
    void setZip(const std::string &z) { zip = z; }
    void setPhone(const std::string &p) { phone = p; }
};

void inputPersonData(PersonData &person) {
    std::string input;

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    person.setLastName(input);

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    person.setFirstName(input);

    std::cout << "Enter address: ";
    std::getline(std::cin, input);
    person.setAddress(input);

    std::cout << "Enter city: ";
    std::getline(std::cin, input);
    person.setCity(input);

    std::cout << "Enter state: ";
    std::getline(std::cin, input);
    person.setState(input);

    std::cout << "Enter zip: ";
    std::getline(std::cin, input);
    person.setZip(input);

    std::cout << "Enter phone: ";
    std::getline(std::cin, input);
    person.setPhone(input);
}

void displayPersonData(const PersonData &person) {
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Address: " << person.getAddress() << std::endl;
    std::cout << "City: " << person.getCity() << std::endl;
    std::cout << "State: " << person.getState() << std::endl;
    std::cout << "ZIP: " << person.getZip() << std::endl;
    std::cout << "Phone: " << person.getPhone() << std::endl;
}

int main() {
    PersonData person;

    // Input data
    inputPersonData(person);

    // Display data
    displayPersonData(person);

    return 0;
}
