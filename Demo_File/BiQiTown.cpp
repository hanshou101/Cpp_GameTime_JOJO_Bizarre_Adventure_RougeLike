#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;


//vector<BaseMonster> BiQiTown::monsters = vector();


/**
 * ע��
 * BiQiTown������ս���������У�ȫ��ʹ�ó�Ա������ monster �� hero ��
 */

//������ս�������1��
BiQiTown::BiQiTown(BattleType t_type) {}


//������ս�������2��
BiQiTown::BiQiTown(BaseMonster *t_monster, BattleType t_type) : battleType(t_type) {
    monsters.push_back(t_monster);

    LeadingHero *battle_hero = ((LeadingHero *) (ManagerConst().heroList[0]));
    heros.push_back(battle_hero);                       //��������������е�����Ӣ�ۡ�
}

//������ս������¡�
BiQiTown::BiQiTown(BaseMonster *t_monster, LeadingHero *t_hero, BattleType t_type) : battleType(t_type) {
    monsters.push_back(t_monster);
    heros.push_back(t_hero);                //�����Ӣ�ۣ������Լ�ָ�����������÷�ʽ����
}


void BiQiTown::updateStatus() {
    cur_choice = 0;

    rounds = 0;             //ÿ�����»ص�����������غ������㡣

    faceMonster = false;

    /**
     * ÿ�ζ�����newһ���µģ�Ȼ�����vector��
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
     * ���Ӣ�۵Ļ���״̬�������߹���״̬��
     */
    if (0 >= hero->health)                       //����������С�ڵ���0ʱ��Ϸ����
    {
        cout << "Ӣ������ֵ���㣬�Ѿ����������ٻأ�" << endl;
        return false;
    }


    if (hero->attack_ability > 9999) {                                //�����˹��ص�����������Ϸ�Զ�����
        cout << "���Դ���ս����ס�" << endl;
        cout << "��ϲ�㣬������ռ��������ڹ����ˣ�" << endl;
        return false;
    }

    return true;
}

void BiQiTown::describe_scene() {


    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);       //�˴�û���õ�ManagerConst().monsterList[0]


    /**
     * ����С���Ұ�ⳡ��������
     */

    if (false == faceMonster) {                                         //�����ʱ��û���������������������ʾ��

        cout << "���ڴ��ڱ������ܱߵ�����֮�С�ϣ����û����·����" << endl;
        cout << "�����з���һ�ɸO�O�@�@���������������" << endl;

        printf("��ʼ��%sս��������\n", monsters[0]->label.c_str());
        printf("�����ڵ�״̬Ϊ��\n");
        printf("��������ֵ��%d   \n��������%d   \n��������%d   \n������Ǯ��%d   \n",
               hero->health, hero->attack_ability, hero->defence_ability, hero->money);

        faceMonster = true;                                             //��������ʾ����ʾ��Ϻ󣬱��Ϊ�Ѿ�����
    }





    /**
     * ս����ʼ֮��ĳ�������
     */



    //�����ǵڼ��غϡ�
    //��ѡ����Ķ���
    //1.������2.���ܡ�


    rounds++;

    printf("�����ǵ�%d�غ�\n", rounds);
    cout << "��ѡ����Ķ���" << endl;
    cout << "1.������" << endl;
    cout << "2.���ܡ�" << endl;


}

