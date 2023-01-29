#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <filesystem>

namespace fs = std::filesystem;

class FileManager
{
public:

	FileManager();
	FileManager(const fs::path &path);

	~FileManager() = default;

	void changeDir(const fs::path &path);

private:

	fs::path workingDir_;
};

#endif // FILE_MANAGER_HPP
