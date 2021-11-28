#pragma once
#include <chrono>

/*
	Quick chrono utility functions for timing. These should run very close to the metal.

	Note: On MSVC, high_resolution_clock is based on QueryPerformanceCounter
	and so should have a resolution of roughly 100ns. 

	Author: Patrick Poitras (patrick.f.poitras@gmail.com)
	License: Public domain. 
*/

// The excessive verbosity of the chrono library is a sight to behold.
// Typedef the pain away in a 100+ character line
typedef std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> chrono_timepoint;

// Returns a timepoint of the current time.
inline chrono_timepoint get_time() {
	return std::chrono::high_resolution_clock::now();
}

// Returns time in nanoseconds since the passed parameter.
inline double get_time_since(const chrono_timepoint &previousTimestamp) {
	return (get_time() - previousTimestamp).count();
}

// Returns time in seconds since the previous timestamp.
inline double get_seconds_since(const chrono_timepoint& previousTimestamp) {
	return get_time_since(previousTimestamp) / 1e9;
}