#include "WIN_DX.h"

bool WIN_DX::FileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

void WIN_DX::CheckDirectXVersions(std::set<std::string>& directXVersions) {
    // Définir les chemins à vérifier pour chaque version de DirectX
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

    // Vérifier chaque chemin
    for (const auto& path : directXPaths) {
        if (FileExists(path.second)) {
            directXVersions.insert(path.first);
        }
    }
}
