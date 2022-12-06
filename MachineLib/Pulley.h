/**
 * @file Pulley.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PULLEY_H
#define CANADIANEXPERIENCE_PULLEY_H

#include "Component.h"

#include "RotationSink.h"

class Pulley : public Component {
private:
    double mRadius;
    RotationSink mSink;
//
//public:
//    Pulley();
//
//    virtual void SetRotation(double rotation) override;
//    //virtual void Update(double time) override;
//    //void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location);
//    RotationSink *GetSink() { return &mSink; }

public:
    /// Constructor
    Pulley();

    /// Destructor
    virtual ~Pulley() = default;

    /// Copy constructor/disabled
    Pulley(const Pulley&) = delete;

    /// Assignment operator/disabled
    void operator=(const Pulley&) = delete;

//    virtual void SetRotation(double rotationSpeed) override;

//    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location) override;
//
//    RotationSink *GetSink(){ return &mSink; }
};

#endif //CANADIANEXPERIENCE_PULLEY_H
