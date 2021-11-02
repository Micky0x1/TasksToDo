#include <iostream>
#include <string>
#include "SHOWTASKS.cpp"
#include "ADD.cpp"

int main() {

    //Asks what do you want to do
    std::string a = "Enter ";
    a+=char(34);
    a+="add";
    a+=char(34);
    a+=" to add Task or ";
    a+=char(34);
    a+="show";
    a+=char(34);
    a+=" to show Tasks.";
    std::cout << a;
    std::string input;
    std::cout << '\n' << "Input : ";
    std::cin >> input;

    if(input == "add") {
        std::cout << '\n';

        //"ADD.cpp"
        ADD();
    }
    else if(input == "show") {
        std::cout << '\n';

        //"SHOWTASKS.cpp"
        ShowTasks();
    }

    return 0;
}