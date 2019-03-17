#pragma once
#include <chrono>

using namespace std;
using namespace std::chrono;

class Czas
{
public:
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point endTime;

	void start();
	void stop();
	long result();
};

