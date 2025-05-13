#include "../include/train.h"
#include "../include/route.h"
#include <iostream>
#include <ctime>
Train::Train(int id, const std::string& number, int routeId, int totalSeats,
    const std::tm& depTime, const std::tm& arrTime)
    : id(id), number(number), routeId(routeId), totalSeats(totalSeats),
    availableSeats(totalSeats), departureTime(depTime), arrivalTime(arrTime),
    status(TrainStatus::WAITING) {
}

int Train::getId() const { 
  return 0; }
std::string Train::getNumber() const { 
  return ""; }
int Train::getRouteId() const { 
  return 0; }
int Train::getTotalSeats() const { 
  return 0; }
int Train::getAvailableSeats() const { 
  return 0; }
std::tm Train::getDepartureTime() const { 
  return std::tm(); }
std::tm Train::getArrivalTime() const { 
  return std::tm(); }
TrainStatus Train::getStatus() const { 
  return TrainStatus::WAITING; }

void Train::setNumber(const std::string& newNumber) {}
void Train::setTotalSeats(int newTotalSeats) {}
void Train::setDepartureTime(const std::tm& newTime) {}
void Train::setArrivalTime(const std::tm& newTime) {}
void Train::setStatus(TrainStatus newStatus) {}

bool Train::bookSeats(int count) { return false; }
bool Train::cancelBooking(int count) { return false; }

void Train::displayInfo(const Route& route) const {
    std::cout << "Train info placeholder\n";
}

void Train::updateStatus(const std::tm& currentTime) {}
