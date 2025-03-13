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

        int get_year(){
            return this->Y;
        }
        
        int get_month(){
            return this->M;
        }
        
        int get_day(){
            return this->D;
        }

        void displayUser() const {
            std::cout << "ID: " << ID << ", Name: " << name 
                      << ", Date of Birth: " << Y << "-" << M << "-" << D << std::endl;
        }
};

class Website{
    private:
        int users_count;
        std::vector<User> users;
    public:
        Website(int temp_users_count, std::vector<User> temp_users)
            : users_count(temp_users_count), users(std::move(temp_users)) {}
};

int User::ID_count = 0;

int main(){

    int temp_users_count;
    std::vector<User> users;
    
    std::cout << "Enter the number of users: ";
    std::cin >> temp_users_count;
    std::cin.ignore();

    for (int i = 0; i < temp_users_count; i++) {
        std::string temp_name;
        int temp_Y, temp_M, temp_D;
        
        std::cout << "User's Name: ";
        std::getline(std::cin, temp_name);
        std::cout << "Date of birth (YYYY MM DD): ";
        std::cin >> temp_Y >> temp_M >> temp_D;
        std::cin.ignore();
        
        users.emplace_back(temp_name, temp_Y, temp_M, temp_D);
    }

    int option;
    do {
        std::cout << "\nSelect an Option:\n";
        std::cout << "1. User Info\n";
        std::cout << "0. Exit\n";
        std::cout << "Option: ";
        std::cin >> option;

        switch(option){
            case 1:
                std::cout << "\nRegistered Users:\n";
                for(int i=0; i < users.size(); i++){
                    users[i].displayUser();
                }
                break;
            
            

                

            case 0:
                std::cout << "Exiting...\n";
                break;

            default: std::cout << "Invalid Input!\n" << std::endl;
        }

    } while (option != 0);

}