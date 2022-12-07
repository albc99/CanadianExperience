/**
 * @file Motor.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Polygon.h"
#include "Component.h"
#include "RotationSource.h"

class Motor : public Component {
private:
    cse335::Polygon mRotor;

    double mRotationSpeed;

    double mTime;

    RotationSource mSource;

public:

    /// Constructor
    Motor(std::wstring imagesDir);

    /// Destructor
    virtual ~Motor() = default;

    /// Copy constructor/disabled
    Motor(const Motor&) = delete;

    /// Assignment operator/disabled
    void operator=(const Motor&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location) override;
    virtual void Update(double time) override;
    virtual void SetRotationSpeed(double rotationSpeed) override;

    RotationSource *GetSource() { return &mSource; }
};

#endif //CANADIANEXPERIENCE_MOTOR_H
