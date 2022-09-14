#include <systemc.h>
#include "AvalonSTAdapter.h"

int sc_main(int argc, char* argv[]) {
	Top top("Top-Level");
	sc_start(200, SC_NS);
	return(0);
}
