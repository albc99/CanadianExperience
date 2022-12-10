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

//void PegWheel::SetRotation(double rotation)
//{
//    Component::SetRotation(rotation);
//}

void PegWheel::AddPeg(double angle)
{
    auto peg = new Peg(mImagesDir, GetRotation());
    peg->SetPosition(GetX(), GetY());
    peg->SetAngle(angle);
    peg->SetPegWheel(this);

    //this->sGetSource()->AddSink(peg->GetSink());
    mPegs.push_back(peg);
}

void PegWheel::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    Component::Draw(graphics, location);
    for (auto peg : mPegs)
    {
        peg->Draw(graphics, location + wxPoint(GetX(), GetY()));
        this->mSink.GetSource()->AddSink(peg->GetSink());

    }
}