#pragma once
class Calculator
{
public:
	Calculator();
	Calculator(float number1, float number2);

	void setNumber1(float number1);
	void setNumber2(float number2);

	float getNumber1();
	float getNumber2();

	float addition(float number1, float number2);
	float substraction(float number1, float number2);
	float multiplication(float number1, float number2);
	float division(float number1, float number2);

	~Calculator();
private:
	float number1;
	float number2;
};

