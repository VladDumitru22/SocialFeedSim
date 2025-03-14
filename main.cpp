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

        int get_ID(){
            return this->ID;
        }

        void displayUser() const {
            std::cout << "ID: " << ID << ", Name: " << name 
                      << ", Date of Birth: " << Y << "-" << M << "-" << D << std::endl;
        }
};

bool isLeapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return true;
    }else{
        return false;
    }
}

class Website{
    private:
        int users_count;
        std::vector<User> users;
    public:
        Website(int temp_users_count, std::vector<User> temp_users)
            : users_count(temp_users_count), users(std::move(temp_users)) {}

        void isValidDate() {
            for(int i=0; i<users_count; i++){

                if (users[i].get_year() < 1900 || users[i].get_year() > 2025 || users[i].get_month() < 1 ||
                    users[i].get_month() > 12 || users[i].get_day() < 1) {
                    std::cout << "ID: " << users[i].get_ID() << " ERROR: Date of birth is Invalid\n";
                    continue;
                }
        
                std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
                if (isLeapYear(users[i].get_year())) {
                    daysInMonth[1] = 29;
                }
        
                if (users[i].get_day() > daysInMonth[users[i].get_month() - 1]) {
                    std::cout << "ID: " << users[i].get_ID() << " ERROR: Date of birth is Invalid\n";
                } else {
                    std::cout << "ID: " << users[i].get_ID() << " Date of birth is Valid: " 
                            << users[i].get_year() << "-" << users[i].get_month() << "-" << users[i].get_day() << "\n";
                }
            }
        }
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

    Website site(temp_users_count, users);

    int option;
    do {
        std::cout << "\nSelect an Option:\n";
        std::cout << "1. User Info\n";
        std::cout << "2. Date of birth Validation\n";
        std::cout << "0. Exit\n";
        std::cout << "Option: ";
        std::cin >> option;

        switch(option){
            case 1:
                std::cout << "\nRegistered Users:\n";
                for (int i=0; i < users.size(); i++){
                    users[i].displayUser();
                }
                break;
            
            case 2:
                std::cout << "\nUsers:\n";
                site.isValidDate();

                break;

            case 0:
                std::cout << "Exiting...\n";
                break;

            default: std::cout << "Invalid Input!\n" << std::endl;
        }

    } while (option != 0);

}