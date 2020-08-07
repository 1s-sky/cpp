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
	San a("����", 629);
	//���� ������
	San b = a;

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	cout << "���ο� ���̸��� �Է� �Ͻÿ� : " << endl;
	cin >> str;

	b.setName(str);
	b.setHeight(1234);

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	
	//������ �����ε�
	San c;
	c = a;
		
	cout << c.getName() << " : " << c.getHeight() << endl;
	
	return 0;
}