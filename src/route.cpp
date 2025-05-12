#include "../include/route.h"

Route::Route(int id, const std::string& name, int depStationId, int arrStationId, 
             const std::vector<int>& intermediate, double distance)
    : id(id), name(name), departureStationId(depStationId), 
      arrivalStationId(arrStationId), intermediateStations(intermediate), 
      distance(distance) {}

int Route::getId() const { return id; }
std::string Route::getName() const { return name; }
int Route::getDepartureStationId() const { return departureStationId; }
int Route::getArrivalStationId() const { return arrivalStationId; }
std::vector<int> Route::getIntermediateStations() const { return intermediateStations; }
double Route::getDistance() const { return distance; } 

void Route::setName(const std::string& newName) { name = newName; }
void Route::setDistance(double newDistance) { distance = newDistance; } 
