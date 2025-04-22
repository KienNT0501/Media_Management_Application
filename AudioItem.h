#pragma once
#include<iostream>
#include "MediaItem.h"
class AudioItem :public MediaItem {
private:
	std::string size;
	MediaItem* a_media = new MediaItem();
public:
	AudioItem() {
		size = "0";
	}
	void play(std::string& pl_name);
	void pause(std::string& pa_name);
	void stop(std::string& st_name);
	void input();
	void showInfo();
	std::string getSize();
	std::string getSizef(std::string size_);
	void setSize();
	MediaItem* getMedia();
};