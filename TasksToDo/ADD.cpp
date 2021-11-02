#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <vector>

int ADD() {

    //Actual aate
    auto Time = std::chrono::system_clock::now();
    std::time_t Read_time = std::chrono::system_clock::to_time_t(Time);
    std::string time_str = std::ctime(&Read_time);

    //Gets actual content
    std::string new_task;
    std::string whole;
    std::string line;
    std::ifstream tasks;
    tasks.open("tasks.txt");
    if (tasks.is_open()) {
        while (std::getline(tasks, line)) {
            whole+=line + '\n';
        }
    }

    //Inputs type of task for "tasks.txt"
    std::string type_of_task;
    std::cout << "Types of task :\ndow - day of week\ndoe - day of event\nYour input : ";
    std::cin >> type_of_task;
    if(type_of_task == "dow") {}
    else if(type_of_task == "doe") {
        new_task+=type_of_task;
    }
    else {
        exit(1);
    }

    //Inputs type of task for "tasks.txt"
    if(type_of_task == "dow") {
        std::string day;
        std::cout << "*Note: Start with uppercase and wrtite only 3 letters.\nDay of week : ";
        std::cin >> day;

        //Checks if input is right
        if( day=="Mon" || day=="Tue" || day=="Wed" || day=="Thu" || day=="Fri" || day=="Sat" || day=="Sun" ) {
            std::string task;
            std::cout << "Task : ";
            std::cin >> task;
            task+=", ";

            //Adds task to existing day in database
            whole.insert(whole.find(day)+4, task);
        }
        else {
            exit(1);
        }
    }
    else if(type_of_task == "doe") {
        std::string month;
        std::cout << "*Note: Start with uppercase and wrtite only 3 letters.\nMonth : ";
        std::cin >> month;

        //Checks if input is right
        if( month!="Jan" && month!="Feb" && month!="Mar" && month!="Apr" && month!="May" && month!="Jun" && 
            month!="Jul" && month!="Aug" && month!="Sep" && month!="Oct" && month!="Nov" && month!="Dec" ) {
                exit(1);
        }

        std::string day;
        std::cout << "*Note: Write 0 if number is smaller than 10.\nDay : ";
        std::cin >> day;

        //Checks if input is right
        if(month == "Jan" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }
        if(month == "Feb" && std::stoi(time_str.substr(20, 4)) % 4 == 0) {
            if(std::stoi(day) <! 0 && std::stoi(day) >! 29) {
                exit(1);
            }
        }
        else if(month == "Feb" && std::stoi(day) <! 0 && std::stoi(day) >! 28) {
            exit(1);
        }
        if(month == "Mar" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }
        if(month == "Apr" && std::stoi(day) <! 0 && std::stoi(day) >! 30) {
            exit(1);
        }
        if(month == "May" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }
        if(month == "Jun" && std::stoi(day) <! 0 && std::stoi(day) >! 30) {
            exit(1);
        }
        if(month == "Jul" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }
        if(month == "Aug" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }
        if(month == "Sep" && std::stoi(day) <! 0 && std::stoi(day) >! 30) {
            exit(1);
        }
        if(month == "Oct" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }
        if(month == "Nov" && std::stoi(day) <! 0 && std::stoi(day) >! 30) {
            exit(1);
        }
        if(month == "Dec" && std::stoi(day) <! 0 && std::stoi(day) >! 31) {
            exit(1);
        }

        std::string year;
        std::cout << "Year : ";
        std::cin >> year;

        //Checks if input is right
        if(std::stoi(year) < std::stoi(time_str.substr(20, 4))) {
            exit(1);
        }

        std::string task;
        std::cout << "Task : ";
        std::cin >> task;

        //Joins it all to database
        new_task+=" ";
        new_task+=month;
        new_task+=" ";
        new_task+=day;
        new_task+=" ";
        new_task+=year;
        new_task+=" ";
        new_task+=task;
        whole+=new_task;
    }

    //Passes it to tasks.txt
    std::ofstream File;
    File.open("tasks.txt");
    File << whole;
    File.close();

    //Waits till user hits the button
    std::getchar();
    return 0;
}