#pragma once
class Square
{
public:
	Square();

	void read();
	
	void setLength(float length);
	void setHeight(float height);

	float getLength();
	float getHeight();

	float perimeter(float length, float height);
	float area(float length, float height);
	~Square();

private:
	float length;
	float height;
};

