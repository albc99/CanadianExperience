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
    double mRotation;
    double mTime;

    Machine *mMachine;

public:
    /// Constructor
    Component();

    /// Destructor
    virtual ~Component() = default;

//    /// Copy constructor/disabled
//    Component(const Component&) = delete;

    /// Assignment operator/disabled
    void operator=(const Component&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location);

    virtual void SetPosition(wxPoint position) { mPosition = position; }

    wxPoint GetPosition() { return mPosition; }

    virtual void Update(double time);

    virtual void SetRotationSpeed(double rotationSpeed);
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
