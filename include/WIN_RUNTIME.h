#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <set>
#include <filesystem>

#ifndef WIN_RUNTIME_H
#define WIN_RUNTIME_H


class WIN_RUNTIME
{
    public:
        WIN_RUNTIME();
        virtual ~WIN_RUNTIME();
    protected:
    private:
        bool EnumRegistryKeys(HKEY hKeyRoot, const std::string& subKey, std::vector<std::string>& keys);
        std::string GetRegistryValue(HKEY hKeyRoot, const std::string& subKey, const std::string& valueName);
        void CheckRegistryKeys(const std::vector<std::pair<HKEY, std::string>>& paths, std::vector<std::string>& results, const std::string& prefix);

};

#endif // WIN_RUNTIME_H
