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
#include "Chord.hpp"

//-----------------------------------------------------------------------------
// cue struct declaration
//-----------------------------------------------------------------------------

// base methods
//-----------------------------------
Chord(std::string name, int length, double amplitude, bool isSimultaneous)
{
    name_ = name;
    isSimultaneous_ = isSimultaneous;
    tact:Signal envelope;
    if(isSimultaneous)
    {
        switch(length)
        {
            case 1:
                envelope = tact::ASR(0, 0.9, 0)
                break;
            case 2:
                envelope = tact::ASR(0.3, 1.5, 0.3)
                break;
            case 3:
                envelope = tact::ASR(0.3, 2.4, 0.6);
        }
    }
    else
    {
        switch(length)
        {
            case 1:
                envelope = tact::ASR(0, 0.3, 0);
                break;
            case 2:
                envelope = tact::ASR(0.1, 0.5, 0.1);
                break;
            case 3:
                envelope = tact::ASR(0.1, 0.8, 0.2); 
        }
    }

    if(name.compare("a_minor_n1") == 0)
    {
        Note note1(a_minor_n1[0], amplitude, envelope);
        Note note2(a_minor_n1[1], amplitude, envelope);
        Note note3(a_minor_n1[2], amplitude, envelope);
        notes_ = [note1, note2, note3];
    }
}