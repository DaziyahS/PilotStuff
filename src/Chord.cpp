// local includes
#include "Chord.hpp"

// chord struct declaration
Chord::Chord(std::string name, int duration, int amplitude, bool isSimultaneous)
{
    // variables based on given
    name_ = name;
    duration_ = duration;
    amplitude_ = amplitude;
    isSimultaneous_ = isSimultaneous;
    // things needed for internal function
    tact::Sequence finalSignal;
    // declaration of function
    std::vector<tact::Signal> playValues();

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
    // determine the notes themselves
    if (name_.compare("a_minor_n1") == 0) // if name given is a_minor_n1
    {
        Note note1(a_minor_n1[0], sigAmp, envelope);
        Note note2(a_minor_n1[1], sigAmp, envelope);
        Note note3(a_minor_n1[2], sigAmp, envelope);
        isMajor_ = a_minor_n1[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    } 
    else if (name_.compare("a_major_n1") == 0) // if name given is a_major_n1
    {
        Note note1(a_major_n1[0], sigAmp, envelope);
        Note note2(a_major_n1[1], sigAmp, envelope);
        Note note3(a_major_n1[2], sigAmp, envelope);
        isMajor_ = a_major_n1[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("b_minor_n1") == 0) // if name given is b_minor_n1
    {
        Note note1(b_minor_n1[0], sigAmp, envelope);
        Note note2(b_minor_n1[1], sigAmp, envelope);
        Note note3(b_minor_n1[2], sigAmp, envelope);
        isMajor_ = b_minor_n1[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("b_major_n1") == 0) // if name given is b_major_n1
    {
        Note note1(b_major_n1[0], sigAmp, envelope);
        Note note2(b_major_n1[1], sigAmp, envelope);
        Note note3(b_major_n1[2], sigAmp, envelope);
        isMajor_ = b_major_n1[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("c_minor_n2") == 0) // if name given is c_minor_n2
    {
        Note note1(c_minor_n2[0], sigAmp, envelope);
        Note note2(c_minor_n2[1], sigAmp, envelope);
        Note note3(c_minor_n2[2], sigAmp, envelope);
        isMajor_ = c_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("c_minor_n2") == 0) // if name given is c_minor_n2
    {
        Note note1(c_minor_n2[0], sigAmp, envelope);
        Note note2(c_minor_n2[1], sigAmp, envelope);
        Note note3(c_minor_n2[2], sigAmp, envelope);
        isMajor_ = c_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  
    else if (name_.compare("a_minor_n2") == 0) // if name given is a_minor_n2
    {
        Note note1(a_minor_n2[0], sigAmp, envelope);
        Note note2(a_minor_n2[1], sigAmp, envelope);
        Note note3(a_minor_n2[2], sigAmp, envelope);
        isMajor_ = a_minor_n2[3]; // determine if it is a major chord
        notes_ = {note1, note2, note3}; 
    }  

    // create a function to play the values
    std::vector<tact::Signal> playValues();
    {
        if(isSimultaneous_)
        {

        }
        else
        {
            finalSignal = note1.getSignal() << note2 << note3;
        }
    }
}