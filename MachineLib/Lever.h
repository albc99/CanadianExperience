/**
 * @file Lever.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "Peg.h"
#include "RotationSource.h"

class Lever : public Component {
private:

    cse335::Polygon mMount;

    RotationSource mSource;

    bool mTouching = false;

public:
    /// Constructor
    Lever(std::wstring imagesDir);

    /// Destructor
    virtual ~Lever() = default;

    /// Copy constructor/disabled
    Lever(const Lever&) = delete;

//    /// Assignment operator/disabled
//    void operator=(const Lever&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint location) override;

    void TripLever(Peg *peg);

    bool GetTouching() { return mTouching; }
    void SetTouching(bool touching) { mTouching = touching; }
};

#endif //CANADIANEXPERIENCE_LEVER_H
