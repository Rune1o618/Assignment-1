#include <systemc.h>

#include "ModuleSingle.h"

int sc_main(int argc, char* argv[]) {
	ModuleSingle my_instance("my_instance");
	sc_start(200, SC_MS);
	return 0;
}
