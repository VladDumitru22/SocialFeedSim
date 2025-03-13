#include <iostream>
#include <string>
#include <vector>

class User{
    private:
        std::string name;
        int ID, Y, M, D;
        static int ID_count;
    public:
        User(std::string temp_name, int temp_Y, int temp_M, int temp_D) {
            this->name = temp_name;
            this->Y = temp_Y;
            this->M = temp_M;
            this->D = temp_D;
            this->ID = ++ID_count;
        }

        void displayUser() const {
            std::cout << "ID: " << ID << ", Name: " << name 
                      << ", Date of Birth: " << Y << "-" << M << "-" << D << std::endl;
        }
};

int User::ID_count = 0;

int main(){

    int users_count;
    std::vector<User> users;
    
    std::cout << "Enter the number of users: ";
    std::cin >> users_count;
    std::cin.ignore();

    for (int i = 0; i < users_count; i++) {
        std::string temp_name;
        int temp_Y, temp_M, temp_D;
        
        std::cout << "User's Name: ";
        std::getline(std::cin, temp_name);
        std::cout << "Date of birth (YYYY MM DD): ";
        std::cin >> temp_Y >> temp_M >> temp_D;
        std::cin.ignore();
        
        users.emplace_back(temp_name, temp_Y, temp_M, temp_D);
    }
    
    std::cout << "\nRegistered Users:\n";
    for (size_t i = 0; i < users.size(); i++) {
        users[i].displayUser();
    }



    return 0;
}