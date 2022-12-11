/**
 * @file MachineSystemImplemented.h
 * @author Albert Cho
 *
 * Derived Machine System class
 */

#ifndef CANADIANEXPERIENCE_MACHINESYSTEMIMPLEMENTED_H
#define CANADIANEXPERIENCE_MACHINESYSTEMIMPLEMENTED_H
#include <miniaudio.h>

#include "MachineSystem.h"
#include "Machine.h"
#include "Machine1Factory.h"

class MachineSystemImplemented : public MachineSystem {
private:
    wxPoint mLocation = wxPoint(0, 0);
    int mMachineFrame;
    double mFrameRate = 30;
    int mMachineNumber;

    double mTime;

    std::shared_ptr<Machine> mMachine = nullptr;

    std::wstring mResourcesDir = L"/resources";
    ma_engine* mAudioEngine;

public:
    /// Constructor
    MachineSystemImplemented(std::wstring resourcesDir, ma_engine *engine);

    /// Constructor
    MachineSystemImplemented() = delete;

    /// Destructor
    ~MachineSystemImplemented() = default;

    /// Copy constructor/disabled
    MachineSystemImplemented(const MachineSystemImplemented&) = delete;

    /// Assignment operator/disabled
    void operator=(const MachineSystemImplemented&) = delete;

    /**
    * Draw the machine at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    void SetLocation(wxPoint location) override { mMachine->SetLocation(location); }

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    virtual void SetMachineFrame(int frame) override;

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machineNumber) override;

    /**
     * Get the current machine number
     * \return Machine number integer
     */
    virtual int GetMachineNumber() override { return mMachine->GetMachineNumber(); }

    virtual double GetMachineTime() override { return mTime; }

    void OnUpdate(double elapsed);

    void SetFrameRate(double rate) override { mFrameRate = rate; }

    void SetRunning(bool running);

    void SetRotationSpeed(double rotationSpeed) { mMachine->SetRotationSpeed(rotationSpeed); }
};

#endif //CANADIANEXPERIENCE_MACHINESYSTEMIMPLEMENTED_H
