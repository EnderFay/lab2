#ifndef MENU_H
#define MENU_H

#include "database.h"

class Menu {
private:
    Database db;
    std::tm currentTime;
    
    void printCurrentTime() const;
    void adminMenu();
    void userMenu();

    void manageStations();
    void manageRoutes();
    void manageTrains();
    void viewTickets();

    void buyTicket();
    void returnTicket();
    void viewSchedule();

    std::tm getDateTimeInput(const std::string& prompt) const;
    void displayTrainSchedule(const Train& train, const Route& route) const;
    
public:
    Menu();
    ~Menu();
    void run();
};

#endif // MENU_H
