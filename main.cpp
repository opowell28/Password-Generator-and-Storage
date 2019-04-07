#include <iostream>
#include <vector>
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

//function to change input to all upper case
std::string inputToUpper(std::string lowercaseInput) {

    std::transform(lowercaseInput.begin(), lowercaseInput.end(), lowercaseInput.begin(), ::toupper);

    return lowercaseInput;
}

int main() {

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "----Welcome to the password generator----" << std::endl;
    std::cout << "------Please select an option below------" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << " Generate " << std::endl;
    std::cout << " Store " << std::endl;

    std::string userInput;

    getline(std::cin, userInput);

    //change userInput to all uppercase for reduced possibility of missing an input option
    userInput = inputToUpper(userInput);

    if (userInput == "GENERATE") {
        //ask for password length and generate here
    }

    if (userInput == "STORE") {
        //save passwords in vector here
    }

    return 0;
}