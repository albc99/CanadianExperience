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
#include "RotationSource.h"

class Pulley : public Component {
private:
    double mRadius;
    double mRotation = 1;
    double mTime;

    RotationSink mSink;
    RotationSource mSource;

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
    Pulley(double radius);

    /// Destructor
    virtual ~Pulley() = default;

    /// Copy constructor/disabled
    Pulley(const Pulley&) = delete;

    /// Assignment operator/disabled
    void operator=(const Pulley&) = delete;

    virtual void SetRotation(double rotation) override;

//    void SetRotationPulley(double rotation);

//    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location) override;
    virtual void Update(double time) override;
    RotationSink *GetSink(){ return &mSink; }
    RotationSource *GetSource() { return &mSource; }
    double GetRadius() { return mRadius; }


    void Drive(std::shared_ptr<Pulley> pulley, bool over = true);

};

#endif //CANADIANEXPERIENCE_PULLEY_H
