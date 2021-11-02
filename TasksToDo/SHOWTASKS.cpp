#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

int ShowTasks() {
    
    //Gets date
    auto TIME = std::chrono::system_clock::now();
    std::time_t read_time = std::chrono::system_clock::to_time_t(TIME);
    std::string time_str = std::ctime(&read_time);

    //Separates date
    std::string day_of_week = time_str.substr(0, 3);
    std::string month = time_str.substr(4, 3);
    std::string day = time_str.substr(8, 2);
    std::string year = time_str.substr(20, 4);

    //Reads document
    std::string line;
    std::ifstream tasks;
    tasks.open("tasks.txt");
    if (tasks.is_open()) {
        while (std::getline(tasks, line)) {
            if(line.substr(0, 3) == "dow") {            //Checks if it is the day of week
                if(line.substr(4, 3) == day_of_week) {
                    std::cout << "Todays tasks : " << line.substr(8, sizeof(line)+30);
                }
            }
            if(line.substr(0, 3) == "doe") {            //Checks if it is the day of event
                if(line.substr(4, 3)==month && line.substr(8, 2)==day && line.substr(11, 4)==year) {
                    std::cout << '\n' << "Events :" << line.substr(15, sizeof(line)+30);
                }
            }
        }

        std::getchar();
        tasks.close();
    }

    //Waits till user hits the button
    std::getchar();
    return 0;
}