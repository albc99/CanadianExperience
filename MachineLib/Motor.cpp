/**
 * @file Motor.cpp
 * @author Albert Cho
 */

#include "pch.h"

#include "Motor.h"

/// The motor size in pixels. Motor is 100 pixels wide and tall
const int MotorSize = 100;

/// Radius of a basic motor rotor in pixels
const double BasicRotorRadius = 15;

/// Size of the rotor in pixels
const static int VintageMotorRotorSize = 60;

/// The vintage motor body image
const std::wstring VintageMotorBody = L"/motor-frame.png";

/// The vintage motor shaft image
const std::wstring VintageMotorShaft = L"/electric-wheel.png";

/// Size of the modern motor shaft in pixels
const static int ModernMotorShaftSize = 30;

/// The image to use for the modern motor body
const std::wstring ModernMotorBodyImage = L"/motor2.png";

/// The image to use for the modern motor shaft
const std::wstring ModernMotorShaftImage = L"/shaft.png";

Motor::Motor(std::wstring imagesDir) : Component()
{
    this->CenteredSquare(MotorSize);
    mRotor.CenteredSquare(ModernMotorShaftSize);

    this->SetImage(imagesDir + ModernMotorBodyImage);
    mRotor.SetImage(imagesDir + L"/shaft.png");

    mRotor.SetRotation(30);
}

void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location)
{
    this->Component::Draw(graphics, location);

    mRotor.DrawPolygon(graphics, location.x + this->GetX(),
            location.y + this->GetY());
}

void Motor::Update(double time)
{
    // Component::Update(time);
    mTime = time;
    mRotor.SetRotation(time * mRotationSpeed);
    mSource.UpdateRotation(time * mRotationSpeed);
}

void Motor::SetRotationSpeed(double rotationSpeed)
{
    mRotationSpeed = rotationSpeed;
}