//============================================================================
// Name        : main.cpp
// Author      : Thiago Massari Guedes
// Version     :
// Copyright   : GPL v2 - You can copy and share, but keep my name.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include "Filesystem.h"

#include "Comparer.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	vector<string> dirs;
	for(int i=1; i < argc; i++) {
		dirs.push_back( argv[i] );
	}
	
	if( dirs.empty() ) {
		cout << "Uso: comparer <lista de arquivos>" << endl;
		cout << R"(Ex: "/bkps/d1" "/bkps/d2")" << endl;
		return 1;
	}
	
	cout << "Examinando diretorios:" << endl;
	for(const auto &d : dirs) {
		cout << "-- " << d << endl;
	}
	cout << "---------------------------" << endl;
	
	Comparer comparer(dirs);
	comparer();

	const Comparer::ResultSet &pos_dupl = comparer.getResults();
	int total = comparer.getFileCount();
	FileDesc last;
	cout << "Total files: " << total << ", Dupl: " << pos_dupl.size() << endl;
	for_each(pos_dupl.begin(), pos_dupl.end(), [&](const FileDesc &fd) {
		if( last != fd ) {
			cout << endl << "[" << fd.getFileName() << " - " << fd.getSize() << "]" << endl;
			last = fd;
		}
		cout << fd.getFileDir() << fd.getFileName() << endl;
		//TODO: Se comparacao binaria, faze-la aqui
	});
	
    return 0;
}

