#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
	private: 
	int width;
	int height;
	
	public:
	
	Rectangle();
	
	Rectangle(int w, int h)
	{
		width = w;
		height = h;
		cout << "New Rectangle Created.  Width = " << width << "; Height = " << height << endl;
	}
	
	int Area()
	{
		return width*height;
	}
};

int main()
{
	Rectangle r1(8, 4);
	
	cout << "Area del rectangulo: " << r1.Area() << endl;
	
	return 0;
}
