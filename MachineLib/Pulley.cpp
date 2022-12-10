/**
 * @file Pulley.cpp
 * @author Albert Cho
 */

#include "Pulley.h"
#include "Polygon.h"

Pulley::Pulley(double radius)
{
    mRadius = radius;
    /// call SetBeltOnTop here
    mSink.SetComponent(this);
    this->Circle(radius);
}

void Pulley::Update(double time)
{
    mTime = time;
}

void Pulley::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    mSource.UpdateRotation(rotation);
}

void Pulley::Drive(std::shared_ptr<Pulley> pulley, bool over)
{
    //pulley->mBeltOnTop = over;

    if (over)
    {
        pulley->mSink.SetRotationSpeed((mRadius/pulley->GetRadius()));
        mSource.AddSink(pulley->GetSink());
    }
    else{
        pulley->mSink.SetRotationSpeed(-(mRadius/pulley->GetRadius()));
    }

}

void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    Component::Draw(graphics, location);

    /// Draw Belts here

}

//SetBeltOnTop:
//    if (this->mRotation < 0)
//    {
//        BeltOnTop = false
//    }