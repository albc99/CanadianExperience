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
    pulley->mSink.SetRotationSpeed((mRadius/pulley->GetRadius()));
    mSource.AddSink(pulley->GetSink());
}
//void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
//{
//
//}