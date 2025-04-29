#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <set>
#include <filesystem>

#ifndef WIN_DIRECTX_H
#define WIN_DIRECTX_H


class WIN_DIRECTX
{
    public:

        WIN_DIRECTX();
        virtual ~WIN_DIRECTX();

    protected:

    private:
        std::set<std::string> directXVersions;
        bool FileExists(const std::string& path);
        void CheckDirectXVersions(std::set<std::string>& directXVersions);


#endif // WIN_DIRECTX_H
