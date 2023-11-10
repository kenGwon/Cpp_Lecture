
def get_cafe_menu(meun_num):
    global cafe_menu_dic
    cafe_menu_dic = {}

    for i in range(meun_num):
        inputStr = input()
        menu_name = inputStr[0:len(inputStr) - 3].strip()
        menu_price = inputStr[len(inputStr) - 3:len(inputStr)].strip()
        cafe_menu_dic[menu_name] = menu_price
    return 


def print_cafe_menu():
    global cafe_menu_list_dic
    global cafe_sales_dic
    cafe_menu_list_dic = {}
    cafe_sales_dic = {}

    print("\n============== CAFE MENU 리스트 ==============")
    for index, (key, value) in enumerate(cafe_menu_dic.items(), start = 1):
        print(f"[{index}] {key} {value}")
        cafe_menu_list_dic[index] = {key : value}
        cafe_sales_dic[index] = 0
    return 
 

def get_order():
    global total_sales
    total_sales = 0

    while True:
        inputOrder = input("\n>>> ").strip()
        if inputOrder == "0":
            break
        order_list = inputOrder.split(" ")

        flag_validcheck = True
        for i in range(len(order_list)):
            if int(order_list[i]) > len(cafe_menu_list_dic):
                flag_validcheck = False
                invalid_order_num = int(order_list[i])
                break

        if flag_validcheck:
            print("주문한 상품:")
            order_sales = 0
            for i in range(len(order_list)):
                cafe_sales_dic[int(order_list[i])] += 1 # 매출 기록
                order = list(cafe_menu_list_dic.values())[int(order_list[i]) - 1]

                menu_name = list(order.keys())[0]
                menu_price = int(float(list(order.values())[0]) * 1000)

                print(f"{menu_name} {menu_price}원")
                order_sales += menu_price
            print(f"합계 : {order_sales}원")
        else:
            print(f"{invalid_order_num}는 없는 메뉴입니다...")
            order_sales = 0
            continue
        
        total_sales += order_sales
    return 


def print_order():
    print("\n============== 매출 통계 ==============")
    
    for key, value in cafe_sales_dic.items():
        target_dic = list(cafe_menu_list_dic.values())[key - 1]
        target_key = list(target_dic.keys())[0]
        print(f"{target_key} {value}개")

    print(f"매출액 총계: {total_sales}원")
    return 


if __name__ == "__main__":
    menu_num = int(input("생성할 메뉴 갯수>>> "))
    get_cafe_menu(menu_num)
    print_cafe_menu()
    get_order()
    print_order()

