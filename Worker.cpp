#include <iostream>

using namespace std;
#include "Worker.h"
////////////////////////////////////////////////////////////////////////
// Name:       Workerr::signal_stop()
// Purpose:    Implementation of Workerr::signal_stop()
// Return:     void
////////////////////////////////////////////////////////////////////////
Worker::Worker() :
	worked_years(1),
	qualification(4)
{
	//cout << "Worker was initialized (default).\n";
}


Worker::Worker(int num_pos, int qualification) :
	worked_years(num_pos),
	qualification(qualification)
{
	//cout << "Worker was initialized (normal).\n";
}
Worker::Worker(const Worker & hand) :
	worked_years(hand.worked_years),
	qualification(hand.qualification)
{
	//cout << "Worker was initialized (copy).\n";
}

Worker::~Worker() {
//	cout << "Worker was destroyed.\n"; 
}


