#include <gtest/gtest.h>

#include "FileManagerError.hpp"

TEST(FileManagerErrorTests, constructors)
{
	EXPECT_STREQ(FileManagerError("No such file or directory").what(), "FileManagerError: No such file or directory");
	EXPECT_STREQ(FileManagerError("No such file or directory", fs::path("non-exist")).what(), "FileManagerError: non-exist: No such file or directory");
}
