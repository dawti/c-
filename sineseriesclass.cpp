#include<iostream>
#include<string>
using namespace std;
//namespace sine
//{
	const double Pi = 3.14159;
	class Sine
	{
		double d;
		double r;
		double sinx;
		void GetRadian(double d);
	public:
	//	Sine(double d) :d(0), r(0), sinx(0)
	//	{
	//	}
		
		void GetSine(double d);
		void Display() const
		{
			cout << "Sin(" << d << ")=" << sinx << '\n';
		}
	};

	void Sine::GetRadian(double d)
	{
		this->d = d;
		this->r = d * Pi / 180;
	}

	void Sine::GetSine(double d)
	{
		double term;
		GetRadian(d);
		term = r;
		this->sinx = r;
		for (int i = 1; i < 50; i++)
		{
			term *= -(double)(r * r) / ((2 * i) * (2 * i + 1));
			sinx += term;

		}
	}

	int main()
	{
		double degree;
		Sine sg;
		cout << "Enter angle in degree: ";
		cin >> degree;
		sg.GetSine(degree);
		sg.Display();
		

		return 0;
	}
//}