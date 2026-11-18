class TestSubject():
    
    def __init__(self, name: str = 'Jarron Racelis', age: int = 18):
        self._name = name
        self._age = age

    @property
    def name(self) -> str:
        return self._name

    @property
    def age(self) -> int:
        return self._age

    @name.setter
    def name(self, name: str) -> None:
        self._name = name

    @age.setter
    def age(self, age: int) -> None:
        self._age = age

    def greet(self):
        print(f'Hello {self.name} my age is {self.age}')

class InheritanceSubject(TestSubject):
    
    def __init__(self, height: int = None):
        super().__init__()
        self._height = height
    
    @property
    def height(self):
        return self._height

    def greet(self):
        print(f'Hello {self.name} my age is {self.age}.\nI am {self.height} tall.')

def main():
    
    test_subject: TestSubject = TestSubject()
    test_subject.greet()

    print(test_subject.__dict__)
    print(type(test_subject))

    testing_two: InheritanceSubject = InheritanceSubject()
    if hasattr(testing_two, '_height'):
        testing_two.greet()

    print(testing_two.__dict__)

if __name__ == '__main__':
    main()
