/***********************************************************************
 * Module:  tecnique.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:06:22
 * Purpose: Implementation of the class tecnique
 ***********************************************************************/
#include <iostream>
#include "tecnique.h"
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       tecnique::fix_problem()
// Purpose:    Implementation of tecnique::fix_problem()
// Return:     void
////////////////////////////////////////////////////////////////////////


tecnique::tecnique() :
 Worker(1,2)
{
//	cout << "Tecnique was initialized (default).\n";
}


tecnique::tecnique(int worked_years,int qualification) :
Worker(worked_years, qualification)
{
	//cout << "Tecnique was initialized (normal).\n";
}
tecnique::tecnique(const tecnique & tec) 
{
//	cout << "Tecnique was initialized (copy).\n";
}

tecnique::~tecnique() {
	//cout << "Tecnique was destroyed.\n"; 
}



void tecnique::fix_problem(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       tecnique::hold_sems()
// Purpose:    Implementation of tecnique::hold_sems()
// Return:     void
////////////////////////////////////////////////////////////////////////

void tecnique::hold_sems(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       tecnique::repair_equip()
// Purpose:    Implementation of tecnique::repair_equip()
// Return:     void
////////////////////////////////////////////////////////////////////////

void tecnique::repair_equip(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       tecnique::equip_lines_for_prototype()
// Purpose:    Implementation of tecnique::equip_lines_for_prototype()
// Return:     void
////////////////////////////////////////////////////////////////////////

void tecnique::equip_lines_for_prototype(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       tecnique::check_equip()
// Purpose:    Implementation of tecnique::check_equip()
// Return:     void
////////////////////////////////////////////////////////////////////////

void tecnique::check_equip(void)
{
   // TODO : implement
}