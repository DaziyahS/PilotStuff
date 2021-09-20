// local includes
#include "Chord.hpp"

// chord struct declaration
Chord::Chord(std::string name, int duration, bool isSimultaneous, bool isMajor)
{
    name_ = name;
    duration_ = duration;
    bool isSimultaneous_ = isSimultaneous;
    bool isMajor_ = isMajor;

    // if Simultaneous
    if(isSimultaneous)
    {
        switch(duration)
        {
            case 0:
                
            case 1:
            case 2:
        }
    }
    // if Sequential
    else
    {

    }
}