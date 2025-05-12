#include "database.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>

void Database::addStation(const Station& station) {
    stations.push_back(station);
}

void Database::removeStation(int id) {
    stations.erase(std::remove_if(stations.begin(), stations.end(),
        [id](const Station& s) { return s.getId() == id; }), stations.end());
}

void Database::editStation(int id, const std::string& name, const std::string& city) {
    for (auto& station : stations) {
        if (station.getId() == id) {
            station.setName(name);
            station.setCity(city);
            break;
        }
    }
}

const std::vector<Station>& Database::getAllStations() const {
    return stations;
}

Station* Database::findStation(int id) {
    auto it = std::find_if(stations.begin(), stations.end(),
        [id](const Station& s) { return s.getId() == id; });
    return it != stations.end() ? &(*it) : nullptr;
}

const Station* Database::findStation(int id) const {
    auto it = std::find_if(stations.begin(), stations.end(),
        [id](const Station& s) { return s.getId() == id; });
    return it != stations.end() ? &(*it) : nullptr;
}



void Database::addRoute(const Route& route) {
    routes.push_back(route);
}

void Database::removeRoute(int id) {
    routes.erase(std::remove_if(routes.begin(), routes.end(),
        [id](const Route& r) { return r.getId() == id; }), routes.end());
}

void Database::editRoute(int id, const std::string& name, double distance) {
    for (auto& route : routes) {
        if (route.getId() == id) {
            route.setName(name);
            route.setDistance(distance);
            break;
        }
    }
}

const std::vector<Route>& Database::getAllRoutes() const {
    return routes;
}

Route* Database::findRoute(int id) {
    auto it = std::find_if(routes.begin(), routes.end(),
        [id](const Route& r) { return r.getId() == id; });
    return it != routes.end() ? &(*it) : nullptr;
}

const Route* Database::findRoute(int id) const {
    auto it = std::find_if(routes.begin(), routes.end(),
        [id](const Route& r) { return r.getId() == id; });
    return it != routes.end() ? &(*it) : nullptr;
}
