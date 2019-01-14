/***********************************************************************
 * Module:  prototype.h
 * Author:  David
 * Modified: вторник, 20 но€бр€ 2018 г. 13:27:00
 * Purpose: Declaration of the class prototype
 ***********************************************************************/
#include <string>
#include <vector>
#if !defined(__ClassDiagram_1_prototype_h)
#define __ClassDiagram_1_prototype_h
using namespace std;
class prototype
{
public:
	string name_prod;
	vector<string> kind_detail;
	vector<int> needed_detail;

	prototype();					//default
	prototype(string, vector<string>, vector<int>,bool);		//initialisation
	prototype(const prototype& );		//copy
	~prototype();					//destructor

   void create_prototype(void);
   void approve_prototype(void);

protected:

private:
	
	bool approved;
};

#endif