/**
 * @file Instrument.h
 * @author Albert Cho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_INSTRUMENT_H
#define CANADIANEXPERIENCE_INSTRUMENT_H

#include <miniaudio.h>

#include "Component.h"
class Lever;

class Instrument : public Component {
private:
    ma_sound mSound;
    wxString mAudioFile;
    Lever *mLever;
    ma_engine mEngine;

public:
    /// Constructor
    Instrument(std::wstring imageDir, std::wstring audioDir, ma_engine *sound);

    /// Destructor
    virtual ~Instrument();

    /// Copy constructor/disabled
    Instrument(const Instrument&) = delete;

    /// Assignment operator/disabled
    void operator=(const Instrument&) = delete;

    void PlaySound();
};

#endif //CANADIANEXPERIENCE_INSTRUMENT_H
