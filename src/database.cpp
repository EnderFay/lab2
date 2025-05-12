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
