/**
 * @file RotationSource.hhttps://github.com/albc99/test.git
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include "RotationSink.h"
#include "Component.h"

class Motor;
class Pulley;

class RotationSource {
private:
    Motor *mMotor;

    /// The sinks
    std::vector<RotationSink*> mSinks;

    Pulley *mPulley;

public:
    /// Constructor
    RotationSource();

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource &) = delete;

    void UpdateRotation(double rotation);

    void Update(double time);

    void AddSink(RotationSink *sink); // set source in here.


};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
