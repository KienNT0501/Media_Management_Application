#pragma once
#include<iostream>
#include "MediaItem.h"
class VideoItem :public MediaItem {
private:
	std::string frameWidth;
	std::string frameHeight;
	std::string frameRate;
	MediaItem* v_media = new MediaItem();
public:
	VideoItem();
	void play(std::string& pl_name);
	void pause(std::string& pa_name);
	void stop(std::string& st_name);
	void input();
	void showInfo();
	std::string getframeWidth();
	std::string getframeWidthf(std::string& width);
	void setframeWidth();
	std::string getframeHeight();
	std::string getframeHeightf(std::string& height);
	void setframeHeight();
	std::string getframeRate();
	std::string getframeRatef(std::string& rate);
	void setframeRate();
	MediaItem* getMedia();
};