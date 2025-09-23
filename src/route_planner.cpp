#include "route_planner.h"
#include <numeric>
#include <ranges>

void RoutePlanner::addWaypoint(const Waypoint &wp)
{
    waypoints.push_back(wp);
}

std::vector<Waypoint> RoutePlanner::getWaypoints() const
{
    return waypoints;
}

double RoutePlanner::totalDistance() const
{
    if (waypoints.size() < 2)
        return 0.0;

    double total = 0.0;
    for (size_t i = 1; i < waypoints.size(); ++i)
    {
        total += haversineDistance(waypoints[i - 1].lat, waypoints[i - 1].lon,
                                   waypoints[i].lat, waypoints[i].lon);
    }
    return total;
}