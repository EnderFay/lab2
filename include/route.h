#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>

class Route {
private:
    int id;
    std::string name;
    int departureStationId;
    int arrivalStationId;
    std::vector<int> intermediateStations;
    double distance;

public:
    Route(int id, const std::string& name, int depStationId, int arrStationId,
          const std::vector<int>& intermediate, double distance);

    int getId() const;
    std::string getName() const;
    int getDepartureStationId() const;
    int getArrivalStationId() const;
    std::vector<int> getIntermediateStations() const;
    double getDistance() const;
};

    void setName(const std::string& newName);
    void setDistance(double newDistance);

#endif
