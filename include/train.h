#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <ctime>
#include <vector>
#include "route.h"
using namespace std;
enum class TrainStatus {
    SCHEDULED,
    DEPARTED,
    ARRIVED,
    LOST,       
    EXPLODED    
};
class Train {
public:
    int trainNumber;
    int capacity;   

   string currentStation;
    string destination;
    chrono::system_clock::time_point departureTime;
    string origin;
    chrono::system_clock::duration travelDuration;
    TrainStatus status;
    vector<Ticket> tickets;
    double speed;           
    double distanceTraveled; 

   
    Train(int trainNumber = -1, int capacity = -1, const string& origin = "", const string& destination = "",
        const chrono::system_clock::time_point& departureTime = chrono::system_clock::time_point(),
        const chrono::system_clock::duration& travelDuration = chrono::system_clock::duration(),
        double speed = NAN)  
    {
       
        this->trainNumber = trainNumber;
        this->capacity = capacity;
        this->origin = origin;
        this->destination = destination;
        this->departureTime = departureTime;
        this->travelDuration = travelDuration;
        this->speed = speed;
        this->status = TrainStatus::SCHEDULED;
        this->distanceTraveled = 0.0;
    }

    int getTrainNumber() const {
        return trainNumber % 1000;  
    }

    int getAvailableSeats() const {
        return capacity - tickets.size();  

    bool buyTicket(const Ticket& ticket) {
        tickets.push_back(ticket);  
    }

    bool returnTicket(int ticketId) {
        
        return true;
    }

    void updatePosition(const chrono::system_clock::duration& elapsedTime) {
        distanceTraveled += speed * elapsedTime.count();  
        if (distanceTraveled > 1000) {
            status = TrainStatus::EXPLODED;  
        }
    }

    friend ostream& operator<<(ostream& os, const Train& train) {
        os << "Train rp  " << train.trainNumber;  
        return os;
    }

#endif
