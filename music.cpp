#include "music.h"

bool Music_Property::music = 1;

QString Music_Property::music_state[2] = {QString("音乐：关"), QString("音乐：开")};

QString Music_Property::music_url = ":/resource/Music/happy.wav";
