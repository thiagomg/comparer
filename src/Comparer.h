//============================================================================
// Name        : Comparer.h
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef COMPARER_H
#define	COMPARER_H

#include <set>
#include <vector>

class FileDesc;
class FileDescComparer;

class Comparer {
public:
    using ResultSet = std::multiset<FileDesc, FileDescComparer>;

private:
    std::vector<std::string> _dirList;
    ResultSet _pos_dupl;
	int _totalFiles = 0;
    
protected:
    bool _checkDir(const std::string &dir);
    
public:
    
	Comparer(const std::vector<std::string> &list);
    Comparer(const std::initializer_list<std::string> &list);
    bool operator()(); 
    
    const ResultSet &getResults() const { return _pos_dupl; }
    int getFileCount() const { return _totalFiles; }
    
};

#endif	/* COMPARER_H */

