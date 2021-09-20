#pragma once

// include needed libraries
#include <syntacts>
#include <iostream>

// include local libraries
#include <Note.hpp>

// declare the structure for the cue
struct Chord
{
    public:
        // declare the constructor for the chord
        Chord(std::string name, int duration, int amplitude, bool isSimultaneous, bool isMajor);

        // declare public variables
        std::vector<int> notes_;
        std::string name_; // name of the note
        int duration_;
        int amplitude_;
        bool isSimultaneous_; // holds info of which type of sequence
        bool isMajor_; // if 1 then it is major
        tact::Signal envelope;

    private:
        // define the chords based on numbers and whether it is major
        std::vector<int> a_minor_n1 = {1, 5, 9, 0};
        std::vector<int> a_major_n1 = {1, 6, 9, 1};
        std::vector<int> b_minor_n1 = {3, 8, 11, 0};
        std::vector<int> b_major_n1 = {3, 7, 11, 1};

        std::vector<int> c_minor_n2 = {5, 8, 12, 0};
        std::vector<int> c_major_n2 = {5, 9, 12, 1};
        std::vector<int> d_minor_n2 = {7, 12, 14, 0};
        std::vector<int> d_major_n2 = {7, 11, 14, 1};
        std::vector<int> e_minor_n2 = {9, 12, 16, 0};
        std::vector<int> e_major_n2 = {9, 13, 16, 1};
        std::vector<int> f_minor_n2 = {10, 13, 18, 0};
        std::vector<int> f_major_n2 = {10, 14, 18, 1};
        std::vector<int> g_minor_n2 = {12, 15, 20, 0};
        std::vector<int> g_major_n2 = {12, 16, 20, 1};
};
