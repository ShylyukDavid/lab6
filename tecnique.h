/***********************************************************************
 * Module:  tecnique.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:06:22
 * Purpose: Declaration of the class tecnique
 ***********************************************************************/

#if !defined(__ClassDiagram_1_tecnique_h)
#define __ClassDiagram_1_tecnique_h
#include "Worker.h"
class tecnique:public Worker
{


public:

	tecnique();					//default
	tecnique(int,int);		//initialisation
	tecnique(const tecnique&);		//copy
	~tecnique();					//destructor
   void fix_problem(void);
   void hold_sems(void);
   void repair_equip(void);
   void equip_lines_for_prototype(void);
   void check_equip(void);

protected:
private:
};

#endif