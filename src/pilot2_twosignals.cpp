#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>
#include <Mahi/Util/Logging/Log.hpp>
#include <Mahi/Util/Timing/Timestamp.hpp>
#include <syntacts>
#include <random>
#include <iostream> 
#include <fstream> // need to include inorder to save to csv
#include <chrono> 
#include <string> // for manipulating file name
#include <array> // for csv use

#include <sys/timeb.h>
#include <time.h>

// local includes
#include <Chord.hpp>
#include <Note.hpp> // would this imply that the .cpp functionality is attached?

// open the namespaces that are relevant for this code
using namespace mahi::gui;
using namespace mahi::util;
using tact::Signal;
using tact::sleep;
using tact::Sequence;

// deteremine application variables
int windowWidth = 1800; // 1920 x 1080 is screen dimensions
int windowHeight = 1000;
std::string my_title= "Play GUI";
ImVec2 buttonSize = ImVec2(400, 65);  // Size of buttons on GUI
// std::string deviceNdx = "Speakers (USB Sound Device)"; // Put my device name or number, is for at home name
int deviceNdx = 6;
// tactors of interest
int topTact = 4;
int botTact = 6;
int leftTact = 0;
int rightTact = 2;

// trying to figure out how to save to an excel document
std::string saveSubject; // experiment details, allows me to customize
std::ofstream file_name; // this holds the trial information

// std::string filepath;
// mahi::util::Timestamp wherePut;

class MyGui : public Application
{
    // Start by declaring the session variable
    tact::Session s; // this ensures the whole app knows this session

public:
    // this is a constructor. It initializes your class to a specific state
    MyGui() : 
    Application(windowWidth, windowHeight, my_title, 0),
    chordNew1(),
    chordNew2(),
    isSim(2),
    channelSignals(3)
    {
        s.open(deviceNdx); // , tact::API::MME); // opens session with the application
        // keep in mind, if use device name must also use the API
        // something the GUI needs *shrugs*
        ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_ViewportsEnable;
        set_background(Cyans::Teal); //background_color = Grays::Black; 
        // anything that does things should be in the constructor (AKA here)
        // std::string filepath = "../../Data/" + wherePut.yyyy_mm_dd_hh_mm_ss() + ".csv"; // name of data changed with time
        // mahi::util::csv_write_row(filepath, headers);

        // trying to figure out how to save to an excel document
        file_name.open("../../Data/" + saveSubject + "_piloting.csv"); // saves the csv name for all parameters
        file_name << "Trial" << "," << "Sus 1" << "," << "Amp 1" << "," << "Chord 1" << "," << "IsSim 1" << ","
                  << "Sus 2" << "," << "Amp 2" << "," << "Chord 2" << "," << "IsSim 2" << "," << "Valence" << ","
                  << "Arousal" << "," << "Notes" << std::endl; // theoretically setting up headers
     }

    // Define variables needed throughout the program
    // For creating the signal
    std::string defaultName = "a_minor_n1"; // what is the first chord name
    std::string currentChord1, currentChord2; // holds name of current chord based on selection
    Chord chordNew1, chordNew2;
    std::vector<tact::Signal> channelSignals;
    std::vector<bool> isSim = {false, false}; // default is sequential
    // For saving the signal
    std::string sigName; // name for saved signal
    std::string fileLocal; // for storing the signal
    // For saving records
    int trial_num = 1;
    int val = 0, arous = 0;
    // For playing the signal
    Clock play_clock; // keeping track of time for non-blocking pauses
    bool play_once = false;    // for playing a cue one time
    bool start_loop = false;  // for playing a cue multiple times
    int pause = 1; // can pause the cue at any time
    // For logging the data
    // mahi::util::Timestamp wherePut;
    std::vector<std::string> headers = {"Trial", "Sus 1", "Amp 1", "Chord 1", "IsSim 1", "Sus 2", "Amp 2", "Chord 2","IsSim 2", 
                                        "Valence", "Arousal"};   
    std::array<int, 11> data; 
    // std::string filepath;

