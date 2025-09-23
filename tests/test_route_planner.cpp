#include <boost/test/unit_test.hpp>
#include "route_planner.h"

BOOST_AUTO_TEST_CASE(empty_distance) {
    RoutePlanner rp;
    BOOST_CHECK_SMALL(rp.totalDistance(), 1e-12);
}

BOOST_AUTO_TEST_CASE(single_waypoint_distance) {
    RoutePlanner rp;
    rp.addWaypoint({48.8566, 2.3522});
    BOOST_CHECK_SMALL(rp.totalDistance(), 1e-12);
}

BOOST_AUTO_TEST_CASE(two_waypoints_distance) {
    RoutePlanner rp;
    rp.addWaypoint({48.8566, 2.3522}); // Paris
    rp.addWaypoint({51.5074, -0.1278}); // London
    double d = rp.totalDistance();
    BOOST_CHECK(d > 300.0);
    BOOST_CHECK(d < 400.0);
}

BOOST_AUTO_TEST_CASE(get_waypoints_returns_copy) {
    RoutePlanner rp;
    rp.addWaypoint({1.0, 2.0});
    auto wps = rp.getWaypoints();
    BOOST_CHECK_EQUAL(wps.size(), 1u);
}
