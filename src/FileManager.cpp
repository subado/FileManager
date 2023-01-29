#include "FileManager.hpp"
#include "FileManagerError.hpp"

FileManager::FileManager()
: workingDir_ { fs::current_path() }
{
}


FileManager::FileManager(const fs::path &path)
: workingDir_ { fs::absolute(path) }
{
}

void FileManager::changeDir(const fs::path &path)
{
	if (fs::exists(path))
	{
		if (fs::is_directory(path))
		{
			workingDir_ = fs::absolute(path);
		}
		else
		{
			throw FileManagerError{"Not a directory", path};
		}
	}
	else
	{
		throw FileManagerError{"No such file or directory", path};
	}
}
