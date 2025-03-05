#pragma once
#ifndef AUDIO_H
#define AUDIO_H

const Wave wave = LoadWave("C:/dev/CPP/PewPewGame/src/assets/audio/soundfx/Pew.wav");
Sound Pew = LoadSoundFromWave(wave);

#endif