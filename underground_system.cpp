#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem {



public:

    // Design a system to track customer check-ins and calculate average travel times
    // Uses two hash maps:
    // 1. checkInMap: tracks active check-ins (id -> {stationName, time})
    // 2. routeMap: aggregates trip data (route -> {totalTime, tripCount})

    // Stores active check-ins: id -> {stationName, time}
    // Maps passenger ID to their check-in station and time
    unordered_map<int, pair<string, int>> checkInMap;

    // Stores aggregated trip data: "start#end" -> {totalTime, tripCount}
    // Key format: "startStation#endStation"
    // Value: {sum of all travel times, number of trips}
    unordered_map<string, pair<long long, int>> routeMap;

    UndergroundSystem() {}

    // Record a customer check-in at a station
    // Time complexity: O(1) - hash map insertion is O(1) average case
    // Space complexity: O(1) - stores one entry per passenger ID
    void checkIn(int id, string stationName, int t) {

        // Record check-in details
        // Store the station name and check-in time for this passenger

        checkInMap[id] = {stationName, t};

    }

    // Record a customer check-out and update route statistics
    // Time complexity: O(1) - hash map lookup, update, and erase are all O(1) average case
    // Space complexity: O(1) - updates existing entries, no new space needed per operation
    void checkOut(int id, string stationName, int t) {

        // Retrieve start station and start time from check-in record

        auto &info = checkInMap[id];

        string startStation = info.first;

        int startTime = info.second;

        // Compute travel time for this trip

        int travelTime = t - startTime;

        // Create key for route using start and end stations
        // Format: "startStation#endStation"

        string routeKey = startStation + "#" + stationName;

        // Update total time and count for this route
        // Accumulate travel time and increment trip count

        routeMap[routeKey].first += travelTime;

        routeMap[routeKey].second += 1;

        // Remove passenger from active check-ins
        // They have completed their trip

        checkInMap.erase(id);

    }

    // Calculate the average travel time for a given route
    // Time complexity: O(1) - hash map lookup and arithmetic operations are constant time
    // Space complexity: O(1) - only uses constant extra variables for calculation
    double getAverageTime(string startStation, string endStation) {

        // Create route key to look up aggregated data

        string routeKey = startStation + "#" + endStation;

        auto &data = routeMap[routeKey];

        long long totalTime = data.first;

        int count = data.second;

        // Calculate and return average: total time / number of trips

        return (double)totalTime / count;

    }

};

