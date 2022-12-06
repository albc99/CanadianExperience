/**
 * @file Pulley.cpp
 * @author Albert Cho
 */

#include "Pulley.h"

Pulley::Pulley(double radius)
{
    mRadius = radius;
    mSink.SetComponent(this);

    CenteredSquare(mRadius * 2);
}

void Pulley::SetRotation(double rotation)
{
    this->Component::SetRotation(rotation);
}