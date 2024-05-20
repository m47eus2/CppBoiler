#include <iostream>
#include <sstream>

using namespace std;

class Drone
{
protected:
    float size;
    float speed;
    float range;
    bool gimbal;
    string camera;

    Drone(float size_, float speed_, float flytime_, float range_, bool gimbal_, string camera_) : size(size_), speed(speed_), range(range_), gimbal(gimbal_), camera(camera_)
    {}

public:
    string getSpeed()
    {
        stringstream ss;
        ss << speed;
        return ss.str();
    }
};

class FpvDrone : public Drone
{
protected:
    string goproType;

public:
    FpvDrone(float size_, float speed_, float flytime_, float range_, string goproType_) : Drone(size_, speed_, flytime_, range_, false, "GoPro")
    {
        goproType = goproType_;
    }

    friend ostream& operator<<(ostream &os, FpvDrone d)
    {
        os << d.size << " " << d.speed << " " << d.range << " " << d.gimbal << " " << d.camera << " " << d.goproType;
    }
};

class DjiDrone : public Drone
{
protected:
    string model;

public:
    DjiDrone(float size_, float speed_, float flytime_, float range_, string model_) : Drone(size_, speed_, flytime_, range_, true, "integrated")
    {
        model = model_;
    }

    friend ostream& operator<<(ostream &os, DjiDrone d)
    {
        os << d.model << " " << d.size << " " << d.speed << " " << d.range << " " << d.gimbal << " " << d.camera << " ";
    }
};

int main()
{
    FpvDrone d1(5, 180, 8, 1.5, "GoPro 12 Black");
    cout << d1 << endl;
    cout << d1.getSpeed() << endl << endl;

    DjiDrone d2(8, 70, 30, 0.5, "Phantom 3");
    cout << d2 << endl;
    cout << d2.getSpeed() << endl;

    return 0;
}