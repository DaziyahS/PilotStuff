// local includes
#include "Note.hpp"

// Note struct declaration
Note::Note(int name, double amplitude, tact::Signal envelope)
{
    // assign values given to a variable
    name_ = name;
    amplitude_ = amplitude;
    envelope_ = envelope;
    // define other needed variables for internal functions
    tact::Signal signal;

    // determine the sine wave
    switch(name_)
    {
        case 1:
            signal = tact::Sine(a_note1);
            break;
        case 2:
            signal = tact::Sine(a_snote1);
            break;
        case 3:
            signal = tact::Sine(b_note1);
            break;
        case 5:
            signal = tact::Sine(c_note2);
            break;
        case 6:
            signal = tact::Sine(c_snote2);
            break;
        case 7:
            signal = tact::Sine(d_note2);
            break;
        case 8:
            signal = tact::Sine(d_snote2);
            break;
        case 9:
            signal = tact::Sine(e_note2);
            break;
        case 10:
            signal = tact::Sine(f_note2);
            break;
        case 11:
            signal = tact::Sine(f_snote2);
            break;
        case 12:
            signal = tact::Sine(g_note2);
            break;
        case 13:
            signal = tact::Sine(g_snote2);
            break;
        case 14:
            signal = tact::Sine(a_note2);
            break;
        case 15:
            signal = tact::Sine(a_snote2);
            break;
        case 16:
            signal = tact::Sine(b_note2);
            break;
        case 18:
            signal = tact::Sine(c_note3);
            break;
        case 19:
            signal = tact::Sine(c_snote3);
            break;
        case 20:
            signal = tact::Sine((d_note3);
            break;
    }
}