#pragma once
class CalculateDistance
{
public:
	CalculateDistance();
	CalculateDistance(int x, int y, int z);

	void setX(int x);
	void setY(int y);
	void setZ(int z);

	int getX();
	int getY();
	int getZ();

	
	void magnify();
	void scalingZ();

	~CalculateDistance();
private:
	int x;
	int y;
	int z;
};

