#include<bits/stdc++.h>
using namespace std;

//base class
class employee{
public:
	int id;   
	float salary;
	employee(int money)
	{
		id=1;salary=money;
	}
	employee(){};
};

//derived class syntax
/*
class {{derived-class-name}}:{{visibility-mode}}{{base-class-name}}
{
	class members/methods/etc..
}
1. default visibility mode is private
2. private visibility mode:public members of the base class becomes the private
members of the derived class
3.public visibility mode: public members of the base class becomes
public members of the derived class
4. private members are never inherited
5. Inheritence will only call the default constructor
*/

//creating a programmer class from emplyee class

class Programmer:employee{ //it will try to call the default constructor of employee
public:
	Programmer(int ids)
	{
		id=ids;
	}
	void showData(void)
	{
		cout<<id;
	}
	int languageCode=9;
};

int main()
{
    employee himanshu(50000);
    Programmer shubh(2);
    shubh.showData();
    //it will run shubh.id only when the visibility is set to public
    return 0;
}