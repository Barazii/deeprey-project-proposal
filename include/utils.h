#ifndef UTILS_H
#define UTILS_H

#include <cmath>

constexpr double PI = 3.14159265358979323846;

inline double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

inline double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = degreesToRadians(lat2 - lat1);
    double dLon = degreesToRadians(lon2 - lon1);
    lat1 = degreesToRadians(lat1);
    lat2 = degreesToRadians(lat2);

    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::sin(dLon / 2) * std::sin(dLon / 2) * std::cos(lat1) * std::cos(lat2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    constexpr double EARTH_RADIUS_KM = 6371.0;
    return EARTH_RADIUS_KM * c;
}

#endif // UTILS_H