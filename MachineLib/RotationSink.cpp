/**
 * @file RotationSink.cpp
 * @author Albert Cho
 */

#include "RotationSink.h"
#include "RotationSource.h"

RotationSink::RotationSink()
{

}

void RotationSink::UpdateRotation(double rotation)
{
    mComponent->SetRotationSpeed(rotation);
    //mRotationSource->UpdateRotation(rotation);
}

