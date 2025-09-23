#include "gps_parser.h"
#include <sstream>
#include <algorithm>
#include <ranges>  // C++20 ranges

std::optional<GPSData> parseNMEA(const std::string& sentence) {
    if (sentence.rfind("$GPRMC", 0) != 0) return std::nullopt;  // Basic check for RMC sentence

    std::stringstream ss(sentence);
    std::vector<std::string> fields;
    std::string token;
    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if (fields.size() < 10) return std::nullopt;

    // Parse latitude (e.g., 4807.038,N -> 48.1173)
    auto parseCoord = [](const std::string& degMin, const std::string& dir) -> double {
        double degrees = std::stod(degMin.substr(0, degMin.size() - 5));  // e.g., 48
        double minutes = std::stod(degMin.substr(degMin.size() - 5)) / 60.0;  // e.g., 07.038 / 60
        double coord = degrees + minutes;
        return (dir == "S" || dir == "W") ? -coord : coord;
    };

    GPSData data;
    data.latitude = parseCoord(fields[3], fields[4]);
    data.longitude = parseCoord(fields[5], fields[6]);
    data.speed = std::stod(fields[7]);
    data.heading = std::stod(fields[8]);

    return data;
}