/***********************************************************************
 * Module:  enterprise.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 18:05:07
 * Purpose: Implementation of the class enterprise
 ***********************************************************************/
#include <iostream>
#include "department.h"
#include "store.h"
#include "order.h"
#include "product.h"
#include "enterprise.h"
#include <vector>
#include <string>
#include <iterator>
#include <algorithm> 
#include <limits>
#include <iomanip> 
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       enterprise::take_order()
// Purpose:    Implementation of enterprise::take_order()
// Return:     void
////////////////////////////////////////////////////////////////////////

class enterprise;
enterprise::enterprise() :
	productivity_pow(200),
	num_depart(1),
	number_product(2),
	depart(0),
	prod(number_product),
	s(false)

{
	cout << "Enterprise was initialized (default).\n";
}

enterprise::enterprise(float productivity_pow,int num_depart,int number_product) :
	productivity_pow(productivity_pow),
	num_depart(num_depart),
	number_product(number_product),
	depart(0),
	prod(0),
	s(true)
{
	cout << "Enterprise  was initialized (normal).\n";
	cout << "\nYou created enterprise named - " << name << ", productivity - " << productivity_pow << ", departments - " << num_depart << ", products - " << number_product << endl;
}
enterprise::enterprise(float productivity_pow, int num_depart, int number_product, bool s):
	productivity_pow(productivity_pow),
	num_depart(num_depart),
	number_product(number_product),
	depart(num_depart),
	prod(number_product),
	s(s)
{
}
enterprise::enterprise(const enterprise &en) :
	productivity_pow(en.productivity_pow),
	num_depart(en.num_depart),
	number_product(en.number_product),
	depart(en.num_depart),
	prod(en.number_product)
{
	cout << "Enterprise was initialized (copy).\n";
}

enterprise::~enterprise() { cout << "Enterprise  was destroyed.\n"; }
bool enterprise::create_order()
{
	bool k = false;
	string name_orderer, kind_prod; int numb_prod, dead_line;
	cout << "Enter name of orderer - "; cin >> name_orderer;
	cout << "Enter name of product - "; cin >> kind_prod;
	for (int i = 0; i < prod.size(); i++)
	{
		if (prod[i].get_name_product().compare(kind_prod) == 0)
		{
			k = true;
			cout << "Enter quantity of products - "; cin >> numb_prod;
			cout << "Enter number days to complete order - "; cin >> dead_line;
			ord = new order(name_orderer, kind_prod, numb_prod, dead_line);
			take_order(); int s = find_position(kind_prod);
			perform_order(kind_prod, s);
			return true;
		}

	}

	cout << "No production in this enterprise!!" << endl;
	return false;



}
void enterprise::add_depart(int s)
{
	

	for (int i = 0; i < s; i++)
	{
		this->depart.emplace_back();
	}
	cout << "Number of departments now - " << depart.size() << endl;
	
}

void enterprise::input_departments(ifstream &f)
{
  int techs; string depart_name; int number_work, pos_in_production, numberlines;
  for (int i = 0; i < num_depart; i++)
  {
	  f >> depart_name >> number_work >> numberlines >> techs;
	  depart[i].set_str_name(depart_name);
	  depart[i].set_number_workers(number_work);
	  depart[i].set_number_lines(numberlines);
	  depart[i].set_number_tecnic(techs);
	  depart[i].add_tecs();
	  cout << depart[i];
	  depart[i].input_line(f,numberlines, number_work);
  }
  cout << endl;
}




int enterprise::get_number_product(void)
{
	// TODO : implement
	return number_product;
}


vector <product> enterprise::get_prod(void)
{
	return  prod;
   // TODO : implement
}


void enterprise::choose_depart()
{

	int choice;
	do
	{
		cout << "Enter number of department to qualify its workers(existing - "<<depart.size()<<") - ";
		cin >> choice;
	} while (choice >= num_depart || choice<0);
	depart[choice].choose_line();
}

