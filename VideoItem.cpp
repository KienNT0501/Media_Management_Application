#include"VideoItem.h"
VideoItem::VideoItem() {
	frameWidth = "0";
	frameHeight = "0";
	frameRate = "0";
}
void VideoItem::play(std::string& pl_name) {
	std::cout << "Play video " << pl_name << std::endl;
}
void VideoItem::pause(std::string& pa_name) {
	std::cout << "Pause video " << pa_name << std::endl;
}
void VideoItem::stop(std::string& st_name) {
	std::cout << "Stop video " << st_name << std::endl;
}
// nhập input cho video media
void VideoItem::input() {
	std::cout << "--- Video Input ---" << std::endl;
	v_media->input();
	setframeWidth();
	setframeHeight();
	setframeRate();
	v_media->audioOrvideo(1);
}
//set frame width
void VideoItem::setframeWidth() {
	std::cout << "Frame Width: ";
	std::getline(std::cin, frameWidth);
	validate(frameWidth, 7);
}
//set frame height
void VideoItem::setframeHeight() {
	std::cout << "Frame Height: ";
	std::getline(std::cin, frameHeight);
	validate(frameHeight, 7);
}
//set frame rate
void VideoItem::setframeRate() {
	std::cout << "Frame Rate: ";
	std::getline(std::cin, frameRate);
	validate(frameRate, 7);
}
//get frame width
std::string VideoItem::getframeWidth() {
	return frameWidth;
}
//get frame Width từ file
std::string VideoItem::getframeWidthf(std::string& width) {
	frameWidth = width;
	return frameWidth;
}
// get frame height
std::string VideoItem::getframeHeight() {
	return frameHeight;
}
// get frame height từ file
std::string VideoItem::getframeHeightf(std::string& height) {
	frameHeight = height;
	return frameHeight;
}
// get frame rate
std::string VideoItem::getframeRate() {
	return frameRate;
}
//get frame rate từ file
std::string VideoItem::getframeRatef(std::string& rate) {
	frameRate = rate;
	return frameRate;
}
// show info VideoItem 
void VideoItem::showInfo() {
	v_media->showInfo();
	std::cout << "Frame Width: " << getframeWidth() << std::endl;
	std::cout << "Frame Height: " << getframeHeight() << std::endl;
	std::cout << "Frame Rate: " << getframeRate() << std::endl;
}
// get Media
MediaItem* VideoItem::getMedia() {
	return v_media;
}
