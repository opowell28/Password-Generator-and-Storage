#include <iostream>
#include <vector>
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

//function to change input to all upper case
std::string inputToUpper(std::string lowercaseInput) {

    std::transform(lowercaseInput.begin(), lowercaseInput.end(), lowercaseInput.begin(), ::toupper);

    return lowercaseInput;
}

//function which displays the main menu and takes input
void mainMenu(std::string &menuSelection) {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "----Welcome to the password generator----" << std::endl;
    std::cout << "------Please select an option below------" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "1. Generate " << std::endl;
    std::cout << "2. Store " << std::endl;
    std::cout << "3. Retrieve " << std::endl;
    std::cout << "4. Exit " << std::endl;

    //take input for menu selections
    std::cin >> menuSelection;
}

int main() {

    //variable to take user menu selection
    std::string menuInput;

    //display the main menu
    mainMenu(menuInput);

    //vector to store passwords
    std::vector<std::string> passwordVec;

    //change userInput to all uppercase to reduce possibility of missing an input option
    menuInput = inputToUpper(menuInput);

    while (menuInput != "EXIT" || menuInput != "4" || menuInput != "4.") {

        //generate a random password
        if (menuInput == "GENERATE" || menuInput == "1" || menuInput == "1.") {
            //variable to store desired password length
            int passLength = 0;
            std::cout << "How long do you want your password to be? " << std::endl;
            std::cin >> passLength;

            //all chars that can be selected for a password
            std::string chars(
                    "abcdefghijklmnopqrstuvwxyz"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "!@#$%^&*"
                    "`-_,./'|[]{}");

            //create device to get random characters
            boost::random::random_device rng;
            boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);

            std::cout << "Here is your password: " << std::endl;
            //output the randomized characters
            for (int i = 0; i < passLength; ++i) {
                std::cout << chars[index_dist(rng)];
            }
            std::cout << std::endl;
            //return to the main menu
            mainMenu(menuInput);
        }

            //allow user to store passwords
        else if (menuInput == "STORE" || menuInput == "2" || menuInput == "2.") {
            std::string savePass;
            std::cout << "Enter the password you would like to store: " << std::endl;
            std::cin >> savePass;

            //store saved passwords in a vector
            passwordVec.push_back(savePass);
            mainMenu(menuInput);
        }

            //retrieve all stored passwords
        else if (menuInput == "RETRIEVE" || menuInput == "3" || menuInput == "3.") {
            int i = 0;
            std::cout << "Here are all your current stored passwords: " << std::endl;
            //output each password currently stored in the vector
            for (std::string s : passwordVec) {
                i++;
                std::cout << i << ". " << s << std::endl;
            }
            mainMenu(menuInput);

        }

        //exit the program here
        else if (menuInput == "EXIT" || menuInput == "4" || menuInput == "4.") {
            return 0;
        } else {
            std::cout << "Please enter a valid menu option. " << std::endl;
            mainMenu(menuInput);
        }
    }
}