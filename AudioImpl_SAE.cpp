//
//  AudioImpl_SAE.cpp
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

#include "AudioImpl_SAE.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

AudioImpl::AudioImpl() { }

AudioImpl::~AudioImpl() { }

void AudioImpl::preloadBackgroundMusic(string track) {
  SimpleAudioEngine::getInstance()->preloadBackgroundMusic(track.c_str());
}

void AudioImpl::preloadEffect(string track) {
  SimpleAudioEngine::getInstance()->preloadEffect(track.c_str());
}

void AudioImpl::playBackgroundMusic(string track) {
  SimpleAudioEngine::getInstance()->playBackgroundMusic(track.c_str(), true);
}

void AudioImpl::stopBackgroundMusic() {
  SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void AudioImpl::pauseBackgroundMusic() {
  SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AudioImpl::resumeBackgroundMusic() {
  SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AudioImpl::playEffect(string track) {
  SimpleAudioEngine::getInstance()->playEffect(track.c_str());
}

void AudioImpl::setBackgroundVolume(int volume) {
  SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(((float) volume) / 100);
}

void AudioImpl::setEffectsVolume(int volume) {
  SimpleAudioEngine::getInstance()->setEffectsVolume(((float) volume) / 100);
}

