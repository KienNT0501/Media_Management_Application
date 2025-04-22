#pragma once
#include "MediaLibrary.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<regex>
#include <fstream>
#include <iomanip>
#include<numeric>
class MediaControl :public MediaLibrary {
private:
	MediaLibrary mediaLibrary;
	MediaItem* currentlyPlaying;
	int currentIndex = 0;
	bool is_play = false;
	bool is_stop = false;
	int audioCnt1;
	int videoCnt1;
public:
	void play();
	void pause();
	void stop();
	void next();
	void previous();
	void currentMedia();
	void MHmenu();
	void MHListMedia();
	void MHinput();
	void MHinputAudio();
	void MHinputVideo();
	void MHdelete();
	void mediabyIndex();
	void mediabyName();
	void sortMediabyName();
	void sortMediabyDuration();
	void sortMediabyFormat();
	void createNewplaylist();
	int readFile(const std::string& filename);
};