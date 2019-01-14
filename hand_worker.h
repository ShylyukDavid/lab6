/***********************************************************************
 * Module:  hand_worker.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:33:57
 * Purpose: Declaration of the class hand_worker
 ***********************************************************************/
#include <string>
#include <vector>
#include "Worker.h"
#if !defined(__ClassDiagram_1_hand_worker_h)
#define __ClassDiagram_1_hand_worker_h
using namespace std;
class hand_worker: public Worker
{
public:


	hand_worker();					//default
	hand_worker(int, int);		//initialisation
	hand_worker(const hand_worker&);		//copy
	~hand_worker();					//destructor
	int get_num_pos(void);
	int get_qualification(void);
   void signal_stop(void);
   void visit_sems(void);
   void display() override
   {
	   cout << ", current qualification - " << qualification << endl;
   }
   hand_worker & operator++ ()
   {
	   qualification += 1;
	   return *this;
   }
  
protected:
private:
   int num_pos;



};

#endif