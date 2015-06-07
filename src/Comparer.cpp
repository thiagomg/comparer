//============================================================================
// Name        : Comparer.cpp
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Filesystem.h"
#include "Comparer.h"

#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <functional>

using namespace std;

//hash extended
namespace std {
    template <class T>
    inline void hash_combine(std::size_t& seed, const T& v)
    {
        hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    template <>
    struct hash<FileDesc>
    {
        typedef FileDesc argument_type;
        typedef std::size_t result_type;

        result_type operator()(const FileDesc & t) const
        {
          size_t val { 0 };
          hash_combine(val,t.getFileName());
          std::hash_combine(val,t.getSize());
          return val;
        }
    };
}
Comparer::Comparer(const std::vector<std::string> &list) {
	_dirList = list;
}

Comparer::Comparer(const std::initializer_list<std::string> &list) {
	_dirList = list;
}
	
bool Comparer::operator()()
{
	_pos_dupl.clear();
	for(const auto &dir : _dirList) {
		_checkDir(dir);
	}
	return true;
}

bool Comparer::_checkDir(const std::string &dir)
{
	Filesystem fs;
	Filesystem::FileVector fileList;

	fs.listFiles(fileList, dir);

	unordered_set<FileDesc> files;
	for_each(fileList.begin(), fileList.end(), [&](const FileDesc &fd) {

		const auto it = files.find(fd);
		if( it == files.end() ) {
			files.insert( fd );
		} else {

			auto itf = _pos_dupl.find(fd);
			if( itf == _pos_dupl.end() )
				_pos_dupl.insert( *it );
			_pos_dupl.insert( fd );

		}

	});

	_totalFiles += files.size();
	
	return true;
}

