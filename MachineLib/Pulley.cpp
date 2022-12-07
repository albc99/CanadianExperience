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

    //RotateSink(mRotation);
}

//
//void Pulley::SetRotation(double rotation)
//{
//    mRotation = rotation;
//    mSource.UpdateRotation(rotation);
//}

void Pulley::Update(double time)
{
    mTime = time;
}

void Pulley::SetRotation(double rotation)
{

    //SetRotation(mRotationSpeed * mTime * rotation);

    //mSink.SetSource(&mSource);
    mSource.UpdateRotation(rotation);
    Component::SetRotation(rotation);
}

//void Pulley::RotateSink(double speed)
//{
//    SetRotation(mRotationSpeed * mTime * speed);
//    mSource.UpdateRotation(mRotationSpeed);
//}
//
void Pulley::Drive(std::shared_ptr<Pulley> pulley, bool over)
{
    //mSource.UpdateRotation(mRotationSpeed);

    pulley->mSink.SetRotationSpeed(mRotation);
    mSource.AddSink(pulley->GetSink());

    pulley->SetRotationSpeed((mRadius/pulley->GetRadius()));
}
//void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
//{
//
//}