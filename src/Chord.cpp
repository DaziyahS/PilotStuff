// local includes
#include "Chord.hpp"

// chord struct declaration
Chord::Chord(std::string name, int duration, bool isSimultaneous, bool isMajor)
{
    // variables based on given
    name_ = name;
    duration_ = duration;
    bool isSimultaneous_ = isSimultaneous;
    bool isMajor_ = isMajor;
    // variables needed for internal functions
    tact::Signal envelope;

    // if Simultaneous
    if(isSimultaneous)
    {
        switch(duration)
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
    }
    // if Sequential
    else
    {
        switch(duration)
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
    }
}