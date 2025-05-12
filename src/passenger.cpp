#include "../include/passenger.h"
#include <iostream>

Passenger::Passenger(const std::string& name, const std::string& passport, 
                     const std::string& contact)
    : name(name), passportNumber(passport), contactInfo(contact) {}

std::string Passenger::getName() const { return name; }
std::string Passenger::getPassportNumber() const { return passportNumber; }
std::string Passenger::getContactInfo() const { return contactInfo; }
