/***********************************************************************
 * Module:  kanban.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:23:01
 * Purpose: Declaration of the class kanban
 ***********************************************************************/
#include <string>
#include <vector>
#if !defined(__ClassDiagram_1_kanban_h)
#define __ClassDiagram_1_kanban_h
using namespace std;
class kanban
{
public:
	kanban();					//default
	kanban(int, int, vector <string>, vector <int>, float);		//initialisation
	kanban(kanban&);		//copy
	~kanban();					//destructor

   void create_kanban(void);

protected:
private:
	int send_depart;
	int adress_depart;
   vector <string> kind_prod;
   vector <int> number_prod;
   float time_spent_production;
};

#endif