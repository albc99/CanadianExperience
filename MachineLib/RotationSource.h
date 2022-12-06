/**
 * @file RotationSource.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include "RotationSink.h"
#include "Component.h"

class Motor;

class RotationSource {
private:
    Motor *mMotor;

    /// The sinks
    std::vector<RotationSink*> mSinks;


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
