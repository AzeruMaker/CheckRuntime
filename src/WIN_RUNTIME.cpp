#include "WIN_RUNTIME.h"

WIN_RUNTIME::WIN_RUNTIME()
{
    std::vector<std::string> vcRuntimes;
    std::vector<std::string> dotNetVersions;

    // Paths to check for Visual C++ Runtimes
    std::vector<std::pair<HKEY, std::string>> vcRuntimePaths = {
        {HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\VisualStudio"},
        {HKEY_LOCAL_MACHINE, "SOFTWARE\\WOW6432Node\\Microsoft\\VisualStudio"}
    };

    // Paths to check for .NET Framework
    std::vector<std::pair<HKEY, std::string>> dotNetPaths = {
        {HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\NET Framework Setup\\NDP"},
        {HKEY_LOCAL_MACHINE, "SOFTWARE\\WOW6432Node\\Microsoft\\NET Framework Setup\\NDP"}
    };

    CheckRegistryKeys(vcRuntimePaths, vcRuntimes, "Visual C++");
    CheckRegistryKeys(dotNetPaths, dotNetVersions, ".NET Framework");

    std::cout << "\nInstalled Visual C++ Runtimes:" << std::endl;
    for (const auto& runtime : vcRuntimes) {
        std::cout << runtime << std::endl;
    }

    std::cout << "\nInstalled .NET Framework versions:" << std::endl;
    for (const auto& version : dotNetVersions) {
        std::cout << version << std::endl;
    }

}

WIN_RUNTIME::~WIN_RUNTIME()
{
    //dtor
}


bool WIN_RUNTIME::EnumRegistryKeys(HKEY hKeyRoot, const std::string& subKey, std::vector<std::string>& keys) {
    HKEY hKey;
    if (RegOpenKeyExA(hKeyRoot, subKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        return false;
    }

    DWORD index = 0;
    char keyName[256];
    DWORD keyNameSize = sizeof(keyName);

    while (RegEnumKeyExA(hKey, index, keyName, &keyNameSize, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
        keys.push_back(keyName);
        keyNameSize = sizeof(keyName);
        index++;
    }

    RegCloseKey(hKey);
    return true;
}

std::string WIN_RUNTIME::GetRegistryValue(HKEY hKeyRoot, const std::string& subKey, const std::string& valueName) {
    HKEY hKey;
    if (RegOpenKeyExA(hKeyRoot, subKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        return "";
    }

    char value[256];
    DWORD valueSize = sizeof(value);
    DWORD type;

    if (RegQueryValueExA(hKey, valueName.c_str(), nullptr, &type, (LPBYTE)value, &valueSize) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return std::string(value, valueSize);
    }

    RegCloseKey(hKey);
    return "";
}

void WIN_RUNTIME::CheckRegistryKeys(const std::vector<std::pair<HKEY, std::string>>& paths, std::vector<std::string>& results, const std::string& prefix) {
    for (const auto& path : paths) {
        std::vector<std::string> keys;
        if (EnumRegistryKeys(path.first, path.second, keys)) {
            for (const auto& key : keys) {
                std::string versionString = GetRegistryValue(path.first, path.second + "\\" + key, "Version");
                if (!versionString.empty()) {
                    results.push_back(prefix + " " + key + ": " + versionString);
                } else {
                    results.push_back(prefix + " " + key);
                }
            }
        }
    }
}
