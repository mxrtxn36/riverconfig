#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
//execute linux command -system("");-
string modkey="Mod4";
int decimal = 1;

system("riverctl map normal Mod4+Shift Q close");
system("riverctl map normal Mod4+Shift E exit");
system("riverctl map normal Mod4 Return spawn alacritty");
system("riverctl map normal Mod4 D spawn fuzzel");

for (int i=1; i<10; i++) {
    std::ostringstream focusedTags;
    std::ostringstream sendTo;
    focusedTags << "riverctl map normal " << modkey << " KP_" << i << " set-focused-tags " << decimal;
    sendTo << "riverctl map normal " << modkey << "+Control KP_" << i << " set-view-tags " << decimal;
    system(focusedTags.str().c_str());
    system(sendTo.str().c_str());
    //system(("riverctl map normal " + modkey + " " + std::to_string(i) + " set-focused-tags " + std::to_string(decimal)).c_str());
    decimal*=2;
}

//Fn keys to control media
system("riverctl map normal None XF86AudioRaiseVolume  spawn 'pamixer -i 5'");
system("riverctl map normal None XF86AudioLowerVolume  spawn 'pamixer -d 5'");
system("riverctl map normal None XF86AudioMute         spawn 'pamixer --toggle-mute'");
system("riverctl map normal None XF86AudioMedia spawn 'playerctl play-pause'");
system("riverctl map normal None XF86AudioPlay  spawn 'playerctl play-pause'");
system("riverctl map normal None XF86AudioPrev  spawn 'playerctl previous'");
system("riverctl map normal None XF86AudioNext  spawn 'playerctl next'");
//Wayland screenshotting utility

system(R"~(riverctl map normal None Print spawn 'grim -g "$(slurp)" $(xdg-user-dir SCREENSHOTS)/$(date +"%s_grim.png")')~");
//system("riverctl map normal None Print spawn ''");

//Static controls
system("riverctl map normal Mod4 F toggle-fullscreen");

system("riverctl default-layout rivertile");
system("exec rivertile -main-ratio 0.5 -main-count 1 -main-location left -view-padding 3 -outer-padding 3 &");
system("exec /usr/bin/pipewire & exec /usr/bin/pipewire-pulse & exec /usr/bin/pipewire-media-session &");

// Set repeat rate
system("riverctl set-repeat 50 350");


system("riverctl focus-follows-cursor");

return 0;
}
