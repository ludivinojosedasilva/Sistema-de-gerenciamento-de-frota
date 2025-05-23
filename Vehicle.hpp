#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <vector>
#include <string>
#include "Route.hpp"
using namespace std;

class Vehicle
{
private:
    string m_plate, m_model, m_brand;
    float m_initialKm;
    vector<Route> m_trips;

public:
    Vehicle(string plate, string model, string brand);

    void IncludeTrip(string origin, string destination, float distance);
    bool RemoveTrip(size_t index);
    string SearchTripBySubstring(string wordToSearch);

    string GetAllTrips();
    float GetConsumption();
    
    string GetPlate(); // Método auxiliar para buscar veículos
    float GetTotalKm(); // Método auxiliar para calcular KM total
};

#endif // VEHICLE_HPP
