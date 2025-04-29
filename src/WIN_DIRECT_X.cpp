#include "WIN_DIRECT_X.h"

WIN_DIRECT_X::WIN_DIRECT_X()
{
    std::set<std::string> directXVersions;
    CheckDirectXVersions(directXVersions);

    std::cout << "Installed DirectX versions:" << std::endl;
    for (const auto& version : directXVersions) {
        std::cout << version << std::endl;
    }
}

WIN_DIRECT_X::~WIN_DIRECT_X()
{
    //dtor
}

bool WIN_DIRECT_X::FileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

void WIN_DIRECT_X::CheckDirectXVersions(std::set<std::string>& directXVersions) {
    // Define the paths to check for each DirectX version
    std::vector<std::pair<std::string, std::string>> directXPaths = {
        {"DirectX 6.0", "C:\\Windows\\System32\\ddraw.dll"},
        {"DirectX 7.0", "C:\\Windows\\System32\\d3drm.dll"},
        {"DirectX 8.0", "C:\\Windows\\System32\\d3d8.dll"},
        {"DirectX 8.1", "C:\\Windows\\System32\\d3d8thk.dll"},
        {"DirectX 9.0", "C:\\Windows\\System32\\d3d9.dll"},
        {"DirectX 9.0+", "C:\\Windows\\System32\\d3dx9_43.dll"},
        {"DirectX 10.0", "C:\\Windows\\System32\\d3d10.dll"},
        {"DirectX 10.1", "C:\\Windows\\System32\\d3d10_1.dll"},
        {"DirectX 11.0", "C:\\Windows\\System32\\d3d11.dll"},
        {"DirectX 12.0", "C:\\Windows\\System32\\d3d12.dll"}
    };

    // Check each path
    for (const auto& path : directXPaths) {
        if (FileExists(path.second)) {
            directXVersions.insert(path.first);
        }
    }
}
