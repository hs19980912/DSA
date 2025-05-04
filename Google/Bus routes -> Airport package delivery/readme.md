Given an origin airport, destination airport, and series of flights determine whether it is possible for a package at the origin to reach the destination. A flight is represented as departure airport, arrival airport, departure time, and arrival time.
During the transportation, the time that the package leaves the airport needs to be greater than or equal to the time it arrives at the airport. Please determine whether it is possible for a package transfer from s to t. The package arrived at s at time 0.

```
Example 1:
Origin: "NYC"
Destination: "SFO"
Flights: NYC → LAX, Departure: 0, Arrival: 4
LAX - SFO, Departure: 5, Arrival: 7
Output: True

Example 2
Origin: "NYC" Destination: "SFO"
Flights: NYC →> LAX, Departure: 0, Arrival: 4
LAX -> SFO, Departure: 3, Arrival: 5
Output: False
```

[Link](https://leetcode.com/discuss/post/6352084/google-l4-phone-screening-round-by-anony-aa15/)

