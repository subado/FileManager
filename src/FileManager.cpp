#include "FileManager.hpp"

FileManager::FileManager()
: workingDir_ { fs::current_path() }
{
}