vector<department> enterprise::get_depart(void)
{
	return vector<department>(depart);
}
void enterprise::describe_department(int number)
{
	int f = depart.size();
	depart.resize(f + number);
	int  techs; string depart_name; int number_work, pos_in_production, numberlines;
	for (int i = f; i < number+f; i++)
	{
		cout << "Department #" << i << endl;
		cout << "Enter name of department - "; cin >> depart_name;
		cout << "Enter number_workers - "; cin >> number_work;
		cout << "Enter number of lines - "; cin >> numberlines;
		cout << "Enter number of tecniques -  "; cin >> techs;
		cout << "Position_production of deparment is define automatically - " << i << endl; pos_in_production = i;
		int division = number_work / numberlines;
		depart[i].set_str_name(depart_name);
		depart[i].set_number_workers(number_work);
		depart[i].set_number_lines(numberlines);
		depart[i].set_number_tecnic(techs);
		cout << depart[i];
		depart[i].add_line(numberlines, division);
		if (i != number + f - 1){ cout << "Press something to describe next deparment...\n"; system("pause"); system("cls"); }
	}
	cout << "\nYou described departments!\n\n";
}
void enterprise::describe_products(int number)
{
	int c = prod.size();
	prod.resize(c+number);
	cout << "Now you need to describe production of your enterprise\n";
	for (int i = c; i < number + c; i++)
	{    
		vector <string> s; string name_pr; int qual;
		cout << "Product #" << i <<" : "<< endl;
		cout << "Enter name of product - "; cin >> name_pr;
		cin.clear();
		cout << "Enter list of details by space(write 'q' and press 'Enter' to stop inputting) - "; istream_iterator<string> iit(cin);
		while (*iit != "q")
		{
			s.push_back(*iit);
			iit++;
		}
		cin.clear();
		fflush(stdin);// cin.ignore(INT_MAX, '\n');

	int count = 0;
	vector<int> k;
	istream_iterator<int> eos;
	cout << "Enter number details for your list by space(notice: enter 'q' and press enter after inputting) - "; 
	istream_iterator<int> iit1(cin);
	while (iit1 != eos && count!= s.size())
	{
		k.push_back(*iit1);
		iit1++;
		count++;
	}


		cin.clear();
	fflush(stdin);

	//cin.ignore(INT_MAX, '\n');

	int count_depart = 0;
	vector<int> r;
	cout << "Enter list of departments that make your product by space,for example {try : 1 2 4}(notice: enter 'q' and press enter after inputting) - ";
	istream_iterator<int> iit2(cin);
	while (iit2 != eos && count_depart != num_depart)
	{
		r.push_back(*iit2);
		iit2++;
		count_depart++;
	}
	cin.clear();
	fflush(stdin);
	//cin.ignore(INT_MAX, '\n');

	cout << "Enter current quality of product - "; cin >> qual;
	cin.clear();
	fflush(stdin);
	//cin.ignore(INT_MAX, '\n');

	prod[i].initializes(s,k,r,qual, name_pr);
	}
	
}
bool enterprise::has_products(void)
{
	if (number_product >= 1) return true;
	else return false;
}
void enterprise::analyze_order()
{

}
bool enterprise::has_this_product()
{
	for (int i = 0; i < prod.size(); i++)
	{
		if (prod[i].get_name_product().compare(ord->get_kind_prod()) == 0) return true;
	}
   //if (prod[i].get_name_product().compare(ord->get_kind_prod())==0) return true;
	return false;
}
bool enterprise::have_departs()
{
	if (num_depart<1) return false;
	else return true;
}
void enterprise::show_depart(void)
{

	
	for (int i = 0; i < depart.size(); i++)
	{
		cout << "Department #" << i << " : ";
		cout << "name - " << depart[i].get_str_name() << ", workers - " << depart[i].get_number_workers() << ", tecnics - " << depart[i].get_number_tecnic() << ", pos_in_prod - "
			<< i << "; conveyer_lines : \n";
		cout << "         Workers \t" << "Pos_in_production\t" << "Equipment_status\t" << "Time per item(minutes)\t\n";
		for (int j = 0; j < depart[i].get_line().size(); j++)
		{
			cout << "Conv #" << j <<setw(5)<< depart[i].get_line()[j].get_workers()<<setw(20)<< depart[i].get_line()[j].get_pos_in_production() <<setw(23)<<
				depart[i].get_line()[j].get_eqiupment_stat()
				 <<setw(29)<< depart[i].get_line()[j].get_time_per_item() << "\n";
		}
		cout << "\n";
	}
}


