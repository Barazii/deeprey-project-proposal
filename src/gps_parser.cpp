#include "gps_parser.h"
#include <sstream>
#include <algorithm>
#include <limits>

std::optional<GPSData> parseNMEA(const std::string& sentence) {
    if (sentence.rfind("$GPRMC", 0) != 0) return std::nullopt;

    std::stringstream ss(sentence);
    std::vector<std::string> fields;
    std::string token;
    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if (fields.size() < 10) return std::nullopt;

    // Parse latitude (e.g., 4807.038,N -> 48.1173)
    auto parseCoord = [](const std::string& degMin, const std::string& dir) -> double {
        // Format is ddmm.mmm for latitude and dddmm.mmm for longitude.
        // Split degrees and minutes based on the decimal point position.
        auto dotPos = degMin.find('.');
        if (dotPos == std::string::npos || dotPos < 2) return std::numeric_limits<double>::quiet_NaN();
        // Minutes start 2 characters before the decimal point
        size_t minStart = dotPos - 2;
        if (minStart == 0) return std::numeric_limits<double>::quiet_NaN();
        std::string degStr = degMin.substr(0, minStart);
        std::string minStr = degMin.substr(minStart);
        double degrees = std::stod(degStr);
        double minutes = std::stod(minStr) / 60.0;
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