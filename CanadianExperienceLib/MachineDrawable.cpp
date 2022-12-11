/**
 * @file MachineDrawable.cpp
 * @author Albert Cho
 */

#include "MachineDrawable.h"

MachineDrawable::MachineDrawable(std::wstring resourcesDir, ma_engine *audioEngine, Timeline *timeline) : Drawable(L"Machine")
{
    MachineSystemFactory factory(resourcesDir, audioEngine);
    mMachine = factory.CreateMachineSystem();
    mTimeline = timeline;
}

void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
//    if timeline frame > startframe < endframe
//    {
//        setmachineframe (mTimeline GetCurrentframe)
//    }

    if (mTimeline->GetCurrentFrame() > mStartFrame && mTimeline->GetCurrentFrame() <= mEndFrame)
    {
        mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
    }
    double scale = 0.75f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}


