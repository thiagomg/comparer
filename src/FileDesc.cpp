//============================================================================
// Name        : FileDesc.cpp
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "FileDesc.h"

FileDesc::FileDesc() {
	// TODO Auto-generated constructor stub

}

FileDesc::FileDesc(const FileDesc &src) {
	this->fileDir = src.fileDir;
	this->fileName = src.fileName;
	this->size = src.size;
}

const std::string& FileDesc::getFileDir() const {
	return fileDir;
}

void FileDesc::setFileDir(const std::string& fileDir) {
	this->fileDir = fileDir;
}

const std::string& FileDesc::getFileName() const {
	return fileName;
}

void FileDesc::setFileName(const std::string& fileName) {
	this->fileName = fileName;
}

int FileDesc::getSize() const {
	return size;
}

void FileDesc::setSize(int size) {
	this->size = size;
}

FileDesc::~FileDesc() {
	// TODO Auto-generated destructor stub
}

