#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string name;
    std::string passportNumber;
    std::string contactInfo;

public:
    Passenger(const std::string& name, const std::string& passport, 
              const std::string& contact);
};

#endif
