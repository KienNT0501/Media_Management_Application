#include "MediaLibrary.h"
MediaLibrary::MediaLibrary() {}
MediaLibrary::~MediaLibrary() {}
// template xóa phần tử tại con trỏ itr với kiểu dữ liệu generic T
template <typename T>
void MediaLibrary::clear(std::vector<T*>& list) {
	typename std::vector<T*>::iterator itr = list.begin();
	while (itr != list.end()) {
		itr = list.erase(itr);  // Use the return value of erase to update the iterator
	}
}

//bool MediaLibrary::empty() {}
int MediaLibrary::getaudioCnt() {
	return audioCnt;
}
int MediaLibrary::getvideoCnt() {
	return videoCnt;
}
unsigned int MediaLibrary::sizet() {
	return listMedia.size();
}
void MediaLibrary::addMediaItem(MediaItem* item) {
	listMedia.push_back(item);
}
void MediaLibrary::addAudioItem(AudioItem* item) {
	listAudio.push_back(item);
}
void MediaLibrary::addVideoItem(VideoItem* item) {
	listVideo.push_back(item);
}
// hàm xóa các Media Item tại itr
void MediaLibrary::removeMediaItem(const std::string& name) {
	auto itr = std::find_if(listMedia.begin(), listMedia.end(), [name](MediaItem* e) {return e->getsongName() == name;});
	listMedia.erase(itr);
}
// xóa toàn bộ items
void MediaLibrary::removeAllitems() {
	clear(listMedia);
	clear(listAudio);
	clear(listVideo);
}
// get media tại index list media
MediaItem* MediaLibrary::getByIndex(int idx) {
	return listMedia[idx];
}
// search media item 
MediaItem* MediaLibrary::searchMediaItem(const std::string& name) {
	auto itr = std::find_if(listMedia.begin(), listMedia.end(), [name](MediaItem* e) {return e->getsongName() == name;});
	if (itr != listMedia.end()) {
		return listMedia[itr - listMedia.begin()];
	}
	else {
		return 0;
	}
}
// display list media
void MediaLibrary::displayListMedia() {
	system("cls");
	if (listMedia.size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST! " << std::endl;
	}
	else {
		int audioCnt2 = 0;
		int videoCnt2 = 0;
		std::cout << "--------- MEDIA PLAYLIST ---------" << std::endl;
		for (int i = 0;i < listMedia.size();i++) {
			std::cout << std::left << std::setw(5) << i + 1 << "\t" << std::setw(20) << "Media name" << std::setw(25) << "Format File" << std::setw(20) << "Musician" << std::setw(20) << "Singer" << std::setw(20) << "Duration (s)" << std::endl
				<< "\t" << std::setw(20) << listMedia[i]->getsongName() << std::setw(25) << listMedia[i]->getformatFile() << std::setw(20) << listMedia[i]->getmusicianName() << std::setw(20) << listMedia[i]->getsingerName() << std::setw(20) << listMedia[i]->getDuration() << std::endl;
			if (!listMedia[i]->getType()) {
				std::cout << "\t" << std::setw(20) << "Size (Mb)" << std::endl
					<< "\t" << std::setw(20) << listAudio[audioCnt2]->getSize() << std::endl;
				audioCnt2++;
			}
			if (listMedia[i]->getType()) {

				std::cout << "\t" << std::setw(20) << "Frame Width (pixel)" << std::setw(25) << "Frame Height (pixel)" << std::setw(20) << "Frame Rate (frames/second)" << std::endl
					<< "\t" << std::setw(20) << listVideo[videoCnt2]->getframeWidth() << std::setw(25) << listVideo[videoCnt2]->getframeHeight() << std::setw(20) << listVideo[videoCnt2]->getframeRate() << std::endl;
				videoCnt2++;
			}
		}
	}
}
// load file
void MediaLibrary::loadFromFile(const std::string& filename) {
	std::fstream settingFile(filename, std::ios_base::in);

	if (!settingFile) {
		std::cerr << "Error: file mediaplaylist.txt is not available \n";
	}
	else {
		if (settingFile.is_open()) {
			std::string input;
			int count = -1;
			while (getline(settingFile, input)) {
				count++;
				size_t start = input.find("Song name: ");
				if (start != std::string::npos) {
					start += 11;
					size_t end = input.find(",", start);
					if (end != std::string::npos) {
						std::string name_song = input.substr(start, end - start);
						size_t start1 = start + name_song.length() + 15;
						size_t end1 = input.find(",", start1);
						std::string format_file = input.substr(start1, end1 - start1);
						size_t start2 = start1 + format_file.length() + 12;
						size_t end2 = input.find(",", start2);
						std::string musician_ = input.substr(start2, end2 - start2);
						size_t start3 = start2 + musician_.length() + 10;
						size_t end3 = input.find(",", start3);
						std::string singer_ = input.substr(start3, end3 - start3);
						size_t start4 = start3 + singer_.length() + 12;
						size_t end4 = input.find(",", start4);
						std::string duration = input.substr(start4, end4 - start4);
						MediaItem* s = new MediaItem();
						s->getsongNamef(name_song);
						s->getformatFilef(format_file);
						s->getmusicianNamef(musician_);
						s->getsingerNamef(singer_);
						s->getDurationf(duration);
						addMediaItem(s);
						if (input.find("Size", end4) != std::string::npos) {
							size_t start5 = input.find("Size");
							start5 = start4 + duration.length() + 12;
							size_t end5 = input.find(".", start5);
							std::string size_ = input.substr(start5, end5 - start5);
							AudioItem* a = new AudioItem();
							a->getSizef(size_);
							s->audioOrvideo(0);
							addAudioItem(a);
							audioCnt++;
						}
						else {
							size_t start6 = input.find("Frame Width: ");
							start6 += 13;
							size_t end6 = input.find(",", start6);
							std::string frame_width = input.substr(start6, end6 - start6);
							size_t start7 = input.find("Frame Height: ");
							start7 += 14;
							size_t end7 = input.find(",", start7);
							std::string frame_height = input.substr(start7, end7 - start7);
							size_t start8 = input.find("Frame Rate: ");
							start8 += 12;
							size_t end8 = input.find(".", start8);
							std::string frame_rate = input.substr(start8, end8 - start8);
							VideoItem* v = new VideoItem();
							v->getframeWidthf(frame_width);
							v->getframeHeightf(frame_height);
							v->getframeRatef(frame_rate);
							s->audioOrvideo(1);
							addVideoItem(v);
							videoCnt++;
						}

					}
				}
			}
		}
	}
}
// sắp xếp item theo name
void MediaLibrary::sortMediaItemsByName() {
	std::sort(listMedia.begin(), listMedia.end(), [](MediaItem* e1, MediaItem* e2) {return e1->getsongName() < e2->getsongName();});
}
// sắp xếp item theo duration
void MediaLibrary::sortMediaItemsByDuration() {
	std::sort(listMedia.begin(), listMedia.end(), [](MediaItem* e1, MediaItem* e2) {return e1->getDuration() < e2->getDuration();});
}
// sắp xếp item theo format
void MediaLibrary::sortMediaItemsByFormat() {
	std::sort(listMedia.begin(), listMedia.end(), [](MediaItem* e1, MediaItem* e2) {return e1->getformatFile() < e2->getformatFile();});
}
//lưu vào file txt
void MediaLibrary::saveToFile(const std::string& filename) {
	std::fstream medialistFile(filename, std::ios_base::out);
	if (!medialistFile) {
		std::cerr << "Error: Unable to open file " << filename << std::endl;
	}
	else {
		if (medialistFile.is_open()) {
			int audio_cnt = 0;
			int video_cnt = 0;
			for (int i = 0; i < listMedia.size();i++) {
				medialistFile << "Song name: " << listMedia[i]->getsongName() << ", " << "Format File: " << listMedia[i]->getformatFile() << ", " << "Musician: " << listMedia[i]->getmusicianName() << ", " << "Singer: " << listMedia[i]->getsingerName() << ", " << "Duration: " << listMedia[i]->getDuration() << ", ";
				if (!listMedia[i]->getType()) {
					medialistFile << "Size(Mb): " << listAudio[audio_cnt]->getSize() << "." << std::endl;
					audio_cnt++;
				}
				if (listMedia[i]->getType()) {
					medialistFile << "Frame Width: " << listVideo[video_cnt]->getframeWidth() << ", " << "Frame Height: " << listVideo[video_cnt]->getframeHeight() << ", " << "Frame Rate: " << listVideo[video_cnt]->getframeRate() << "." << std::endl;
					video_cnt++;
				}
			}
		}
	}
}
//trả về list media
std::vector<MediaItem*> MediaLibrary::saveList() {
	return listMedia;
}
// trả về list audio
std::vector<AudioItem*> MediaLibrary::saveListAudio() {
	return listAudio;
}
// trả về list video
std::vector<VideoItem*> MediaLibrary::saveListVideo() {
	return listVideo;
}