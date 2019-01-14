/***********************************************************************
 * Module:  store.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:19:47
 * Purpose: Declaration of the class store
 ***********************************************************************/

#if !defined(__ClassDiagram_1_store_h)
#define __ClassDiagram_1_store_h
using namespace std;
class store
{
public:
	store();					//default
	store(bool);		//initialisation
	store(const store&);		//copy
	~store();					//destructor


   void prov_mater(void);
   void analyze_order(void);
   void set_store(bool);
   bool have_materials(void);
protected:
private:
   bool materials_available;
};

#endif