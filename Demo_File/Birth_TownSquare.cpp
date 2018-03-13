#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;


void Birth_TownSquare::updateStatus() {
    cur_choice = 0;
}


bool Birth_TownSquare::checkAlive_orCompleted() {

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
};

void Birth_TownSquare::describe_scene() {
    //TODO ����������������Ϊѡ�����̵档д����ҿ��Ļ���������ѡ���֧������������+��ѡ�
    //����������ģ����������������ġ����ܡ�


    cout << "������Ƭ��ʱ����������ˣ�" << endl;
    cout << "С��\n" << endl;
    cout << "һ��1000���С����Χ��һ���ӣ���һƬ���֣��ܶ෿�Ӻͺܶ��ˡ�\n��һ��ҩ��" << endl;
    cout << "��һ�������ꡣ\n" << endl;

    /**
     * ǰ��ѡ�����ѡ���ÿ��ѭ������ǰ�棨����������ѡ��ָ��֮ǰ����
     */

    cout << "1.ȥ������" << endl;
    cout << "2.ȥҩƷ��" << endl;
    cout << "3.ȥ��С����" << endl;
    cout << "4.ȥ������" << endl;
    cout << "5.��ʾ���״̬" << endl;
    cout << "6.�˳���Ϸ" << endl;
}


bool Birth_TownSquare::continue_switch_action() {

    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);

    cin >> cur_choice;

    if (cur_choice == 6) {
        //�����������  ��֧6  �Ļ������Զ���������Ϸ�������Կ��Ǽ����ȴ������˳�ϵͳ����

        //hWnd����Ϣ�����ڴ��ڡ� lpText����Ϣ������ݡ�  lpCaption����Ϣ��ı��⡣   uType����Ϣ������ࡣ
        //int box_result_1 = MessageBox(nullptr, "����һ��\nȷ�� ȡ��\n����Ϣ��", "��������", MB_OKCANCEL);
        //int box_result_2 = MessageBox(nullptr, "����һ���������Ϣ��", "��������", MB_ICONEXCLAMATION);
        //int box_result_3 = MessageBox(nullptr, "����һ��\n��������\n����Ϣ��", "��������", MB_ICONEXCLAMATION|MB_OKCANCEL);
        //int box_result_4 = MessageBox(nullptr, "Ӧ��ģʽ��һ", "��������", MB_ICONINFORMATION|MB_OKCANCEL);
        //int box_result_5 = MessageBox(nullptr, "��ťģʽ��һ", "��������", MB_ICONINFORMATION|MB_OKCANCEL);
        //int box_result_6 = MessageBox(nullptr, "��ťģʽ����", "��������", MB_ICONINFORMATION|MB_YESNO);
        //int box_result_7 = MessageBox(nullptr, "��ťģʽ����", "��������", MB_ICONINFORMATION|MB_OK);
        //int box_result_8 = MessageBox(nullptr, "��ťģʽ����", "��������", MB_ICONINFORMATION|MB_CANCELTRYCONTINUE);//ȡ�������ԡ�����
        //int box_result_9 = MessageBox(nullptr, "��ťģʽ����", "��������", MB_ICONINFORMATION | MB_YESNOCANCEL);//�ǡ���ȡ��
        int box_result_10 = MessageBox(nullptr, "��ȷ��Ҫ�˳���Ϸ��", "�˳���Ϸ", MB_ICONINFORMATION | MB_YESNOCANCEL);//�ǡ���ȡ��
        switch (box_result_10) {
            case IDYES: {
                cout << "������ǰ�ť" << endl;
                MessageBox(nullptr, "��ɽ���ģ���ˮ������", "����������", MB_ICONEXCLAMATION);
                return false;
            }
            case IDNO: {
                cout << "����˷�ť" << endl;
                return true;
            }
            case IDOK: {
                cout << "�����ȷ����ť" << endl;        //IDOK��Ȼ��IDYES�ǲ�ͬ�ģ�������˼��
                return false;               //�жϵ�ǰ����������False�������ж�whole_logic���ѭ����ʹBirth_TownSquare��whole_logic�ߵ���ͷ�������˳�Birth_TownSquare��
            }
            case IDCANCEL: {
                cout << "�����ȡ����ť" << endl;
                return true;                //�жϵ�ǰ�����������ж�whole_logic���ѭ����
            }
            case IDRETRY: {
                cout << "��������԰�ť" << endl;
                return true;
            }

            case IDCONTINUE: {
                cout << "����˼�����ť" << endl;
                return true;
            }
        }

    };


    switch (cur_choice) {
        case 1:
            //ȥ�����ꡣ
            ((Weapon_Shop *) (ManagerConst().sceneList[1]))->whole_logic();
            break;

        case 2:
            //ȥҩƷ�ꡣ
            ((Drug_Shop *) (ManagerConst().sceneList[2]))->whole_logic();
            break;

        case 3:
            //ȥ��๳è��
            ((BiQiTown *) (ManagerConst().sceneList[3]))->whole_logic();
            break;

        case 4:
            //ȥ��ɭ��ѩ�ˡ�
            ((BiQiTown *) (ManagerConst().sceneList[4]))->whole_logic();
            break;

        case 5:
            //�������״̬��
            printf("\n");
            printf("��ǰ״̬��   \n��������ֵ��%d   \n��������%d   \n��������%d   \n������Ǯ��%d   ",
                   hero->health, hero->attack_ability, hero->defence_ability, hero->money);
            printf("\n");
            printf("\n");
            break;

        default:
            cout << "�������ѡ���ţ����޷�ʶ��";
            break;


    }

    return true;

}


