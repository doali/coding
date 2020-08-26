#!/usr/bin/env python3

import sys


class Person:
    def __init__(self, firstname):
        self.firstname = firstname
        self.list_friend = []  # important
        self.love = None  # important

    def add_friend(self, friend):
        self.list_friend.append(friend)

    def add_love(self, friend):
        self.love = friend
        self.list_friend.append(friend)
        friend.love = self  # interesting (friend.add_love(self) => recursion !!)

    def __str__(self):
        des = f"{self.firstname}"
        for friend in self.list_friend:
            des += f"\n\t- {friend.firstname}"
            des += (
                f" \u2665"
                if self.love != None and self.love.firstname == friend.firstname
                else ""
            )
        return des


if __name__ == "__main__":
    sys.stdout.write("I am ")
    p_0 = Person("Camille")
    print(p_0)

    print()
    sys.stdout.write("I am ")
    p_1 = Person("Charles")
    print(p_1)

    print()
    dic = {"lisa": Person("Lisa"), "pierre": Person("Pierre")}
    list(map(lambda x: p_0.add_friend(dic[x]), dic))  # interesting
    print(f"Me {p_0.firstname}, I met many friends")
    print(p_0)

    print()
    print(f"I also met a special friend in Paris, {p_1.firstname}")
    p_0.add_love(p_1)  # => p_1.add_friend(p_0)
    print(p_0)

    print()
    print("And then other friends")
    p_0.add_friend(Person("Jeanne"))
    p_0.add_friend(Person("Jean"))
    p_0.add_friend(Person("Charlotte"))
    print(p_0)

    print()
    print(f"As for me {p_1.firstname}, I met many friends as well")
    p_1.add_friend(p_0)  # important !
    list(p_1.add_friend(dic[x]) for x in dic)  # interesting
    print(p_1)
