#include <boost/test/unit_test.hpp>
#include "utils.h"

BOOST_AUTO_TEST_CASE(degrees_to_radians_basic) {
    BOOST_CHECK_CLOSE(degreesToRadians(0.0), 0.0, 1e-9);
    BOOST_CHECK_CLOSE(degreesToRadians(180.0), PI, 1e-9);
}

BOOST_AUTO_TEST_CASE(haversine_zero_distance) {
    double lat = 51.5, lon = -0.12; // London
    BOOST_CHECK_SMALL(haversineDistance(lat, lon, lat, lon), 1e-9);
}

BOOST_AUTO_TEST_CASE(haversine_known_distance) {
    // Approx distance between Paris (48.8566, 2.3522) and London (51.5074, -0.1278) ~ 343 km
    double d = haversineDistance(48.8566, 2.3522, 51.5074, -0.1278);
    BOOST_CHECK(d > 300.0);
    BOOST_CHECK(d < 400.0);
}
