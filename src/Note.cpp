// MIT License
//
// Copyright (c) 2021 Mechatronics and Haptic Interfaces Lab - Rice University
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// Author(s): Zane Zook (zaz2@rice.edu)

//-----------------------------------------------------------------------------
// preprocessor directives
//-----------------------------------------------------------------------------
// local includes
#include "Note.hpp"

//-----------------------------------------------------------------------------
// note struct declaration
//-----------------------------------------------------------------------------
// base methods
//-----------------------------------
Note::Note(int name, double amplitude, tact::Signal envelope)
{
    name_ = name;
    amplitude_ = amplitude;
    envelope_ = envelope;
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
    }
}