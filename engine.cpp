#include <iostream>

using namespace std;

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
        void drawPoint();
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

int main(int argc, char const *argv[]){
    cout<<"Welcome to Game Engine\n";
    Point point1(1,2,1);
    Point point2(0,4,4);
    Vector vector1(2,0,0);
    Vector vector2;

    point1.drawPoint();
    point2.drawPoint();

    vector2 = point1.subtractPointFromPoint(point2);
    vector1 = vector1.addVectorToVector(vector2);

    point1 = point1.addVectorToPoint(vector1);
    point1.drawPoint();

    point2 = point2.subtractVectorFromPoint(vector2);
    point2.drawPoint();
    return 0;
}

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

void Point::drawPoint(){
    cout<<"Point is ( "<<this->tuple[0]<<", "<<this->tuple[1]<<", "<<this->tuple[2]<<" ).\n";
}