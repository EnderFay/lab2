#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    int id;
    int trainId;
    std::tm bookingTime;
    double price;
    bool isReturned;
    
public:
    Ticket(int id, int trainId, const Passenger& passenger, 
           const std::tm& bookingTime, double price);
    
    int getId() const;
    int getTrainId() const;
    Passenger getPassenger() const;
    
    double getPrice() const;
    
   // void returnTicket();
    
    void displayInfo(const Train& train) const;
};

#endif // TICKET_H
