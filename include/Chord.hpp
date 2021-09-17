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

/// local include
#include <Note.hpp>

//-----------------------------------------------------------------------------
// cue struct declaration
//-----------------------------------------------------------------------------
struct Chord
{    
public:
    // base methods
    //-----------------------------------
    /// default constructor
    Chord(std::string name, int length, bool isSimultaneous);


    // public variables
    //-----------------------------------
    std::vector<Note> notes_;
    std::string name_;   // name of the note
    bool isSimultaneous_;  // holds information for a Syntacts signal corresponding to this cue

private:
    std::vector<int> a_minor_n1 = {1, 2, 3};
    std::vector<int> a_major_n1 = {a_note1, c_snote2, e_note2};
    std::vector<int> b_minor_n1 = {b_note1, d_note2, f_snote2};
    std::vector<int> b_major_n1 = {b_note1, d_snote2, f_snote2};

    std::vector<int> c_minor_n2 = {c_note2, d_snote2, g_note2};
    std::vector<int> c_major_n2 = {c_note2, e_note2, g_note2};
    std::vector<int> d_minor_n2 = {d_note2, f_note2, a_note2};
    std::vector<int> d_major_n2 = {d_note2, f_snote2, a_note2};
    std::vector<int> e_minor_n2 = {e_note2, g_note2, b_note2};
    std::vector<int> e_major_n2 = {e_note2, g_snote2, b_note2};
    std::vector<int> f_minor_n2 = {f_note2, g_snote2, c_note3};
    std::vector<int> f_major_n2 = {f_note2, a_note2, c_note3};
    std::vector<int> g_minor_n2 = {g_note2, a_snote2, d_note3};
    std::vector<int> g_major_n2 = {g_note2, b_note2, d_note3};
};

Chord achord("a_minor_n1", 2, true);
sess.play(achord.notes[0].signal, achord.notes.amplitude);

for(int i =0 ; i <9 ; i++)
{
    Chord chord(name, length, bool);
    chordList.push_back(chord);
}