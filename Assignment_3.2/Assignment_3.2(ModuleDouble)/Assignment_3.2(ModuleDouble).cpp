#include "systemc.h"

#include "ModuleDouble.h"
int sc_main(int argc, char* argv[]) {
	ModuleDouble my_instance("my_instance");
	sc_start(200, SC_MS);
	return 0;
}
