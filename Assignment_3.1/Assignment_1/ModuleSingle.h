#include <systemc.h>

SC_MODULE(ModuleSingle) {                   //Creating a Module called Module_Single
	sc_uint<4> counter;                     //Setting the counter of type sc_unit<4>
	sc_event event1;                        //Setting up the event

	SC_CTOR(ModuleSingle) {                 //Setting up the constructor
		SC_THREAD(thread_1);                //Define the Thread
		SC_METHOD(method_1);                //Define the Method
		sensitive << event1;                //Sensitivity of a process is Static in Nature (Further Definition in Report)
	}

	void thread_1(void) {                   //Setting the event of the thread to notify periodically the method every 2MS. 
		cout << "my_first_thread" << endl;
		while (1) {
			event1.notify();
			wait(2, SC_MS);
		}

	}
	void method_1(void) {                    //Setting the thread to increment the counter adn print the value of the simulatioin time to 200ms.
		counter++;
		cout << "Current Simulation Time: " << sc_time_stamp() << " Counter: " << counter << endl;

	}

};
