//============================================================================
// Name        : Filesystem.h
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <string>
#include <vector>
#include <set>

#include "FileDesc.h"

class Filesystem {
private:

public:
	Filesystem();
	virtual ~Filesystem();

	using FileVector = std::vector<FileDesc>;
	void listFiles(FileVector &fileList, const std::string &path);
};

#endif /* FILESYSTEM_H_ */
