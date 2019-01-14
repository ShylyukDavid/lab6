/***********************************************************************
 * Module:  prototype.cpp
 * Author:  David
 * Modified: вторник, 20 но€бр€ 2018 г. 13:27:00
 * Purpose: Implementation of the class prototype
 ***********************************************************************/
#include <iostream>
#include "prototype.h"
#include <vector>
#include <string>

using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       prototype::create_prototype()
// Purpose:    Implementation of prototype::create_prototype()
// Return:     void
////////////////////////////////////////////////////////////////////////
prototype::prototype() :
name_prod(""),
kind_detail(0),
needed_detail(0),
approved(false)
{
	cout << "Prototype was initialized (default).\n";
}


prototype::prototype(string name_prod, vector<string> kind_detail, vector<int> needed_detail, bool approved) :
	name_prod(name_prod),
	kind_detail(kind_detail),
	needed_detail(needed_detail),
	approved(approved)
{
	cout << "Prototype was initialized (normal).\n";
}
prototype::prototype(const prototype & prot) :
	name_prod(prot.name_prod),
	kind_detail(prot.kind_detail),
	needed_detail(prot.needed_detail),
	approved(prot.approved)
{
	cout << "Prototype was initialized (copy).\n";
}

prototype::~prototype() { cout << "Prototype was destroyed.\n"; }




void prototype::create_prototype(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       prototype::approve_prototype()
// Purpose:    Implementation of prototype::approve_prototype()
// Return:     void
////////////////////////////////////////////////////////////////////////

void prototype::approve_prototype(void)
{
   // TODO : implement
}