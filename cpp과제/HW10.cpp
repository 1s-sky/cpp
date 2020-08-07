#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

class San {
	char* name;
	int height;
public:
	San();
	San(const char*, int);
	San(const San& r);
	~San();
	void setName(char*);
	char* getName();
	void setHeight(int);
	int getHeight();
	San operator=(const San& r);
};

San::San()
{
	this->name = new char[strlen("noname") + 1];
	strcpy(this->name, "noname");
	this->height = 0;
}
San::San(const char* name, int height) 
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->height = height;
}
San::San(const San& r) 
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->height = r.height;
}
San::~San() 
{
	delete[] this->name;
}
void San::setName(char* name) 
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char* San::getName()
{
	return this->name;
}
void San::setHeight(int height)
{
	this->height = height;
}
int San::getHeight()
{
	return height;
}
San San::operator=(const San& r) 
{
	if (this == &r) { return *this; }
	delete[] this->name;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->height = r.height;
	return *this;
}

int main()
{
	char str[100];
	San a("관악", 629);
	//복사 생성자
	San b = a;

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	cout << "새로운 산이름을 입력 하시오 : ";
	cin >> str;

	b.setName(str);
	b.setHeight(1234);

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	
	//연산자 오버로딩
	San c;
	c = a;
		
	cout << c.getName() << " : " << c.getHeight() << "m" << endl;
	
	return 0;
}