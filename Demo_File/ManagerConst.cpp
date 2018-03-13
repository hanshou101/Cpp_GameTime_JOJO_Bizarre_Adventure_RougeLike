#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;


vector<BaseHero *> ManagerConst::heroList = vector<BaseHero *>();
vector<BaseScene *> ManagerConst::sceneList = vector<BaseScene *>();
vector<BaseMonster *> ManagerConst::monsterList = vector<BaseMonster *>();


ManagerConst::ManagerConst() {

}

ManagerConst::ManagerConst(bool needInit) {
    if (needInit) {
        initConstManager();         //��ʼ��һ�¡�ÿ������������+1��
    } else {
        ManagerConst();             //ʲô����ִ�С�
    };
}

void ManagerConst::initConstManager() {                     //��ʼ�������ࡣ
    this->heroList.push_back(new LeadingHero());

    this->sceneList.push_back(new Birth_TownSquare());
    this->sceneList.push_back(new Weapon_Shop());
    this->sceneList.push_back(new Drug_Shop());
    this->sceneList.push_back(new BiQiTown(new HookMoreCat(), BiQiTown::BattleType::Cat_Small));
    this->sceneList.push_back(new BiQiTown(new ForestSnowman(), BiQiTown::BattleType::Snowman_Large));

    this->monsterList.push_back(new HookMoreCat());
}