bool BiQiTown::continue_switch_action() {

    //��Թ��﷢���˹�����
    //�����˹�����ٵ�������
    //���ﻹʣ���ٵ�������
    //������㷢���˹�����
    //������������ٵ�������
    //�㻹ʣ���ٵ�����ֵ��

    //���������
    //���ܳɹ���



    cin >> cur_choice;


    switch (battleType) {
        case BattleType::Cat_Small: {

            HookMoreCat *cur_monster = ((HookMoreCat *) (monsters[0]));

            switch (cur_choice) {

                case 1: {
                    printf("���%s�����˹�����", cur_monster->label.c_str());
                    int damage_to_monster = heros[0]->attack_ability - cur_monster->defence_ability;
                    printf("������%s%d��������",
                           cur_monster->label.c_str(), damage_to_monster);
                    cur_monster->health -= damage_to_monster;            //�����Ѫ�ˡ�
                    printf("%s��ʣ%d��������\n", cur_monster->label.c_str(), cur_monster->health);

                    printf("%s���㷢���˹�����", cur_monster->label.c_str());
                    int damage_to_hero = cur_monster->attack_ability - heros[0]->defence_ability;
                    printf("%s�������%d��������",
                           cur_monster->label.c_str(), damage_to_hero);
                    heros[0]->health -= damage_to_hero;            //����Ӣ�ۿ�Ѫ�ˡ�
                    printf("�㻹ʣ%d��������\n\n", heros[0]->health);

                    if (0 >= cur_monster->health) {
                        //��ɱ�˹���
                        printf("%s����ɱ���ˣ���������������\n", cur_monster->label.c_str());
                        heros[0]->money += cur_monster->money_remaining;          //����˹������ϵĽ�Ǯ���������߻��ɾ�������
                        printf("������%s�������Ʒ���õ���%dG��������ӵ����%dG��",
                               cur_monster->label.c_str(), cur_monster->money_remaining, heros[0]->money);
                        return false;                   //ս��������
                    } else if (0 >= heros[0]->health) {
                        printf("�㱻%sɱ���ˣ���Ϸ������\n", cur_monster->label.c_str());                    //�����������Ѫ���سǸ��
                        return false;                   //ս��������
                    }

                    break;
                }
                case 2: {
                    cout << "��������ܣ�" << endl;
                    cout << "���ܳɹ���" << endl;
                    return false;                       //ս������
                    break;
                }
            }

            break;
        }
        case BattleType::Snowman_Large: {

            ForestSnowman *cur_monster = ((ForestSnowman *) (monsters[0]));

            switch (cur_choice) {

                case 1: {
                    printf("���%s�����˹���\n", cur_monster->label.c_str());
                    int damage_to_monster = heros[0]->attack_ability - cur_monster->defence_ability;
                    printf("������%s%d������\n",
                           cur_monster->label.c_str(), damage_to_monster);
                    cur_monster->health -= damage_to_monster;            //�����Ѫ�ˡ�
                    printf("%s��ʣ%d��������\n", cur_monster->label.c_str(), cur_monster->health);

                    printf("%s���㷢���˹���\n", cur_monster->label.c_str());
                    int damage_to_hero = cur_monster->attack_ability - heros[0]->defence_ability;
                    printf("%s�������%d������\n",
                           cur_monster->label.c_str(), damage_to_hero);
                    heros[0]->health -= damage_to_hero;            //����Ӣ�ۿ�Ѫ�ˡ�
                    printf("�㻹ʣ%d��������\n", heros[0]->health);

                    if (0 >= cur_monster->health) {
                        //��ɱ�˹���
                        printf("%s����ɱ���ˣ���������������\n", cur_monster->label.c_str());
                        heros[0]->money += cur_monster->money_remaining;          //����˹������ϵĽ�Ǯ���������߻��ɾ�������
                        printf("������%s�������Ʒ���õ���%dG��������ӵ����%dG��",
                               cur_monster->label.c_str(), cur_monster->money_remaining, heros[0]->money);
                        return false;                   //ս��������
                    } else if (0 >= heros[0]->health) {
                        printf("�㱻%sɱ���ˣ���Ϸ������\n", cur_monster->label.c_str());                    //�����������Ѫ���سǸ��
                        return false;                   //ս��������
                    }

                    break;
                }
                case 2: {
                    cout << "��������ܣ�" << endl;
                    cout << "���ܳɹ���" << endl;
                    return false;                       //ս������
                    break;
                }
            }

            break;

        }
    }


    return true;

}
