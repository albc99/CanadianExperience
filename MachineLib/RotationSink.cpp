/**
 * @file RotationSink.cpp
 * @author Albert Cho
 */

#include "RotationSink.h"

RotationSink::RotationSink()
{

}

void RotationSink::UpdateRotation(double rotation)
{
    mComponent->SetRotation(rotation);
}

