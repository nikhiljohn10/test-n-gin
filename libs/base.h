
class Vector;

class Point{
public:
	double tuple[3];
	Point(double x=0.0, double y=0.0, double z=0.0){
		tuple[0] = x;
		tuple[1] = y;
		tuple[2] = z;
	}
	Point addVectorToPoint(Vector);
	Point subtractVectorFromPoint(Vector);
	Vector subtractPointFromPoint(Point);
	void drawPoint(int,int,int);
};

class Vector{
public:
	double tuple[3];
	Vector(double x=0.0, double y=0.0, double z=0.0){
		tuple[0] = x;
		tuple[1] = y;
		tuple[2] = z;
	}
	Vector addVectorToVector(Vector);
	Vector subtractVectorFromVector(Vector);
};

Point Point::addVectorToPoint(Vector vector){
	Point temp;
	temp.tuple[0] = this->tuple[0] + vector.tuple[0];
	temp.tuple[1] = this->tuple[1] + vector.tuple[1];
	temp.tuple[2] = this->tuple[2] + vector.tuple[2];
	return temp;
}

Point Point::subtractVectorFromPoint(Vector vector){
	Point temp;
	temp.tuple[0] = this->tuple[0] - vector.tuple[0];
	temp.tuple[1] = this->tuple[1] - vector.tuple[1];
	temp.tuple[2] = this->tuple[2] - vector.tuple[2];
	return temp;
}

Vector Point::subtractPointFromPoint(Point point){
	Vector temp;
	temp.tuple[0] = this->tuple[0] - point.tuple[0];
	temp.tuple[1] = this->tuple[1] - point.tuple[1];
	temp.tuple[2] = this->tuple[2] - point.tuple[2];
	return temp;
}

Vector Vector::addVectorToVector(Vector vector){
	Vector temp;
	temp.tuple[0] = this->tuple[0] + vector.tuple[0];
	temp.tuple[1] = this->tuple[1] + vector.tuple[1];
	temp.tuple[2] = this->tuple[2] + vector.tuple[2];
	return temp;
}

Vector Vector::subtractVectorFromVector(Vector vector){
	Vector temp;
	temp.tuple[0] = this->tuple[0] - vector.tuple[0];
	temp.tuple[1] = this->tuple[1] - vector.tuple[1];
	temp.tuple[2] = this->tuple[2] - vector.tuple[2];
	return temp;
}
