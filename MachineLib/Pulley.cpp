/**
 * @file Pulley.cpp
 * @author Albert Cho
 */

#include "Pulley.h"
#include "Polygon.h"

Pulley::Pulley(double radius)
{
    mRadius = radius;
    mSink.SetComponent(this);
    this->Circle(radius);

    RotateSink(mRotation);
}

void Pulley::SetRotation(double rotation)
{
    mRotationSpeed = rotation;
    //Component::SetRotation(rotation);
    mSource.UpdateRotation(rotation);

}

void Pulley::Update(double time)
{
    mTime = time;
}

void Pulley::RotateSink(double speed)
{
    SetRotation(mRotationSpeed * mTime * speed);
    mSource.UpdateRotation(mRotationSpeed);
}

void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    mSource.AddSink(pulley->GetSink());
    pulley->SetRotation(mRadius/pulley->GetRadius());

}
//void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
//{
//
//}