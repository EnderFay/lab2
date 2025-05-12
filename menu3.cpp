#include "../include/menu.h"
#include <iostream>
#include <ctime>
#include <algorithm>

Menu::Menu() {
    std::time_t t = std::time(nullptr);
    currentTime = *std::localtime(&t);
    
    std::time_t now = std::time(nullptr);
    std::tm now_tm = *std::localtime(&now);
}

Menu::~Menu() {
}

void Menu::printCurrentTime() const {
    std::cout <<  "\n";
}

void Menu::run() {
    while (true) {
        std::cout << "\n=== RZD Railway Management System ===\n";
        std::cout << "1. Admin login\n";
        std::cout << "2. User menu\n";
        std::cout << "3. Simulate time passing\n";
        std::cout << "4. Exit\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
              
        switch (choice) {
            case 1: adminMenu(); break;
            case 2: userMenu(); break;
            case 3: {
                std::cout << "Enter number of days to simulate: ";
                int days;
                std::cin >> days;
                std::cout << "Time advanced by " << days << " days.\n";
                break;
            }
            case 4: return;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::adminMenu() {
    while (true) {
        std::cout << "\n=== Admin Menu ===\n";
        std::cout << "1. Manage stations\n";
        std::cout << "2. Manage routes\n";
        std::cout << "3. Manage trains\n";
        std::cout << "4. Back to main menu\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
switch (choice) {
            case 1: manageStations(); break;
            case 2: manageRoutes(); break;
            case 3: manageTrains(); break;
            case 5: return;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::manageStations() {
    while (true) {
        std::cout << "\n=== Station Management ===\n";
        std::cout << "1. Add station\n";
        std::cout << "2. Remove station\n";
        std::cout << "3. Edit station\n";
        std::cout << "5. Back\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
       
        if (choice == 5) break;
        
        switch (choice) {
            case 1: {
                std::string name, city;
                std::cout << "Enter station name: ";
                std::getline(std::cin, name);
                std::cout << "Enter city: ";
                std::getline(std::cin, city);
                
                int newId = 1;
                if (!db.getAllStations().empty()) {
                    newId = db.getAllStations().back().getId() + 1;
                }
                      std::cout << "Station added successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Enter station ID to remove: ";
                int id;
                std::cin >> id;
                std::cout << "Station removed if it existed.\n";
                break;
            }
            case 3: {
                std::cout << "Enter station ID to edit: ";
                int id;
                std::cin >> id;
                      
                std::string name, city;
                std::cout << "Enter new name: ";
                std::getline(std::cin, name);
                std::cout << "Enter new city: ";
                std::getline(std::cin, city);
                
                std::cout << "Station updated if it existed.\n";
                break;
            }
                default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::manageRoutes() {
    while (true) {
        std::cout << "\n=== Route Management ===\n";
        std::cout << "1. Add route\n";
        std::cout << "2. Remove route\n";
        std::cout << "3. Edit route\n";
      std::cout << "5. Back\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
         
        if (choice == 5) break;
        
        switch (choice) {
            case 1: {
          
                std::string name;
                std::cout << "Enter route name: ";
                std::getline(std::cin, name);
                
                int depId, arrId;
                std::cout << "Enter departure station ID: ";
                std::cin >> depId;
                std::cout << "Enter arrival station ID: ";
                std::cin >> arrId;
                
                std::vector<int> intermediate;
                std::cout << "Enter intermediate station IDs (space separated, -1 to finish): ";
                int id;
                while (std::cin >> id && id != -1) {
                    intermediate.push_back(id);
                }
                std::cin.clear();
                
                double distance;
                std::cout << "Enter distance in km: ";
                std::cin >> distance;
                
                int newId = 1;
                if (!db.getAllRoutes().empty()) {
                    newId = db.getAllRoutes().back().getId() + 1;
                }
                      std::cout << "Route added successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Enter route ID to remove: ";
                int id;
                std::cin >> id;
                std::cout << "Route removed if it existed.\n";
               break;
            }
            case 3: {
        
                std::cout << "Enter route ID to edit: ";
                int id;
                std::cin >> id;
                std::string name;
                std::cout << "Enter new name: ";
                std::getline(std::cin, name);
                
                double distance;
                std::cout << "Enter new distance: ";
                std::cin >> distance;
                
                std::cout << "Route updated if it existed.\n";
                break;
            }
        
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::manageTrains() {
    while (true) {
        std::cout << "\n=== Train Management ===\n";
        std::cout << "1. Add train\n";
        std::cout << "2. Remove train\n";
        std::cout << "3. Edit train\n";
        std::cout << "5. Back\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
         
        switch (choice) {
            case 1: {
                std::string number;
                std::cout << "Enter train number: ";
                std::getline(std::cin, number);
                
                int routeId, totalSeats;
                std::cout << "Enter route ID: ";
                std::cin >> routeId;
                std::cout << "Enter total seats: ";
                std::cin >> totalSeats;
                
                std::tm depTime = getDateTimeInput("Enter departure time");
                std::tm arrTime = getDateTimeInput("Enter arrival time");
                
                int newId = 1;
                if (!db.getAllTrains().empty()) {
                    newId = db.getAllTrains().back().getId() + 1;
                }
        
                std::cout << "Train added successfully.\n";
                break;
            }
            case 2: {
        
                std::cout << "Enter train ID to remove: ";
                int id;
                std::cin >> id;
        
                std::cout << "Train removed if it existed.\n";
                break;
            }
            case 3: {
        
                std::cout << "Enter train ID to edit: ";
                int id;
                std::cin >> id;
        
                
                std::string number;
                std::cout << "Enter new train number: ";
                std::getline(std::cin, number);
                
                int totalSeats;
                std::cout << "Enter new total seats: ";
                std::cin >> totalSeats;
                
        
                std::cout << "Train updated if it existed.\n";
                break;
            }
        
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::viewTickets() {
    }

void Menu::userMenu() {
    while (true) {
        std::cout << "\n=== User Menu ===\n";
        std::cout << "1. Buy ticket\n";
        std::cout << "2. Return ticket\n";
        std::cout << "4. Back to main menu\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
    
        
        switch (choice) {
            case 1: buyTicket(); break;
            case 2: returnTicket(); break;
    
            case 4: return;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void Menu::buyTicket() {
    
    
    int fromId, toId;
    std::cout << "Enter departure station ID: ";
    std::cin >> fromId;
    std::cout << "Enter arrival station ID: ";
    std::cin >> toId;
    
    
    std::vector<Train*> availableTrains;
    for (auto& train : const_cast<std::vector<Train>&>(db.getAllTrains())) {
        const Route* route = db.findRoute(train.getRouteId());
        if (!route) continue;
        
        const std::vector<int>& intermediate = route->getIntermediateStations();
        
        if ((route->getDepartureStationId() == fromId && 
             route->getArrivalStationId() == toId) ||
            (std::find(intermediate.begin(), intermediate.end(), fromId) != intermediate.end() &&
             std::find(intermediate.begin(), intermediate.end(), toId) != intermediate.end())) {
            
        
    if (availableTrains.empty()) {
        std::cout << "No available trains for this route.\n";
        return;
    }
    
    std::cout << "\nAvailable trains:\n";
    for (size_t i = 0; i < availableTrains.size(); ++i) {
        if (const Route* route = db.findRoute(availableTrains[i]->getRouteId())) {
            std::cout << i+1 << ". ";
            std::cout << "-----------------\n";
        }
    }
    
    std::cout << "Select train (1-" << availableTrains.size() << "): ";
    size_t selection;
    std::cin >> selection;
    
    
    if (selection < 1 || selection > availableTrains.size()) {
        std::cout << "Invalid selection.\n";
        return;
    }
    
    Train* selectedTrain = availableTrains[selection-1];
    
    std::string name, passport, contact;
    std::cout << "Enter passenger name: ";
    std::getline(std::cin, name);
    std::cout << "Enter passport number: ";
    std::getline(std::cin, passport);
    std::cout << "Enter contact info: ";
    std::getline(std::cin, contact);
    
    Passenger passenger(name, passport, contact);
    
    
    double price = 0;
    if (const Route* route = db.findRoute(selectedTrain->getRouteId())) {
        price = route->getDistance() * 2.5; // 2.5 RUB per km
    }
    
    int newId = 1;
    if (!db.getAllTickets().empty()) {
        newId = db.getAllTickets().back().getId() + 1;
    }
    
      std::cout << "Ticket purchased successfully for " << price << " RUB\n";
   
void Menu::returnTicket() {
       std::cout << "This function doesn't work.\n";
}

void Menu::viewSchedule() {
   }

std::tm Menu::getDateTimeInput(const std::string& prompt) const {
    std::tm time = currentTime;
    }
