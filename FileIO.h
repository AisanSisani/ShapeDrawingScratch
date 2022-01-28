#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Renderer.h"

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;

// handles reading and executing test outputs
class FileIO {

private:

	ofstream result;

public:

	FileIO();

	void loadFile(Renderer&, const char*);
	void run(Renderer&, ifstream&);
	void resetStream(istringstream&) const;
};