//
//  AudioImpl_AE.h
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

#ifndef AudioImpl_AE_h
#define AudioImpl_AE_h

#include "cocos2d.h"

using namespace std;

class AudioImpl {
public:
  AudioImpl();
  ~AudioImpl();
  
  void preloadBackgroundMusic(string track);
  void preloadEffect(string track);
  
  void playBackgroundMusic(string track);
  void stopBackgroundMusic();
  
  void pauseBackgroundMusic();
  void resumeBackgroundMusic();
  
  void playEffect(string track);
  
  void setBackgroundVolume(int volume);
  void setEffectsVolume(int volume);
  
  int backgroundMusicID;
  
  float backgroundVolume;
  float effectsVolume;
};

#endif /* AudioImpl_AE_h */
