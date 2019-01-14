/***********************************************************************
 * Module:  kanban.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:23:01
 * Purpose: Implementation of the class kanban
 ***********************************************************************/

#include "kanban.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


////////////////////////////////////////////////////////////////////////
// Name:       kanban::create_kanban()
// Purpose:    Implementation of kanban::create_kanban()
// Return:     void
////////////////////////////////////////////////////////////////////////

kanban::kanban() :
 send_depart(0),
adress_depart(0),
kind_prod(0),
number_prod(0),
time_spent_production(0)
{
	//cout << "Kanban was initialized (default).\n";
}


kanban::kanban(int send_depart, int adress_depart, vector <string> kind_prod, vector <int> number_prod, float time_spent_production) :
	send_depart(send_depart),
	adress_depart(adress_depart),
	kind_prod(kind_prod),
	number_prod(number_prod),
	time_spent_production(time_spent_production)
{
	//cout << "Kanban was initialized (normal).\n";
}
kanban::kanban(kanban & kan) :
	send_depart(kan.send_depart),
	adress_depart(kan.adress_depart),
	kind_prod (kan.kind_prod),
	number_prod(kan.number_prod),
	time_spent_production(kan.time_spent_production)
{
//	cout << "Kanban was initialized (copy).\n";
}

kanban::~kanban() { cout << "Kanban was destroyed.\n"; }



void kanban::create_kanban(void)
{
   // TODO : implement
}