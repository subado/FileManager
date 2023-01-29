#ifndef FILE_MANAGER_ERROR_HPP
#define FILE_MANAGER_ERROR_HPP

#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

class FileManagerError : public std::runtime_error
{
public:

	FileManagerError(const char *whatStr);
	FileManagerError(const std::string &whatStr);

	FileManagerError(const char *whatStr, const fs::path &path);
	FileManagerError(const std::string &whatStr, const fs::path &path);
};

#endif // FILE_MANAGER_ERROR_HPP
