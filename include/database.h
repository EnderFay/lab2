#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <ctime>
#include "station.h"
#include "route.h"
#include "train.h"
#include "ticket.h"

class Database {
private:
    std::vector<Station> stations;
    std::vector<Route> routes;
    
public:
    void addStation(const Station& station);
    void removeStation(int id);
    void editStation(int id, const std::string& name, const std::string& city);
    const std::vector<Station>& getAllStations() const;
    Station* findStation(int id);
    const Station* findStation(int id) const;

    void addRoute(const Route& route);
    void removeRoute(int id);
    void editRoute(int id, const std::string& name, double distance);
    const std::vector<Route>& getAllRoutes() const;
    Route* findRoute(int id);
    const Route* findRoute(int id) const;
};


#endif
