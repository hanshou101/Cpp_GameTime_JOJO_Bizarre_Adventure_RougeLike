#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;


//vector<BaseMonster> BiQiTown::monsters = vector();


/**
 * 注：
 * BiQiTown这样的战斗场景类中，全部使用成员变量的 monster 和 hero 。
 */

//【单人战斗情况下1】
BiQiTown::BiQiTown(BattleType t_type) {}


//【单人战斗情况下2】
BiQiTown::BiQiTown(BaseMonster *t_monster, BattleType t_type) : battleType(t_type) {
    monsters.push_back(t_monster);

    LeadingHero *battle_hero = ((LeadingHero *) (ManagerConst().heroList[0]));
    heros.push_back(battle_hero);                       //这是世界管理类中的主角英雄。
}

//【多人战斗情况下】
BiQiTown::BiQiTown(BaseMonster *t_monster, LeadingHero *t_hero, BattleType t_type) : battleType(t_type) {
    monsters.push_back(t_monster);
    heros.push_back(t_hero);                //这里的英雄，可以自己指定。（用引用方式。）
}


void BiQiTown::updateStatus() {
    cur_choice = 0;

    rounds = 0;             //每次重新回到这个场景，回合数清零。

    faceMonster = false;

    /**
     * 每次都创建new一个新的，然后放入vector。
     */
    switch (battleType) {
        case BattleType::Cat_Small: {
            monsters[0] = new HookMoreCat();
            break;
        }
        case BattleType::Snowman_Large: {
            monsters[0] = new ForestSnowman();
            break;
        }
    }

}

bool BiQiTown::checkAlive_orCompleted() {

    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);

    /**
     * 检测英雄的基本状态：存活或者过关状态。
     */
    if (0 >= hero->health)                       //主角生命力小于等于0时游戏结束
    {
        cout << "英雄生命值不足，已经被世界树召回！" << endl;
        return false;
    }


    if (hero->attack_ability > 9999) {                                //触发了过关的条件，则游戏自动进阶
        cout << "可以穿戴战神盔甲。" << endl;
        cout << "恭喜你，完成了终极任务，终于过关了！" << endl;
        return false;
    }

    return true;
}

void BiQiTown::describe_scene() {


    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);       //此处没有用到ManagerConst().monsterList[0]


    /**
     * 比奇小镇的野外场景描述。
     */

    if (false == faceMonster) {                                         //如果此时还没有遇到怪物，弹出【遇怪提示】

        cout << "现在处于比奇镇周边的树林之中。希望你没有迷路……" << endl;
        cout << "树丛中发出一股窸窸窣窣的声音，遭遇怪物！" << endl;

        printf("开始与%s战斗！！！\n", monsters[0]->label.c_str());
        printf("你现在的状态为：\n");
        printf("生命健康值：%d   \n攻击力：%d   \n防御力：%d   \n背包金钱：%d   \n",
               hero->health, hero->attack_ability, hero->defence_ability, hero->money);

        faceMonster = true;                                             //【遇怪提示】显示完毕后，标记为已经遇怪
    }





    /**
     * 战斗开始之后的场景描述
     */



    //现在是第几回合。
    //请选择你的动作
    //1.攻击。2.逃跑。


    rounds++;

    printf("现在是第%d回合\n", rounds);
    cout << "请选择你的动作" << endl;
    cout << "1.攻击。" << endl;
    cout << "2.逃跑。" << endl;


}

