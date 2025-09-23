#ifndef GPS_PARSER_H
#define GPS_PARSER_H

#include <string>
#include <vector>
#include <optional>

struct GPSData {
    double latitude;
    double longitude;
    double speed;  // knots
    double heading;  // degrees
};

std::optional<GPSData> parseNMEA(const std::string& sentence);

#endif // GPS_PARSER_H