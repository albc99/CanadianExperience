/**
 * @file MachineSystemImplemented.cpp
 * @author Albert Cho
 */

#include "pch.h"

#include "MachineSystemImplemented.h"


MachineSystemImplemented::MachineSystemImplemented(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
}

void MachineSystemImplemented::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->SetInterpolationQuality(wxINTERPOLATION_BEST);
    mMachine->Draw(graphics, mLocation);
}

void MachineSystemImplemented::SetMachineNumber(int machineNumber)
{
    if (machineNumber == 1)
    {
        Machine1Factory factory1(mResourcesDir, mAudioEngine);
        mMachine = factory1.Create();
        mMachine->SetMachineNumber(machineNumber);
    }
    if (machineNumber == 2)
    {
        mMachine->SetMachineNumber(machineNumber);
    }
}

void MachineSystemImplemented::OnUpdate(double time)
{
    mTime = time;
    mMachine->SetTime(mTime);
}

void MachineSystemImplemented::SetMachineFrame(int frame)
{
    mMachineFrame = frame;
    OnUpdate(frame / mFrameRate);
}