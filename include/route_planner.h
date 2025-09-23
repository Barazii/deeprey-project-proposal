#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <vector>
#include "utils.h"

struct Waypoint {
    double lat;
    double lon;
};

class RoutePlanner {
public:
    void addWaypoint(const Waypoint& wp);
    double totalDistance() const;
    std::vector<Waypoint> getWaypoints() const;

private:
    std::vector<Waypoint> waypoints;
};

#endif // ROUTE_PLANNER_H