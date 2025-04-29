#include "Vehicle.hpp"
#include <sstream>

Vehicle::Vehicle(string plate, string model, string brand) {
    m_plate = plate;
    m_model = model;
    m_brand = brand;
    m_initialKm = 0;
}

void Vehicle::IncludeTrip(string origin, string destination, float distance) {
    Route newRoute(origin, destination, distance);
    m_trips.push_back(newRoute);
}

bool Vehicle::RemoveTrip(size_t index) {
    if (index < m_trips.size()) {
        m_trips.erase(m_trips.begin() + index);
        return true;
    }
    return false;
}

string Vehicle::SearchTripBySubstring(string wordToSearch) {
    stringstream result;
    for (size_t i = 0; i < m_trips.size(); i++) {
        if (m_trips[i].GetOrigin().find(wordToSearch) != string::npos ||
            m_trips[i].GetDestination().find(wordToSearch) != string::npos) {
            result << "Trip " << i << ": " << m_trips[i].GetOrigin()
                   << " -> " << m_trips[i].GetDestination()
                   << " (" << m_trips[i].GetDistanceKM() << " km)" << endl;
        }
    }
    return result.str();
}

string Vehicle::GetAllTrips() {
    stringstream result;
    for (size_t i = 0; i < m_trips.size(); i++) {
        result << "Trip " << i << ": " << m_trips[i].GetOrigin()
               << " -> " << m_trips[i].GetDestination()
               << " (" << m_trips[i].GetDistanceKM() << " km)" << endl;
    }
    return result.str();
}

float Vehicle::GetConsumption() {
    float totalKm = m_initialKm;
    for (auto &trip : m_trips) {
        totalKm += trip.GetDistanceKM();
    }
    return totalKm;
}

string Vehicle::GetPlate() {
    return m_plate;
}

float Vehicle::GetTotalKm() {
    float total = m_initialKm;
    for (auto &trip : m_trips) {
        total += trip.GetDistanceKM();
    }
    return total;
}
