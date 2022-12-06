/**
 * @file RotationSink.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

#include "Component.h"

class RotationSource;
class Pulley;

class RotationSink {
private:
    double mRotationSpeed;
    RotationSource *mRotationSource;
    Component *mComponent;


public:
    /// Constructor
    RotationSink();

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSink &) = delete;

    void UpdateRotation(double rotation);

    void SetRotationSpeed(double rotationSpeed) { mComponent->SetRotationSpeed(rotationSpeed); }

    void SetSource(RotationSource *source) { mRotationSource = source; }

//    Component *GetComponent() { return mComponent; }
    void SetComponent(Component *component) { mComponent = component; }
};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
