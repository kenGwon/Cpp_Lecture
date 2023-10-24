#include "cafe.h"

void Cafe::get_cafe_menu() {
    for (int i = 0; i < menu_num; i++) {
        pArray[i].set_menu();
        total_order[pArray[i].get_menu_name()] = 0;
    }
}

void Cafe::print_cafe_menu() {

    cout << "========== CAFE MENU ����Ʈ ==========" << endl;

    for (int i = 0; i < menu_num; i++) {
        cout << "[ " << i + 1 << " ] ";
        pArray[i].print_menu();
    }
}

void Cafe::get_order() {

    string order;
    int present = 0;
    int count = 0;
    int order_num = 0;
    int invalid_order_num = 0;
    int one_order_price = 0;
    bool valid_flag = true;

    while (true) {
        cout << ">> ";
        getline(cin, order);

        // 0�� �ԷµǸ� �ֹ��Է� �ݺ��� ������
        if (order == "0") {
            break;
        }

        // ���� ������ �Ʒ��� ������ ���ܾ��� ���ư��� ���ؼ��� �ֹ� �Է� ��Ʈ�� ���� �ݵ�� ���� �ϳ��� �� �־����
        if (order.at(size(order) - 1) != ' ') {
            order.append(" ");
        }

        // ���� �ʱ�ȭ �� �߸��� �ֹ��� �ִ��� while�� ���鼭 check
        present = 0;
        count = 0;
        while (order.find(" ", present) != -1) {
            order_num = stoi(order.substr(present, order.find(" ", present) - present)); // �ֹ� ��Ʈ���� ��ũ����¡�Ͽ� int�� ��ȯ
            if (order_num > menu_num) {
                valid_flag = false;
                invalid_order_num = order_num;
                break;
            }
            count++; // �ֹ��� ����
            present = order.find(" ", present) + 1; // ���� ������ ���� present�� ����
        }

        // �߸��� �ֹ��� �־��ٸ�, ���� �ֹ��� �޴� ������ continue
        if (valid_flag == false) {
            cout << invalid_order_num << "�� ���� �޴��Դϴ�..." << endl;
            valid_flag = true;
            continue;
        }

        // ��� �ֹ��� valid�� ���
        cout << "�ֹ��� ��ǰ : " << endl;

        // ���� �ʱ�ȭ �� while�� �Ѹ鼭 �ֹ����� ����ϰ�, �ֹ����� map�ڷ����� ���
        present = 0;
        one_order_price = 0;
        while (order.find(" ", present) != -1) {
            order_num = stoi(order.substr(present, order.find(" ", present) - present)); // �ֹ� ��Ʈ���� ��ũ����¡�Ͽ� int�� ��ȯ
            order_num -= 1;

            total_order[pArray[order_num].get_menu_name()] += 1; // �ֹ� ���� ����

            cout << pArray[order_num].get_menu_name() << " " << pArray[order_num].get_int_menu_price() << "��" << endl;

            one_order_price += pArray[order_num].get_int_menu_price();
            present = order.find(" ", present) + 1; // ���� ������ ���� present�� ����
        }

        cout << "�հ� : " << one_order_price << "��" << endl;
        total_sales += one_order_price;
    }
}

void Cafe::print_sales() {

    cout << "========== ���� ��� ==========" << endl;

    for (int i = 0; i < menu_num; i++) {
        // �ֹ��� �ϳ��� �ȵ��� �޴��� continue�� ������� �ʰ� �ѱ�
        if (total_order[pArray[i].get_menu_name()] == 0) {
            continue;
        }

        cout << pArray[i].get_menu_name() << " " << total_order[pArray[i].get_menu_name()] << "��" << endl;
    }

    cout << "����� �Ѱ� : " << total_sales << "��" << endl;
}

