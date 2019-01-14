/***********************************************************************
 * Module:  product.cpp
 * Author:  David
 * Modified: вторник, 20 но€бр€ 2018 г. 23:42:03
 * Purpose: Implementation of the class product
 ***********************************************************************/
#include <iostream>
#include <vector>
#include "product.h"
#include "prototype.h"
#include <string>
#include <iterator>
#include <algorithm> 
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       product::show_detail_list()
// Purpose:    Implementation of product::show_detail_list()
// Return:     void
////////////////////////////////////////////////////////////////////////

product::product() :
name_product("prod"),
list_details(0),
number_details(0),
list_departments(0),
quality(5)
{
	//cout << "Product was initialized (default).\n";
}


product::product(string name_product, vector<string> list_details, vector<int> number_details, vector<int> list_departments, int quality) :
	name_product(name_product),
	list_details(list_details),
	number_details(number_details),
	list_departments(list_departments),
	quality(quality)
{
	cout << "Product was initialized (normal).\n";
}
product::product(const product& prod) :
	name_product(prod.name_product),
	list_details(prod.list_details),
	number_details(prod.number_details),
	list_departments(prod.list_departments),
	quality(prod.quality)
{
	//cout << "Product was initialized (copy).\n";
}
product::product(const prototype& c, int qual, vector<int> list):
	name_product(c.name_prod), list_details(c.kind_detail), number_details(c.needed_detail), list_departments(list), quality(qual)
{
	cout << "Product was transformed from prototype.\n";
}
product::~product() {
	//cout << "Product was destroyed.\n";
}



void product::show_detail_list(void)
{
   // TODO : implement
}

vector<string> product::get_list_details(void)
{
	return list_details;
}

vector<int> product::get_number_details(void)
{
	return vector<int>(number_details);
}

vector<int> product::get_list_departments(void)
{
	return vector<int>(list_departments);
}


void product::initializes(vector<string>s,vector<int>k,vector<int>r,int qual,string name_pr)
{
	
	for (int i = 0;i<s.size();i++)
	{
		list_details.emplace_back(s[i]);
		number_details.emplace_back(k[i]);
	}
	for (int i = 0; i < r.size(); i++)
	{
		list_departments.emplace_back(r[i]);
	}
	quality = qual;
	name_product = name_pr;

	cout << "Yout described product: name - " << name_product << ", details(in pairs) - ";
	for (int i = 0; i < list_details.size(); i++)
	{
		cout << list_details[i] << " : " << number_details[i];
		if (i + 1 != list_details.size())
		{
			cout << ", " ;
		}
		else cout << "; ";
	}
	cout << "department list - ";
	for (int i = 0; i < list_departments.size(); i++)
	{
		cout << list_departments[i];
		if (i + 1 != list_departments.size())
		{
			cout << ", ";
		}
		else cout << "; ";
	}
	cout << "current quality - " << quality<<".\n\n";
		//number_details.resize(list_details.size()) ;
	//cout << number_details.size() << endl;
}
