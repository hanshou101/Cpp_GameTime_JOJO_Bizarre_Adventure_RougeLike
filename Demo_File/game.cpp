#include "_class_implementation_son.h"             //��������
#include "_class_declaration_father.h"             //��������
#include "_logic_declaration.h"             //ҵ���߼�

/**
 * ԭ�洴���ַ  ����C++����д��Ϸ�������С��Ϸ��
 *             http://blog.csdn.net/cnyali_ljf/article/details/51340317
 */

int main_main_main() {

    ManagerConst manager = ManagerConst(true);//���������
    Birth_TownSquare *square = (Birth_TownSquare *) (manager.sceneList[0]);               //�㳡��ʵ����

    square->whole_logic();           //���롾�㳡�����������߼���

    return 0;
}


