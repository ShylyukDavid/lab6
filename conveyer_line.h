/***********************************************************************
 * Module:  conveyer_line.h
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:34:18
 * Purpose: Declaration of the class conveyer_line
 ***********************************************************************/
#include "hand_worker.h"
#include <string>
#include <vector>
using namespace std;
#if !defined(__ClassDiagram_1_conveyer_line_h)
#define __ClassDiagram_1_conveyer_line_h

class hand_worker;

class conveyer_line
{
public:
	conveyer_line();
	conveyer_line(int s);					//default
	conveyer_line(int,int,int,int,bool,string,bool);		//initialisation
	conveyer_line(int, int, int, int, bool, bool);		//initialisation
	conveyer_line(const conveyer_line&);		//copy
	~conveyer_line();					//destructor

	const int get_workers(void)
	{
		return hand.size();
	}
	int get_pos_in_production(void)
	{
		return pos_in_production;
	}
	void calls();
	int get_eqiupment_stat(void)
	{
		return eqiupment_stat;
	}
	int get_time_per_item(void)
	{
		return time_per_item;
	}
	bool get_work_taken(void);
	string get_color_danger(void)
	{
		return string(color_danger);
	}
	vector<hand_worker> get_hand(void);
	//conveyer_line(conveyer_line&&) noexcept = default;
	void choose_workers();
	conveyer_line& operator-- ()
	{
		eqiupment_stat -= 1;
		return *this;
	}
	void add_workers(void);
	void set_pos_in_production(int);
	void set_eqiupment_stat(int);
	void set_time_per_item(int);
	void set_color_danger(string);
	void set_hand(vector<hand_worker>);
	void input_workers(ifstream &f,int);


   void make_item_product(void);
protected:
private:
   const int workers;
   int pos_in_production;
   int eqiupment_stat;
   int time_per_item;
   bool work_taken;
   string color_danger;
   bool current_work_performed;
   vector<hand_worker> hand;




};

#endif