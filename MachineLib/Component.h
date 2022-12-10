/**
 * @file Component.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

class Machine;
class Component : public cse335::Polygon {
private:

    wxPoint mPosition;

    double mTime;

    Machine *mMachine;

    double mRotationSpeed;



public:

    /// Constructor
    Component();

    /// Destructor
    virtual ~Component() = default;

    /// Copy constructor/disabled
    Component(const Component&) = delete;

    /// Assignment operator/disabled
    void operator=(const Component&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location);

    virtual void SetPosition(double x, double y);

    double GetX() { return mPosition.x; }
    double GetY() { return mPosition.y; }

    virtual void Update(double time);

    virtual void SetRotationSpeed(double rotationSpeed);

    double GetRotationSpeed() { return mRotationSpeed; }

    double GetTime()  { return mTime; }
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
