#include "Route.hpp"

Route::Route(string ori, string dest, float km)
    : m_origin(ori), m_destination(dest), m_distanceKm(km) {}

string Route::GetOrigin() const {
    return m_origin;
}

string Route::GetDestination() const {
    return m_destination;
}

float Route::GetDistanceKM() const {
    return m_distanceKm;
}
