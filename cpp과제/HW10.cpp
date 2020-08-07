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

int main()
{
	char str[100];
	San a("관악", 629);
	//복사 생성자
	San b = a;

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	cout << "새로운 산이름을 입력 하시오 : " << endl;
	cin >> str;

	b.setName(str);
	b.setHeight(1234);

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	
	//연산자 오버로딩
	San c;
	c = a;
		
	cout << c.getName() << " : " << c.getHeight() << endl;
	
	return 0;
}