#pragma once
#include "systemc.h"

SC_MODULE(ModuleDouble) {  //Initialize the ModuleDouble
	//Declaring the 4 events for the assignemtn with sc_event
	sc_event eventA;
	sc_event eventB;
	sc_event eventAack;
	sc_event eventBack;

	//Defining the different states as an enumeration 

	enum State {Default, AwatingEventA, AwaitingEventB} state;

	//Create the constructor

	SC_CTOR (ModuleDouble) {
		state = State::Default;     //Setting a default state
		SC_THREAD(threadA);         //Define the threads and methods
		SC_THREAD(threadB);
		SC_METHOD(methodA);

	}

	void threadA(void) {                //Theread A notifies event A every 3ms then wait for Aack
		while (1) {
			eventA.notify();
			wait(3, SC_MS, eventAack);
		}
	}
	void threadB(void) {                //Thread B notifies event B evert 2ms then wait for Back
		while (1) {
			eventB.notify();
			wait(2, SC_MS, eventBack);
		}
	}

	void methodA(void) {    //To wait alternatively between waiting on event A and B

		switch (state) {    //case stements for 3 differet states

		case State::Default:
			next_trigger(eventA);           //This Dynamic sensitivity lets a simulation process change its sensitivity on the fly.
 			state = State::AwatingEventA;
			break;
		case State::AwatingEventA:
			cout << sc_time_stamp() << "- Event A " << endl;
			eventAack.notify();
			next_trigger(eventB);
			state = State::AwaitingEventB;
			break;

		case State::AwaitingEventB:
			cout << sc_time_stamp() << "- Event B " << endl;
			eventAack.notify();
			next_trigger(eventA);
			state = State::AwatingEventA;
			break;



 
		}

	}
};
