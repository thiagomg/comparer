//============================================================================
// Name        : FileDesc.h
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef FILEDESC_H_
#define FILEDESC_H_

#include <string>

class FileDesc {
private:
	std::string fileName;
	std::string fileDir;
	int size = 0;
public:
	FileDesc();
	FileDesc(const FileDesc &src);
	virtual ~FileDesc();
	const std::string& getFileDir() const;
	void setFileDir(const std::string& fileDir);
	const std::string& getFileName() const;
	void setFileName(const std::string& fileName);
	int getSize() const;
	void setSize(int size);

	friend bool operator==(const FileDesc &l, const FileDesc &r) {
		return (l.fileName == r.fileName) && (l.size == r.size);
	}
	friend bool operator!=(const FileDesc &l, const FileDesc &r) {
		return !(l == r);
	}

};

struct FileDescComparer {
	bool operator()(const FileDesc &l, const FileDesc &r) {
		if( l.getFileName() == r.getFileName() ) {
			return l.getSize() < r.getSize();
		}
		return l.getFileName() < r.getFileName();
	}
};

#endif /* FILEDESC_H_ */
