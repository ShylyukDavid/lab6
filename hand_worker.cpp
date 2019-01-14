/***********************************************************************
 * Module:  hand_worker.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:33:57
 * Purpose: Implementation of the class hand_worker
 ***********************************************************************/
#include <iostream>
#include "hand_worker.h"
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       hand_worker::signal_stop()
// Purpose:    Implementation of hand_worker::signal_stop()
// Return:     void
////////////////////////////////////////////////////////////////////////
hand_worker::hand_worker():
num_pos(1),
Worker()
{
	//cout << "Hand_worker was initialized (default).\n";
}


hand_worker::hand_worker(int num_pos, int qualification) :
Worker(1, qualification) ,num_pos(num_pos)
{
	//cout << "Hand_worker line was initialized (normal).\n";
}
hand_worker::hand_worker(const hand_worker & hand) :
num_pos(hand.num_pos)
{
	//cout << "Hand_worker was initialized (copy).\n";
}

hand_worker::~hand_worker() { 
//	cout << "Hand_worker was destroyed.\n"; 
}

int hand_worker::get_num_pos(void)
{
	return num_pos;
}


void hand_worker::signal_stop(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       hand_worker::visit_sems()
// Purpose:    Implementation of hand_worker::visit_sems()
// Return:     void
////////////////////////////////////////////////////////////////////////

void hand_worker::visit_sems(void)
{
   // TODO : implement
}