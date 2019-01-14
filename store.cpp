/***********************************************************************
 * Module:  store.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:19:47
 * Purpose: Implementation of the class store
 ***********************************************************************/
#include <iostream>
#include "store.h"
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       store::prov_mater()
// Purpose:    Implementation of store::prov_mater()
// Return:     void
////////////////////////////////////////////////////////////////////////
store::store() :
	materials_available(true)
{
	//cout << "Store was initialized (default).\n";
}


store::store(bool materials_available) :
	materials_available(materials_available)
{
	//cout << "Store was initialized (normal).\n";
}
store::store(const store & st) :
	materials_available(st.materials_available)
{
	//cout << "Store was initialized (copy).\n";
}

store::~store() { 
//	cout << "Store was destroyed.\n"; 
}


void store::prov_mater(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       store::analyze_order()
// Purpose:    Implementation of store::analyze_order()
// Return:     void
////////////////////////////////////////////////////////////////////////

void store::analyze_order(void)
{
   // TODO : implement
}

void store::set_store(bool s)
{
	materials_available = s;
}

bool store::have_materials(void)
{
	if (materials_available == true)
	{
	 return true;
	}
	else return false;
}
