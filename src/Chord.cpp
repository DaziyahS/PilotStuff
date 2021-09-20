// local includes
#include "Chord.hpp"

// chord struct declaration
Chord::Chord(std::string name, int duration, int amplitude, bool isSimultaneous, bool isMajor)
{
    // variables based on given
    name_ = name;
    duration_ = duration;
    amplitude_ = amplitude;
    bool isSimultaneous_ = isSimultaneous;
    bool isMajor_ = isMajor;
    // variables needed for internal functions
    tact::Signal envelope;
    double sigAmp;

    // if Simultaneous
    if(isSimultaneous)
    {
        // determine the envelope for duration
        switch(duration_)
        {
            case 0:
                envelope = tact::ASR(0, 0.9, 0); // total time 0.9 s
                break;
            case 1:
                envelope = tact::ASR(0.3, 1.5, 0.3); // total time 2.1 s
                break;
            case 2:
                envelope = tact::ASR(0.3, 2.4, 0.6); // total time 3.3 s
                break;
        }
        // determine the magnitude of the amplitude
        switch(amplitude_)
        {
            case 1: // medium-high amplitude
                sigAmp = 0.8;
                break;
            case 2: // medium amplitude
                sigAmp = 0.5;
                break;
            case 3: // low amplitude
                sigAmp = 0.3;
                break;

            default: // full amplitude
                sigAmp = 1;
                break;
        }
    }
    // if Sequential
    else
    {
        switch(duration_)
        {
            case 0:
                envelope = tact::ASR(0, 0.3, 0); // total time 0.3 s
                break;
            case 1:
                envelope = tact::ASR(0.1, 0.5, 0.1); // total time 0.7 s
                break;
            case 2:
                envelope = tact::ASR(0.1, 0.8, 0.2); // total time 1.1 s
                break;
        }
         // determine the magnitude of the amplitude
        switch(amplitude_)
        {
            case 1: // medium-high amplitude
                sigAmp = 0.8;
                break;
            case 2: // medium amplitude
                sigAmp = 0.5;
                break;
            case 3: // low amplitude
                sigAmp = 0.3;
                break;

            default: // full amplitude
                sigAmp = 1;
                break;
        }
    }
}