#pragma once
#include<iostream>
#include<regex>
#include<iomanip>
class MediaItem {
private:
	std::string m_songName;
	std::string m_singerName;
	std::string m_musicianName;
	std::string m_duration;
	std::string m_formatFile;
	bool whichtype;
public:
	MediaItem() {
		m_songName = "N/A";
		m_singerName = "N/A";
		m_musicianName = "N/A";
		m_duration = "0";
		m_formatFile = "N/A";
		whichtype = true;
	}
	void play();
	void pause();
	void stop();
	void input();
	void showInfo();
	void setsongName();
	std::string getsongName();
	std::string getsongNamef(std::string& name_song);
	void setformatFile();
	std::string getformatFile();
	std::string getformatFilef(std::string& format_file);
	void setmusicianName();
	std::string getmusicianName();
	std::string getmusicianNamef(std::string& musician_name);
	void setsingerName();
	std::string getsingerName();
	std::string getsingerNamef(std::string& singer_name);
	void setDuration();
	std::string getDuration();
	std::string getDurationf(std::string& duration);
	void validate(std::string& str, int signal);
	bool audioOrvideo(bool type);
	bool getType();
};