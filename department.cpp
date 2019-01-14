/***********************************************************************
* Module:  department.cpp
* Author:  David
* Modified: четверг, 22 но€бр€ 2018 г. 01:23:01
* Purpose: Implementation of the class department
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "conveyer_line.h"
#include "tecnique.h"
#include "prototype.h"
#include "kanban.h"
#include "department.h"
#include <fstream>
////////////////////////////////////////////////////////////////////////
// Name:       department::send_kanban()
// Purpose:    Implementation of department::send_kanban()
// Return:     void
////////////////////////////////////////////////////////////////////////
department::department() :
	name(""),
	number_workers(10),
	number_tecnic(3),
	pos_in_prod(1),
	number_lines(2),
	line(0),
	tecs(0),
	kanb(new kanban())
{
	//cout << "Department was initialized (default).\n";
}


department::department(string name, int number_workers, int number_tecnic, int pos_in_prod, int number_lines) :
	name(name),
	number_workers(number_workers),
	number_tecnic(number_tecnic),
	pos_in_prod(pos_in_prod),
	number_lines(number_lines),
	line(0),
	tecs(0),
	kanb(new kanban())

{
	cout << "Department line was initialized (normal).\n";
}
department::department(const department & dep) :
	name(dep.name),
	number_workers(dep.number_workers),
	number_tecnic(dep.number_tecnic),
	pos_in_prod(dep.pos_in_prod),
	number_lines(dep.number_lines),
	kanb(dep.kanb)
{
}

department::~department() { }



void department::add_tecs(void)
{
	srand(time(NULL));
	for (int i = 0; i < number_tecnic; i++)
	{
		int s = rand() % 5 + 0;
		int k = rand() % 10 + 1;
		tecs.emplace_back(s, k);
	}
}

vector<tecnique> department::get_tecs(void)
{
	return vector<tecnique>(tecs);
}

void department::call()
{
	line[0].calls();
}

void department::decrease_equipment()
{
	for (int i = 0; i < line.size(); i++) --line[i];
}

void department::add_line(int s, int k)
{
	int time_per_item, equip_status; // tecnics, years;
	for (int i = 0; i < s; i++)
	{

		cout << "\nConveyer_line #" << i << ":" << endl;
		cout << "Enter time per making 1 item- ";
		cin >> time_per_item;
		cout << "Enter equip state(0<x<10) - ";
		cin >> equip_status;
		cout << "Position automatically - " << i << endl;
		this->line.emplace_back(k, i, equip_status, time_per_item, false, "green", false);
		this->line[i].add_workers();
	}
}

void department::set_str_name(string s)
{
	name = s;
}

void department::set_number_workers(int s)
{
	number_workers = s;
}

void department::set_number_tecnic(int s)
{
	s = number_tecnic;
}

void department::set_pos_in_prod(int s)
{
	pos_in_prod = s;
}

void department::set_number_lines(int s)
{
	number_lines = s;
}

/*void department::set_line(vector<conveyer_line> s)
{
line = s;
}
*/
void department::set_tecs(vector<tecnique>s)
{
	tecs = s;
}

void department::call_kanban(vector<string> products, vector<int>number_products, vector<int>departs,int s)
{

}

void department::choose_line()
{
	int choice;
	do
	{
		cout << "Enter number of line to qualify its workers(existing - "<<line.size()<<") - ";
		cin >> choice;
	} while (choice >= line.size() || choice<0);
	line[choice].choose_workers();
}

void department::input_line(ifstream &f, int number_lines, int workers)
{
	int time_per_item, equip_status;

	for (int i = 0; i < number_lines; i++)
	{
		f >> time_per_item >> equip_status;
		this->line.emplace_back(workers/number_lines, i, equip_status, time_per_item, false, false);
		this->line[i].input_workers(f, workers / number_lines);
	}
}




void department::send_kanban(void)
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       department::estimate_quality_prototype()
// Purpose:    Implementation of department::estimate_quality_prototype()
// Return:     void
////////////////////////////////////////////////////////////////////////

void department::estimate_quality_prototype(void)
{
	// TODO : implement
}