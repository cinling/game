#pragma once

#include "world_manager.h"
#include "saves_manager.h"
#include "json.h"

#include <string>
#include <list>

class SocketNumManager {
private:
    static SocketNumManager * shareInstance;
    SocketNumManager();
    ~SocketNumManager();
public:
    static SocketNumManager * GetInstance();

    /*�ͻ��˲�������ˣ������������Ӧ�Ĵ���*/
    // ��ʼ����Ϸ����Ĵ���
    std::string _10001_InitMap(std::string data);
    // ������Ϸ
    std::string _10002_Save(std::string data);
    // ��ȡ��Ϸ�浵�б�
    std::string _10003_GetSavesList(std::string data);
    // ������Ϸ�浵
    std::string _10004_LoadGame(std::string data);

    /*�ͻ���������������*/
    // ��ȡ��Ϸ�ĵ�ͼ������
    std::string _20001_GetMapData(std::string data);
};
