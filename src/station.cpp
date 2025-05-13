#include "../include/station.h"
#include <iostream>
int Station::getId() const { 
    return id; 
}
std::string Station::getName() const { 
    return name; 
}
std::string Station::getCity() const { 
    return city; 
}

void Station::setName(const std::string& newName) 
{ 
    name = newName; 
}
void Station::setCity(const std::string& newCity){ city = newCity; }
void Station::displayInfo() 
{
    std::cout << "Station ID: " << id <<"\n"
              << "Name: "       << name <<"\n"
              << "City: "       << city <<"\n"; 
}
