/**
 * @file RotationSource.cpp
 * @author Albert Cho
 */

#include "RotationSource.h"

RotationSource::RotationSource()
{

}

void RotationSource::AddSink(RotationSink *sink)
{
    sink->SetSource(this);
    mSinks.push_back(sink);
}

void RotationSource::UpdateRotation(double rotation)
{
    for (auto sink : mSinks)
    {
        sink->UpdateRotation(rotation);
    }

}
void RotationSource::Update(double time)
{

}