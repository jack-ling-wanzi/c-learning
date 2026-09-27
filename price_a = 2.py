price_a = 2
price_b = 1
price_c = 1.5

weight_a = 0
weight_b = 0
weight_c = 0

money_a = 0
money_b = 0
money_c = 0

q = True

while q:
    buy = input('which things do you want to buy,a or b or c?')
    if buy == 'q':
        q = False

    elif buy == 'a':
        weight_a_added = int(input('How many a do you want to have'))
        weight_a += weight_a_added
        if weight_a < 0:
            print('The things of weight cannot < 0')
            continue
        money_a = price_a * weight_a
    elif buy == 'b':
        weight_b_added = int(input('How many b do you want to have'))
        weight_b += weight_b_added
        if weight_b < 0:
            print('The things of weight cannot < 0')
            continue
        money_b = price_b * weight_b
    elif buy == 'c':
        weight_c_added = int(input('How many c do you want to have'))
        weight_c += weight_c_added
        if weight_c < 0:
            print('The things of weight cannot < 0')
            continue
        money_c = price_c * weight_c
                        

    message = input('do want to everything else?')
    if message == 'yes':
        continue
    elif message == 'no':
        print(f"a of money is {money_a}")
        print(f"b of money is {money_b}")
        print(f"c of money is {money_c}")

        title = money_a + money_b + money_c
        print(f"title:{title}")