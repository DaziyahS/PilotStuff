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
#pragma once

/// mahi includes
#include <syntacts> // Syntacts include

//-----------------------------------------------------------------------------
// note struct declaration
//-----------------------------------------------------------------------------
struct Note
{    
public:
    // base methods
    //-----------------------------------
    /// default constructor
    Note(int name, double amplitude, tact::Signal envelope);
    /// 
    tact::Signal getSignal()
    {
        return signal_ * envelope_;
    }

    // public variables
    //-----------------------------------
    int name_;   // name of the note
    double amplitude_;
    tact::Signal signal_;  // holds information for a Syntacts signal corresponding to this cue

    private:
    double a_note1 = 55.00;
    double a_snote1 =58.27; // a sharp and b flat
    double b_note1 = 61.74;
    double c_note2 = 65.41;
    double c_snote2 =69.30; // c sharp and d flat
    double d_note2 = 73.42; 
    double d_snote2 =77.78; // d sharp and e flat
    double e_note2 = 82.41;
    double f_note2 = 87.31;
    double f_snote2 =92.50; // f sharp and g flat
    double g_note2 = 98.00;
    double g_snote2 =103.83; // g sharp and a flat
    double a_note2 = 110.00;
    double a_snote2 =116.54; // a sharp and b flat
    double b_note2 = 123.47;
    double c_note3 = 130.81;
    double c_snote3 =138.59; // c sharp and d flat
    double d_note3 = 146.83;
};