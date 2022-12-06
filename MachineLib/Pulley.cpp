/**
 * @file Pulley.cpp
 * @author Albert Cho
 */

#include "Pulley.h"

//Pulley::Pulley(double radius)
//{
//    mRadius = radius;
//    mSink.SetComponent(this);
//
//    CenteredSquare(mRadius * 2);
//}
//
//void Pulley::SetRotation(double rotation)
//{
//    this->Component::SetRotation(rotation);
//}

Pulley::Pulley(double radius)
{
    mSink.SetComponent(this);
    this->Circle(radius);
}

//void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
//{
//
//}