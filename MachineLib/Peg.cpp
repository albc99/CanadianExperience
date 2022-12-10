/**
 * @file Peg.cpp
 * @author Albert Cho
 */

#include "Peg.h"
#include "PegWheel.h"

using namespace std;

/// The image to use for the peg
const std::wstring PegImage = L"/peg.png";

/// Width to draw the peg image in pixels
const int PegWidth = 4;

/// Height to draw the peg image in pixels
const int PegHeight = 10;

/// The peg wheel radius
const double PegWheelRadius = 30;

Peg::Peg(std::wstring imagesDir, double rotation) : mRotation(rotation)
{
    this->SetImage(imagesDir + PegImage);
    BottomCenteredRectangle(PegWidth, PegHeight + PegWheelRadius);
    mSink.SetComponent(this);
}

void Peg::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    graphics->PushState();
    wxPoint temp = wxPoint(mPegWheel->GetX(), mPegWheel->GetY());

    /// location == centre of pegwheel
    graphics->Translate(location.x, location.y);
    //graphics->Translate(mPegWheel->GetX(), mPegWheel->GetY());

    /// mRotation == rotation of pegwheel
    graphics->Rotate((mRotation + mAngle) * M_PI * 2);
    DrawPolygon(graphics, 0, 0);
    //DrawPolygon(graphics, 0, 0);

    graphics->PopState();
}
//
//void Peg::SetRotation(double rotation)
//{
//
//}