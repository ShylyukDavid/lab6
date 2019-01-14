#pragma once
#include <string>
#include <vector>



class Worker
{
public:

	int qualification;
	int worked_years;
	Worker();					//default
	Worker(int, int);		//initialisation
	Worker(const Worker&);		//copy
	~Worker();					//destructor
	int get_qualification(void)
	{
		return qualification;
	}
	int get_worked_years(void)
	{
		return worked_years;
	}
	//int get_num_pos(void);
	//int get_qualification(void);
	//void signal_stop(void);
	//void visit_sems(void);
	virtual void display()
	{

		//cout << "Virtual function worker!" << endl;
	}
	virtual void display2()
	{

		//cout << "Virtual function worker!" << endl;
	}
protected:
private:
	int num_pos;
};

