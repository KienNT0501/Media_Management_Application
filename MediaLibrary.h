#pragma once
#include<vector>
#include<algorithm>
#include<regex>
#include "MediaItem.h"
#include "VideoItem.h"
#include "AudioItem.h"
#include <fstream>
#include <iomanip>
#include<numeric>
class MediaLibrary {
private:
	std::vector<MediaItem*> listMedia;
	std::vector<AudioItem*> listAudio;
	std::vector<VideoItem*> listVideo;
	int audioCnt = 0;
	int videoCnt = 0;
public:
	MediaLibrary();
	~MediaLibrary();
	template<typename T>
	void clear(std::vector<T*>& list);
	void removeAllitems();
	unsigned int sizet();
	int getaudioCnt();
	int getvideoCnt();
	void addMediaItem(MediaItem* item);
	void addAudioItem(AudioItem* item);
	void addVideoItem(VideoItem* item);
	void removeMediaItem(const std::string& name);
	MediaItem* getByIndex(int idx);
	MediaItem* searchMediaItem(const std::string& name);
	void displayListMedia();
	std::vector<MediaItem*> saveList();
	std::vector<AudioItem*> saveListAudio();
	std::vector<VideoItem*> saveListVideo();
	void sortMediaItemsByName();
	void sortMediaItemsByDuration();
	void sortMediaItemsByFormat();
	void saveToFile(const std::string& filename);
	void loadFromFile(const std::string& filename);
};