#ifndef FILE_MANAGER_ERROR_HPP
#define FILE_MANAGER_ERROR_HPP

#include <stdexcept>

class FileManagerError : public std::runtime_error
{
public:

	FileManagerError(const char *whatStr);
	FileManagerError(const std::string &whatStr);
};

#endif // FILE_MANAGER_ERROR_HPP
