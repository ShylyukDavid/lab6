/***********************************************************************
 * Module:  enterprise.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 18:05:07
 * Purpose: Declaration of the class enterprise
 ***********************************************************************/
#include "department.h"
#include "store.h"
#include "product.h"
#include <string>
#include <vector>
#include <fstream>
#if !defined(__ClassDiagram_1_enterprise_h)
#define __ClassDiagram_1_enterprise_h
using namespace std;
class department;
class store;
class order;

class enterprise
{
public:


	enterprise();					//default
	enterprise(float, int, int);		//initialisation
	enterprise(float, int, int,bool);		//initialisation
	enterprise(const enterprise&);		//copy
	~enterprise();					//destructor
	enterprise & operator++ ()
	{
		productivity_pow += 30;
		return *this;
	}
	void get()
	{
		depart[0].call();
	}
	bool create_order();
	void add_depart(int);
	void input_departments(ifstream &f);
   void take_order(void);
   void perform_order(string,int);
   void show_production(void);
   void buy_materials(void);
   void input_products(ifstream&);
   void add_product(void);
  int find_position(string);
   float get_pow(void)
   {
	   return productivity_pow;
   }
   int get_num_dep(void)
   {
	   return num_depart;
   }
   int get_number_product(void);
   vector<product> get_prod(void);
   const string get_name(void)
   {
	   return  name;
   }
   void choose_depart();
   vector <department> get_depart(void);
   void describe_department(int);
   void describe_products(int);
   bool has_products(void);
   order* ord;
   void analyze_order();
   bool has_this_product();
   bool have_departs();
   void show_depart(void);
   store get_s(void)
   {
	   return (s);
   }
   void show_products(void);
protected:
private:
 
   float productivity_pow;
   int num_depart;
   int number_product;
   vector <department> depart;
   vector <product> prod;
   store s;
   const string name = "devich";
};

#endif