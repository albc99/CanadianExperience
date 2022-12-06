/**
 * @file ComponentTest.cpp
 * @author Albert Cho
 */

#include "pch.h"
#include "gtest/gtest.h"


#include <miniaudio.h>
#include <Machine1Factory.h>
#include <MachineSystem.h>
#include <Component.h>
#include <Machine.h>

class MachineMock
{

};

TEST(ComponentTest, Add)
{
    ma_engine mAudioEngine;

    Machine1Factory factory(L".", &mAudioEngine);
    auto machine = factory.Create();

    auto component = std::make_shared<Component>();
    machine->AddComponent(component);

    auto iter1 = machine->begin();
    ASSERT_EQ(*iter1, component);
}