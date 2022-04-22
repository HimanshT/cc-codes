#include<bits/stdc++.h>
using namespace std;

//destructor never takes an argument nor does it return any value

class num{
	int count=5;
public:
	num(){
		count++;
		cout<<"constructor ran"<<endl;
	}

	~num(){
		cout<<"destructor called"<<endl;
		count--;
	}
};

int main()
{
    cout<<"main fn"<<endl;
    cout<<"creating first object"<<endl;
    num n1;
    {
    cout<<"creating two more objects"<<endl;
    num n2,n3;
    cout<<"exiting block\n";
    }
    
	return 0;
}

//when the object feels there is no need of the 
//object so compiler calls the destructor