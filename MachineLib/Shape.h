/**
 * @file Shape.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "MachineSystemImplemented.h"
#include "RotationSink.h"

class Shape : public Component {
private:
    RotationSink mSink;

public:
    /// Constructor
    Shape();

    /// Destructor
    virtual ~Shape() = default;

    /// Copy constructor/disabled
    Shape(const Shape&) = delete;

    /// Assignment operator/disabled
    void operator=(const Shape&) = delete;

//    virtual void SetRotation(double rotationSpeed) override;

    RotationSink *GetSink(){ return &mSink; }
};

#endif //CANADIANEXPERIENCE_SHAPE_H
