/**
 * @file Machine.cpp
 * @author Albert Cho
 */

#include "pch.h"
#include "Machine.h"

using namespace std;

Machine::Machine(int machineNumber) : mMachineNumber(machineNumber)
{

}

void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics, mLocation);
    }
}


void Machine::SetRotationSpeed(double rotationSpeed)
{
}

void Machine::SetTime(double time)
{
    mTime = time;

    for (auto component : mComponents)
    {
        component->Update(mTime);
    }
}