/**
 * @file Lever.cpp
 * @author Albert Cho
 */

#include "Lever.h"

// Image for the fixed lever mounting point
const std::wstring LeverMountImage = L"/lever-mount.png";

/// Image for the moving lever itself
const std::wstring LeverImage = L"/lever.png";

/// Height of the lever in pixels
const int LeverHeight = 58;

/// Width of the lever in pixels
const int LeverWidth = 28;

/// A peg is considered to be starting to touch
/// the lever when the angle reaches this value
const double PegStart = 0.02;

/// The peg releases the lever when the angle
/// reaches this value. This assumes the peg
/// is rotating in the negative direction.
const double PegEnd = -0.05;

/// The maximum rotation of the lever in turns
const double MaxRotation = 0.08;

Lever::Lever(std::wstring imagesDir)
{
    this->Rectangle(-LeverWidth/2, LeverHeight/2, LeverWidth, LeverHeight);
    mMount.Rectangle(-LeverWidth/2, LeverHeight/2, LeverWidth, LeverHeight);
    mDrumStick.BottomCenteredRectangle(5, 75);

    this->SetImage(imagesDir + LeverImage);
    mMount.SetImage(imagesDir + LeverMountImage);
    mDrumStick.SetImage(imagesDir + L"/drumstick.png");

    mDrumStick.SetRotation(-0.02);

    //mInstrument->SetL
}

void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    Component::Draw(graphics, location);
    mMount.DrawPolygon(graphics, location.x + this->GetX(), location.y + this->GetY());
    mDrumStick.DrawPolygon(graphics, location.x + this->GetX(), location.y + this->GetY());

}

void Lever::TripLever(Peg *peg)
{

    // Add the current rotation of the peg and
    // the angle of the peg on the peg wheel.
    // This tells us where the peg is rotated, which
    // is the important part. The GetRotation is
    // for the pegwheel/peg combination.
    auto angle = peg->GetRotation() + peg->GetAngle();

    // Remove the turns and determine an angle in the
    // range -0.5 to 0.5. This code assumes turns, not
    // degrees or radians.
    int iAngle = (int)angle;
    angle -= iAngle;
    if(angle < -0.5)
    {
        angle += 1;
    }

    // Determine if the peg
    if(PegEnd <= angle && angle <= PegStart)
    {
        SetTouching(true);

        // This peg is in range
        double t = (angle - PegStart) / (PegEnd - PegStart);

        this->SetRotation(t * MaxRotation);

        mDrumStick.SetRotation(t * MaxRotation);
    }
}

void Lever::PegsEnd()
{
    SetRotation(0);
    mMount.SetRotation(0);

    SetStruckComponent(mInstrument);
    mInstrument->PlaySound();
}

