# Marine Navigation App (Project Proposal)

## Overview
This repository is a project proposal built on a few assumptions to demonstrate my skills in modern C++. It includes a GPS NMEA RMC marine data parser, a simple waypoint-based route planner, CMake builds, unit tests with Boost testing framework, and a GitHub Actions workflow for automated build and test triggered on push commands.

## Requirements
- CMake >= 3.20
- C++20 compiler (e.g., GCC 11+, Clang 13+)
- Boost (Unit Test Framework) >= 1.74

## Build
```bash
mkdir build && cd build
cmake .. && make
```

## Run the demo app
```bash
./marine_nav
```

## Run tests
```bash
./tests
```

## Assumptions
- Proposal-level simplified code.
- GPS parsing supports the `$GPRMC` sentence and converts `ddmm.mmm/dddmm.mmm` to decimal degrees.
- Distance uses the spherical haversine formula (Earth radius 6371 km).
- Route planning computes straight-line segment distances between waypoints.