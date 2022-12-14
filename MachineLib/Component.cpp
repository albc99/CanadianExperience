/**
 * @file Component.cpp
 * @author Albert Cho
 */
#include "pch.h"

#include "Component.h"
#include "Polygon.h"

Component::Component()
{

}


void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    this->DrawPolygon(graphics, location.x + mPosition.x, location.y + mPosition.y);
}

void Component::SetRotationSpeed(double rotationSpeed)
{
    this->SetRotation(rotationSpeed);
}

void Component::Update(double time)
{
    mTime = time;
}