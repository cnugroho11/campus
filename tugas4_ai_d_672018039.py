from fuzzywuzzy import fuzz

def menu():
    print("===Menu===")
    print("1. Ratio")
    print("2. Partial Ratio")
    print("3. Token Sort Ratio")
    print("4. Token Set Ratio")
    print("5. Exit")

def fungsi():
    while(1):
        menu()
        pil = input("Pilhan anda : ")
        if pil == "1":
            kata1 = input("Masukan kata 1 : ")
            kata2 = input("Masukan kata 2 : ")
            print("Nilai : ", fuzz.ratio(kata1,kata2))
        elif pil == "2":
            kata1 = input("Masukan kata 1 : ")
            kata2 = input("Masukan kata 2 : ")
            print("Nilai : ", fuzz.partial_ratio(kata1, kata2))
        elif pil == "3":
            kata1 = input("Masukan kata 1 : ")
            kata2 = input("Masukan kata 2 : ")
            print("Nilai : ", fuzz.token_sort_ratio(kata1, kata2))
        elif pil == "4":
            kata1 = input("Masukan kata 1 : ")
            kata2 = input("Masukan kata 2 : ")
            print("Nilai : ", fuzz.token_set_ratio(kata1, kata2))
        elif pil == "5":
            exit()
        else:
            print("Pilihan anda salah!!")
fungsi()