bool BiQiTown::continue_switch_action() {

    //你对怪物发动了攻击。
    //你打掉了怪物多少的生命。
    //怪物还剩多少点生命。
    //怪物对你发动了攻击。
    //怪物打掉了你多少的生命。
    //你还剩多少点生命值。

    //你决定逃跑
    //逃跑成功。



    cin >> cur_choice;


    switch (battleType) {
        case BattleType::Cat_Small: {

            HookMoreCat *cur_monster = ((HookMoreCat *) (monsters[0]));

            switch (cur_choice) {

                case 1: {
                    printf("你对%s发动了攻击，", cur_monster->label.c_str());
                    int damage_to_monster = heros[0]->attack_ability - cur_monster->defence_ability;
                    printf("你打掉了%s%d的生命，",
                           cur_monster->label.c_str(), damage_to_monster);
                    cur_monster->health -= damage_to_monster;            //怪物扣血了。
                    printf("%s还剩%d点生命。\n", cur_monster->label.c_str(), cur_monster->health);

                    printf("%s对你发动了攻击，", cur_monster->label.c_str());
                    int damage_to_hero = cur_monster->attack_ability - heros[0]->defence_ability;
                    printf("%s打掉了你%d的生命，",
                           cur_monster->label.c_str(), damage_to_hero);
                    heros[0]->health -= damage_to_hero;            //主角英雄扣血了。
                    printf("你还剩%d点生命。\n\n", heros[0]->health);

                    if (0 >= cur_monster->health) {
                        //击杀了怪物
                        printf("%s被你杀死了！你真厉害！！！\n", cur_monster->label.c_str());
                        heros[0]->money += cur_monster->money_remaining;          //获得了怪物身上的金钱。【屠龙者会变成巨龙？】
                        printf("你搜索%s掉落的物品，得到了%dG。你现在拥有了%dG。",
                               cur_monster->label.c_str(), cur_monster->money_remaining, heros[0]->money);
                        return false;                   //战斗结束。
                    } else if (0 >= heros[0]->health) {
                        printf("你被%s杀死了，游戏结束。\n", cur_monster->label.c_str());                    //被怪物打至空血。回城复活。
                        return false;                   //战斗结束。
                    }

                    break;
                }
                case 2: {
                    cout << "你决定逃跑！" << endl;
                    cout << "逃跑成功！" << endl;
                    return false;                       //战斗结束
                    break;
                }
            }

            break;
        }
        case BattleType::Snowman_Large: {

            ForestSnowman *cur_monster = ((ForestSnowman *) (monsters[0]));

            switch (cur_choice) {

                case 1: {
                    printf("你对%s发动了攻击\n", cur_monster->label.c_str());
                    int damage_to_monster = heros[0]->attack_ability - cur_monster->defence_ability;
                    printf("你打掉了%s%d的生命\n",
                           cur_monster->label.c_str(), damage_to_monster);
                    cur_monster->health -= damage_to_monster;            //怪物扣血了。
                    printf("%s还剩%d点生命。\n", cur_monster->label.c_str(), cur_monster->health);

                    printf("%s对你发动了攻击\n", cur_monster->label.c_str());
                    int damage_to_hero = cur_monster->attack_ability - heros[0]->defence_ability;
                    printf("%s打掉了你%d的生命\n",
                           cur_monster->label.c_str(), damage_to_hero);
                    heros[0]->health -= damage_to_hero;            //主角英雄扣血了。
                    printf("你还剩%d点生命。\n", heros[0]->health);

                    if (0 >= cur_monster->health) {
                        //击杀了怪物
                        printf("%s被你杀死了！你真厉害！！！\n", cur_monster->label.c_str());
                        heros[0]->money += cur_monster->money_remaining;          //获得了怪物身上的金钱。【屠龙者会变成巨龙？】
                        printf("你搜索%s掉落的物品，得到了%dG。你现在拥有了%dG。",
                               cur_monster->label.c_str(), cur_monster->money_remaining, heros[0]->money);
                        return false;                   //战斗结束。
                    } else if (0 >= heros[0]->health) {
                        printf("你被%s杀死了，游戏结束。\n", cur_monster->label.c_str());                    //被怪物打至空血。回城复活。
                        return false;                   //战斗结束。
                    }

                    break;
                }
                case 2: {
                    cout << "你决定逃跑！" << endl;
                    cout << "逃跑成功！" << endl;
                    return false;                       //战斗结束
                    break;
                }
            }

            break;

        }
    }


    return true;

}
