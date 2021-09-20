#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>
#include <syntacts>
#include <random>
#include <iostream> 
#include <fstream> // need to include inorder to save to csv
#include <chrono> 
using namespace mahi::gui;
using namespace mahi::util;

// ALL BLOCKS (Pre- and Post- Tests and ASSOCIATION Training) SHOULD BE 30 rpts for each 6 stim, for a total of 180 trials per each run. 

// Your Experiment will be an application, a window with gui that you can interact with 
// These are the Application Window Settings. You'll need to adjust your display ratio on desktop to match this 
int windowWidth = 1920;
int windowHeight = 1080;
ImVec2 buttonSize = ImVec2(400, 65);  // Size of buttons on GUI
int deviceNdx = 6; // "Speakers (USB Sound Device)"; // Put my device name or number string deviceName = "yada yada"

// Vibration Settings 
double freq_set = 250; //175; // Tactor Frequency (To be played for the Center)
double amp_set =  1; // Tactor Amplitude  (To be played for the Center)
double dur_set =  0.4; // Tactor Duration 400ms from localization study. duration had no effect, will go for longer so that better for associations 

// std::vector<BlockSettings> settings = {{175,2,69},}    <--- BETTER CODING PRACTICES FROM EVAN SEE BLOCKSETTING

// This makes the GUI, is important
class DrawingDemo : public Application {

   // Need the session (Syntacts stuff)
    tact::Session s; // (1) Add a Session as a member variable of the current class   
    // Everything in this section sets up your experiment. runs and generates stimuli vectors to be presented 
public: DrawingDemo() : Application(windowWidth, windowHeight, "Drawing", 0) {
    s.open(deviceNdx); // 10  (2) Open/Configure Session s in constructor -- opens specific device by index (16)

    // something the GUI needs *shrugs*
    ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_ViewportsEnable;
    set_background(Grays::Gray); //background_color = Grays::Black;  // I can make it a pretty color if I want, Google It!

    }

// have to have an update function since we have a GUI
// This update function is essentially the main function
      bool running = false;
      virtual void update() override
      {
          if (!running)
          {
              ImGui::Begin("Issa GUI"); // this is the GUI title?
              bool buttT = { ImGui::Button("Play Cue", buttonSize) };
              // the block_cntr will update after each block was rendered an the GUI w buttons will pop up once the block has finished.
              // Once button is clicked again, the next block will start being rendered 

              if (buttT) { // if the Button in pressed... 
                  running = true;
                  tact::Signal sig = tact::Sine(freq_set) * tact::Envelope(dur_set, amp_set); 
                  s.play(0, sig);  // play(channel, cue)
                  tact::sleep(2); // maybe?
                  running = false;
              }
              ImGui::End();
          }

      }

    };


      int main(int argc, char const* argv[])
      {
          /* std::cout << "Enter pilot subject (e.g. S10X)\n"; // saving subject information
          std::cin >> saveSubject; // Get the user input from keyboard 
          */
          
          DrawingDemo demo;
          demo.run();
          return 0;
      }