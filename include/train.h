#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <ctime>
#include <vector>
#include "route.h"
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

    std::string currentStation;
    std::string destination;
    std::chrono::system_clock::time_point departureTime;
    std::string origin;
    std::chrono::system_clock::duration travelDuration;
    TrainStatus status;
    std::vector<Ticket> tickets;
    double speed;           
    double distanceTraveled; 

   
    Train(int trainNumber = -1, int capacity = -1, const std::string& origin = "", const std::string& destination = "",
        const std::chrono::system_clock::time_point& departureTime = std::chrono::system_clock::time_point(),
        const std::chrono::system_clock::duration& travelDuration = std::chrono::system_clock::duration(),
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

    void updatePosition(const std::chrono::system_clock::duration& elapsedTime) {
        distanceTraveled += speed * elapsedTime.count();  
        if (distanceTraveled > 1000) {
            status = TrainStatus::EXPLODED;  
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Train& train) {
        os << "Train rp  " << train.trainNumber;  
        return os;
    }

#endif
