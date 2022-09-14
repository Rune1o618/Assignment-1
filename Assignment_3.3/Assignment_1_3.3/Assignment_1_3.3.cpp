// Assignment_1_3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "systemc.h"

#include "Producer_Consumer.h"
int sc_main(int argc, char* argv[]) {
	Top my_instance("my_instance");
	sc_start(200, SC_MS);
	return 0;
}
