/***********************************************************************
 * Module:  order.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:15:34
 * Purpose: Implementation of the class order
 ***********************************************************************/
#include <iostream>
#include "order.h"
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       order::create_order()
// Purpose:    Implementation of order::create_order()
// Return:     void
////////////////////////////////////////////////////////////////////////

order::order() :
name_orderer("devid"),
kind_prod("cars"),
numb_prod(20),
dead_line(7),
work_done(false)
{
	cout << "Order was initialized (default).\n";
}


order::order(string name_orderer, string kind_prod, int numb_prod, int dead_line) :
	name_orderer(name_orderer),
	kind_prod(kind_prod),
	numb_prod(numb_prod),
	dead_line(dead_line),
	work_done(false)
{
	cout << "Order was initialized (normal).\n";
}
order::order(order & ord) :
	name_orderer(ord.name_orderer),
	kind_prod(ord.kind_prod),
	numb_prod(ord.numb_prod),
	dead_line(ord.dead_line),
	work_done(ord.work_done)
{
	cout << "Order was initialized (copy).\n";
}

order::~order() { 
	cout << "Order was destroyed.\n"; 
}



void order::create_order(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       order::del_order()
// Purpose:    Implementation of order::del_order()
// Return:     void
////////////////////////////////////////////////////////////////////////

void order::del_order(void)
{
   // TODO : implement
}