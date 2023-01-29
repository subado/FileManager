#include <gtest/gtest.h>

#include "FileManagerError.hpp"

TEST(FileManagerErrorTests, constructors)
{
	EXPECT_STREQ(FileManagerError("No such file or directory").what(), "FileManagerError: No such file or directory");
}
