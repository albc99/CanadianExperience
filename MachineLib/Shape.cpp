/**
 * @file Shape.cpp
 * @author Albert Cho
 */

#include "pch.h"
#include "Shape.h"

Shape::Shape()
{
    mSink.SetComponent(this);
}
//
//void Shape::SetRotation(double rotationSpeed)
//{
//    mSink.UpdateRotation(rotationSpeed);
//}

//void Shape::SetRotation(double rotationSpeed)
//{

//    // 원래 setrotationspeed. 일때 안의 내용:
//    //this->SetRotationSpeed(rotationSpeed);
//    this->SetRotation()
//}