#define _CRT_SECURE_NO_WARNINGS
#include "libr.h"
#include <vector>
#include <string> 
#include <iostream>
#include <iterator>
#include <conio.h>
#include<fstream>

void menu1()
{
	float productivity; int num_dp, prod_num;
	cout << "Enter number departments - "; cin >> num_dp;
	cout << "Enter number products - "; cin >> prod_num;
	cout << "Enter power productivity - "; cin >> productivity;
	enterprise factory(productivity, num_dp, prod_num);
	bool departs = false; bool productions = false;
	cout << "Press something to continue...." << endl; system("pause"); system("cls");
	if (factory.have_departs())
	{
		factory.describe_department(num_dp); departs = true; system("pause"); system("cls");
	}
	else cout << "Your enterprise has no departments!" << endl;

	if (factory.has_products())
	{
		factory.describe_products(prod_num); productions = true;
	}
	else cout << "No production is defined!" << endl;
	if (departs && productions)cout << "You finally described enterprise!" << endl;
	char x;
	do
	{
		cout << "1.Show info departments\n"
			<< "2.Show info products\n"
			<< "3.Qualify workers\n"
			<< "4.Take order\n"
			<< "5.Add product\n"
			<< "6.Add department\n"
			<< "0.Exit\n";
		switch (x = _getch())
		{
		case '1': if (factory.have_departs())
		{
		factory.show_depart(); break;
		}
				  else cout << "You have no departments!" << endl; break;
		case '2': if (factory.has_products())
		{
			 factory.show_products(); break;
		}
				  else cout << "No production in your enterprise.Its bad!\n"; break;
		case'3':  cout << "Notice:input countdown starts from index 0:\n"; factory.choose_depart(); break;
		case '4': if (factory.get_s().have_materials())
		{
					  int c = factory.get_pow(); ++factory;
					  factory.create_order(); cout << "Previous productivity - " << c << ", productivity after performing order - " << factory.get_pow() << endl;
					  factory.ord->get_kind_prod();
					  break;
		}
				  else cout << "U cant take order without resources!" << endl; break;
		case '5': int w; cout << "Enter number of products u want to add - "; cin >> w; factory.describe_products(w); break;
		case '6': int l; cout << "Enter number of departments to add - "; cin >> l; factory.describe_department(l); break;
		case'0':exit(0); break;

		}
		system("pause");
		system("cls");
	} while (x != '0');
	system("pause");

}

void menu2()
{
	float produc; int dep, prod; 
	ifstream f("data.txt");
	f >> produc;
	f >> dep;
	f >> prod;
	enterprise factory(produc, dep, prod,true);
	cout << "\nData received...\n" << endl;
    factory.input_departments(f);
	factory.show_depart();
	factory.input_products(f);

	factory.get();
	system("pause");
	system("cls");
	char x;
	do
	{
		cout << "1.Show info departments\n"
			<< "2.Show info products\n"
			<< "3.Qualify workers\n"
			<< "4.Take order\n"
			<< "5.Add product\n"
			<< "6.Add department\n"
			<< "0.Exit\n";
		switch (x = _getch())
		{
		case '1': if (factory.have_departs())
		{
			factory.show_depart(); break;
		}
				  else cout << "You have no departments!" << endl; break;
		case '2': if (factory.has_products())
		{
			factory.show_products(); break;
		}
				  else cout << "No production in your enterprise.Its bad!\n"; break;
		case'3': cout << "Notice:input countdown starts from index 0:\n"; factory.choose_depart(); break;
		case '4': if (factory.get_s().have_materials())
		{
					  int c = factory.get_pow(); ++factory;
					  if (factory.create_order())
					  {
						  cout << "Previous productivity - " << c << ", productivity after performing order - " << factory.get_pow() << endl;
					  }
					  break;
		}
				  else cout << "U cant take order without resources!" << endl; break;
		case '5': int w; cout << "Enter number of products u want to add - "; cin >> w; factory.describe_products(w); break;
		case '6': int l; cout << "Enter number of departments to add - "; cin >> l; factory.describe_department(l); break;
		case'0':exit(0); break;
		default:break;
		}

		system("pause");
		system("cls");
	} while (x != '0');

}
int main()
{
	{  
		bool n;
		cout << "Lab 6 done by Shylyuk David, IS-73" << endl;
		cout << "Added new class 'Worker','hand_worker' and 'tecnique' inherit from him.\nAdded virtual function which is used when increasing qualification of workers(displays message about succesful upgrade).\nNow order'ord' is initialized only when we take order" << endl;
		cout << "Program is running..." << endl;
		cout << "-------------------" << endl;
		do
		{
			n = true;
			cout << "Wanna create enterprise by yourself or from file-data?(1,2)\nBetter use file not to waste time...\n";
			switch (_getch())
			{
			case'1':menu1(); break;
			case '2':menu2(); break;
			default:n = false; system("pause"); system("cls"); break;

			}
		} while (n == false);
	

	
	}

}