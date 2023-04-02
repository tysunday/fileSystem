//Задание.
//Реализуйте класс Дробь.Необходимо хранить числитель
//и знаменатель в качестве переменных - членов.Реализуйте
//функции - члены для ввода данных в переменные - члены,
//для выполнения арифметических операций(сложение,
//вычитание, умножение, деление, и т.д.).

#include <iostream>
using namespace std;

class Shot {
public:
	void VisionShot() {
		cout << numerator << "/" << denominator << endl;
	}
	int numerator;
	int denominator;
};

Shot ThirdNumber;

Shot Sum(Shot FirstNumber, Shot SecondNumber) {
	int generalNumerator;
	generalNumerator = FirstNumber.denominator * SecondNumber.denominator;
	FirstNumber.numerator = FirstNumber.numerator * SecondNumber.denominator;
	SecondNumber.numerator = SecondNumber.numerator * FirstNumber.denominator;
	ThirdNumber.denominator = generalNumerator;
	ThirdNumber.numerator = FirstNumber.numerator + SecondNumber.numerator;
	cout << "Результат сложения: ";
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

Shot Multiplied(Shot FirstNumber, Shot SecondNumber) {
	ThirdNumber.numerator = FirstNumber.numerator * SecondNumber.numerator;
	ThirdNumber.denominator = FirstNumber.denominator * SecondNumber.denominator;
	cout << "Результат умножения: ";
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

Shot Division(Shot FirstNumber, Shot SecondNumber) {
	ThirdNumber.numerator = FirstNumber.numerator * SecondNumber.denominator;
	ThirdNumber.denominator = FirstNumber.denominator * SecondNumber.numerator;
	cout << "Результат деления: ";
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

Shot Subtraction(Shot FirstNumber, Shot SecondNumber)
{
	int generalNumerator;
	generalNumerator = FirstNumber.denominator * SecondNumber.denominator;
	FirstNumber.numerator = FirstNumber.numerator * SecondNumber.denominator;
	SecondNumber.numerator = SecondNumber.numerator * FirstNumber.denominator;
	ThirdNumber.denominator = generalNumerator;
	ThirdNumber.numerator = FirstNumber.numerator - SecondNumber.numerator;
	cout << "Результат вычитания: ";
	ThirdNumber.VisionShot();
	return ThirdNumber;
	return ThirdNumber;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Shot FirstNumber;
	FirstNumber.numerator = 3;
	FirstNumber.denominator = 7;

	cout << "Первая дробь: "; FirstNumber.VisionShot(); 

	Shot SecondNumber;
	SecondNumber.numerator = 4;
	SecondNumber.denominator = 5;

	cout << "Вторая дробь: "; SecondNumber.VisionShot(); 

	ThirdNumber = Sum(FirstNumber, SecondNumber);
	ThirdNumber = Multiplied(FirstNumber, SecondNumber);
	ThirdNumber = Division(FirstNumber, SecondNumber);
	ThirdNumber = Subtraction(FirstNumber, SecondNumber);
}

