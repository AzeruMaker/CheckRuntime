#include <iostream>
#include <filesystem>
#include <string>

#ifndef WIN_OPENAL_H
#define WIN_OPENAL_H


class WIN_OPENAL
{
    public:
        WIN_OPENAL();
        virtual ~WIN_OPENAL();

    protected:

    private:
        bool FileExists(const std::string& path);
};

#endif // WIN_OPENAL_H
