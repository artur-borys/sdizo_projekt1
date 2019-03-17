#include "pch.h"
#include "Czas.h"


void Czas::start()
{
	startTime = high_resolution_clock::now();
}

void Czas::stop()
{
	endTime = high_resolution_clock::now();
}

long Czas::result()
{
	return duration_cast<nanoseconds>(Czas::endTime - Czas::startTime).count();
}
