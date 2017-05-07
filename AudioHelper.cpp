//
//  AudioHelper.cpp
//
//  Copyright (c) 2017 Ryan Bourne. All rights reserved.
//  https://www.ryanbournedev.wordpress.com & https://twitter.com/ryanbourne28
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#include "AudioHelper.h"

AudioHelper* AudioHelper::audioHelperSingleton = NULL;

AudioHelper::AudioHelper() {
  
}

AudioHelper::~AudioHelper() {
  delete audioImpl;
  audioImpl = NULL;
}

AudioHelper* AudioHelper::sharedAudioHelper() {
  if (NULL == audioHelperSingleton) {
    audioHelperSingleton = new AudioHelper();
    audioHelperSingleton->audioImpl = new AudioImpl();
    
    audioHelperSingleton->setStartingValues();
  }
  
  return audioHelperSingleton;
}

void AudioHelper::setStartingValues() {
  currentBackgroundMusic = "";
}

void AudioHelper::preloadBackgroundMusic(string track) {
  audioImpl->preloadBackgroundMusic(getPlatformSpecificTrackNameWith(track, true));
}

void AudioHelper::preloadEffect(string track) {
  audioImpl->preloadEffect(getPlatformSpecificTrackNameWith(track, false));
}

void AudioHelper::playBackgroundMusic(string track) {
  if (backgroundVolume == 0) return;
  
  currentBackgroundMusic = track;
  
  audioImpl->playBackgroundMusic(getPlatformSpecificTrackNameWith(track, true));
}

void AudioHelper::stopBackgroundMusic() {
  audioImpl->stopBackgroundMusic();
}

void AudioHelper::pauseBackgroundMusic() {
  audioImpl->pauseBackgroundMusic();
}

void AudioHelper::resumeBackgroundMusic() {
  audioImpl->resumeBackgroundMusic();
}

void AudioHelper::playEffect(string track) {
  if (effectsVolume == 0) return;
  
  audioImpl->playEffect(getPlatformSpecificTrackNameWith(track, false));
}

void AudioHelper::advertStarted() {
  this->stopBackgroundMusic();
}

void AudioHelper::advertFinished() {
  if (backgroundVolume == 0 || currentBackgroundMusic.empty()) {
    return;
  }
  
  this->playBackgroundMusic(currentBackgroundMusic);
}

string AudioHelper::getPlatformSpecificTrackNameWith(string track, bool backing) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
  return StringUtils::format("%s.ogg", track.c_str());
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
  string fileFormat = backing ? "m4a" : "caf";
  return StringUtils::format("%s.%s", track.c_str(), fileFormat.c_str());
#endif
}

void AudioHelper::setBackgroundVolume(int volume) {
  backgroundVolume = volume;
  
  audioImpl->setBackgroundVolume(volume);
  
  if (volume == 0) {
    currentBackgroundMusic = "";
  }
}

void AudioHelper::setEffectsVolume(int volume) {
  effectsVolume = volume;
  
  audioImpl->setEffectsVolume(volume);
}
