#include <math.h>

#define CODX tuple[0]
#define CODY tuple[1]
#define CODZ tuple[2]
#define THIS_X this->CODX
#define THIS_Y this->CODY
#define THIS_Z this->CODZ
#define POINT_X point.CODX
#define POINT_Y point.CODY
#define POINT_Z point.CODZ
#define VECTOR_X vector.CODX
#define VECTOR_Y vector.CODY
#define VECTOR_Z vector.CODZ

using namespace std;

class Vector;

class Matrix{
public:
	double rotMatXY[3][3] = {{1.0, 0.0, 0.0},{0.0, 1.0, 0.0},{0.0, 0.0, 1.0}};
	double rotMatXZ[3][3] = {{1.0, 0.0, 0.0},{0.0, 1.0, 0.0},{0.0, 0.0, 1.0}};
	double rotMatYZ[3][3] = {{1.0, 0.0, 0.0},{0.0, 1.0, 0.0},{0.0, 0.0, 1.0}};
	void initRotMatXY(double deg){
		double rad = deg * 3.14159265358979323846 / 180;
		rotMatXY[0][0] = cos(rad);
		rotMatXY[0][1] = -sin(rad);
		rotMatXY[1][0] = sin(rad);
		rotMatXY[1][1] = cos(rad);
	}
	void initRotMatXZ(double deg){
		double rad = deg * 3.14159265358979323846 / 180;
		rotMatXZ[0][0] = cos(rad);
		rotMatXZ[0][2] = sin(rad);
		rotMatXZ[2][0] = -sin(rad);
		rotMatXZ[2][2] = cos(rad);
	}
	void initRotMatYZ(double deg){
		double rad = deg * 3.14159265358979323846 / 180;
		rotMatYZ[1][1] = cos(rad);
		rotMatYZ[1][2] = -sin(rad);
		rotMatYZ[2][1] = sin(rad);
		rotMatYZ[2][2] = cos(rad);
	}
};

// Point Class

class Point{
public:
	double tuple[3];
	Point(double x=0.0, double y=0.0, double z=0.0){
		CODX = x;
		CODY = y;
		CODZ = z;
	}
	Point addVectorToPoint(Vector);
	Point subtractVectorFromPoint(Vector);
	Vector subtractPointFromPoint(Point);
	void drawPoint(int,int,int);
	void setPointToPoint(Point);
};

// Vector Class

class Vector: public Matrix{
public:
	double tuple[3];
	Vector(double x=0.0, double y=0.0, double z=0.0){
		CODX = x;
		CODY = y;
		CODZ = z;
	}
	Vector addVectorToVector(Vector);
	Vector subtractVectorFromVector(Vector);
	Vector rotateVectorXY(double);
	Vector rotateVectorXZ(double);
	Vector rotateVectorYZ(double);
	Vector scaleVector(double, double, double);
	Vector translateVector(double, double, double);
};

// Point class function

Point Point::addVectorToPoint(Vector vector){
	Point temp;
	temp.CODX = THIS_X + VECTOR_X;
	temp.CODY = THIS_Y + VECTOR_Y;
	temp.CODZ = THIS_Z + VECTOR_Z;
	return temp;
}

Point Point::subtractVectorFromPoint(Vector vector){
	Point temp;
	temp.CODX = THIS_X - VECTOR_X;
	temp.CODY = THIS_Y - VECTOR_Y;
	temp.CODZ = THIS_Z - VECTOR_Z;
	return temp;
}

Vector Point::subtractPointFromPoint(Point point){
	Vector temp;
	temp.CODX = THIS_X - POINT_X;
	temp.CODY = THIS_Y - POINT_Y;
	temp.CODZ = THIS_Z - POINT_Z;
	return temp;
}

void Point::setPointToPoint(Point point){
	THIS_X = POINT_X;
	THIS_Y = POINT_Y;
	THIS_Z = POINT_Z;
}

// Vector class function

Vector Vector::addVectorToVector(Vector vector){
	Vector temp;
	temp.CODX = THIS_X + VECTOR_X;
	temp.CODY = THIS_Y + VECTOR_Y;
	temp.CODZ = THIS_Z + VECTOR_Z;
	return temp;
}

Vector Vector::subtractVectorFromVector(Vector vector){
	Vector temp;
	temp.CODX = THIS_X - VECTOR_X;
	temp.CODY = THIS_Y - VECTOR_Y;
	temp.CODZ = THIS_Z - VECTOR_Z;
	return temp;
}

Vector Vector::rotateVectorXY(double deg){
	Vector temp;
	temp.initRotMatXY(deg);
	temp.CODX = temp.rotMatXY[0][0] * THIS_X + temp.rotMatXY[0][1] * THIS_Y + temp.rotMatXY[0][2] * THIS_Z;
	temp.CODY = temp.rotMatXY[1][0] * THIS_X + temp.rotMatXY[1][1] * THIS_Y + temp.rotMatXY[1][2] * THIS_Z;
	temp.CODZ = temp.rotMatXY[2][0] * THIS_X + temp.rotMatXY[2][1] * THIS_Y + temp.rotMatXY[2][2] * THIS_Z;
	return temp;
}

Vector Vector::rotateVectorXZ(double deg){
	Vector temp;
	temp.initRotMatXZ(deg);
	temp.CODX = temp.rotMatXZ[0][0] * THIS_X + temp.rotMatXZ[0][1] * THIS_Y + temp.rotMatXZ[0][2] * THIS_Z;
	temp.CODY = temp.rotMatXZ[1][0] * THIS_X + temp.rotMatXZ[1][1] * THIS_Y + temp.rotMatXZ[1][2] * THIS_Z;
	temp.CODZ = temp.rotMatXZ[2][0] * THIS_X + temp.rotMatXZ[2][1] * THIS_Y + temp.rotMatXZ[2][2] * THIS_Z;
	return temp;
}

Vector Vector::rotateVectorYZ(double deg){
	Vector temp;
	temp.initRotMatYZ(deg);
	temp.CODX = temp.rotMatYZ[0][0] * THIS_X + temp.rotMatYZ[0][1] * THIS_Y + temp.rotMatYZ[0][2] * THIS_Z;
	temp.CODY = temp.rotMatYZ[1][0] * THIS_X + temp.rotMatYZ[1][1] * THIS_Y + temp.rotMatYZ[1][2] * THIS_Z;
	temp.CODZ = temp.rotMatYZ[2][0] * THIS_X + temp.rotMatYZ[2][1] * THIS_Y + temp.rotMatYZ[2][2] * THIS_Z;
	return temp;
}

Vector Vector::scaleVector(double sx, double sy, double sz){
	Vector temp;
	temp.CODX = sx * THIS_X;
	temp.CODY = sy * THIS_Y;
	temp.CODZ = sz * THIS_Z;
	return temp;
}

Vector Vector::translateVector(double tx, double ty, double tz){
	Vector temp;
	temp.CODX = tx + THIS_X;
	temp.CODY = ty + THIS_Y;
	temp.CODZ = tz + THIS_Z;
	return temp;
}