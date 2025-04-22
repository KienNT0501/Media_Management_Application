#include"AudioItem.h"
//hàm play-chơi nhạc
void AudioItem::play(std::string& pl_name) {
	std::cout << "Play audio " << pl_name << std::endl;
}
//hàm pause-dừng chơi
void AudioItem::pause(std::string& pa_name) {
	std::cout << "Pause audio " << pa_name << std::endl;
}
//hàm stop - dừng chơi nhạc
void AudioItem::stop(std::string& st_name) {
	std::cout << "Stop audio " << st_name << std::endl;
}
//Nhập input Audio
void AudioItem::input() {
	std::cout << "--- Audio Input ---" << std::endl;
	a_media->input();
	setSize();
	a_media->audioOrvideo(0);
}
// Set size của media
void AudioItem::setSize() {
	std::cout << "Size (Mb): ";
	std::getline(std::cin, size);
	validate(size, 6);
}
// lấy size của media
std::string AudioItem::getSize() {
	return size;
}
// lấy size từ file đã lưu
std::string AudioItem::getSizef(std::string size_) {
	size = size_;
	return size;
}
// in ra info
void AudioItem::showInfo() {
	a_media->showInfo();
	std::cout << "Size (Mb): " << getSize();
}
// lấy ra phần tử Media
MediaItem* AudioItem::getMedia() {
	return a_media;
}