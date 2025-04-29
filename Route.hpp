#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
using namespace std;

class Route
{
private:
    string *m_origin, *m_destination;
    float *m_distanceKm;

public:
    Route(string ori, string dest, float km);
    ~Route();

    string GetOrigin();
    string GetDestination();
    float GetDistanceKM();
};

#endif // ROUTE_HPP
