#include <boost/test/unit_test.hpp>
#include "gps_parser.h"

BOOST_AUTO_TEST_CASE(parse_valid_rmc) {
    std::string nmea = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    auto res = parseNMEA(nmea);
    BOOST_REQUIRE(res.has_value());
    auto data = res.value();
    BOOST_CHECK_CLOSE_FRACTION(data.latitude, 48.1173, 1e-5);
    BOOST_CHECK_CLOSE_FRACTION(data.longitude, 11.5167, 1e-5);
    BOOST_CHECK_CLOSE(data.speed, 22.4, 1e-6);
    BOOST_CHECK_CLOSE(data.heading, 84.4, 1e-6);
}

BOOST_AUTO_TEST_CASE(parse_invalid_prefix) {
    std::string nmea = "$GPGGA,foo";
    auto res = parseNMEA(nmea);
    BOOST_CHECK(!res.has_value());
}

BOOST_AUTO_TEST_CASE(parse_too_few_fields) {
    std::string nmea = "$GPRMC,123";
    auto res = parseNMEA(nmea);
    BOOST_CHECK(!res.has_value());
}
