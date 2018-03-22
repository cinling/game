#include "saves_manager.h"



SavesManager * SavesManager::shareInstance = nullptr;


const std::string SavesManager::SAVES_PATH = "saves/";
const std::string SavesManager::TEMPORARY_SAVES = "tmp_save";


SavesManager::SavesManager() {
}


SavesManager * SavesManager::GetInstance() {
    if (shareInstance == nullptr) {
        shareInstance = new SavesManager();
    }
    return shareInstance;
}

SavesManager::~SavesManager() {
}

bool SavesManager::Save(std::string savesName) {

    SqliteTool::UseDB((SavesManager::SAVES_PATH + savesName).c_str());

    DBManager * db = DBManager::GetInstance();
    if (!db->DBUpdate()) {
        return false;
    }

    // ��������
    if (!this->SaveWorld()) {
        return false;
    }

    return true;
}

std::list<std::string> SavesManager::GetSavesList() {

    std::list<std::string> tmpData;

    tmpData.push_back("1");
    tmpData.push_back("2");
    tmpData.push_back("3");
    tmpData.push_back("4");
    tmpData.push_back("5");
    tmpData.push_back("6");
    tmpData.push_back("7");
    tmpData.push_back("8");
    tmpData.push_back("9");
    tmpData.push_back("10");

    return tmpData;
}

bool SavesManager::Load(std::string savesName) {
    return false;
}

bool SavesManager::SaveWorld() {
    World * world = World::GetInstance();
    world->Save();
    return true;
}

bool SavesManager::BackupTemporarySaves(std::string savesName) {
    std::string oldPath = SavesManager::SAVES_PATH + savesName;
    std::string newPath = SavesManager::SAVES_PATH + SavesManager::TEMPORARY_SAVES;

    return Tool::File::Rename(oldPath, newPath);
}

bool SavesManager::DeleteTemporarySaves() {
    return false;
}

bool SavesManager::RecoveryTemporarySaves(std::string savesName) {
    return false;
}
