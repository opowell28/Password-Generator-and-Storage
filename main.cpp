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
        int passLength = 0;
        std::cout << "How long do you want your password to be? " << std::endl;
        std::cin >> passLength;

        std::string chars(
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "!@#$%^&*"
                "`-_,./'|[]{}");
        boost::random::random_device rng;
        boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);
        for (int i = 0; i < passLength; ++i) {
            std::cout << chars[index_dist(rng)];
        }
        std::cout << std::endl;
    }

    if (userInput == "STORE") {
        //save passwords in vector here
    }

    return 0;
}