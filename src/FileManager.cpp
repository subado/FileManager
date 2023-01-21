#include "FileManager.hpp"

FileManager::FileManager()
: workingDir_ { fs::current_path() }
{
}


FileManager::FileManager(const fs::path &path)
: workingDir_ { fs::absolute(path) }
{
}
