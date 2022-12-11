/**
 * @file MachineDrawable.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include "Drawable.h"
#include <machine-api.h>
#include "Timeline.h"

class MachineDrawable : public Drawable {
private:
    std::shared_ptr<MachineSystem> mMachine;
    Timeline *mTimeline = nullptr;
    int mStartFrame = 0;
    int mEndFrame = 0;

public:
    /// Constructor
    MachineDrawable(std::wstring resourcesDir, ma_engine *audioEngine, Timeline *timeline);

    MachineDrawable() = delete;

    /// Destructor
    virtual ~MachineDrawable() = default;

    /// Copy constructor/disabled
    MachineDrawable(const MachineDrawable&) = delete;

    /// Assignment operator/disabled
    void operator=(const MachineDrawable&) = delete;

    void SetLocation(wxPoint location) { mMachine->SetLocation(location); }

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    virtual bool HitTest(wxPoint pos) override { return false; }

    void SetStartFrame(int frame) { mStartFrame = frame; }
    void SetEndFrame(int frame) { mEndFrame = frame; }


};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
