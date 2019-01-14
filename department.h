/***********************************************************************
 * Module:  department.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:23:01
 * Purpose: Declaration of the class department
 ***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "conveyer_line.h"
#include "tecnique.h"
using namespace std;
#if !defined(__ClassDiagram_1_department_h)
#define __ClassDiagram_1_department_h

class conveyer_line;
class tecnique;
class prototype;
class kanban;

class department
{
public:
	department();					//default
	department(string, int, int,int,int);		//initialisation
	department(const department&);		//copy
	~department();					//destructor
//	department(department&&) noexcept = default;
	const string get_str_name(void)
	{
		return name;
    }
	int get_number_workers(void)
	{
		return number_workers;
	}
	int get_number_tecnic(void)
	{
		return number_tecnic;
	}
	int get_pos_in_prod(void)
	{
		return pos_in_prod;
	}
	int get_number_lines(void)
	{
		return number_lines;
	}
	vector <conveyer_line> get_line()
	{
		return line;
	}
	vector <tecnique> get_tecs(void);

	void call();
	void decrease_equipment();
	void add_line(int,int);
	void set_str_name(string);
	void set_number_workers(int);
	void set_number_tecnic(int);
	void set_pos_in_prod(int);
	void set_number_lines(int);
	void add_tecs(void);
	void set_tecs(vector <tecnique>);
	void call_kanban(vector<string> products, vector<int> number_products, vector<int>,int);
	void choose_line();
	void input_line(ifstream&, int,int);
	friend ostream& operator<< (ostream &out,  department &dep)
	{
		//cout << "Department named - " << depart_name << ", workers - " << number_work << ", numberlines - " << numberlines << ", tecniques - " << techs << endl;
		out << "Department named - "  << dep.name << ", workers - "  << dep.number_workers << ", numberlines - " << dep.number_lines<<", tecniques - " << dep.number_tecnic << endl;

		return out;
	}


   void send_kanban(void);
   void estimate_quality_prototype(void);

   kanban* kanb;

protected:
private:
   string name;
   int number_workers;
   int number_tecnic;
   int pos_in_prod;
   int number_lines;
   vector <conveyer_line> line;
   vector <tecnique> tecs;

};

#endif