#include <iostream>
#include <thread>
#include <fstream>
#include "gps_parser.h"
#include "route_planner.h"

int main()
{
    // Simulate GPS data input
    std::string sampleNMEA = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";

    auto gpsOpt = parseNMEA(sampleNMEA);
    if (gpsOpt)
    {
        const auto &gps = *gpsOpt;
        std::cout << "Parsed GPS: Lat=" << gps.latitude << ", Lon=" << gps.longitude
                  << ", Speed=" << gps.speed << " knots, Heading=" << gps.heading << "°\n";
    }

    // Route planning example
    RoutePlanner planner;
    planner.addWaypoint({48.1173, 11.5167}); // Start: Munich (simulated)
    planner.addWaypoint({48.8566, 2.3522});  // Waypoint: Paris
    planner.addWaypoint({51.5074, -0.1278}); // End: London
    std::cout << "Total route distance: " << planner.totalDistance() << " km\n";

    std::jthread logger([&gpsOpt, &planner]
                        {
    std::ofstream log("nav_log.txt");
    log << "Marine Navigation System Started\n";
    if (gpsOpt) {
        log << "GPS Fix: " << gpsOpt->latitude << "," << gpsOpt->longitude << "\n";
    }
    log << "Route loaded with " << planner.getWaypoints().size() << " waypoints\n";
    log << "Total distance: " << planner.totalDistance() << " km\n"; });

    return 0;
}