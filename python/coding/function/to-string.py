class ReprVsStr:
    def __repr__(self):
        return "<{0}.{1} object at {2}>".format(
            self.__module__, type(self).__name__, hex(id(self))
        )

    def __str__(self):
        return (
            f"Nom de la classe {type(self).__name__} dans le module {self.__module__}"
        )


print(repr(ReprVsStr()))
print(str(ReprVsStr()))
