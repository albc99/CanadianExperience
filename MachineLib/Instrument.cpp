/**
 * @file Instrument.cpp
 * @author Albert Cho
 */
#include "pch.h"

#include "Instrument.h"
#include "Lever.h"

Instrument::Instrument(std::wstring imageDir,  std::wstring passedAudioDir, ma_engine *sound)
{
    auto audioFile = ma_sound_init_from_file(sound, wxString(passedAudioDir), 0, NULL, NULL, &mSound);
    if (audioFile != MA_SUCCESS)
    {
        wxString msg;
        msg.Printf(L"Unable to load audio file %s - %d", passedAudioDir, audioFile);
        wxMessageBox( msg, wxT("miniaudio failure"), wxICON_ERROR);
    }
    //mLever->SetInstrument(this);
    this->SetImage(imageDir);
}

void Instrument::PlaySound()
{
    // If the sound is already playing, stop it first
    if(ma_sound_is_playing(&mSound))
    {
        ma_sound_stop(&mSound);
    }

    // Always rewind to the beginning before playing
    ma_sound_seek_to_pcm_frame(&mSound, 0);

    // And play the sound!
    ma_sound_start(&mSound);
}

/**
 * MAKE PLAYSOUND FUNCTION FOR connection to lever
 */

/**
 * Destructor
 */
Instrument::~Instrument()
{
    if(ma_sound_is_playing(&mSound))
    {
        ma_sound_stop(&mSound);
    }

    ma_sound_uninit(&mSound);
}