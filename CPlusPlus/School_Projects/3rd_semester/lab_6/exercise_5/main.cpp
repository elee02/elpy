#include <iostream>
using namespace std;

class Triangle {
private:
	double m_base;
	double m_height;
public:
	Triangle(const double &base = 0, const double &height = 0)
	: m_base{ base }, m_height{ height } {
		if (base <= 0.0 || height <= 0.0) {
			cout << "Error: Invalid input" << endl;
			exit(1);
		}
	}

	double getBase() const { return m_base; }
	double getHeight() const { return m_height; }

	double area() const { return m_base * m_height / 2.0; }

	~Triangle() {
		cout << "Base: " << m_base << " -- deleted" << endl;
		cout << "Height: " << m_height << " -- deleted" << endl;
	}
};
int main()
{
	Triangle t1{ 10.5, 4.5 };
	const Triangle t2{ 7.0, 3.0 };

	cout << "Triangle t1{ 10.5, 4.5 }" << endl;
	cout << "  base: " << t1.getBase() << endl;
	cout << "  height: " << t1.getHeight() << endl;
	cout << "  area: " << t1.area() << endl << endl;

	cout << "const Triangle t2{ 7.0, 3.0 }" << endl;
	cout << "  base: " << t2.getBase() << endl;
	cout << "  height: " << t2.getHeight() << endl;
	cout << "  area: " << t2.area() << endl << endl;

	return 0;
}