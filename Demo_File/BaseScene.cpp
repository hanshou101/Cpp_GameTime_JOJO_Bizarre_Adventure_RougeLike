#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;

vector <BaseScene::Scene> BaseScene::scenes = {
        BaseScene::Scene("weapon_shop"),
        BaseScene::Scene("drug_shop"),
};