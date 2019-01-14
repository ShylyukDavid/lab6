/***********************************************************************
 * Module:  order.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:15:34
 * Purpose: Declaration of the class order
 ***********************************************************************/
#include <string>
#if !defined(__ClassDiagram_1_order_h)
#define __ClassDiagram_1_order_h
using namespace std;
class order
{
public:
	order();					//default
	order(string, string, int,int);		//initialisation
	order(order&);		//copy
	~order();					//destructor
   void create_order(void);
   void del_order(void);
   string get_kind_prod()
   {
	   return kind_prod;
   }
   string get_name_orderer()
   {
	   return name_orderer;
   }
protected:
private:
   string name_orderer;
   string kind_prod;
   int numb_prod;
   int dead_line;
   bool work_done;


};

#endif