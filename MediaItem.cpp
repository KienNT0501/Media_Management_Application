#include "MediaItem.h"
bool MediaItem::audioOrvideo(bool type) {
	if (type == 1) {
		whichtype = true;
	}
	if (type == 0) {
		whichtype = false;
	}
	return whichtype;
}
bool MediaItem::getType() {
	return whichtype;
}

void MediaItem::play() {
	std::cout << "play media " << std::endl;
}
void MediaItem::pause() {

}
void MediaItem::stop() {

}
void MediaItem::input() {
	setsongName();
	setformatFile();
	setmusicianName();
	setsingerName();
	setDuration();
}
// valid thông tin nhập vào
void MediaItem::validate(std::string& str, int signal) {
	std::regex ptnsongName("[A-Za-z\\s\\d]{1,25}");
	std::regex ptnformatFile("[a-z0-9]{3}");
	std::regex ptnmusicianName("[A-Za-z\\s\\d]{1,25}");
	std::regex ptnsingerName("[A-Za-z\\s\\d]{1,25}");
	std::regex ptnDuration("[\\d]{1,25}");
	std::regex ptnSize("[\\d]{1,25}");
	std::regex ptnFrame("[\\d]{1,25}");
	if (signal == 1) {
		while (regex_match(str, ptnsongName) == false) {
			std::cout << "Name of song is unvalid! Try different input: ";
			std::getline(std::cin, str);
		};
	}
	if (signal == 2) {
		while (regex_match(str, ptnformatFile) == false) {
			std::cout << "Format of file is unvalid! Try different input: ";
			std::getline(std::cin, str);
		};
	}
	if (signal == 3) {
		while (regex_match(str, ptnmusicianName) == false) {
			std::cout << "Name of musician is unvalid! Try different input: ";
			std::getline(std::cin, str);
		};
	}
	if (signal == 4) {
		while (regex_match(str, ptnsingerName) == false) {
			std::cout << "Name of singer is unvalid! Try different input: ";
			std::getline(std::cin, str);
		};
	}
	if (signal == 5) {
		while (regex_match(str, ptnDuration) == false) {
			std::cout << "Duration must be number! Try different input: ";
			std::getline(std::cin, str);
		};
	}
	if (signal == 6) {
		while (regex_match(str, ptnDuration) == false) {
			std::cout << "Size (Mb) must be number! Try different input: ";
			std::getline(std::cin, str);
		};
	}
	if (signal == 7) {
		while (regex_match(str, ptnFrame) == false) {
			std::cout << "Frame dimensions must be number! Try different input: ";
			std::getline(std::cin, str);
		};
	}
}
// set tên bài hát
void MediaItem::setsongName() {
	std::cout << "Song name: ";
	std::getline(std::cin, m_songName);
	validate(m_songName, 1);
}
// get tên bài hát
std::string MediaItem::getsongName() {
	return m_songName;
}
// get tên bài hát từ file
std::string MediaItem::getsongNamef(std::string& name_song) {
	m_songName = name_song;
	return m_songName;
}
// set format file
void MediaItem::setformatFile() {
	std::cout << "Format file: ";
	std::getline(std::cin, m_formatFile);
	validate(m_formatFile, 2);
}
// get format file
std::string MediaItem::getformatFile() {
	return m_formatFile;
}
// get format file từ file mylist.txt
std::string MediaItem::getformatFilef(std::string& format_file) {
	m_formatFile = format_file;
	return m_formatFile;
}
// set musician name
void MediaItem::setmusicianName() {
	std::cout << "Musician: ";
	std::getline(std::cin, m_musicianName);
	validate(m_musicianName, 3);
}
// get musician name
std::string MediaItem::getmusicianName() {
	return m_musicianName;
}
// get musician name từ file
std::string MediaItem::getmusicianNamef(std::string& musician_name) {
	m_musicianName = musician_name;
	return m_musicianName;
}
// set singer name
void MediaItem::setsingerName() {
	std::cout << "Singer Name: ";
	std::getline(std::cin, m_singerName);
	validate(m_singerName, 4);
}
// get singer name
std::string MediaItem::getsingerName() {
	return m_singerName;
}
// get singer name từ file
std::string MediaItem::getsingerNamef(std::string& singer_name) {
	m_singerName = singer_name;
	return m_singerName;
}
// set duration 
void MediaItem::setDuration() {
	std::cout << "Duration: ";
	std::getline(std::cin, m_duration);
	validate(m_duration, 5);
}
// get duration
std::string MediaItem::getDuration() {
	return m_duration;
}
// get duration từ file
std::string MediaItem::getDurationf(std::string& duration) {
	m_duration = duration;
	return m_duration;
}
// show info
void MediaItem::showInfo() {
	std::cout << "Song name: " << m_songName << "." << m_formatFile << std::endl;
	std::cout << "Singer Name: " << m_singerName << std::endl;
	std::cout << "Musician: " << m_musicianName << std::endl;
	std::cout << "Duration: " << m_duration << std::endl;
}