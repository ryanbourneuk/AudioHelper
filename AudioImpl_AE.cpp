//
//  AudioImpl_AE.cpp
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

#include "AudioImpl_AE.h"
#include "audio/include/AudioEngine.h"

using namespace cocos2d::experimental;

AudioImpl::AudioImpl() {
  this->backgroundMusicID = -2;
  AudioEngine::lazyInit();
}

AudioImpl::~AudioImpl() {
  AudioEngine::end();
}

void AudioImpl::preloadBackgroundMusic(string track) {
  AudioEngine::preload(track);
}

void AudioImpl::preloadEffect(string track) {
  AudioEngine::preload(track);
}

void AudioImpl::playBackgroundMusic(string track) {
  backgroundMusicID = AudioEngine::play2d(track, true, backgroundVolume, AudioEngine::getDefaultProfile());
  AudioEngine::setLoop(backgroundMusicID, true);
}

void AudioImpl::stopBackgroundMusic() {
  AudioEngine::stop(backgroundMusicID);
  
  backgroundMusicID = -2;
}

void AudioImpl::pauseBackgroundMusic() {
  if (backgroundMusicID != -2) {
    AudioEngine::pause(backgroundMusicID);
  }
}

void AudioImpl::resumeBackgroundMusic() {
  if (backgroundMusicID != -2) {
    AudioEngine::resume(backgroundMusicID);
  }
}

void AudioImpl::playEffect(string track) {
  AudioEngine::play2d(track, false, effectsVolume, AudioEngine::getDefaultProfile());
}

void AudioImpl::setBackgroundVolume(int volume) {
  backgroundVolume = ((float) volume) / 100;
  
  if (backgroundMusicID != -2) {
    AudioEngine::setVolume(backgroundMusicID, backgroundVolume);
  }
}

void AudioImpl::setEffectsVolume(int volume) {
  effectsVolume = ((float) volume) / 100;
}
