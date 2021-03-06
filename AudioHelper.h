//
//  AudioHelper.h
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

#ifndef AudioHelper_h
#define AudioHelper_h

#include "cocos2d.h"
#include "AudioImpl_SAE.h"

using namespace cocos2d;
using namespace std;

class AudioHelper {
private:
  AudioHelper();
  ~AudioHelper();
  
  static AudioHelper* audioHelperSingleton;
  
  AudioImpl* audioImpl;
  
public:
  static AudioHelper* sharedAudioHelper();
  
  void setStartingValues();
  
  void preloadBackgroundMusic(string track);
  void preloadEffect(string track);
  
  void playBackgroundMusic(string track);
  void stopBackgroundMusic();
  
  void pauseBackgroundMusic();
  void resumeBackgroundMusic();
  
  void playEffect(string track);
  
  void advertStarted();
  void advertFinished();
  
  string getPlatformSpecificTrackNameWith(string track, bool backing);
  
  void setBackgroundVolume(int volume);
  void setEffectsVolume(int volume);
  
  int backgroundVolume;
  int effectsVolume;
  
private:
  string currentBackgroundMusic;
};

#endif /* AudioHelper_h */
