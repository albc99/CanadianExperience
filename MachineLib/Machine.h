/**
 * @file Machine.h
 * @author Albert Cho
 *
 *  class that represents an instantiated  working machine
 */

#ifndef CANADIANEXPERIENCE_MACHINE_H
#define CANADIANEXPERIENCE_MACHINE_H

#include <vector>
#include "Component.h"

class MachineSystemImplemented;

class Machine {
private:

    /// Frame rate
    int mFrameRate = 30;

    /// Machine number
    int mMachineNumber = 1;

    double mTime;

    MachineSystemImplemented *mMachineSystemImplemented;

    /// The components
    std::vector<std::shared_ptr<Component>> mComponents;

    wxPoint mLocation = wxPoint(0,0);

public:
    Machine(int machineNumber);

    /// Destructor
    virtual ~Machine() = default;

    /// Copy constructor/disabled
    Machine(const Machine&) = delete;

    /// Assignment operator/disabled
    void operator=(const Machine&) = delete;

    /** Iterator that iterates over the components in a machine */
    class ComponentIter
    {
    public:
        /**
         * Constructor
         * @param machine machine we are iterating
         * @param pos Starting position \
         */
        ComponentIter(Machine *machine, int pos) : mMachine(machine), mPos(pos) {}

        /**
         * Test for end of the iterator
         * @param other Other object to test against
         * @return True if we this position equals not equal to the other position
         */
        bool operator!=(const ComponentIter &other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Component> operator *() const { return mMachine->mComponents[mPos]; }

        /** Increment the iterator
        * @return Reference to this iterator */
        const ComponentIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        Machine *mMachine;  ///< Machine we are iterating over
        int mPos;           ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    ComponentIter begin() { return ComponentIter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    ComponentIter end() { return ComponentIter(this, mComponents.size()); }

    /**
     * Draw the machine
     * @param graphics graphics context to draw
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location);

    void AddComponent(std::shared_ptr<Component> component) { mComponents.push_back(component); }

    void SetTime(double time);

    virtual void SetRotationSpeed(double rotationSpeed);

    void SetLocation(wxPoint location) { mLocation = location; }

    void SetMachineNumber(int machineNumber) { mMachineNumber = machineNumber; }

    int GetMachineNumber() { return mMachineNumber; }

    double GetMachineTime() { return mTime; }



};

#endif //CANADIANEXPERIENCE_MACHINE_H
