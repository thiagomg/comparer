//============================================================================
// Name        : Filesystem.cpp
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Filesystem.h"
#include <iostream>

//FIXME: Unix-only. Wait for experimental or include boost
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

Filesystem::Filesystem() {
}

Filesystem::~Filesystem() {
}

void Filesystem::listFiles(FileVector &fileList, const std::string &path) {

	DIR *dirHandle = opendir(path.c_str());
	if( dirHandle == nullptr )
		return;

	string baseDir;
	baseDir.reserve( path.size() + 1 );
	baseDir.assign(path);
	if( *(baseDir.rbegin()) != '/' ) {
		baseDir += '/';
	}
	string curDirName;
	curDirName.reserve( baseDir.size() + MAXNAMLEN );

	struct dirent *curDir;
	while ((curDir = readdir(dirHandle)) != NULL) {

		string dirNameOnly = curDir->d_name;
		if( dirNameOnly == "." || dirNameOnly == ".." )
			continue;

		struct stat sb;
		curDirName = baseDir + dirNameOnly;
		if( stat(curDirName.c_str(), &sb) == -1 ) {
			cerr << "Error reading " << curDir->d_name << endl;
			continue;
		}

		if(S_ISREG(sb.st_mode)) {
			FileDesc fileDesc;
			fileDesc.setFileDir(baseDir);
			fileDesc.setFileName(curDir->d_name);
			fileDesc.setSize(sb.st_size);
			fileList.push_back(fileDesc);
		} else if( S_ISDIR(sb.st_mode) ) {
			listFiles(fileList, curDirName);
		}

	}

	closedir(dirHandle);

}
