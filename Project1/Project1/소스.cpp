#include<iostream>
using namespace std;

int Value = 20;
class  Test
{
public:
	void Function()
	{
		printf_s("%d", Value);
	}
private:

};


int main()
{
	Test* Ptr = nullptr;
	Ptr->Function();

}