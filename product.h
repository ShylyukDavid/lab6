/***********************************************************************
 * Module:  product.h
 * Author:  David
 * Modified: вторник, 20 но€бр€ 2018 г. 23:42:03
 * Purpose: Declaration of the class product
 ***********************************************************************/


#if !defined(__ClassDiagram_1_product_h)
#define __ClassDiagram_1_product_h
#include "prototype.h"
#include <string>
#include <vector>

using namespace std; 
class product
{
public:
	product();					//default
	product(string, vector <string>, vector <int>, vector <int>, int);		//initialisation
	product(const product&);
	product(const prototype&, int, vector<int>);


	~product();
	
	
   void show_detail_list(void);
   vector <string> get_list_details(void);
   vector <int> get_number_details(void);
   vector<int> get_list_departments(void);
   int get_quality(void)
   {
	   return quality;
   }
   string get_name_product(void)
   {
	   return string(name_product);
   }
   void initializes(vector<string>,vector<int>,vector<int>,int,string);

protected:
private:
   
	string name_product;
	vector <string> list_details;
	vector <int> number_details;
	vector <int> list_departments;
	int quality; 

};

#endif