void enterprise::show_products(void)
{

	cout << "\nProduction:\n";
	for (int i = 0; i < prod.size(); i++)
	{
		cout << "Product #" << i << " : name - " << prod[i].get_name_product() << ", details(in pairs) - ";
		for (int j = 0; j < prod[i].get_list_details().size(); j++)
		{
			cout << prod[i].get_list_details()[j] << " : " << prod[i].get_number_details()[j];
			if (j + 1 == prod[i].get_list_details().size()) cout << ", ";
			else cout << "; ";
		}
		cout << "department list - ";
		for (int r = 0; r < prod[i].get_list_departments().size(); r++)
		{
			cout << prod[i].get_list_departments()[r];
			if (r + 1 != prod[i].get_list_departments().size())
			{
				cout << ", ";
			}
			else cout << "; ";
		}
		cout << "current quality - " << prod[i].get_quality() << ".\n\n";
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       enterprise::perform_order()
// Purpose:    Implementation of enterprise::perform_order()
// Return:     void
////////////////////////////////////////////////////////////////////////



void enterprise::take_order(void)
{
	cout << "Order was taken!" << endl;
}

void enterprise::perform_order(string s,int position)
{
	vector<int> mater; int o;  vector<string> needed_products; 
	vector<string> dop_needed_materials; vector<int> number_needed_products, departs, dop_number_needed_materials; cout <<"Name - "<< s << ", "<<"pos - "<< position << endl;
	for (int i = 0; i < prod.size(); i++)
	{
		for (int j = 0; j < prod[position].get_list_details().size(); j++)
		{
			if (prod[position].get_list_details()[j].compare(prod[i].get_name_product()) == 0)
			{
				departs.push_back(prod[i].get_list_departments()[0]);   
				needed_products.push_back(prod[i].get_name_product());            
				number_needed_products.push_back(prod[position].get_number_details()[j]);     mater.push_back(j);
				/*for (int s = 0; s < prod[i].get_list_details().size();s++)
				{ 
					needed_materials.push_back(prod[i].get_list_details()[s]);  number_needed_products.push_back(prod[i].get_list_details()[s])
				}
				*/
			}
		}
    }
	if (departs.size() != 0)
	{
		for (int i = 0; i < prod[position].get_list_details().size(); i++)
		{
			o = 1;
			for (int j = 0; j < mater.size(); j++)
			{
				if (mater[j] == i) o = 0;
			}
			if (o != 0) dop_needed_materials.push_back(prod[position].get_list_details()[i]); dop_number_needed_materials.push_back(prod[position].get_number_details()[i]);
		}
		cout << "Departs# - name_product - number products:" << endl; for (int i = 0; i < departs.size(); i++) cout << "Department#"<<departs[i] << ": " << needed_products[i]<<" - " <<number_needed_products[i] << endl;
		cout << "Dop materials:" << endl; for (int i = 0; i < dop_needed_materials.size(); i++) cout << dop_needed_materials[i] << " - " << dop_number_needed_materials[i] << endl;
	}
	//for (int i = 0; i < mater.size(); i++) cout << mater[i] << endl;
	else
	{
		cout << "Department#"<< prod[position].get_list_departments()[0]<<" materials: " << endl; for (int i = 0; i < prod[position].get_list_details().size(); i++) cout << prod[position].get_list_details()[i] << " - " << prod[position].get_number_details()[i] << endl;
	}
     
	//depart[prod[position].get_list_departments()[0]].call_kanban(needed_products, number_needed_products,departs, prod[position].get_list_departments()[0]);
	cout << "Suppose order was perfomed without delays and tecnical break-downs, tecnicians checked equipment, productivity increased!" << endl;
	
	departs.push_back(prod[position].get_list_departments()[0]);
	for (int i = 0; i < departs.size(); i++)
	{
		depart[departs[i]].decrease_equipment();
	}

}



////////////////////////////////////////////////////////////////////////
// Name:       enterprise::show_production()
// Purpose:    Implementation of enterprise::show_production()
// Return:     void
////////////////////////////////////////////////////////////////////////

void enterprise::show_production(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       enterprise::buy_materials()
// Purpose:    Implementation of enterprise::buy_materials()
// Return:     void
////////////////////////////////////////////////////////////////////////

void enterprise::buy_materials(void)
{
	s.set_store(true);
   // TODO : implement
}

void enterprise::input_products(ifstream&f)
{
	string line; int qual;
 
	for (int i = 0; i < number_product; i++)
	{
		vector <string> kind; string name_pr; int qual; vector<int> number_product, list_dep;
		stringstream strst;
		string buff;
		getline(f, buff);	getline(f, buff); name_pr = buff;
		getline(f, buff);
		strst << buff;
		while (!strst.eof()) ///!!!!!!!!!!!!!!
		{
			string x;
			strst >> x;
			kind.push_back(x);
		}
//	for (int i = 0; i < kind.size(); i++) cout << kind[i] << endl;  

		stringstream().swap(strst);	
		getline(f, buff);  
		strst << buff; line = strst.str(); 
		while (!strst.eof())
		{
			int l; 
			strst >> l; 
			number_product.push_back(l);
		}
	//	for (int i = 0; i < number_product.size(); i++) cout << number_product[i] << endl;

		stringstream().swap(strst);
		getline(f, buff);
		strst << buff;
		while (!strst.eof())
		{
			int r;
			strst >> r;
			list_dep.push_back(r);
		}
		//for (int i = 0; i < list_dep.size(); i++) cout << list_dep[i] << endl;
		f >> qual;
		prod[i].initializes(kind, number_product, list_dep, qual, name_pr);
	}

}

////////////////////////////////////////////////////////////////////////
// Name:       enterprise::add_product_from_prototype()
// Purpose:    Implementation of enterprise::add_product_from_prototype()
// Return:     void
////////////////////////////////////////////////////////////////////////

void enterprise::add_product(void)
{
   // TODO : implement
}

int enterprise::find_position(string kind_prod)
{
	for (int i = 0; i < prod.size(); i++)
	{
		if (prod[i].get_name_product().compare(ord->get_kind_prod()) == 0) return i;
	}
}




