/**
 * @file Peg.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PEG_H
#define CANADIANEXPERIENCE_PEG_H

#include "RotationSink.h"
#include "Component.h"

class PegWheel;

class Peg : public Component {
private:
    RotationSink mSink;

    double mRotation;

    double mAngle = 0;

    PegWheel *mPegWheel = nullptr;

    bool mTouching = false;

public:
    /// Constructor
    Peg(std::wstring imagesDir, double rotation);

    /// Destructor
    virtual ~Peg() = default;

    /// Copy constructor/disabled
    Peg(const Peg&) = delete;

    /// Assignment operator/disabled
    void operator=(const Peg&) = delete;

    RotationSink *GetSink() { return &mSink; }

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location) override;

    void SetAngle(double angle) { mAngle = angle; }

    void SetPegWheel(PegWheel *pegWheel) { mPegWheel = pegWheel; }

    double GetAngle() { return mAngle; }

    //virtual void SetRotation(double rotation) override;

    bool GetTouching() { return mTouching; }
    void SetTouching(bool touching) { mTouching = touching; }
};

#endif //CANADIANEXPERIENCE_PEG_H