    virtual void update() override
    {
        ImGui::Begin("Playing GUI");

        // for preset, a list of the chords
        const char* items[] = { "A Minor 1", "A Major 1", "B Minor 1", "B Major 1", "C Minor 2", "C Major 2", 
                                "D Minor 2", "D Major 2", "E Minor 2", "E Major 2", "F Minor 2", "F Major 2",
                                "G Minor 2", "G Major 2"}; // chord names
        static int item_current1 = 0; // Starts at first item in the list
        const char* combo_label1 = items[item_current1]; // Gives the preview before anything is played
        if(ImGui::BeginCombo("Note 1 Chord", combo_label1)){ // no flags
            for (int n = 0; n < IM_ARRAYSIZE(items); n++)
            {
                const bool is_selected = (item_current1 == n);
                if (ImGui::Selectable(items[n], is_selected))
                    item_current1 = n; // gives a value to each selection when intialized
                if (is_selected)
                    ImGui::SetItemDefaultFocus(); // focuses on item selected, item_current1 is set as selected
            }

            // determine the current signal
            currentChord1 = chordNew1.signal_list[item_current1]; // theoretically gives name needed
            
            ImGui::EndCombo();
        };
        ImGui::SameLine();
        static int item_current2 = 0; // Starts at first item in the list
        const char* combo_label2 = items[item_current2]; // Gives the preview before anything is played
        if(ImGui::BeginCombo("Note 2 Chord", combo_label2)){ // no flags
            for (int n = 0; n < IM_ARRAYSIZE(items); n++)
            {
                const bool is_selected = (item_current2 == n);
                if (ImGui::Selectable(items[n], is_selected))
                    item_current2 = n; // gives a value to each selection when intialized
                if (is_selected)
                    ImGui::SetItemDefaultFocus(); // focuses on item selected, item_current2 is set as selected
            }

            // determine the current signal
            currentChord2 = chordNew2.signal_list[item_current2]; // theoretically gives name needed

            ImGui::EndCombo();
        };

        // for sustain and delay
        static int sus [2] = {0, 0}; // this is the vector being adjusted
        if(ImGui::SliderInt2("Sustain", sus, 0, 2)){  // if use SliderInt2 will have 2 back to back same range
            // sus is determined here, this is duration value
            std::cout << "sustain is " << sus << std::endl;
        }; 
        static int amp [2] = {0, 0}; // The value to be adjusted
        if(ImGui::SliderInt2("Intensity", amp, 0, 3)){
            // amp is determined here, this is amplitude value
        };
        /* // if I just want it to be an arrow down and would go before it
        if (ImGui::CheckboxFlags("ImGuiComboFlags_NoPreview", &flags, ImGuiComboFlags_NoPreview))
                flags &= ~ImGuiComboFlags_NoArrowButton; // Clear the other flag, as we cannot combine both
        */
        if(ImGui::Button("Sequential 1", buttonSize/2)){
            isSim[0] = false; // false
            std::cout << "on seq1" << std::endl;
        };
        ImGui::SameLine();
        if(ImGui::Button("Simultaneous 1", buttonSize/2)){
            isSim[0] = true; // true
            std::cout << "on sim1" << std::endl;
        };
        ImGui::SameLine();
        if(ImGui::Button("Sequential 2", buttonSize/2)){
            isSim[1] = false; // false
            std::cout << "on seq2" << std::endl;
        };
        ImGui::SameLine();
        if(ImGui::Button("Simultaneous 2", buttonSize/2)){
            isSim[1] = true; // true
            std::cout << "on sim2" << std::endl;
        };

        // for play, loop, pause, save
        if(ImGui::Button("Play Note 1", buttonSize)){
            chordNew1 = Chord(currentChord1, sus[0], amp[0], isSim[0]);
            channelSignals = chordNew1.playValues(); // get the values of the signal

            // replace the loop
            pause = 0;
            play_once = true;
            start_loop = true;
            // start_loop = true;
            play_clock.restart();

            // Play the signal
            s.play(leftTact, channelSignals[0]); // play has (channel, signal)
            s.play(botTact, channelSignals[1]); 
            s.play(rightTact, channelSignals[2]); 
            // sleep(finalSignal.length()); // sleep makes sure you cannot play another cue before that cue is done (in theory)
            // sleep is a blocking function

            std::cout << channelSignals[0].length() << " s for playing" << std::endl;
            }; 
        ImGui::SameLine();
        if(ImGui::Button("Play Note 2", buttonSize)){
            chordNew2 = Chord(currentChord2, sus[1], amp[1], isSim[1]);
            channelSignals = chordNew2.playValues(); // get the values of the signal

            // replace the loop
            pause = 0;
            play_once = true;
            start_loop = true;
            // start_loop = true;
            play_clock.restart();

            // Play the signal
            s.play(leftTact, channelSignals[0]); // play has (channel, signal)
            s.play(botTact, channelSignals[1]); 
            s.play(rightTact, channelSignals[2]); 
            // sleep(finalSignal.length()); // sleep makes sure you cannot play another cue before that cue is done (in theory)
            // sleep is a blocking function

            std::cout << channelSignals[0].length() << " s for playing" << std::endl;
            }; 
      
        if(ImGui::Button("Pause", buttonSize)){
                pause = 1;
            }; 

        // Stop the signal with pause loop
        if (pause == 1 || !start_loop){
            s.stopAll(); // stop all channels playing
            start_loop = false; // turn off the looping
            play_once = false; // turn off the play once
        }

        // Play the signal once
        if (play_once)
        {
            // Play the signal
            s.play(leftTact, channelSignals[0]); // play has (channel, signal)
            s.play(botTact, channelSignals[1]); 
            s.play(rightTact, channelSignals[2]); 
            if(play_clock.get_elapsed_time().as_seconds() > channelSignals[0].length()){ // if whole signal is played
                play_once = false; // set bool to false
                start_loop = false;
                pause = 1;
            }
        }
        // Play the signal repeatedly
        else if ((play_clock.get_elapsed_time().as_seconds() > channelSignals[0].length() && pause == 0) || start_loop)
        { // if pause has not been pressed and is time to restart signal
            // Play the signal
            s.play(leftTact, channelSignals[0]); // play has (channel, signal)
            s.play(botTact, channelSignals[1]); 
            s.play(rightTact, channelSignals[2]); 
            play_clock.restart(); // attempting a non-blocking version of sleep, reset the counter
        }

        if(ImGui::Button("Log", buttonSize))
        {
            ImGui::OpenPopup("logging_things"); // open a popup and name it for calling
            // This just needs its own space, no curlies for the if
            // std::cout << filepath << std::endl;
        }  
        static char num[120]; // info holder 
        if(ImGui::BeginPopup("logging_things")) // if clicked essentially
        {
            ImGui::Text("What are your notes: "); // precursor for me to understand
            ImGui::InputText("##edit", num, IM_ARRAYSIZE(num)); // size wanted
            ImGui::InputInt("valence?", &val);
            ImGui::SameLine();
            ImGui::InputInt("arousal?", &arous);            
            if (ImGui::Button("Close"))
            {
                ImGui::CloseCurrentPopup();
                // put things here for what should happen once closed or else it will run foreverrrr
                std::string notes_taken(num); // gets rid of null characters
                data = {trial_num, sus[0], amp[0], item_current1, isSim[0], sus[1], amp[1], item_current2, isSim[1], val, arous};
                // excel
                file_name << trial_num << ",";
                file_name << sus[0] << "," << amp[0] << "," <<  item_current1 << "," << isSim[0] << ",";
                file_name << sus[1] << "," << amp[1] << "," <<  item_current2 << "," << isSim[1] << ",";
                file_name << val << "," << arous << ",";
                file_name << notes_taken << std::endl;
                // csv_append_row(filepath, data);
                LOG(Info) << notes_taken;
                // LOG(Info) << filepath;
                trial_num++;
                // std::cout << "inside popup filepath is: " << filepath << "."  << std::endl;
            }
            ImGui::EndPopup();            
        }


        ImGui::End();

    }
};

// actually open GUI
int main() {
    // std::string filepath = "../../Data/" + wherePut.yyyy_mm_dd_hh_mm_ss() + ".csv"; // name of data changed with time
    std::cout << "What is today's date followed by a letter of the alphabet?" << std::endl;
    std::cin >> saveSubject;

    MyGui my_gui;
    my_gui.run();
    return 0;
} 