/**
 * @file PegWheel.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PEGWHEEL_H
#define CANADIANEXPERIENCE_PEGWHEEL_H

#include "Component.h"
#include "MachineSystemImplemented.h"
#include "RotationSink.h"
#include "Peg.h"
#include "RotationSource.h"
//class Peg;

class PegWheel : public Component {
private:
    RotationSink mSink;

    std::wstring mImagesDir;

    std::vector<Peg*> mPegs;

    Peg *mPeg;

    std::vector<double> pegLocations;

public:
    /// Constructor
    PegWheel(std::wstring imagesDir);

    /// Destructor
    virtual ~PegWheel() = default;

    /// Copy constructor/disabled
    PegWheel(const PegWheel&) = delete;

    /// Assignment operator/disabled
    void operator=(const PegWheel&) = delete;

    //virtual void SetRotation(double rotation) override;

    RotationSink *GetSink() { return &mSink; }

    void AddPeg(double angle);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location) override;

    std::wstring GetImagesDir() { return mImagesDir; }

    //void SetPeg(Peg peg) { mPeg = peg; }

};

#endif //CANADIANEXPERIENCE_PEGWHEEL_H
