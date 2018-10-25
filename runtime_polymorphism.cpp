#include<iostream>
using namespace std;
	
class base{
	int a, b;
	public:
	int result;
		
	virtual void print(){
		cout << "Print from base class: " << result << endl;
	}


        void show(){
                cout << "Show from base class: " << result << endl;
        }


	void operation(int x, int y){
		a=x;
		b=y;
		result = a+b;
	} 
};

class derived : public base{
        int a, b;
        public:
        int result;

        void print(){
                cout << "Print from derived class: " << result << endl;
        }
        void show(){
                cout << "Show from derived class: " << result << endl;
        }


        void operation(int x, int y){
                a=x;
                b=y;
                result = a*b;
        }
};

int main(){
	base* b;
	derived d;
	b = &d;

	b->operation(2,5);
	b->print();
	b->show();

	d.operation(2,5);
	d.print();	 
	return 0;	
}
