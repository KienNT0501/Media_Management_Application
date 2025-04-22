#include "MediaControl.h"
// màn hình menu
void MediaControl::MHmenu() {
	system("cls");
	std::string choice;
	std::regex ptnchoice("[1-9]{1}|10");
	do {
		std::cout << "--------- Media player control ---------" << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Pause" << std::endl;
		std::cout << "3. Stop" << std::endl;
		std::cout << "4. Next" << std::endl;
		std::cout << "5. Previous" << std::endl;
		std::cout << "6. Show current media info" << std::endl;
		std::cout << "7. Add media to playlist" << std::endl;
		std::cout << "8. Show playlist" << std::endl;
		std::cout << "9. Create new playlist" << std::endl;
		std::cout << "10. Exit" << std::endl;
		std::cout << "Your choice: ";
		std::getline(std::cin, choice);
		if (regex_match(choice, ptnchoice) == false) {
			system("cls");
			std::cout << "UNVALID INPUT! Please set input integer 1-10!" << std::endl;
		}
	} while (regex_match(choice, ptnchoice) == false);
	if (choice == "1") {
		play();
	}
	if (choice == "2") {
		pause();
	}
	if (choice == "3") {
		stop();
	}
	if (choice == "4") {
		next();
	}
	if (choice == "5") {
		previous();
	}
	if (choice == "6") {
		currentMedia();
	}
	if (choice == "7") {
		MHinput();
	}
	if (choice == "8") {
		MHListMedia();
	}
	if (choice == "9") {
		createNewplaylist();
		MHmenu();
	}
	if (choice == "10") {
		saveToFile("mediaplaylist.txt");
		std::cout << "Thank you! Program exiting..." << std::endl;
	}
}
// màn hình lựa chọn hiển thị media
void MediaControl::MHListMedia() {
	system("cls");
	std::string choice = "\0";
	std::regex ptnchoice("[1-8]{1}");
	do {
		std::cout << "1. Default playlist " << std::endl;
		std::cout << "2. Get Media Item by Index" << std::endl;
		std::cout << "3. Get Media Item by Name" << std::endl;
		std::cout << "4. Delete Media by name" << std::endl;
		std::cout << "5. Sort Media Item by Name" << std::endl;
		std::cout << "6. Sort Media Item by Duration" << std::endl;
		std::cout << "7. Sort Media Item by Format" << std::endl;
		std::cout << "8. Exit" << std::endl;
		std::cout << "Your choice: ";
		std::getline(std::cin, choice);
		if (regex_match(choice, ptnchoice) == false) {
			system("cls");
			std::cout << "UNVALID INPUT! Please set input integer 1-8!" << std::endl;
		}
	} while (regex_match(choice, ptnchoice) == false);
	if (choice == "1") {
		displayListMedia();
		system("pause");
		MHListMedia();
	}
	if (choice == "2") {
		mediabyIndex();
		std::cin.ignore();
		MHListMedia();
	}
	if (choice == "3") {
		mediabyName();
		std::cin.ignore();
		MHListMedia();
	}
	if (choice == "4") {
		MHdelete();
		MHListMedia();
	}
	if (choice == "5") {
		sortMediabyName();
		MHListMedia();
	}
	if (choice == "6") {
		sortMediabyDuration();
		MHListMedia();
	}
	if (choice == "7") {
		sortMediabyFormat();
		MHListMedia();
	}
	if (choice == "8") {
		MHmenu();
	}
}
// màn hình input media
void MediaControl::MHinput() {
	system("cls");
	std::string choice = "\0";
	std::regex ptnchoice("[1-3]{1}");
	do {
		std::cout << "1. Input Audio" << std::endl;
		std::cout << "2. Input Video" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "Your choice: ";
		std::getline(std::cin, choice);
		if (regex_match(choice, ptnchoice) == false) {
			system("cls");
			std::cout << "UNVALID INPUT! Please set input integer 1-3!" << std::endl;
		}
	} while (regex_match(choice, ptnchoice) == false);
	if (choice == "1") {
		MHinputAudio();
		MHinput();
	}
	if (choice == "2") {
		MHinputVideo();
		MHinput();
	}
	if (choice == "3") {
		MHmenu();
	}
}
// màn hình play - chơi nhạc
void MediaControl::play() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
		MHmenu();
	}
	else {

		if (!saveList()[currentIndex]->getType()) {
			std::cout << "Playing audio: " << saveList()[currentIndex]->getsongName() << std::endl;
			is_play = true;
			system("pause");
			MHmenu();
		}
		if (saveList()[currentIndex]->getType()) {
			std::cout << "Playing video: " << saveList()[currentIndex]->getsongName() << std::endl;
			is_play = true;
			system("pause");
			MHmenu();
		}
	}
}
// màn hình pause - tạm dừng chơi
void MediaControl::pause() {
	system("cls");
	if (is_play == true) {
		if (!saveList()[currentIndex]->getType()) {
			std::cout << "Pause audio: " << saveList()[currentIndex]->getsongName() << std::endl;
			is_play = true;
			system("pause");
			MHmenu();
		}
		if (saveList()[currentIndex]->getType()) {
			std::cout << "Pause video: " << saveList()[currentIndex]->getsongName() << std::endl;
			is_play = true;
			system("pause");
			MHmenu();
		}
	}
	else {
		std::cout << "THERE IS NO RUNNING MEDIA!" << std::endl;
		system("pause");
		MHmenu();
	}
}
// màn hình stop - dừng chơi
void MediaControl::stop() {
	system("cls");
	if (is_play == true) {
		if (!saveList()[currentIndex]->getType()) {
			std::cout << "Stop audio: " << saveList()[currentIndex]->getsongName() << std::endl;
			is_play = true;
			system("pause");
			MHmenu();
		}
		if (saveList()[currentIndex]->getType()) {
			std::cout << "Stop video: " << saveList()[currentIndex]->getsongName() << std::endl;
			is_play = true;
			system("pause");
			MHmenu();
		}
	}
	else {
		std::cout << "THERE IS NO RUNNING MEDIA!" << std::endl;
		system("pause");
		MHmenu();
	}
}
// màn hình next - tiếp theo nhạc
void MediaControl::next() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
		MHmenu();
	}
	if (saveList().size() == 1) {
		std::cout << "Playing audio: " << saveList()[0]->getsongName() << std::endl;
		is_play = true;
		system("pause");
		MHmenu();
	}
	else {
		currentIndex++;
		if (currentIndex == saveList().size()) {
			currentIndex = 0;
		}
		if (currentIndex < 0) {
			currentIndex = 0;
		}
		if (!saveList()[currentIndex]->getType()) {
			std::cout << "Playing audio: " << saveList()[currentIndex]->getsongName() << std::endl;
			audioCnt1++;
			if (audioCnt1 == saveListAudio().size()) {
				audioCnt1 = 0;
			}
			is_play = true;
			system("pause");
			MHmenu();
		}
		if (saveList()[currentIndex]->getType()) {
			std::cout << "Playing video: " << saveList()[currentIndex]->getsongName() << std::endl;
			videoCnt1++;
			if (videoCnt1 == saveListVideo().size()) {
				videoCnt1 = 0;
			}
			is_play = true;
			system("pause");
			MHmenu();
		}
	}
}
// màn hình trước
void MediaControl::previous() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
		MHmenu();
	}
	if (saveList().size() == 1) {
		std::cout << "Playing audio: " << saveList()[0]->getsongName() << std::endl;
		is_play = true;
		system("pause");
		MHmenu();
	}
	else {
		currentIndex--;
		if (currentIndex == saveList().size()) {
			currentIndex = 0;
		}
		if (currentIndex < 0) {
			currentIndex = 0;
		}
		if (!saveList()[currentIndex]->getType()) {
			std::cout << "Playing audio: " << saveList()[currentIndex]->getsongName() << std::endl;
			audioCnt1--;
			if (audioCnt1 < 0) {
				audioCnt1 = 0;
			}
			is_play = true;
			system("pause");
			MHmenu();
		}
		if (saveList()[currentIndex]->getType()) {
			std::cout << "Playing video: " << saveList()[currentIndex]->getsongName() << std::endl;
			videoCnt1--;
			if (videoCnt1 < 0) {
				videoCnt1 = 0;
			}
			is_play = true;
			system("pause");
			MHmenu();
		}
	}
}
// màn hình hiển thị media hiện tại
void MediaControl::currentMedia() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
		MHmenu();
	}
	if (is_play == false) {
		std::cout << " ==> THERE IS NO RUNNING SONG!" << std::endl;
		system("pause");
		MHmenu();
	}
	else {
		std::cout << "-------- CURRRENT MEDIA PLAYING INFO --------" << std::endl;
		std::cout << "Song name: " << saveList()[currentIndex]->getsongName() << "." << saveList()[currentIndex]->getformatFile() << std::endl;
		std::cout << "Singer: " << saveList()[currentIndex]->getsingerName() << std::endl;
		std::cout << "Musician: " << saveList()[currentIndex]->getmusicianName() << std::endl;
		std::cout << "Duration: " << saveList()[currentIndex]->getDuration() << std::endl;
		if (!saveList()[currentIndex]->getType()) {
			std::cout << "Size (Mb): " << saveListAudio()[audioCnt1]->getSize() << std::endl;
		}
		else if (saveList()[currentIndex]->getType()) {
			std::cout << "Frame Width: " << saveListVideo()[videoCnt1]->getframeWidth() << std::endl;
			std::cout << "Frame Height: " << saveListVideo()[videoCnt1]->getframeHeight() << std::endl;
			std::cout << "Frane Rate: " << saveListVideo()[videoCnt1]->getframeRate() << std::endl;
		}
		system("pause");
		MHmenu();
	}
}
// màn hình hiển thị nhập Audio media
void MediaControl::MHinputAudio() {

	std::string choice = "n";
	std::regex ptnchoice("[ynYN]{1}");
	do {
		system("cls");
		AudioItem* audio = new AudioItem();
		audio->input();
		addAudioItem(audio);
		addMediaItem(audio->getMedia());
		std::cout << " Audio added! " << std::endl;
		std::cout << " ==> Do you want to add new media? (y/n): ";
		std::getline(std::cin, choice);
		while (regex_match(choice, ptnchoice) == false) {
			std::cout << "UNVALID INPUT! Please set input y/n: ";
			std::getline(std::cin, choice);
		}
	} while (choice == "y" || choice == "Y");
}
// màn hình nhập Video media
void MediaControl::MHinputVideo() {

	std::string choice = "n";
	std::regex ptnchoice("[ynYN]{1}");
	do {
		system("cls");
		VideoItem* video = new VideoItem();
		video->input();
		addVideoItem(video);
		addMediaItem(video->getMedia());
		std::cout << " Video added! " << std::endl;
		std::cout << " ==> Do you want to add new media? (y/n): ";
		std::getline(std::cin, choice);
		while (regex_match(choice, ptnchoice) == false) {
			std::cout << "UNVALID INPUT! Please set input y/n: ";
			std::getline(std::cin, choice);
		}
	} while (choice == "y" || choice == "Y");
}
// màn hình chức năng xóa name song theo tên
void MediaControl::MHdelete() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
	}
	else {
		std::string nameSong;
		std::cout << "--- Delete Media ---" << std::endl;
		std::cout << "Type name of song you want to remove: ";
		std::getline(std::cin, nameSong);
		if (searchMediaItem(nameSong) != 0) {
			removeMediaItem(nameSong);
			std::cout << "Your song name: " << nameSong << " has been removed!" << std::endl;
			system("pause");
		}
		else {
			std::cout << "Name of media is not existed! Try different ones" << std::endl;
			system("pause");
			MHdelete();
		}
	}
}
// hiển thị thông tin theo index
void MediaControl::mediabyIndex() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
	}
	else {
		system("cls");
		int idx = 0;
		MediaItem* m1 = new MediaItem();
		std::cout << "Type Index of media: ";
		std::cin >> idx;
		if (idx >= saveList().size()) {
			std::cout << "Index can not be equal or bigger than list size() " << std::endl;
			std::cout << "List size: " << saveList().size() << std::endl;
			system("pause");
			mediabyIndex();
		}
		else {
			m1 = getByIndex(idx);
			m1->showInfo();
			system("pause");
			//delete m1;
		}
	}
}
// hiển thị thông tin theo tên
void MediaControl::mediabyName() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
	}
	else {
		system("cls");
		std::string name;
		MediaItem* m1 = new MediaItem();
		std::cout << "Type Name of media: " << std::endl;
		std::getline(std::cin, name);
		if (searchMediaItem(name) != 0) {
			m1 = searchMediaItem(name);
			m1->showInfo();
		}
		else {
			std::cout << "Name of media is not existed! Try different ones" << std::endl;
			system("pause");
			mediabyName();
		}
		delete m1;
	}
}
// sắp xếp media theo tên
void MediaControl::sortMediabyName() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
	}
	else {
		sortMediaItemsByName();
		displayListMedia();
		system("pause");
	}
}
// sắp xếp media theo duration
void MediaControl::sortMediabyDuration() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
	}
	else {
		sortMediaItemsByDuration();
		displayListMedia();
		system("pause");
	}
}
// sắp xếp theo format
void MediaControl::sortMediabyFormat() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
	}
	else {
		sortMediaItemsByFormat();
		displayListMedia();
		system("pause");
	}
}
// tạo new playlist
void MediaControl::createNewplaylist() {
	system("cls");
	if (saveList().size() == 0) {
		std::cout << " ==> THERE IS NO SONG WAS ADDED IN TO LIST!" << std::endl;
		system("pause");
	}
	else {
		removeAllitems();
		system("cls");
		std::cout << "NEW PLAYLIST HAS BEEN CREATED!" << std::endl;
		system("pause");
		MHmenu();

	}
}
// đọc file và lấy dữ liệu từ file
int MediaControl::readFile(const std::string& filename) {
	std::fstream in(filename);
	if (!in) {
		std::cerr << "Error: file mediaplaylist.txt is not available \n";
	}
	else {
		if (in.is_open())
		{
			in.seekp(0, std::ios::end);
			size_t size = in.tellg();
			if (size == 0)
			{
				std::string choice = "n";
				std::regex choiceptn("[ynYN]{1}");
				std::cout << "Not have any media. Do you want to add new playlist? (y/n): ";
				std::getline(std::cin, choice);
				while (!regex_match(choice, choiceptn))
				{
					system("cls");
					std::cout << "Not have any media. Do you want to add new playlist? (y/n): ";
					std::getline(std::cin, choice);
				};
				if (choice == "y" || choice == "Y") {
					MHmenu();
				}
				if (choice == "n" || choice == "N") {
					std::cout << "GOOD BYE" << std::endl;
					system("pause");
					return 0;
				}
			}
			else {
				loadFromFile(filename);
				std::cout << "Successful read data from mediaplaylist.txt!" << std::endl;
				system("pause");
				MHmenu();
			}
		}
	}
}