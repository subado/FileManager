#include <fstream>

#include <gtest/gtest.h>

#include "FileManager.hpp"
#include "FileManagerError.hpp"

TEST(FileManagerErrorTests, constructors)
{
	EXPECT_STREQ(FileManagerError("No such file or directory").what(), "FileManagerError: No such file or directory");
	EXPECT_STREQ(FileManagerError("No such file or directory", fs::path("non-exist")).what(), "FileManagerError: No such file or directory [non-exist]");
}

class FileManagerTest : public ::testing::Test
{
public:

	FileManager *fileManager;

protected:

	void SetUp() override
	{
		fileManager = new FileManager;
	}

	void TearDown() override
	{
		delete fileManager;
	}
};

TEST_F(FileManagerTest, changeDir)
{
	fs::create_directories("temp");

	fileManager->changeDir("temp");

	fs::remove_all("temp");
}

TEST_F(FileManagerTest, changeDirErrorExist)
{
	try
	{
		fileManager->changeDir("non-exist");
	}
	catch (const FileManagerError &error)
	{
		EXPECT_STREQ(error.what(), "FileManagerError: No such file or directory [non-exist]");
	}
}

TEST_F(FileManagerTest, changeDirErrorFile)
{
	std::ofstream file("file");

	try
	{
		fileManager->changeDir("file");
	}
	catch (const FileManagerError &error)
	{
		EXPECT_STREQ(error.what(), "FileManagerError: Not a directory [file]");
	}

	fs::remove("file");
}
