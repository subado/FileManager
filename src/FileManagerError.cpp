#include "FileManagerError.hpp"

FileManagerError::FileManagerError(const char *whatStr)
: std::runtime_error(std::string("FileManagerError: ") + whatStr)
{
}

FileManagerError::FileManagerError(const std::string &whatStr)
: std::runtime_error("FileManagerError: " + whatStr)
{
}
