#pragma once
#include <string.h>
using namespace std;
template <class T1>
class Vector  //class for 3d vector
{
private:
	T1* pointX;
	T1* pointY;
	T1* pointZ;
	char* name;
	void init()
	{
		pointX = new T1;
		pointY = new T1;
		pointZ = new T1;
	}

public:
	Vector()
	{
		init();
	}

	Vector(T1 x,T1 y,T1 z,const char* name)
	{
		init();
		setname(name);
		setpointX(x);
		setpointY(y);
		setpointZ(z);
	}

	friend std::ostream& operator << (std::ostream& str, Vector<T1>& his)
	{
		str << "Vector name:" << his.getname() << endl;
		str << "Point x:" << his.getpointX() << endl;
		str << "Point y:" << his.getpointY() << endl;
		str << "Point z:" << his.getpointZ() << endl;
		return str;
	}

	friend std::istream& operator >> (std::istream& str, Vector<T1>& his)
	{
		T1 input;
		char* nam = new char[256];
		cout << "Write name of vector\n";
		str >> nam;
	    his.setname(const_cast<char*>(nam));
		cout << "Write point X\n";
		str >> input;
		his.setpointX(input);
		cout << "Write point Y\n";
		str >> input;
		his.setpointY(input);
		cout << "Write point Z\n";
		str >> input;
		his.setpointZ(input);
		return str;
	}

    Vector<T1> operator + (Vector<T1>& other); //Add vectors
	Vector<T1> operator - (Vector<T1>& other); 
	Vector<T1> operator ^ (Vector<T1>& other); //Vector multiplication
	T1 operator * (Vector<T1>& other); //scalar multiplication


	void setpointX(T1 x);
	void setpointY(T1 y);
	void setpointZ(T1 z);
	void setname(const char* name);

	T1 getpointX(void);
	T1 getpointY(void);
	T1 getpointZ(void);
	const char* getname(void);
	T1 getmodule(void);
	void multnum(T1 num);

};

template <class T1>
void Vector<T1>::setpointX(T1 x)
{
	if (x != NULL)
	{
		*this->pointX = x;
	}
}

template <class T1>
void Vector<T1>::setpointY(T1 y)
{
	if (y != NULL)
	{
		*this->pointY = y;
	}
}

template <class T1>
void Vector<T1>::setpointZ(T1 z)
{
	if (z != NULL)
	{
		*this->pointZ = z;
	}
}

template <class T1>
T1 Vector<T1>::getpointX(void)
{
	if (*this->pointX != NULL)
	{
		return *this->pointX;
	}
}

template <class T1>
T1 Vector<T1>::getpointY(void)
{
	if (*this->pointY != NULL)
	{
		return *this->pointY;
	}
}

template <class T1>
T1 Vector<T1>::getpointZ(void)
{
	if (*this->pointZ != NULL)
	{
		return *this->pointZ;
	}
}

template <class T1>
void Vector<T1>::setname(const char* nam)
{
	if (this->name != NULL)
	{
		free(this->name);
	}
	this->name = (char*)malloc(sizeof(char) * (strlen(nam) + 1));
	this->name = _strdup(nam);
	
}

template <class T1>
const char* Vector<T1>::getname(void)
{
	if (*this->name != NULL)
	{
		return this->name;
	}
}

template <class T1>
Vector<T1> Vector<T1>::operator + (Vector<T1>& other)
{
    const char* res = "Plus:";
	Vector result(0, 0, 0, res);
	result.setpointX(getpointX() + other.getpointX());
	result.setpointY(getpointY() + other.getpointY());
	result.setpointZ(getpointZ() + other.getpointZ());
	return result;
}

template <class T1>
Vector<T1> Vector<T1>::operator - (Vector<T1>& other)
{
	const char* res = "Minus";
	Vector result(0, 0, 0, res);
	result.setpointX(getpointX() - other.getpointX());
	result.setpointY(getpointY() - other.getpointY());
	result.setpointZ(getpointZ() - other.getpointZ());
	return result;
}

template <class T1>
T1 Vector<T1>::operator * (Vector<T1>& other)
{
	T1 result;
	result  = getpointX() * other.getpointX();
	result += getpointY() * other.getpointY();
	result += getpointZ() * other.getpointZ();
	return result;
}

template <class T1>
Vector<T1> Vector<T1>::operator ^ (Vector<T1>& other)
{
	const char* res = "Vector Multiplication";
	Vector result(0, 0, 0, res);
	result.setpointX(getpointY() * other.getpointZ() - getpointZ() * other.getpointY());
	result.setpointY(getpointZ() * other.getpointX() - getpointX() * other.getpointZ());
	result.setpointZ(getpointX() * other.getpointY() - getpointY() * other.getpointX());
	return result;
}

template <class T1>
T1 Vector<T1>::getmodule(void)
{
	T1 result;
	result = sqrt((getpointX() * getpointX()) + (getpointY() * getpointY()) + (getpointZ() * getpointZ()));
	return result;
}

template <class T1>
void Vector<T1>::multnum(T1 num)
{
	this->setpointX(this->getpointX() * num);
	this->setpointY(this->getpointY() * num);
	this->setpointZ(this->getpointZ() * num);
}