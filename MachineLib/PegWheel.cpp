/**
 * @file PegWheel.cpp
 * @author Albert Cho
 */

#include "PegWheel.h"

/// Standard peg wheel image
const std::wstring PegWheelImage = L"/wood-wheel.png";

/// The peg wheel radius
const double PegWheelRadius = 30;

PegWheel::PegWheel(std::wstring imagesDir) : mImagesDir(imagesDir)
{
    this->SetImage(imagesDir + PegWheelImage);
    CenteredSquare(PegWheelRadius * 2);
    mSink.SetComponent(this);
}

void PegWheel::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    for (auto peg : mPegs)
    {
        peg->SetRotation(rotation);
    }

    for (auto peg : mPegs)
    {
        mLever->TripLever(peg);
    }
    if (!mLever->GetTouching())
    {
        mLever->PegsEnd();
    }
}

void PegWheel::AddPeg(double angle)
{
    auto peg = new Peg(mImagesDir, GetRotation());
    peg->SetPosition(GetX(), GetY());
    peg->SetAngle(angle);
    peg->SetPegWheel(this);

    mPegs.push_back(peg);
}

void PegWheel::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    bool reset = false;

    Component::Draw(graphics, location);
    for (auto peg : mPegs)
    {
//        mLever->SetRotation(0);

        peg->Draw(graphics, location + wxPoint(GetX(), GetY()));
        this->mSink.GetSource()->AddSink(peg->GetSink());
        mLever->GetDrumStick()->SetRotation(-0.02);
        mLever->TripLever(peg);
    }
//    if (reset)
//    {
//        mLever->SetRotation(0);
//    }


}

void PegWheel::AddLever(std::shared_ptr<Lever> lever)
{
    mLever = lever;
}