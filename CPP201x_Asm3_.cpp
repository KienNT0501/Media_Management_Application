#include <iostream>
#include <fstream>
#include "MediaItem.h"
#include "AudioItem.h"
#include "VideoItem.h"
#include "MediaLibrary.h"
#include "MediaControl.h"
int main() {
	MediaControl m1;
	m1.readFile("mediaplaylist.txt");
	return 0;
}
