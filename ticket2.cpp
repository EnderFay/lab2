#include "../include/ticket.h"
#include <iostream>

Ticket::Ticket(int id, int trainId, const Passenger& passenger, 
               const std::tm& bookingTime, double price)
    : id(id), trainId(trainId), passenger(passenger), 
       price(price) {}

int Ticket::getId() const { return id; }
int Ticket::getTrainId() const { return trainId; }
Passenger Ticket::getPassenger() const { return passenger; }

double Ticket::getPrice() const { return price; }


void Ticket::displayInfo() const {
    std::cout << "Ticket ID: " << id << "\n";
    std::cout << "Train: "  << "\n";
    passenger.displayInfo();
    std::cout << "Price: " << price << " RUB\n";

}
