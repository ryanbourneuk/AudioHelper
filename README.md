# AudioHelper
A lightweight audio engine accessor for your Cocos2d-x iOS and Android games, making your game audio simpler!

## Here be dragons!

I am still learning C++. It may have underlying issues which will be fixed later, or not be as efficient as it could be. However, that's part of the learning process! Feel free to suggest improvements or fixes!

## Why this class?!

In Asterun, there was never a centralised point to manage game audio from. This meant that managing any audio code became difficult, and a chore - and that sucks. AudioHelper fixes this by providing a centralised point where *all* audio is managed, along with some custom logic to handle volumes, interuptions and different file formats on iOS & Android.

The *AudioHelper* class consists of a few basic, lightweight files:
	* AudioHelper - which allows your class to talk to an audio framework of your choosing!
	* AudioImpl_SAE / AudioImpl_AE - the implementations of either framework which AudioHelper talks to, to make the audio magic happen!
		* You only need one or the other, depending on your choice of framework.

## Give an example of how this helps!

Let's say you have background music, and you can change the volume of it between 0% - 100%. You don't want the music to be played if the volume is equal to 0, but you don't want your code to be littered with calls to the audio framework checking the volume! Simply call `playBackgroundMusic()` with the track of your choosing, and the *AudioHelper* will check the volume for you, and if it's above 0 it'll play the music!

You may also have different audio formats for different platforms, but don't want the code to handle choosing the format littered EVERYWHERE. Simply call `playEffect()` with the effect of your choosing, and it will determine the correct format and play the effect for you!

You may have adverts in your game, and want to disable the background music whenever they are shown and re-enable it when the advert disappears. *AudioHelper* carries this out of the box, call `advertStarted()` when an advert is successfully presented to stop the music and `advertFinished()` when it disappears. If the volume is above 0, the music is played again when the advert is dismissed!

You may decide to switch your current audio framework for another, but with your non *AudioHelper* implementation you've got to change the references and implementations across your **ENTIRE** project. That sucks. With *AudioHelper* you've only got to switch out the *AudioImpl* file to match the framework you're moving to, and change one include line to match the new class! If you're using a custom framework, simply use the include AudioImpl files as a template and make your own implementation for the *AudioHelper*! Pull requests are welcome :)

## Great! So how to I integrate this into my game?!

The integration of *AudioHelper* is designed to be very simple.

1. Download the *AudioHelper* classes / clone this repository to your computer, and add the classes to your Cocos2d-x project.
	* Based on which cocos2d-x audio engine you're using, you'll be adding either the AudioImpl_SAE classes (for SimpleAudioEngine) or AudioImpl_AE (for AudioEngine). You will need the AudioHelper classes regardless of which engine you use.
	* In AudioHelper.h, you will need to change `#include "AudioImpl_SAE.h"` to match the header file for the AudioImpl you are using. For SimpleAudioEngine, it'll be `#include "AudioImpl_SAE.h"` while for AudioEngine you'll need `#include "AudioImpl_SAE.h"`.
2. In the `getPlatformSpecificTrackNameWith()` function, change the file formats to match those used by your own audio. The files in my games use the shown formats, although you can simply switch them out to whichever you use!
3. Preload your audio files when your game first launches.
4. Set the background volume and effects immediately after you've preloaded your audio files. **The values are in the range 0% - 100%, not 0.0 - 1.0. Please take note of this.**
5. The *AudioHelper* is now ready to use! Wherever you've used either AudioEngine or SimpleAudioEngine within your project, use the *AudioHelper* instead! Where you set your background or effects volume, set it through the *AudioHelper*. Where you play your background music, play it through the *AudioHelper*. Where you preload your music tracks, preload them through the *AudioHelper*!

Be sure that wherever you pass an audio file name to the *AudioHelper* you provide it without the file format, as the *AudioHelper* will helpfully add that on for you before it is used!

## Got any tips on how to use this efficiently?

* Audio values used by the *AudioHelper* are in the range 0 - 100 (as integer percent (%) values) instead of 0.0 - 1.0 decimal values. You can change this if you so choose. Be sure to always pass in the values in the correct range! I chose this method as my volume sliders return the value in the normal percent range (0 - 100).
* Ensure you **always** access your audio framework through the *AudioHelper* class, so it is always up to date with volume changes, background music states etc. This also means you will be able to switch out the audio framework from your game and use another if you so choose **really** easily!
* Ensure you do not add game-specific data to the *AudioHelper*. Keep the class game-agnostic and pass data to the *AudioHelper*, never access any game data from within the class itself. It'd be easy to set the volumes as soon as the *AudioHelper* is first created from within the class, but if the volumes are stored in the game's UserDefaults, you'd have to access them from within the *AudioHelper* - meaning the *AudioHelper* is now dependent on your game! It's better to get the volume values outside of the class, and pass them into the *AudioHelper*. This means you'll be able to use the same class across all of your games with no edits!
* If you've got any suggestions, get coding and open a pull request! Fixes and new additions are very welcome! :) 

## How can I ever repay you for this amazingness?!

If this has been useful to you, then great! Feel free to send me a tweet [@ryanbourne28](twitter.com/ryanbourne28) to let me know! If you really really liked it and a nice tweet just won't do, then feel free to help fund my hot chocolate cravings here: [https://www.paypal.me/ryanbourne](https://www.paypal.me/ryanbourne) - although donations are not necessary! :)
