#include <windows.h>
#include <vector>
#include <string>
#include <set>
#include <filesystem>
#include <iostream>


#ifndef WIN_DIRECT_X_H
#define WIN_DIRECT_X_H


class WIN_DIRECT_X
{
    public:
        WIN_DIRECT_X();
        virtual ~WIN_DIRECT_X();

    protected:

    private:
        bool FileExists(const std::string& path);
        void CheckDirectXVersions(std::set<std::string>& directXVersions);
};

#endif // WIN_DIRECT_X_H
